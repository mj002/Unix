%{
#include "priv.h"
#define ARGSIZ 200
#define LISTSIZ 1000
char *xv[LISTSIZ], **xvp, **xvtop = &xv[LISTSIZ];
#define XPUSH(w) if(xvp<xvtop)*xvp++=w;else error("xvp overflow")
%}
%union {
	char * word;
	Func *func;
}
%token <word>COMMENT WORD REQUEST RMREQUEST
%token DEFINE ACCESS RIGHTS NEEDS DOES
%token RMDEFINE RMACCESS RMRIGHTS RMNODE
%left ','
%type <func> func funlist request rmrequest
%%
list:
	| list ';'
	| list DEFINE funlist ';'	{ makeright($3); }
	| list request NEEDS funlist DOES funlist ';'
					{ needright($2, $4, $6); }
	| list ACCESS WORD funlist ';'
					{ makeaclist($3, $4); }
	| list RIGHTS WORD funlist ';'
					{ makerights($3, $4); }
	| list RMDEFINE funlist ';'	{ rmdef($3); }
	| list rmrequest ';'		{ rmrequest($2); }
	| list RMACCESS WORD funlist ';'{ rmaccess($3, $4); }
	| list RMACCESS WORD ';'	{ rmaccess($3, (Func*)0); }
	| list RMRIGHTS WORD funlist ';'{ rmrights($3, $4); }
	| list RMRIGHTS WORD ';'	{ rmrights($3, (Func*)0); }
	| list RMNODE funlist ';'	{ rmnodes($3); }
	;
funlist:
				{ $$ = 0; }
	| func			{ $$ = funlist((Func*)0, $1); }
	| funlist ',' func	{ $$ = funlist($1, $3); }
	;
request:
	REQUEST '(' arglist ')'	{ $$ = func($1, xvp-xv, xv); }
	;
rmrequest:
	RMREQUEST '(' arglist ')' { $$ = func($1, xvp-xv, xv); }
	;
func:
	WORD 			{ $$ = func($1, 0, xv); }
	| WORD '(' arglist ')'	{ $$ = func($1, xvp-xv, xv); }
	;
arglist:			{ xvp = xv; }
	| WORD			{ xvp = xv; XPUSH($1); }
	| arglist WORD  	{ XPUSH($2); }
	;
%%
char *string(), *strchr();
static int lineno = 0;
static char *fn = 0;
static char *inbuf;
static int len, charno;
char *savec = 0;

parse(file)
register char *file;
{
	int n;
	FILE *infile = fopen(file, "r");
	if(infile == NULL)
		error("cannot open file \"%s\"", file);
	fn = file;
	if(inbuf)
		free(inbuf);
	for(len=0; ; len+=n) {
		inbuf = realloc(inbuf, len+BUFSIZ);
		n = fread(inbuf, 1, BUFSIZ, infile);
		if(n == 0)
			break;
		if(n == -1)
			error("%s: read error", file);
	}
	fclose(infile);
	charno = 0;
	lineno = 1;
	if(yyparse())
		error("syntax");
}

dump(file)
FILE *file;
{
	char buf[BUFSIZ];
	setbuf(file, buf);
	fwrite(inbuf, 1, len, file);
	fflush(file);
	setbuf(file, (char*)0);
}
	/*PRINTFLIKE1*/
void
error(s, t, u, v)
register char *s, *t, *u, *v;
{
	if(lineno>0)
		fprintf(stderr,"error, file %s, line %d: ",
			fn, lineno);
	else if(fn!=0)
		fprintf(stderr,"error, file %s: ", fn);
	else
		fprintf(stderr,"error: ");
	fprintf(stderr,s,t,u,v);
	fprintf(stderr,"\n");
	exit(1);
}

struct kw {
	char *name;
	int type;
} kw[] = {
	{"REQUEST", REQUEST },
	{"DEFINE", DEFINE },
	{"ACCESS", ACCESS },
	{"RIGHTS", RIGHTS},
	{"NEEDS", NEEDS},
	{"DOES", DOES},
	{"RMREQUEST", RMREQUEST },
	{"RMDEFINE", RMDEFINE},
	{"RMACCESS", RMACCESS },
	{"RMRIGHTS", RMRIGHTS},
	{"RMNODE", RMNODE},
	{0, 0}
};

#define unGetc(c) inbuf[--charno] = c;
Getc() 
{
	int c;
	if(charno >= len)
		return 0;
	c = inbuf[charno++];
	if(c == '\n')
		lineno++;
	return c;
}

yylex() 
{
	register struct kw *kwp;
	register int c;
	char buf[ARGSIZ];
	register char *s;
top:
	c = Getc();
	for(s=buf; s<buf+ARGSIZ; c=Getc()) {
		*s = 0;
		switch(c) {
		case 0:
			if(s != buf)
				error("no newline at end of priv file");
			return 0;
		case '\n':
		case ' ':
		case '\t':
		case ',':
		case '(':
		case ')':
		case ';':
			if(s == buf) {
				if(isspace(c)) goto top;
				return c;
			}
			else {
				yylval.word = strdup(buf);
				unGetc(c);
				for(kwp=kw;kwp->name;kwp++)
					if(strcmp(buf,kwp->name)==0) {
						return kwp->type;
					}
				return WORD;
			}
		case '#':
			if(s == buf) {
				char *str = string('\n', 0);
				if(savec) {
					savec = realloc((char*)savec,
					  (unsigned)strlen(savec)+strlen(str)+3);
					strcat(savec,"\n#");
					strcat(savec,str);
					free(str);
				} else
					savec = str;
				goto top;
			}
			break;
		case '"':
			if(s == buf) {
				yylval.word = string('"', '\n');
				if(strchr(", \t\n)",inbuf[charno]) == 0)
					error("junk on end after \"");
				return WORD;
			}
			break;
		}
		*s++ = c;
	}
	error("overlong argument %s",buf);
	return -1;
}
char *
string(stop, safety)
{
	register int c;
	char buf[ARGSIZ];
	register char *s = buf;
	while(s<buf+ARGSIZ) {
		*s = 0;
		c = Getc();
		if(c==0 || c==safety)
			error("unterminated string %s",buf);
		if(c==stop)
			return strdup(buf);
		*s++ = c;
	}
	error("string overflow %s",buf);
	return 0;	/* dummy, not reached */
}

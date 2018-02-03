static	char *sccsid = "@(#)errorsubr.c	1.1 (Berkeley) 10/16/80";
#include <stdio.h>
#include <ctype.h>
#include "error.h"
/*
 *	go through and arrayify a list of rules
 */
arrayify(e_length, e_array, header)
	int			*e_length;
	struct	error_desc	***e_array;
	struct	error_desc	*header;
{
	register	struct	error_desc	*errorp;
	register	struct	error_desc	**array;
	register	int	listlength;
	register	int	listindex;

	for (errorp = header, listlength = 0;
	     errorp; errorp = errorp->error_next, listlength++)
		continue;
	array = (struct error_desc **)Calloc(listlength+1,sizeof (struct error_desc*));
	for(listindex = 0, errorp = header;
	    listindex < listlength;
	    listindex++, errorp = errorp->error_next){
		array[listindex] = errorp;
		errorp->error_position = listindex;
	}
	array[listindex] = (struct error_desc *)0;
	*e_length = listlength;
	*e_array = array;
}

/*VARARGS1*/
error(msg, a1, a2, a3)
	char	*msg;
{
	fprintf(stderr, "Error: ");
	fprintf(stderr, msg, a1, a2, a3);
	fprintf(stderr, "\n");
	fflush(stdout);
	fflush(stderr);
	exit(6);
}
/*ARGSUSED*/
char *Calloc(nelements, size)
	int	nelements;
	int	size;
{
	char	*back;
	if ( (back = (char *)calloc(nelements, size)) == (char *)NULL){
		error("Ran out of memory.\n");
		exit(1);
	}
	return(back);
}

char *strsave(instring)
	char	*instring;
{
	char	*outstring;
	strcpy(outstring = (char *)Calloc(1, strlen(instring) + 1), instring);
	return(outstring);
}
/*
 *	find the position of a given character in a string
 *		(one based)
 */
int position(string, ch)
	register	char	*string;
	register	char	ch;
{
	register	int	i;
	for (i=1; *string; string++, i++){
		if (*string == ch)
			return(i);
	}
	return(-1);
}
/*
 *	clobber the first occurance of ch in string by the new character
 */
char *substitute(string, chold, chnew)
	char	*string;
	char	chold, chnew;
{
	register	char	*cp = string;

	while (*cp){
		if (*cp == chold){
			*cp = chnew;
			break;
		}
		cp++;
	}
	return(string);
}

char lastchar(string)
	char	*string;
{
	int	length;
	length = strlen(string);
	if (length >= 1)
		return(string[length-1]);
	else
		return('\0');
}

char firstchar(string)
	char	*string;
{
	return(string[0]);
}

char	next_lastchar(string)
	char	*string;
{
	int	length;
	length = strlen(string);
	if (length >= 2)
		return(string[length - 2]);
	else
		return('\0');
}

clob_last(string, newstuff)
	char	*string, newstuff;
{
	int	length;
	length = strlen(string);
	if (length >= 1)
		string[length - 1] = newstuff;
}

/*
 *	parse a string that is the result of a format %s(%d)
 *	return TRUE if this is of the proper format
 */
boolean persperdexplode(string, r_perd, r_pers)
	char	*string;
	char	**r_perd, **r_pers;
{
	register	char	*cp;
	int		length;

	length = strlen(string);
	if (   (length >= 4)
	    && (string[length - 1] == ')' ) ){
		for (cp = &string[length - 2];
		     (isdigit(*cp)) && (*cp != '(');
		     --cp)
			continue;
		if (*cp == '('){
			string[length - 1] = '\0';	/* clobber the ) */
			*r_perd = strsave(cp+1);
			string[length - 1] = ')';
			*cp = '\0';			/* clobber the ( */
			*r_pers = strsave(string);
			*cp = '(';
			return(TRUE);
		} 
	}
	return(FALSE);
}
/*
 *	parse a quoted string that is the result of a format \"%s\"(%d)
 *	return TRUE if this is of the proper format
 */
boolean qpersperdexplode(string, r_perd, r_pers)
	char	*string;
	char	**r_perd, **r_pers;
{
	register	char	*cp;
	int		length;

	length = strlen(string);
	if (   (length >= 4)
	    && (string[length - 1] == ')' ) ){
		for (cp = &string[length - 2];
		     (isdigit(*cp)) && (*cp != '(');
		     --cp)
			continue;
		if (*cp == '(' && *(cp - 1) == '"'){
			string[length - 1] = '\0';
			*r_perd = strsave(cp+1);
			string[length - 1] = ')';
			*(cp - 1) = '\0';		/* clobber the " */
			*r_pers = strsave(string + 1);
			*(cp - 1) = '"';
			return(TRUE);
		} 
	}
	return(FALSE);
}

static	char	cincomment[] = CINCOMMENT;
static	char	coutcomment[] = COUTCOMMENT;
static	char	fincomment[] = FINCOMMENT;
static	char	foutcomment[] = FOUTCOMMENT;
static	char	newline[] = NEWLINE;
static	char	piincomment[] = PIINCOMMENT;
static	char	pioutcomment[] = PIOUTCOMMENT;
static	char	lispincomment[] = LISPINCOMMENT;
static	char	riincomment[] = RIINCOMMENT;
static	char	rioutcomment[] = RIOUTCOMMENT;

struct	lang_desc lang_table[] = {
	/*INUNKNOWN	0*/	"unknown", cincomment,	coutcomment,
	/*INCPP		1*/	"cpp",	cincomment,    coutcomment,
	/*INCC		2*/	"cc",	cincomment,    coutcomment,
	/*INAS		3*/	"as",	ASINCOMMENT,   newline,
	/*INLD		4*/	"ld",	cincomment,    coutcomment,
	/*INLINT	5*/	"lint",	cincomment,    coutcomment,
	/*INF77		6*/	"f77",	fincomment,    foutcomment,
	/*INPI		7*/	"pi",	piincomment,   pioutcomment,
	/*INPC		8*/	"pc",	piincomment,   pioutcomment,
	/*INFRANZ	9*/	"franz",lispincomment, newline,
	/*INLISP	10*/	"lisp",	lispincomment, newline,
	/*INVAXIMA	11*/	"vaxima",lispincomment,newline,
	/*INRATFOR	12*/	"ratfor",fincomment,   foutcomment,
	/*INLEX		13*/	"lex",	cincomment,    coutcomment,
	/*INYACC	14*/	"yacc",	cincomment,    coutcomment,
	/*INAPL		15*/	"apl",	".lm",	       newline,
	/*INMAKE	16*/	"make",	ASINCOMMENT,   newline,
	/*INRI		17*/	"ri",	riincomment,   rioutcomment,
				0,	0,	     0
};

printerrors(look_at_subclass, errorc, errorv)
	boolean	look_at_subclass;
	int	errorc;
	struct	error_desc	*errorv[];
{
	register	int	i;
	register	struct	error_desc	*errorp;
	for (errorp = errorv[i = 0]; i < errorc; errorp = errorv[++i]){
		if (errorp->error_e_class == C_IGNORE)
			continue;
		if (look_at_subclass && errorp->error_s_class == C_DUPL)
			continue;
		printf("Error %d, (%s error) [%s], text = \"",
			i,
			class_table[errorp->error_e_class],
			lang_table[errorp->error_language].lang_name);
		wordvprint(stdout,errorp->error_lgtext,errorp->error_text);
		printf("\"\n");
	}
}

wordvprint(fyle, wordc, wordv)
	FILE	*fyle;
	int	wordc;
	char	*wordv[];
{
	int	i;
	for(i = 0; i < wordc; i++){
		fprintf(fyle, "%s",wordv[i]);
		if (i != wordc - 1)
			fprintf(fyle, " ");
	}
}

/*
 *	Given a string, parse it into a number of words, and build
 *	a wordc wordv combination pointing into it.
 */
wordvbuild(string, r_wordc, r_wordv)
	char	*string;
	int	*r_wordc;
	char	***r_wordv;
{
	register	char 	*cp;
			char	*saltedbuffer;
			char	**wordv;
			int	wordcount;
			int	wordindex;

	saltedbuffer = strsave(string);
	for (wordcount = 0, cp = saltedbuffer; *cp; wordcount++){
		while (*cp  && isspace(*cp))
			cp++;
		if (*cp == 0)
			break;
		while (!isspace(*cp))
			cp++;
	}
	wordv = (char **)Calloc(wordcount + 1, sizeof (char *));
	for (cp=saltedbuffer,wordindex=0; wordcount; wordindex++,--wordcount){
		while (*cp && isspace(*cp))
			cp++;
		if (*cp == 0)
			break;
		wordv[wordindex] = cp;
		while(!isspace(*cp))
			cp++;
		*cp++ = '\0';
	}
	if (wordcount != 0)
		error("Initial miscount of the number of words in a line\n");
	wordv[wordindex] = (char *)0;
#ifdef FULLDEBUG
	for (wordcount = 0; wordcount < wordindex; wordcount++)
		printf("Word %d = \"%s\"\n", wordcount, wordv[wordcount]);
	printf("\n");
#endif
	*r_wordc = wordindex;
	*r_wordv = wordv;
}
/*
 *	Compare two 0 based wordvectors
 */
int wordvcmp(wordv1, wordc, wordv2)
	char	**wordv1;
	int	wordc;
	char	**wordv2;
{
	register	int i;
			int	back;
	for (i = 0; i < wordc; i++){
		if (back = strcmp(wordv1[i], wordv2[i])){
			return(back);
		}
	}
	return(0);	/* they are equal */
}
		
/*
 *	splice a 0 basedword vector onto the tail of a
 *	new wordv, allowing the first emptyhead slots to be empty
 */
char	**wordvsplice(emptyhead, wordc, wordv)
	int	emptyhead;
	int	wordc;
	char	**wordv;
{
	register	char	**nwordv;
	int	nwordc = emptyhead + wordc;
	register	int	i;

	nwordv = (char **)Calloc(nwordc, sizeof (char *));
	for (i = 0; i < emptyhead; i++)
		nwordv[i] = 0;
	for(i = emptyhead; i < nwordc; i++){
		nwordv[i] = wordv[i-emptyhead];
	}
	return(nwordv);
}
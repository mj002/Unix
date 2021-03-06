%{
#include <sys/types.h>
#include <pwd.h>
#include <sys/stat.h>
#include <time.h>
#include <libc.h>
#include "header.h"

#define DATE DOCNUM+6
#define SEQNUM DOCNUM+13
#define TYPE DOCNUM+15
#define SOFT DOCNUM+17
struct passwd *getpwuid(), *ps;
int soft;
char *p, *s1, *s2;
int type, ci=0, pm=0, rl=0;
char buf[HEADSIZE];
char *co = &buf[CO];
char *dept = &buf[DOCNUM], *date = &buf[DATE], *seqnum = &buf[SEQNUM];
char *stype = &buf[TYPE], *ssoft = &buf[SOFT];
char *machine = buf;
char *login = &buf[ULOG], *timestamp = &buf[TIMESTAMP];
char *version = &buf[VERSION];
char *pages = &buf[PAGES];
int more = 1;
%}
%%
^".so".*	;
^".TI"	{
	printf(".TL\n");
	}
^".DT".*	;
^".AH".*	{
	yytext[yyleng] = '\0';
	p = strtok(&yytext[3], " \n");
	printf(".AU %s", p);
	if (*p == '"') {
		p = strtok((char *)0, "\"");
		printf(" %s", p);
	}
	p = strtok((char *)0, "\n");
	printf(" \"\"%s\n", p);
	}
^".AP".*	{
	yytext[yyleng] = '\0';
	printf(".rP %s\n",&yytext[3]);
	}
^".SA"	{
	printf(".AS\n");
	}
^".SE"	{
	printf(".AE\n");
	}
^".KW".*	{
	printf(".OK %s\n",&yytext[3]);
	}
^".TY".*	{
	for(p = &yytext[3]; *p == ' ';p++);
	if(*p == 'I')type=2;
	else if(*(p+1) == 'M')type=1;
	else type=3;
	*stype = *p;
	*(stype+1) = *(p+1);
	while(*p != ' '){
		if(*p == '\n'){
			soft=0;
			break;
		}
		p++;
	}
	if(*p == ' ')
		if(*++p == 'y')
			soft=1;
	printf(".MT %d\n",type);
	if(soft){
		*ssoft = 'S';
		printf(".sF\n");
	}
	}
^".MT".*	{
	for(p = &yytext[3]; *p == ' ';p++);
	if(*p == '1') {
		type=1;
		*stype = 'T';
		*(stype+1) = 'M';
	} else if(*p == '2') {
		type=2;
		*stype = 'I';
		*(stype+1) = 'M';
	} else type=3;
	printf(".MT %d\n",type);
	}
^".sF".*	{
	soft = 1;
	*ssoft = 'S';
	printf(".sF\n");
	}
^(".NU"|".dN").*	{
	p = strtok(&yytext[3], "- \n\"");
	if(p != 0){
		sprintf(dept,"%s-",p);
		printf(".dN %s-",p);
		type = 1;
	}
	p = strtok((char *)0, "- \n\"");
	if(p != 0){
		sprintf(date,"%s-",p);
		printf("%s-",p);
	}
	p = strtok((char *)0, "- \n\"");
	if(p != 0){
		*seqnum = *p;
		*(seqnum+1) = *(p+1);
		printf("%s\n",p);
	}
	else if(type) printf("\n");
	p = strtok((char *)0, " \n\"");
	if(p != 0)
		printf(".fC %s\n",p);
	p = strtok((char *)0, " \n\"");
	if(p != 0)
		printf(".wP %s\n",p);
	}
^".MY".*	{
	printf(".mE %s\n",&yytext[3]);
	}
^".ED".*	{
	printf(".eD %s'n",&yytext[3]);
	}
^".PR".*	{
	pm=1;
	printf(".PM %s\n",&yytext[3]);
	}
^".RL".*	{
	rl=1;
	if(yyleng>3){
		p=&yytext[3];
		while(*p == ' ')p++;
		if(*p == '\"')p++;
		if(*p == 'n')printf(".fA n\n");
		else printf(".fA y\n");
	}
	else printf(".fA y\n");
	}
^".GS"	{
	printf(".gS\n");
	}
^".CI".*	{
/*	ci = 1;		gone away
	if(yyleng == 3)
		printf(".cI n\n");
	else {
		p = &yytext[3];
		while(*p == ' ')p++;
		if(*p == '\n' || *p == 'n')
			printf(".cI n\n");
		else if(*p == '\"')p++;
		if(*p == 'y')
			printf(".cI y\n");
		else if(*p == '\"' || *p == 'n')
			printf(".cI n\n");
		else	fprintf(stderr,".CI unknown argument %c\n",*p);
	}*/
	}
^".CO".*	{
/*	if(!ci){
		printf(".cI n\n");
		ci = 1;
	}*/
	if(!rl){
		printf(".fA y\n");
		rl = 1;
	}
	printf(".cC\n");
	}
^".CE"	{
	printf(".cE\n");
	}
^".CV".*	{
/*	if(!ci){
		printf(".cI n\n");
		ci = 1;
	}*/
	if(!rl){
		printf(".fA y\n");
		rl = 1;
	}
	printf(".cS\n");
	}
^".CS".*	{
	ECHO;
	printf("\n");
	return(0);
	}
^".SC".*	{
/*	if(!ci){
		printf(".cI n\n");
		ci = 1;
	}*/
	if(!rl){
		printf(".fA y\n");
		rl = 1;
	}
	p = s1 = &yytext[3];
	while(*s1 == ' ')s1++;
	while(*s1 != ' ')s1++;
	while(*s1 == ' ')s1++;
	while(*s1 != ' ')s1++;
	*s1 = '\0';
	s1++;
	printf(".CS %s \"\" %s\n", p, s1);
	return(0);
	}
.*	{
	ECHO;
	printf("\n");
	}
\n	;
%%
char *header="/tmp/            ";
char *dest = "mhuxd!/usr/spool/uucppublic/doc.mcs";
char *dco = "BL";
main(argc, argv)
char *argv[];
{
	FILE *inp;
	char *filename, *name, *cover, *pid;
	int nuchars, npid, uid, days;
	long mtime;
	if(argc < 3){
		fprintf(stderr,"file name must be supplied to sendcover\n");
		exit(1);
	}
	if((inp=fopen("/etc/whoami","r")) == NULL){
		fprintf(stderr,"can't open /etc/whoami\n");
		exit(1);
	}
	nuchars = fread(machine, sizeof(char), 10, inp);
	nuchars -= 1;
	if(nuchars < 5)pid = machine + nuchars +1;
	else pid = machine + 6;
	cover = pid + 5;
	fclose(inp);
	*(pid-1) = '.';
	npid = getpid();
	sprintf(pid,"%05d",npid);
	*cover = 'c';
	sprintf(&header[5],"%s",machine);
	uid = getuid();
	if ((ps = getpwuid(uid)) == NULL){
		fprintf(stderr, "login not found");
		exit(1);
	}
	strcpy (login,ps->pw_name);
	sprintf(version,"030388L");	/*version*/
	strcpy(co, dco);	/*company name=BL*/
	name = argv[1];
	argc--; argv++;
	if(freopen(argv[1],"r",stdin)==NULL) {
		fprintf(stderr,"%s: cannot open\n", argv[1]);
		exit(1);
	}
	if(freopen(header,"w",stdout)== NULL){
		fprintf(stderr,"%s: cannot open\n",header);
		exit(1);
	}
	if((nuchars = fwrite(buf,sizeof(char),HEADSIZE,stdout)) != HEADSIZE){
		fprintf(stderr,"wrong number of characters written %d\n",nuchars);
			exit(1);
	}
	filename = argv[1];
	mtime = getstamp(filename);
	sprintf(timestamp,"%ld",mtime);
	argv++;
	sprintf(pages,"TP%s",argv[1]);
	yylex();
	rewind(stdout);
	for(p=buf; p < &buf[HEADSIZE-1]; p++)
		if(*p == '\0')*p = ' ';
	*p = '\n';
	if((nuchars = fwrite(buf,sizeof(char),HEADSIZE,stdout)) != HEADSIZE){
		fprintf(stderr,"wrong number of characters written %d\n",nuchars);
			exit(1);
	}
	*(cover+1) = '\0';
	if((inp=fopen(name,"a")) == NULL){
		fprintf(stderr,"can't open tmp file %s\n",name);
		exit(1);
	}
	fprintf(inp,"cd /tmp; uucp -m -C %s %s; rm %s\n",machine,dest,machine);
	fclose(inp);
}	

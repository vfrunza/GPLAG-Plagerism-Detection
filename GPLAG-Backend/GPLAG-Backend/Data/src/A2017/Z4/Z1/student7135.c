#include <stdio.h>
#include <math.h>
void pomjeri(char* tekst,int broj)
{
	char *p=tekst;
	if(*tekst==' ') broj--;
	while(*p!='\0')
		p++;
	*(p+broj)='\0';
	while(p>=tekst) {
		*(p+broj)=*p;
		p--;
	}
}
char* ubaci_broj (char* tekst, int broj)
{
	char* p=tekst;
	char* p1=tekst;
	int negativan=0;
	int pom=broj,cifara=0;
	while(*tekst==' ' && *tekst!='\0') tekst++;
	if(broj<0) negativan=1;
	while(pom!=0) {
		cifara++;
		pom/=10;
	}
	if(negativan==1) cifara++;
	while(*tekst!='\0') {
		while(*tekst!=' ' && *tekst!='\0')
			tekst++;
		if(*tekst=='\0') break;
		tekst++;
		if(*tekst=='\0') break;
		p=tekst;
		while(*p==' ' && *p!='\0') p++;
		if(*p=='\0') break;
		pomjeri(tekst,cifara+1);
		p=tekst+cifara;
		tekst+=cifara;
		*p=' ';
		p--;
		pom=broj;
		while(pom!=0) {
			*p='0'+fabs(pom%10);
			pom/=10;
			p--;
		}
		if(negativan==1) *p='-';
		while(*tekst==' ' && *tekst!='\0') tekst++;
		if(*tekst=='\0') break;
		tekst++;
	}
	return p1;
}
int main()
{
	char s[40] = "  ovo    k   je primjer ";
	printf("\"%s\"", ubaci_broj(s, 123));
	return 0;
}

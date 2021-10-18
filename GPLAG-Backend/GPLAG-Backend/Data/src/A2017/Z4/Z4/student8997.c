#include <stdio.h>





int provjeri(const char*string)
{
	const char *pok1=string,*kraj=string, *klizeci=string,*finalno,*provjera=string;
	int uspjeh=1,isti=1,pronadjen=0;

	while(*string!='\0') {
		while(*string!='<' && *string!='\0') string++;
		if(*string=='\0') return 1;
		pok1=string;
		pok1++; klizeci=pok1+1;kraj=pok1;
	
	do{
		while(*klizeci!=*pok1 && klizeci!='\0') klizeci++;

		if(*(klizeci-1)=='/' && *(klizeci-2)=='<' && *klizeci!='\0') pronadjen=1;
		else klizeci++;}
		while(*klizeci!='\0'&& !pronadjen);
			if(*klizeci=='\0') return 0;	
		
		finalno=klizeci-2;
		if(*pok1==' ' && *pok1=='\0') return 0;
		
		while(*pok1!=' ' && klizeci!='\0' && *pok1!='>' && *pok1=='\0'){
			if(*klizeci!=*pok1) isti=0;
			else klizeci++; pok1++;
		}
		
		if(!(isti&&*klizeci=='>')) uspjeh=0;
		while(*kraj!='\0' && kraj>finalno){
			if(*kraj=='<') provjera=kraj;
			kraj++;
		}
		if(*provjera=='\0') return 0;
		if(*(provjera+1)!='/') uspjeh=0;
		
string++;}


		return uspjeh;}


int main() {
	printf ("Provjera 2: %d\n", provjeri ("<html><head><title></title></head><body><p></p></body></html>"));
		printf ("Provjera 1: %d\n", provjeri ("<div><h4>Naslov</h4><p>Danasnja vijest</div>"));
		return 0;
	}

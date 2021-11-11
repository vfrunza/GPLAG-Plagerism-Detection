#include <stdio.h>

char *ubaci_rijec (char *tekst,int br) {
	return tekst;
}
int jelislovo(char c){
	if(c>='A' && c<='Z' || c>='a' && c<='z') return 1;
	return 0; 
}
char* izbaci_rijec(char *tekst,int br){
	char *temp=tekst;
	char *s1=tekst;
	int rijeci=0;
	while(*tekst!='\0'){
		while(jelislovo(*tekst)==0){tekst++;}
		s1=tekst;
		if(jelislovo(*tekst))rijeci++;
		if(rijeci==br){
			while(jelislovo(*s1)==1){
				tekst=s1; 
				while(*tekst!='\0'){
					*tekst=*(tekst+1);
					tekst++;
				}
			}
		}
		while(jelislovo(*tekst)==1){tekst++;}
	}
	tekst=temp;
	return tekst;
}
int ista (char *p, int duzina, char **rijeci,int broj_rijeci){
	int i,c ;
	char *q;
	char *t;
	c = 1;
	p = p - duzina-1;
	t = p;
	for (i = 0; i<broj_rijeci; i++){
		p = t; 
		q = rijeci[0];
		while (*q != '\0'){
			if (*p == *q ) {c=1; q++; p++;} else {c =0; break;}
		}
	}
	if (c == 1 ){return 1;} else {return 0;}
}
char *zamjena_rijeci (char *tekst, char ** rijeci, char** zamjene, int broj_rijeci)
{
	char* p;
	char *temp;
	char *l;
	int duzina = 0;
	int k = 1; 
	p = tekst;
	temp = p;
	do{
	while(*p==' ') { p++;}
	while(*p!=' '  ) { p++; duzina++; if (*p=='\0') break;}
	l = p;
	ista (p,duzina-1,rijeci,broj_rijeci);
	if (ista==1){ izbaci_rijec(tekst,k); ubaci_rijec(tekst,k); }
	p = l;
	duzina = 0;	
	k++;
	}
	while (*p!='\0');
	
	
	tekst = temp;
	return tekst; 
}


int main ()
{
	/*
	char* rijec[2] ={"je","konj"}; 
	char* p;
	p = rijec[0];
	printf ("%c",*p);
	return 0;
	
	/*char* rijec[2] ={"je","konj"}; 
	char* p;
	p = rijec[0];
	printf ("%s",rijec[0]); */
	
	return 0;
	
}
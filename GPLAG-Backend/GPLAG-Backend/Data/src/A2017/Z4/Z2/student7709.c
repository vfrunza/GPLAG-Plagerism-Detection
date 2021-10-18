#include <stdio.h>
int provjeri_duzine(char*s,int niz[],int duzina)
{
	int i=0,j,brojac=0,brojac2=0;
	while(*s!='\0') {
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			brojac=0;
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
				brojac++;
				s++;
				if(*s=='\0') break;
			}

			brojac2++;
			if(niz[i]!=brojac) return 0;
			i++;
			if(*s=='\0') break;
		}
		if(*s=='\0') break;
		s++;
	}
	if(brojac2!=duzina) return 0;
	
	return 1;
}
int main()
{

	printf("Zadaća 4, Zadatak 2");
	return 0;
}

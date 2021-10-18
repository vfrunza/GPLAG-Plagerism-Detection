#include <stdio.h>
int provjeri_duzine(char* tekst,int niz[],int vel)
{
	int i=0,brojac=0,br_rijeci=0;
	char *s=tekst;
	while(*s!='\0')
	{
		while(((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && *s!='\0')
		{
			brojac++;
			s++;
		}
		if(brojac!=0)
		{
			br_rijeci++;
			if(niz[i]!=brojac || br_rijeci>vel)	return 0;
			else
			i++;
		}
		if(*s=='\0')	break;
		brojac=0;
		s++;
	}
	if(br_rijeci<vel)	return 0;
	return 1;
}
int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}

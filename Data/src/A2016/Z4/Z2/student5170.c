#include <stdio.h>

char* kodiraj(char *tekst, char string[96])
{
	char* rst=tekst, *reset=string;
	int kr=0, znak[97]= {0}, mjesto=97, *a, maxi,i=0;
	a=znak;
	while(*tekst!='\0') {
		znak[*tekst-32]++;
		tekst++;
	}
	while(kr==0) {
		maxi=0;
		kr=1;
		for(i=0; i<96; i++) {
			if(znak[i]>maxi) {
				maxi=znak[i];
				mjesto=i;
			}
			if(maxi!=0) kr=0;

		}
		znak[mjesto]=-1;
		if(maxi!=0) {
			*string=(char)(mjesto+32);
			string++;
		}
	}
	a=znak;
	for(i=0; i<95; i++) {
		if(*a==0) {
			*string=(char)(i+32);
			string++;
		}
		a++;

	}
	*string='\0';
	string=reset;
	tekst=rst;
	mjesto=0;
	while(*tekst!='\0') {
		string=reset;
		mjesto=0;
		while(*string!='\0' && *tekst!=*string) {
			string++;
			mjesto++;
		}
		*tekst=(char)(126-mjesto);
		tekst++;
	}
	tekst=rst;
	return tekst;
}

char* dekodiraj(char* tekst, char* string)
{
	int p=1, provjereno[96]= {0}, tablica[96]= {-1}, maxi=0, i=0;
	char promjeni=*tekst;
	char* rst=tekst;
	while(*tekst!='\0') {
		provjereno[*tekst-32]++;
		tekst++;
	}
	maxi=0;
	do {
		maxi=0;
		for(i=0; i<96; i++) {
			if(provjereno[i]>=maxi)
				maxi=provjereno[i];
		}
		for(i=95; i>=0; i--) {
			if(provjereno[i]==maxi) {
				promjeni=i+32;
				break;
			}
		}
		tablica[promjeni-32]=*string;
		provjereno[promjeni-32]=0;
		string++;
		p=1;
		for(i=0; i<96; i++) {
			if(provjereno[i]!=0)
				p=0;
		}
	} while(p==0);
	tekst=rst;
	while(*tekst!='\0') {
		*tekst=tablica[*tekst-32];
		tekst++;
	}
	return rst;
}

int main()
{
	char tekst[] = "";
	char sifrarnik[100] = "";
	kodiraj(tekst, sifrarnik);
	printf("%s", tekst);
	dekodiraj(tekst, sifrarnik);
	printf("%s", tekst);
	return 0;
}
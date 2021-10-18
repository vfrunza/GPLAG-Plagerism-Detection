#include <stdio.h>

int provjeri_duzine(char *s, int niz[], int vel)
{
	int rijec=0,slovo=0,duzina=0;
	int *n=niz;
	char *kraj=s;
	while(*kraj!='\0') kraj++;
	while(*s!='\0') {
		if (!((*s>='A' && *s<='Z')||(*s>='a' && *s<='z'))) s++;  
		else break;
	}
	while(*s!='\0') {
		if(*(s+1)=='\0' && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
			rijec++;
			duzina++;
			if(rijec>vel) return 0;
			if(duzina!=*n) return 0;
		} else if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			duzina++;
			slovo=1;
		} else if (slovo==1) {
			rijec++;
			if(rijec>vel) return 0;
			if(duzina!=*n) return 0;
			duzina=0;
			slovo=0;
			n++;
		}
		s++;
	}
	if(rijec<vel) return 0;

	return 1;
}

int main()
{
	return 0;
}

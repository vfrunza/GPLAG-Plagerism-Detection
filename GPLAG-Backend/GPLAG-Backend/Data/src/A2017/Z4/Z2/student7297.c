#include <stdio.h>


int provjeri_duzine(char *s, int *niz, int velicina)
{
	int i=0;
	int brojac=0;
	char *p=s;
	while(*s!='\0') {
		while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) {
			brojac++;
			p++;
		}
		if(brojac!=0) {
			s=--p;
			if(i<velicina && brojac == niz[i] ) {
				if (niz[i]<0) return 0;
				i++;
			} else {
				return 0;
			}
			brojac=0;
		}
		p++;
		s++;
	}
	if(i!=velicina) {
		return 0;
	}
	return 1;
}

int main()
{
	char string[]="Ovo je neki primjer teksta";
	int niz[]= {3,2,4,7,6};
	printf("%d", provjeri_duzine(string,niz, 5));
	return 0;
}

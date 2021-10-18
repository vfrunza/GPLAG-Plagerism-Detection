#include <stdio.h>

int provjeri_duzine(char* s, int niz[], int vel) {
	int ispunjeno=1, broj_rijeci=0,neslovo=1,broj_slova=0,i=0;
	char* pom=s;
	while(*pom!='\0') {
		if(!((*pom>='A' && *pom<='Z')  || (*pom>='a' && *pom<='z'))) neslovo=1;
		else if(neslovo==1) {
			neslovo=0;
			broj_rijeci++;
		}
		pom++;
	}
		if(broj_rijeci!=vel)  return 0;
		
		while(*s!='\0') {
		if(*s!='\0' && *s==' ') {
			while(*s!='\0' && *s==' ') s++;
		}
		if((*s>='A' && *s<='Z')  || (*s>='a' && *s<='z')) {
			i++;
			broj_slova=0;
			while((*s>='A' && *s<='Z')  || (*s>='a' && *s<='z')) {
				broj_slova++;
				s++;
			}
			if(i>0) {
		if(broj_slova!=niz[i-1]) 
			ispunjeno=0;
		}
		}
		if(*s!='\0')
	s++;
	}
	if(ispunjeno) 
	return 1;
	else return 0;
}

int main() {
	int br;
	char s[30]={"Ovo je primjer"};
	int niz[3]={3,2,7};
	br=provjeri_duzine(s, niz, 3);
	printf("broj rijeci %d", br);
	return 0;
}

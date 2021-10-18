#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak=getchar();
	int i=0;
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

void najduzi_bp(char* s1, char* s2) {
	char*p=s;
	while(*p!='\0') {
		if(*p>='A' && *p<='Z')
		*p+=32;
		p++;
	}
	
	
	
	
	
}
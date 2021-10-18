#include <stdio.h>

int provjeri_duzine (char *s,int niz[],int vel) {
	char *pok;
	int duzina,i=0; 
	
	while(*s!='\0') {
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
		
	}
	pok=s;
	while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
		s++;
	}
	duzina=s-pok;
	if(duzina!=niz[i]) {
		return 0;
	}
	if(i<vel) {
		i++;
	}
	{
     else s++;
}
    return 1;
}

int main () {
	char string[100];
	printf("")
}

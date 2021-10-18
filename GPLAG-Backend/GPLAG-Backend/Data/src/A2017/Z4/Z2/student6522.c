#include <stdio.h>

void unesi(char niz[], int velicina){
		char znak = getchar();
		int i=0;
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
int provjeri_duzine(char* tekst, int *niz, int broj){
	char* s=tekst;
	char* m=tekst;
	int * k=niz;
	int duzina=0,brojrijeci=0;
	while(*m!='\0'){
		if((*m>='a' && *m<='z') || (*m>='A' && *m<='Z')){
			brojrijeci++;
		while((*m>='a' && *m<='z') || (*m>='A' && *m<='Z')){
			m++;
		}
		}
		if(*m!='\0') m++;
	}
	if(broj!=brojrijeci) return 0;
	else {
	while(*s != '\0'){
		if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')){
		while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')){
			duzina++;
			s++;
		}
		if(*k==duzina){
			k++;
			duzina=0;
		}
		else return 0;
		}
		if(*s=='\0') return 1;
		else s++;
	}
	}
	return 1;
}	
int main() {
	char s[1000];
	int niz[50];
	int l,i;
	printf("Unesite string: ");
	unesi(s,1000);
	printf("Unesite neki niz brojeva: ");
	for(i=0; i<50; i++){
		scanf("%d", &niz[i]);
		if(niz[i]==-1) break;
		l++;
	}
	printf("Da li su jednaki: %d", provjeri_duzine(s,niz,l));
	return 0;
}

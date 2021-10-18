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
char*ubaci_broj(char* tekst, int broj){
	int duzina=0,cifra=0,brojdva=broj;
	char *s=tekst;
	char *k=tekst;
	char *kraj=tekst;
	char *t=tekst;
	if(broj<0) {
		duzina++;
		broj=broj*(-1);
	}
	while(broj!=0){
		duzina++;
		broj=broj/10;
	}
	duzina++;
	while(*s!='\0'){
		while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) s++;
		if((*s==' ') && ((*(s-1)>='a' && *(s-1)<='z') || (*(s-1)>='A' && *(s-1)<='Z'))){
		s++;
		broj=brojdva;
		k=s;
		kraj=s;
		t=s;
		while(*kraj!='\0') kraj++;
		while(kraj>t){
			*(kraj+duzina)=*kraj;
			kraj--;
		}
		while(broj!=0){
		cifra=broj%10;
		*k=cifra+'0';
		k++;
		broj=broj/10;
		}
		k--;
		while(k>=t){
			*s=*k;
			s++;
			k--;
		}
		*s=' ';
		}
		s++;
	}
	return tekst;
}			
	

int main() {
	char tekst[1000];
	int broj;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	printf("Unesite string: ");
	unesi(tekst,1000);
	printf("String ima oblik: \n%s", ubaci_broj(tekst,broj));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

void unesi(char niz[], int velicina){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}


int prebroji(char *s){
	
	int broj=0;
	while(*s!='\0'){
		broj++;
			s++;
	}
	return broj;
}

char* kopi(char *a, const int *b){
	char *postoji=a;
	while(*b){
		*a++=*b++;
	}
	*a=0;
	return postoji;
}

char* ubaci_broj(char* tekst, int broj){
	int i,j;
	int duzina=0;
	char*p=tekst;
		while(*p!='\0'){
			duzina++;
			p++;
		}
		
	while(*tekst!='\0'){
		if(*tekst==' '){
			char *kraj=tekst;
			while(*kraj!='\0') kraj++;
			while(kraj>tekst){
				*(kraj+duzina)=*kraj;
				kraj--;
			}
			char tmp=*(tekst+duzina+1);
			strcpy(tekst,broj);
			*(tekst+duzina+1)=tmp;
		}
		tekst++;
	}
	return tekst;
}


int main() {
	int i;
	char tekst[80];
	char* cstring;
	int broj;
	printf("Unesite recenicu: ");
	unesi(tekst,80);
	printf("Unesite broj: ");
	scanf("%d",&broj);
	//char *p=ubaci_broj(a,broj);
	int p=prebroji(tekst);
	cstring=tekst;
	cstring=ubaci_broj(cstring,broj);
	for(i=0;i<p;i++){
		printf("%c",tekst[i]);
	}
	
	return 0;
}

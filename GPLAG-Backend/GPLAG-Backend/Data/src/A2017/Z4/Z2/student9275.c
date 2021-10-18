#include <stdio.h>

int provjeri_duzine(char *s, int *niz,int vel){
	int i = 0,duz;
	while(*s != '\0'){
		duz = 0;
		if(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z' ){
				while(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z'){s++; duz++;}
				if(duz != niz[i] || i > vel)return 0; // &&i<vel
				if(*s == '\0')s--;
				if(i == vel)return 0;
				i++;
		}
		s++;
	}
	
if(i != vel)return 0;
return 1;
}

int main() {
char tekst[] = " ...i tako smo dosli do petog testa";
int niz[] = {1,4,3,5,2,5,5,8,9,9};
int niz2[] = {4,4,3,5,2,5,5};
int niz3[] = {1,4,3};

printf("%d ", provjeri_duzine(tekst, niz3, 8));
printf("%d ", provjeri_duzine(tekst, niz2, 7));
printf("%d ", provjeri_duzine(tekst, niz, 7));
	return 0;
}

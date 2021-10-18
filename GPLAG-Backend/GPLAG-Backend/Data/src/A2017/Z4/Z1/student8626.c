#include <stdio.h>
#define duzina 10000

void unesi(char niz[], int velicina)
{
	char znak =getchar();
	if(znak=='\n') znak =getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char* ubaci_broj(char* tekst, int broj){
	int i;
	char* pocetak=tekst;
	while (*tekst!='\0'){
		
		 if (*tekst==' '){
			
			char* kraj =tekst;
			while(*kraj!='\0') kraj++;
			while(kraj>tekst) {
				*(kraj+duzina)= *kraj;
				kraj--;
			}
              char* p=broj;
              while (*p!='\0') {
              	*tekst++;
              	*p++;
              }
		 }
			
      	tekst++;
      	printf("%s", tekst);

	}
	return pocetak;
}
int main() {
	char tekst[10000];
	int broj;
	printf("Unesite tekst: ");
	unesi(tekst, 10000);
	printf("\nUnesite broj: ");
	scanf ("%d", &broj);
	printf("%s", ubaci_broj(tekst, broj));
	return 0;
}

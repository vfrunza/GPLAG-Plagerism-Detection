#include <stdio.h>

char* ubaci_broj(char* tekst, int *broj){
	int i=0;
	int *s=broj;
	int br=0;
	
	while((*s>=0 && *s<=9) || *s='-'){
		br++;
		s++;
	}

	
	while(*tekst!='\0'){
		if(*tekst==' '){
			tekst++;
		if(*tekst==' '){
			
			
		}	
      }
	
	tekst++;
	} return tekst;
}

int main() {
	char tekst[]="Ovo   je neki    primjer  teksta";
	int broj=-123;
	ubaci_broj(tekst, broj);
	printf("%s", tekst);
	return 0;
}

#include <stdio.h>

int duzina_cifre(int broj) {
	
	int brojac = 0;
	
	while(broj > 0) {
		
		broj /= 10;
		brojac++;
	}
	
	return brojac;
	
	
}

char* ubaci_broj(char* tekst, int broj) {
	
	char* p = tekst;
	char* p2 = p;
	int duzina = duzina_cifre(broj);
	
	while(*p != '\0') {
		
		if(*p = ' ') {
			
			char* kraj = p;
			while(*kraj != '/0') kraj++;
			
			
		}
	}
		
}
	
	return p2;
	
	
}

int main() {
	
		/* AT1: Primjer iz zadatka */
	char s[44] = "Ovo je neki primjer teksta";
	

	printf("\"%s\"", ubaci_broj(s, 123));
}

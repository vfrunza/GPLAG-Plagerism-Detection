#include <stdio.h>
#include <stdlib.h>

int slovo(char znak){
	/*funkcija vraća 1 ako je znak slovo ili 0 ako znak nije slovo*/
	if((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z')){
		return 1;
	}
	return 0;
}

int istoSlovo(char *s1, char *s2){
	/*Funkcija vraća 1 ako je slovo isto zanemarujući uppercase ili lowercase*/
	char *p1;
	char *p2;
	p1 = s1;
	p2 = s2;
	while(p1 < p2){
		if(abs(*p1 - *p2) == 32 || *p1 == *p2){
			return 1;
		}
		p1++;
	}
	return 0;
	
}

void najduzi_bp(char *s1, char *s2){
	*s2 = '\0';
	char *temp;
	
	char *pocetni_s2;
	pocetni_s2 = s2;
	
	int duzina_s2 = 0;
	int duzina_rijeci = 0;
	
	
	while (*s1 != '\0'){
		if(slovo(*s1)){/*U ovom dijelu se fokusiramo na traženje podstringa u riječi, jer smo ovom petljom napravili da u slučaju ako dio stringa nije riječ, s2 se resetuje*/
			duzina_rijeci = 0;
			temp = s1;
			temp++;
			while(slovo(*temp) && !istoSlovo(s1,temp)){
				temp++;
				duzina_rijeci++;
			}
			
			if(duzina_rijeci > duzina_s2){
				s2 = pocetni_s2;
				while(s1<temp){
					*s2 = *s1;
					s1++;
					s2++;
				}
				*s2 = '\0';
				s1--;
				duzina_s2 = duzina_rijeci;
			}
		}else{

		}
		s1++;
	}
}

int main() {
	char niz[25];
    najduzi_bp ("primjer", niz);
    //printf ("%d", istoSlovo('a','a'));
    printf ("Niz: '%s'", niz);
	return 0;
}

#include <stdio.h>
#include <math.h>

int brojcifara (int broj){
	int brojac = 0;
	if(broj<0) brojac++;
	brojac += (int)log10(fabs(broj))+1;
	return brojac;
}

char* ubaci_broj(char *tekst, int broj) {
	char *pocetak = tekst, *pok1, *pok2, *pok, *kraj;
	int razmak = 0, temp;
	
	while (*tekst == ' ') tekst++;
	
	while(*tekst != '\0') {
		if (*tekst == ' ') {
			
			kraj = tekst;
			while (*kraj == ' ') kraj++;
			
			
			if (*kraj != '\0') {
				razmak = 1;
				if (*(tekst + 1) == ' ') {
					razmak = 0;
				}
			
				pok = pok1 = tekst;
				while(*++pok1 != '\0');
			
				pok2 = pok1 + brojcifara(broj) + razmak;
			
				while (pok1 > tekst) {
					*pok2 = *pok1;
					*pok1 = ' ';
					pok1--;
					pok2--;
				}
			
				while (*tekst == ' ') tekst++;
			
				temp = fabs(broj);
				pok += brojcifara(broj);
				while (temp != 0) {
					*pok = temp%10 + '0';
					temp /= 10;
					pok--;
				}
				if (broj < 0) *pok = '-';
				
			}
		}
		tekst++;
	}
	
	return pocetak;
}

int main() {
	char s[100] = "    Ja Don  Elva   Brada    Official   ";
	ubaci_broj(s, 123);
	printf("%s",s);
	return 0;
}

#include <stdio.h>

int velicina(int broj) {
	int vel = 0;
	if(broj == 0) return 1;
	if(broj < 0) vel++;
	while(broj != 0){
		vel++;
		broj /= 10;
	}
	return vel;
}

char* ubaci_broj(char* tekst, int broj) {
	char *s = tekst, *pok1 = NULL, *pok2 = NULL;
	int razmak = 0, vel = velicina(broj), jedan_razmak = 0, pomocni;
	while (*s == ' ') s++;
	while (*s) {
		if (*s == ' ') {
			if (razmak == 0) pok1 = s;
			razmak = 1;
		}
		else if (razmak == 1) {
			razmak = 0;
			pok2 = s;
			if(pok2-1 == pok1) jedan_razmak = 1;
			while (*pok2 != '\0') pok2++;
			while (pok2 > pok1) { 
				*(pok2+vel+jedan_razmak) = *pok2;
				pok2--;
			}
			pomocni = broj;
			while(vel > 0) {
				if(jedan_razmak){ 
					*(pok2+vel+1) = ' ';
					jedan_razmak = 0;
				}
				if(pomocni < 0) {
					*++pok2 = '-';
					vel--; pomocni *= -1;
				}
				*(pok2+vel) = pomocni%10 + '0';
				pomocni /= 10;
				vel--;
			}
			jedan_razmak = 0;
			vel = velicina(broj);
			s += vel;
		}
		s++;
	}
	return tekst;
}

int main() {
	char s[44] = "a  \t  a a a";
	printf("\"%s\"", ubaci_broj(s, -123));
	return 0;
}

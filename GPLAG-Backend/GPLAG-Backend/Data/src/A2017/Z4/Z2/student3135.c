#include <stdio.h>

/*Funkcija koja vraca pokazivac na n=tu poredu rijec u stringu*/
char* vratiRijec(char* s,int n)
{
	int neslovo=1;
	int	brojRijeci=0;
	while(*s!='\0') {
		if(!((*s>='A'&&*s<='Z')||(*s>='a'&& *s<='z'))) {
			neslovo=1;
		} else if(neslovo==1) {
			neslovo=0;
			brojRijeci++;
		}
		if(brojRijeci==n) {
			return s;
		}
		s++;
	}
}
int daj_broj(char* recenica)
{
	int neslovo=1, br=0;
	while(*recenica!='\0') {
		if(!((*recenica>='A'&&*recenica<='Z')||(*recenica>='a'&&*recenica<='z'))) {
			neslovo=1;
		}
		else if(neslovo==1){
			neslovo=0;
			br++;
		}
		recenica++;
	}
	return br;
}


int provjeri_duzine(char* recenica,int* nizBroj, int vel)
{
	char* pok=recenica;
	int i;
	int duzinaRecenice=daj_broj(recenica);
	if(duzinaRecenice!=vel) {
		return 0;
	}
	for(i=1; i<=vel; i++) {
		char*pok2=vratiRijec(recenica,i);
		int brojac=0;
		while ((*pok2>='A'&&*pok2<='Z')||(*pok2>='a'&&*pok2<='z')) {
			brojac++;
			pok2++;
		}
		if(brojac!=nizBroj[i-1]) {
			
			return 0;

		}
	}
	return 1;
}
int main()
{
	printf("Zadaća 4, Zadatak 2");
	return 0;
}

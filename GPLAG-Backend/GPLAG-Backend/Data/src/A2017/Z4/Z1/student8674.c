#include <stdio.h>
#include <math.h>

char* ubaci_broj (char* tekst, int broj)
{
	int brojac_rijeci=0;
	int znak=1, velicina, brojac=0, razmak=1;
	int *poc=tekst;

/*Provjerimo koliko mjesta treba zauzeti broj*/	
	if (broj<0) znak=-1;
	broj=fabs(broj);
	while(broj!=0) {
		broj=broj/10;
		brojac++;
	}
	if(znak==-1)brojac++;

	velicina=brojac;

/*Ako je string samo jedna rijec, vraca pocetni string*/
	while (*tekst != '\0') {
		if(*tekst == ' ')
			razmak=1;
		else if(razmak==1) {
			razmak=0;
			brojac_rijeci++;
		}
		tekst++;
	}
	if (brojac_rijeci==1) return poc;
	
	tekst=poc;
	while (*tekst != '\0'){
		while (*tekst==' ')tekst++;
		while(*tekst!=' ')tekst++;
		tekst++;
		
	}
	

	









}












int main()
{
	printf("Zadaća 4, Zadatak 1");
	return 0;
}

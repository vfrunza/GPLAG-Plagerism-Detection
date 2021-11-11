#include <stdio.h>
#define BR_EL 100
int dva_od_tri ( int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
	int i, j, logicka = 0, brojac = 0;
	/*Prvi niz*/

	/*Poredimo prvi niz sa 2. i 3.*/
	for(i = 0; i < vel1; i++) {
		/*Najprije provjeravamo da li se trenutni broj vec ponovio u nizu dosadasnjih elemenata
		te ga preskacemo ako jeste*/
		for(j = 0; j < i; j++) {
			if(niz1[i] == niz1[j]) {
				i = i + 1;
				j = 0;
				if(i >= vel1)
					break;
			}
		}
		if(i >= vel1)
			break;

		/*Postavljamo varijablu na 0, koja sluzi da provjerimo da li postoji isti clan
		unutar vise nizova*/
		logicka=0;
		for(j = 0; j < vel2; j++) {
			if(niz1[i] == niz2[j]) {
				logicka++;
				break;
			}
		}
		for(j = 0; j < vel3; j++) {
			if(niz1[i] == niz3[j]) {
				logicka++;
				break;
			}
		}

		/*Ako se broj ponovio ili u 2. ili u 3. nizu, logicka = 1, te se brojac poveca za jedan,
		sto znaci da postoji proj koji se nalazi u dva zadana niza*/
		if(logicka == 1)
			brojac++;

	}
	/* Drugi niz*/

	/*Analogno 1. petlji*/
	for(i = 0; i < vel2; i++) {
		for(j = 0; j < i; j++) {
			if(niz2[i] == niz2[j]) {
				i = i + 1;
				j = 0;
				if(i >= vel2)
					break;
			}
		}
		if(i >= vel2)
			break;
		logicka=0;
		for(j = 0; j < vel1; j++) {
			if(niz2[i] == niz1[j]) {
				logicka++;
				break;
			}
		}
		for(j = 0; j < vel3; j++) {
			if(niz2[i] == niz3[j]) {
				logicka++;
				break;
			}
		}
		if(logicka == 1)
			brojac++;

	}
	/* Treci niz*/
	/*Analogno 1. petlji*/
	for(i = 0; i < vel3; i++) {
		for(j = 0; j < i; j++) {
			if(niz3[i] == niz3[j]) {
				i = i+1;
				j = 0;
				if(i >= vel3)
					break;
			}
		}
		if(i >= vel3)
			break;
		logicka=0;
		for(j = 0; j < vel1; j++) {
			if(niz3[i] == niz1[j]) {
				logicka++;
				break;
			}
		}
		for(j = 0; j < vel2; j++) {
			if(niz3[i] == niz2[j]) {
				logicka++;
				break;
			}
		}
		if(logicka == 1)
			brojac++;

	}

	/*Zbog poredjenja, desava se da se isti clan broji dva puta, pa brojac treba podijeliti sa 2 prilikom vracanja*/
	return brojac/2;
}

int main()
{
	int i, vel1, vel2, vel3, niz1[BR_EL], niz2[BR_EL], niz3[BR_EL];
	printf("Unesite velicinu prvog niza: ");
	scanf("%d",&vel1);
	printf("Unesite clanove prvog niza: ");
	for(i = 0; i < vel1; i++)
		scanf("%d",&niz1[i]);

	printf("Unesite velicinu drugog niza: ");
	scanf("%d",&vel2);
	printf("Unesite clanove drugog niza: ");
	for(i = 0; i < vel2; i++)
		scanf("%d",&niz2[i]);

	printf("Unesite velicinu treceg niza: ");
	scanf("%d",&vel3);
	printf("Unesite clanove treceg niza: ");
	for(i = 0; i < vel3; i++)
		scanf("%d",&niz3[i]);
	return 0;
}

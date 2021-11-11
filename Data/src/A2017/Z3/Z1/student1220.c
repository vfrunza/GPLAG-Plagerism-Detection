#include <stdio.h>

int dva_od_tri(int* niz1, int vel1, int* niz2, int vel2, int*niz3, int vel3)
{
	int i,j;
	int novi_niz[1000]; /*Niz u koji cemo cuvati sve neponavljane brojeve*/
	int brojac=0;
	int jedan_od_tri=0;
	int dva_od_tri=0;

	for(i=0; i<vel1; i++) {
		for(j=0; j<brojac; j++) /*j ide do brojaca jer se svaki clan niza1 mora uporediti novim nizom koji se sastoji od onoliko clanova koliko se do tada brojac puta povecao. To znaci da kada uzmemo npr. peti clan niza1(a do tog petog clana povecali smo brojac npr 3 puta, tj. taj novi niz se sastoji od 3 elementa), taj peti clan niza 1 moramo provjeriti sa svim clanovima novog niza(koji u tom trenutku broji 3 clana) da vidimo da li se on ponavlja sa nekim clanom iz tog novog niza*/
		/* Brejkaj ako se neki broj ponavlja*/
			if(niz1[i]==novi_niz[j]) break;
			/*Novi niz je filtritrani orginalni niz. U njemu cuvaj brojeve koji se javljaju samo jednom, tj koji se ne ponavljaju*/
		if(j==brojac) novi_niz[brojac++]=niz1[i];
	}

	for(i=0; i<vel2; i++) {
		for(j=0; j<brojac; j++)
		/* Brejkaj ako se neki broj ponavlja u odnosu na niz1*/
			if(niz2[i]==novi_niz[j]) break;
			/*Novi niz sada sadrzi brojeve koji se ne ponavljaju u nizu1 i provjeravamo taj niz sa nizom 2. Takodjer ovdje sacuvaj brojeve kojih nema u novom nizu*/
		if(j==brojac) novi_niz[brojac++]=niz2[i];
	}

	for(i=0; i<vel3; i++) {
		for(j=0; j<brojac; j++)
		/* Brejkaj ako se neki broj ponavlja*/
			if(niz3[i]==novi_niz[j]) break;
			/*Novi niz se sada sastoji od brojeva koji se ne ponavljaju, kada smo takve izvukli iz niza1 i niza 2. Sada ga opet uporedjujemo sa nizom 3, i kreiramo konacan niz ne ponavljanih brojeva s kojim cemo raditi u nastavku*/
		if(j==brojac) novi_niz[brojac++]=niz3[i];
	}

	for(i=0; i<brojac; i++) {
		jedan_od_tri=0;

		for(j=0; j<vel1; j++) {
			/*Prodji kroz niz1, i ako se taj clan takodjer javlja u novom nizu, povecaj njegovo postojanje i zavrsi njegovo brojanje */
			if(niz1[j]==novi_niz[i]) {
				jedan_od_tri++;
				break;
			}
		}

		for(j=0; j<vel2; j++) {
			/*Prodji kroz niz2, i ako se taj clan takodjer javlja u novom nizu, povecaj njegovo postojanje i zavrsi njegovo brojanje */
			if(niz2[j]==novi_niz[i]) {
				jedan_od_tri++;
				break;
			}
		}

		for(j=0; j<vel3; j++) {
			/*Prodji kroz niz3, i ako se taj clan takodjer javlja u novom nizu, povecaj njegovo postojanje i zavrsi njegovo brojanje */
			if(niz3[j]==novi_niz[i]) {
				jedan_od_tri++;
				break;
			}
		}
		
		//Posto jot nismo vracali svaki put na nulu, nego smo ga 'pustili' da se povecava(a mogao se povecati na 1 u svakom nizu), ako se povecao dva puta, treba vratiti taj broj, jer se tako trazi*/
		if(jedan_od_tri==2) {
			dva_od_tri++;
		}

	}

	return dva_od_tri;
}

int main()
{
	int A[100];
	int B[100];
	int C[100];
	int i,y;
	int velicinaA,velicinaB,velicinaC;

	printf("Unesi velicinu niza A:\n");
	scanf("%d",&velicinaA);

	printf("Unesi velicinu niza B\n");
	scanf("%d",&velicinaB);

	printf("Unesi velicinu niza C:\n");
	scanf("%d",&velicinaC);

	printf("Unesi niz A:\n");
	for(i=0; i<velicinaA; i++) {
		scanf("%d", &A[i]);
	}

	printf("Unesi niz B:\n");
	for(i=0; i<velicinaB; i++) {
		scanf("%d",&B[i]);
	}

	printf("Unesi niz C:\n");
	for(i=0; i<velicinaC; i++) {
		scanf("%d",&C[i]);
	}

	y=dva_od_tri(A,velicinaA,B,velicinaB,C,velicinaC);

	printf("Broj brojeva koji se javljaju u 2 od tri niza, bez ponavljanja je: %d", y);



	return 0;

}
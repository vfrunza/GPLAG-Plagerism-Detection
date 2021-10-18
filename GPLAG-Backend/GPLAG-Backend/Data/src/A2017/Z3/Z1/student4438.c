#include <stdio.h>
int dva_od_tri(int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3)
{
	int i,j,k;
	int brojac=0,BrojacVeliki=0;
	int brojac_return=0;
	int VelikiNiz[500],VelikaVelicina=0;
	for(i=0; i<vel1; i++) //Pravimo niz koji u sebi sadrzi samo po jednu vrijednost iz svakog niza(dakle pravimo niz koji sadrzi brojeve iz
		// sva tri niza bez ponavljanja tih brojeva (ako se uopste ponavljaju u nizovima) (tj.pravimo niz koji je zapravo UNIJA ova tri niza)
	{
		int brojac=0;
		for(j=0; j<VelikaVelicina; j++) {
			if(niz1[i]==VelikiNiz[j]) //Znaci da li se trenutni broj,tj.niz[i] nalazi vec u velikom nizu(veliki niz-ukupni niz,tj.
				//niz koji u sebi ima sve brojeve od ova tri niza(unija ova tri niza) (bez ponavljanja) 
				//(ovu promjenljivu brojac zamisljamo kao logicku promjenljivu)
			{
				brojac=1;
			}
		}
		if(brojac==0) {
			VelikiNiz[VelikaVelicina]=niz1[i];
			VelikaVelicina++;
		}
	}
	for(i=0; i<vel2; i++) { //isti komentar kao za niz1 vrijedi ovdje
		brojac=0;
		for(j=0; j<VelikaVelicina; j++) {
			if(niz2[i]==VelikiNiz[j]) {
				brojac=1;
			}
		}
		if(brojac==0) {
			VelikiNiz[VelikaVelicina]=niz2[i];
			VelikaVelicina++;
		}
	}
	for(i=0; i<vel3; i++) { //isti komentar kao za niz1 vrijedi ovdje
		brojac=0;
		for(j=0; j<VelikaVelicina; j++) {
			if(niz3[i]==VelikiNiz[j]) {
				brojac=1;
			}
		}
		if(brojac==0) {
			VelikiNiz[VelikaVelicina]=niz3[i];
			VelikaVelicina++;
		}
	}
	for(i=0; i<VelikaVelicina; i++) //Nakon sto smo napravili veliki niz u kojem se nalaze svi brojevi iz tri niza
		// bez ponavljanja,sada provjeravamo koliko se puta javljaju brojevi iz velikog niza u ova tri manja niza
	{
		BrojacVeliki=0;

		for(j=0; j<vel1; j++) {
			if(niz1[j]==VelikiNiz[i]) {
				BrojacVeliki++;
				break;
			}
		}
		for(j=0; j<vel2; j++) {
			if(niz2[j]==VelikiNiz[i]) {
				BrojacVeliki++;
				break;
			}
		}
		for(j=0; j<vel3; j++) {
			if(niz3[j]==VelikiNiz[i]) {
				BrojacVeliki++;
				break;
			}
		}

		if(BrojacVeliki==2) //Ako se neki broj javlja ISKLJUCIVO u dva niza,onda povecavamo "globalni brojac",tj.brojac
			// koji vracamo iz funkcije.U svim ostalim slucajevima nam nije bitna vrijednost ovog velikog brojaca
		{

			brojac_return++;
		}
	}
	return brojac_return;
}
int main()
{
	int niz1[4]= {1,2,3,5};
	int vel1=4;
	int niz2[5]= {1,2,4,6,7};
	int vel2=5;
	int niz3[6]= {1,3,4,8,9,10};
	int vel3=6;
	printf("%d",dva_od_tri(niz1,vel1,niz2,vel2,niz3,vel3));

	return 0;
}
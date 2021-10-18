/*Napisati funkciju sa sljedećim prototipom:
	int max(int matrica[100][100], int visina, int sirina)
Funkcija prima matricu cijelih brojeva koja je deklarisane veličine 100x100, ali njene stvarne dimenzije 
date su promjenljivim visina i sirina. Funkcija vraća član matrice koji se najviše puta ponavlja. Ako se 
više članova ponavljaju jednak (najveći) broj puta, funkcija treba vratiti najmanji od tih članova.

Zatim napisati funkciju izbaci_kolone koja prima matricu (kao iznad) i jedan broj N, a zatim iz matrice
izbacuje sve kolone u kojima se javlja član N. Funkcija vraća broj kolona nakon izbacivanja.

Ove dvije funkcije iskoristite u programu u kojem se najprije traži od korisnika da unese matricu, a zatim 
se u petlji poziva prva pa druga funkcija (iz matrice se izbacuju sve kolone u kojima se nalazi element koji
se najviše puta javlja u matrici), i tako sve dok matrica ne ostane prazna. Prilikom svakog prolaza treba na
ekran ispisati matricu:

Primjer ulaza i izlaza:
	Unesite sirinu i visinu matrice: 4 2
	Unesite elemente 1. reda: 3 3 4 1
	Unesite elemente 2. reda: 2 3 2 1
	
	Nakon 1. prolaza matrica glasi:
	    4    1
	    2    1

	Nakon 2. prolaza matrica glasi:
	    4
	    2

	Nakon 3. prolaza matrica je prazna!
*/

#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina){
	
	int i,j,k=0, max=0,t;
	int niz[10000];
	int brojac[10000]={0};
	
	for (i=0; i<visina; i++){
		for (j=0; j<sirina; j++){
			niz[k]=matrica[i][j];
			k++;
		}
	}
	for (k=0; k<=visina*sirina; k++){
		
		if (brojac[k]>0)
		t=brojac[k];
	}
	max=brojac[0];
	for (k=0; k<=visina*sirina; k++){
		if (t>max || k==0){
			 	max=brojac[k];
			 	return niz [k];
			 }
	}
	
	
			 
	
	return max;
}
	/*for (i=0; i<visina*sirina; i++){
		brojac=0;
		for (j=0; j<visina*sirina; j++){
			if( niz[i]==niz[j])
			brojac++;
		}
		if (brojac==0{
			niz[k]=niz[i];
			
		for (s=0; s<visina*sirina; s++){
			if (niz[s]==niz[i])
		}
		})
	}
	
}*/

int main() {
	
	return 0;
}

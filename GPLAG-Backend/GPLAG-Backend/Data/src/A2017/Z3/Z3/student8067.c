#include <stdio.h>
#include <math.h>

int BrojElemenata(int k){
	int brojac = 0 ;
	int cifra;
	for(;;){
		cifra = k % 10;
		k /= 10;
		brojac++;
		if ( k == 0 ) break;
	}
	return brojac;
}
int izbaci_cifre(int niz1[],int vel1, int niz2[],int vel2){
	int cifra;
	int i , j ,k;
	int niz_cifara[100];
	int brojac = 0 ;
	int broj_el = 0 ;
	int brojac_novih = 0 ;
	
	
	//novi niz za cifre koje nisu u nizu2
	int niz_razl[100];
	int br= 0 ;
	
	for(i = 0 ; i < vel1; i++){
		broj_el = BrojElemenata(niz1[i]);
		for(j = 0 ; j < broj_el; j++){
			for(k = 0 ; k < 100; k++){
				cifra = niz1[j] % 10;
				niz1[j] /= 10;
				niz_cifara[k] = niz1[j];
				brojac++;
			}
		}
	}
	
	
	//uporedjivanje nizova
	for( i = 0 ; i < brojac ; i++){
		for( j = 0 ; j < vel2; j++){
			for( k = 0 ; k < 100; k++){
				if(niz_cifara[i] != niz2[j]){
					niz_razl[k] = niz_cifara[i];
					br++;
				}
			}
		}
	}
	if(br == 0 ) return 0;
	return 1;
	
}
int main() {
/*	int niz1[5],niz2[5];
	int vel1,vel2;
	int i , j ;
	
	printf("Unesite broj el prvog niza: \n");
	scanf("%d",&vel1);
	printf("\nUnesite elemente prvog niza: \n");
	for( i = 0 ; i < vel1; i++){
		scanf("%d",&niz1[i]);
	}
	
	printf("\nUNesite broj el drugog niza: \n");
	scanf("%d",&vel2);
	printf("\nUnesite elemente drugog niza: \n");
	for( i = 0 ; i < vel2; i++){
		scanf("%d",&niz2[i]);
	}

	j = izbaci_cifre(niz1,vel1,niz2,vel2);
	printf("\n%d",j);*/
	return 0;
}

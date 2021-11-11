#include <stdio.h>
#include <stdlib.h>


/*FUNKCIJA ZA SORTIRANJE NIZA*/
void sortiraj(int *niz, int n){
	int i, j,temp;
	for(i = 0; i < (n-1); i++){
		for(j = 0; j < (n-1); j++){
			if(*(niz + j) > *(niz + j + 1)){
				temp = *(niz + j + 1);
				*(niz + j + 1) = *(niz + j);
				*(niz + j) = temp;
			}
		}
	}
}


/*FUNKCIJA ZA KOPIRANJE JEDNOG NIZA U DRUGI*/
void kopiraj(int *niz1, int *niz2, int n){
	int i;
	for(i = 0; i < n; i++){
		*(niz2 + i) = *(niz1 + i);
	}
}


int izbacivac(int x, int y){
	int i;
	int x1 = abs(x);/*RADI MINUSA*/
	int temp[100];
	int duzina = 0,djel = 10, broj = 0;
	int zrtva = abs(x);/*ZRTVA NAM SLUZU ZA RACUNANJE BROJA CIFARA X*/
	
	if(x == 0){
		return 0;
	}
	while(zrtva > 0){
		zrtva /=  10;
		duzina++;
	}
	/*POHRANJIVANJE CIFARA BROJA X U NIZ TEMP*/
	for(i = 0; i < duzina; i++){
		
		temp[i] = (x1 % djel)/(djel / 10);
		/*printf("%d\n", temp[i]);*/
		djel *= 10;
	}
	djel = 1;
	for(i = 0;i < duzina; i++){
		if(temp[i] != y){
			broj += temp[i]*djel;
			djel *= 10;
		}
	}
	if(x < 0){
		return broj * -1;
	}
	return broj;
	
}


int izbaci_cifre(int *nizBrojeva, int n1, int *nizCifara, int n2){
	int i, j;
	int temp[100];
	/*PRVO PROVJERAVAMO DA LI JE NIZ CIFARA ISPRAVAN*/
	for(i = 0; i < n2; i++){
		if(*(nizCifara + i) < 0 || *(nizCifara + i) > 9){
			/*slučaju kada su brojevi van opsega*/
			return 0;
		}
	}
	/*ISPITUJEMO SLUČAJ KADA SE BROJEVI PONAVLJAJU*/
	kopiraj(nizCifara, temp, n2);
	sortiraj(temp,n2);
	for(i = 0; i < n2 - 1; i++){
		if(*(temp + i) == *(temp + i + 1)){
			return 0;
		}
	}
	/*U OVOM TRENUTKU SMO SIGURNI DA JE NAŠ NIZ ISPRAVAN*/
	for(i = 0; i < n1; i++){
		for(j = 0; j < n2; j++){
			/*i nam predstavlja index niza cifara koje treba izbaciti, a j predstavlja niza elemenata kojima se treba izbaciti cifra*/
			*(nizBrojeva + i) = izbacivac(*(nizBrojeva + i), *(nizCifara + j));
		}
	}
	return 1;
	
	
}

int main() {
	int i;
	int nizBrojeva[100];
	int nizCifara[100];
	int n1,n2;
	printf("Unesi broj elemenata niza brojeva: ");
	scanf("%d", &n1);
	printf("Unesi elemente brojeva: ");
	for(i = 0; i < n1; i++){
		scanf("%d", &nizBrojeva[i]);
	}
	printf("Unesi broj elemenata niza cifara: ");
	scanf("%d", &n2);
	printf("Unesi elemente cifara: ");
	printf("%d", izbaci_cifre(nizBrojeva, n1, nizCifara, n2));
	
	return 0;
}

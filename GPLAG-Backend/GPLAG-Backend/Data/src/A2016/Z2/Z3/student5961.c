#include <stdio.h>

int main() {
	int niz1[100], niz2[100], i, j, n, k=0, brojac=0;
	//Unos broja tacaka
	do{
		printf("Unesite broj tacaka: ");
	    scanf("%d", &n);
	    if(n<1 || n>10) printf("Pogresan unos\n");
	}while(n<1 || n>10);
	i=0;
	//Unos tacaka preko dva niza kao x y koordinatne tacke
	do{
	    printf("Unesite %d. tacku: ", i+1);
	    scanf("%d %d", &niz1[i], &niz2[i]);
	    if(niz1[i]<0 || niz1[i]>=20 || niz2[i]<0 || niz2[i]>=20){
	        printf("Pogresan unos\n");
	        i--;
	    }
	    i++;
	}while(i<n);
	//provjeravanje tacaka
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			//provjera svake tacke posebno
			for(k=0; k<n; k++){
                if(niz1[k]==j && niz2[k]==i){
                    brojac++;
                    break;
                }
            }
			if(brojac>0) printf("*");
			else printf(" ");
			brojac=0;
		}
		printf("\n");
	}
	return 0;
}

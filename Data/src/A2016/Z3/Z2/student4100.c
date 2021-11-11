#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void ubaci (int* niz, int vel){
	int* var=niz;
	int* var2;
	int clan=0, k = 0, br;
	while (var < niz + 2 * vel){
		br = abs (*var);
		while (br){
			clan = clan + br % 10;
			br = br / 10;
		}
		for (var2 = niz + (vel + k); var2 > var; var2--){*var2 = *(var2 - 1);}
		k++;
		var++;
		*var = clan;
		clan = 0;
		var++;	
	}
}	
int fibonacci (int br){
		int niz[1000];
	niz[0] = 1;
	niz[1] = 1;
	if (br == 1) 	return 1;
	int* var1 = niz;
	int* var2 = niz+1;
	int* var3 = niz+2;
		while (1){
		*var3 = *var2 + *var1;
		if (*var3 == br) return 1;
		if (*var3 > br){return 0;}
		var1++;
		var2++;
		var3++;
	}
}
int izbaci (int*niz, int velicina){
	int *var = niz;
	int *var2;
	int broj;
	while (var < niz + velicina){
		broj = *var;
        broj = fibonacci(broj);
        if (broj == 1){
        	for (var2 = var; var2 < niz + velicina - 1; var2++){
        		*var2 =* (var2 + 1);
         }
        	velicina--;
        	var--;
    	 }
			var++;
	}
		return velicina;	
}
int main() {
	int i, j, niz[100];
	printf ("Unesite niz od 10 brojeva: ");
	for (i = 0; i < 10; i++)
		scanf ("%d", &niz[i]);
		ubaci(niz, 10);
	j = izbaci(niz, 20);
	printf ("Modificirani niz glasi: ");
	for (i = 0; i < j; i++){
		if (i == j - 1)	printf ("%d.", niz[i]);
		else printf ("%d, ", niz[i]);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define LENGTH(x) (sizeof(x) / sizeof((x)[0]))

/* prototipi */
int izbaci_cifre(int*, int, int*, int);
void removeDigit(int*, int);
int isValid(int*, int);

int main() {
	/* Kratki test, zanemariti */
	
	int br[] = {-54760570};
	//int a[] = {0, 5, 4, 6};
	printf("%d\n", br[0]);
	removeDigit(&br[0], 0);
	//izbaci_cifre(br, LENGTH(br), a, LENGTH(a));
	printf("%d\n", br[0]);
	
	return 0;
}

/* izbaci_cifre - IMPLEMENTACIJA */
int izbaci_cifre(int num[], int numLen, int dgt[], int dgtLen) {
	int i, j;
	
	// provjeri validnost prije no sto dodje do rada sa invalidnim nizom
	if (!isValid(dgt, dgtLen))
		return 0;
	
	// Brisi cifru po cifru
	for (i = 0; i < numLen; i++)
		for (j = 0; j < dgtLen; j++)
			removeDigit(&num[i], dgt[j]);
		
	return 1;
}
// end izbaci_cifre

/* removeDigit - IMPLEMENTACIJA */
// Ova funkcija brise iz datog broja sva pojavljivanja date cifre
void removeDigit(int *num, int dgt) {
	int cpNum = abs(*num);
	int k = 1;
	
	while (cpNum) {
		// brise cifru
		if (cpNum % 10 == dgt)
			*num = *num / (k * 10) * k + *num % k;
		else
			k *= 10;
			
		cpNum /= 10;
	}
}
// end removeDigit

/* isValid - IMPLEMENTACIJA */
/* Ova funkcija provjerava da li se nalazi u nizu nesto sto nije cifra
   i da li se ijedna cifra ponavlja */
int isValid(int dgt[], int dgtLen) {
	int hist[10] = {0};
	int i;
	
	for (i = 0; i < dgtLen; i++) {
		if (dgt[i] < 0 || dgt[i] > 9)
			return 0;
			
		if (hist[dgt[i]])
			return 0;
			
		hist[dgt[i]]++;
	}
	
	return 1;
}
// end isValid
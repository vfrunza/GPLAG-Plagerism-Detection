#include <stdio.h>
#include <stdlib.h>

/* prototipi */
int dva_od_tri(int*, int, int*, int, int*, int);
void sort(int*, int);
int deleteRepeats(int*, int);

int main() {
	/* Testni kod */
	int a[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	int b[] = {3, 3, 3, 2, 2};
	int c[] = {1, 3, 4};
	printf("%d\n", dva_od_tri(a, 11, b, 5, c, 3));
	
	return 0;
}

int dva_od_tri(int arr1[], int len1, int arr2[], int len2, int arr3[], int len3) {
	int *aux1, *aux2, *aux3;
	int res = 0;
	int i, j, k;
	
	aux1 = (int*) malloc(len1 * sizeof(int));
	if (aux1 == NULL)
		return -1;
		
	aux2 = (int*) malloc(len2 * sizeof(int));
	if (aux2 == NULL)
		return -1;
	
	aux3 = (int*) malloc(len3 * sizeof(int));
	if (aux3 == NULL)
		return -1;
	
	/* Pripremi pomozne nizove za rad na njima
	   1. kopiraj sve elemente iz pocetnih u pomocni
	   2. sortiraj ih od najmanjeg ka najvecem
	   3. izbrisi duplikate
	   */
	// PRVI NIZ
	for (i = 0; i < len1; i++)
		aux1[i] = arr1[i];
	sort(aux1, len1);
	len1 = deleteRepeats(aux1, len1);
	
	// DRUGI NIZ
	for (i = 0; i < len2; i++)
		aux2[i] = arr2[i];
	sort(aux2, len2);
	len2 = deleteRepeats(aux2, len2);
	
	// TRECI NIZ
	for (i = 0; i < len3; i++)
		aux3[i] = arr3[i];
	sort(aux3, len3);
	len3 = deleteRepeats(aux3, len3);
	
	i = j = k = 0;
	
	// Poredjenje sva tri niza do kraja najkraceg
	/* Ako su sva trenutni elementi iz sva tri jednaka, onda nastavi dalje na sljedeci.
	   Ako su jednaka iz prva dva: te ukoliko je treci veci od oba, povecaj rezultat i nastavi dalje sa ova dva,
	   inace treba 3. da sustigne ova dva. Analogno za 1. i 3. i 2. i 3.
	   U posljednjem slucaju treba da najmanji sustigne ostale */
	while (i < len1 && j < len2 && k < len3) {
		if (aux1[i] == aux2[j] && aux2[j] == aux3[k]) {
			i++;
			j++;
			k++;
		}
		else if (aux1[i] == aux2[j]) {
			if (aux3[k] > aux1[i]) {
				i++;
				j++;
				res++;
			}
			else
				k++;
		}
		else if (aux1[i] == aux3[k]) {
			if (aux2[j] > aux1[i]) {
				i++;
				k++;
				res++;
			}
			else
				j++;
		}
		else if (aux2[j] == aux3[k]){
			if (aux1[i] > aux3[k]) {
				j++;
				k++;
				res++;
			}
			else
				i++;
		}
		else if (aux1[i] < aux2[j] && aux1[i] < aux3[k])
			i++;
		else if (aux2[j] < aux1[i] && aux2[j] < aux3[k])
			j++;
		else
			k++;
	}
	
	// Poredjenje krajeva 1. i 2. niza
	while (i < len1 && j < len2) {
		if (aux1[i] == aux2[j]) {
			res++;
			
			i++;
			j++;
		}
		else if (aux1[i] < aux2[j])
			i++;
		else
			j++;
	}
	
	// Poredjenje krajeva 1. i 3. niza
	while (i < len1 && k < len3) {
		if (aux1[i] == aux3[k]) {
			res++;
			
			i++;
			k++;
		}
		else if (aux1[i] < aux3[k])
			i++;
		else
			k++;
	}
	
	// Poredjenje krajeva 2. i 3. niza
	while (j < len2 && k < len3) {
		if (aux2[j] == aux3[k]) {
			res++;
			
			j++;
			k++;
		}
		else if (aux2[j] < aux3[k])
			j++;
		else
			k++;
	}
	
	// Brisanje nizova radi preventive curenja memorije
	free(aux1);
	free(aux2);
	free(aux3);
	
	return res;
}

void sort(int arr[], int len) {
	int i, j;
	int tmp, mini;
	
	for (i = 0; i < len - 1; i++) {
		mini = i;
		
		for (j = i + 1; j < len; j++) 
			mini = (arr[mini] > arr[j]) ? j : mini;
			
		tmp = arr[i];
		arr[i] = arr[mini];
		arr[mini] = tmp;
	}
}

int deleteRepeats(int array[], int len) {
	int i, j;
	
	for (i = 0; i < len - 1; i++)
		if (array[i] == array[i + 1]) {
			for (j = i; j < len - 1; j++)
				array[j] = array[j + 1];
				
			len--;
			i--;
		}
	
	return len;
}
#include <stdio.h>

int pripada_nizu(int *niz, int velicina, int broj){
	int i;
	for (i=0; i<velicina; i++)
		if (niz[i]==broj) return 1;
	return 0;
}

int dva_od_tri (int *niz1, int velicina1, int *niz2, int velicina2, int *niz3, int velicina3){
	int i, j, min, temp, brojac=0;
	/*sortiranje 1. niza*/
	for (i=0; i<velicina1; i++){
		min = i;
		for (j=i+1; j<velicina1; j++){
			if (niz1[j] < niz1[min])
				min = j;
		}	
		temp = niz1[i];
		niz1[i] = niz1[min];
		niz1[min] = temp;
	}
	
	/*sortiranje 2. niza*/
	for (i=0; i<velicina2; i++){
		min = i;
		for (j=i+1; j<velicina2; j++){
			if (niz2[j] < niz2[min])
				min = j;
		}	
		temp = niz2[i];
		niz2[i] = niz2[min];
		niz2[min] = temp;
	}
	
	/*sortiranje 3. niza*/
	for (i=0; i<velicina3; i++){
		min = i;
		for (j=i+1; j<velicina3; j++){
			if (niz3[j] < niz3[min])
				min = j;
		}	
		temp = niz3[i];
		niz3[i] = niz3[min];
		niz3[min] = temp;
	}
	
	
	/*ispitujemo da li clan pripada 1. i 2. nizu, a ne pripada 3.*/
	for (i=0; i<velicina1; i++){
		if (i<velicina1-1 && (niz1[i] == niz1[i+1])) continue;
		if (pripada_nizu(niz2, velicina2, niz1[i]) && 
		   !(pripada_nizu(niz3, velicina3, niz1[i])))
		   		brojac++;
	}
	/*ispitujemo da li clan pripada 2. i 3. nizu, a ne pripada 1.*/
	for (i=0; i<velicina2; i++){
		if (i<velicina2-1 && (niz2[i] == niz2[i+1])) continue;
		if (pripada_nizu(niz3, velicina3, niz2[i]) && 
		   !(pripada_nizu(niz1, velicina1, niz2[i])))
		   		brojac++;
	}
	/*ispitujemo da li clan pripada 3. i 1. nizu, a ne pripada 2.*/
	for (i=0; i<velicina3; i++){
		if (i<velicina3-1 && (niz3[i] == niz3[i+1])) continue;
		if (pripada_nizu(niz1, velicina1, niz3[i])&& 
		   !(pripada_nizu(niz2, velicina2, niz3[i])))
		   		brojac++;
	}
	
	return brojac;
}

int main() {
	printf("Zadaća 3, Zadatak 1");
	return 0;
}

#include <stdio.h>

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3) {
	
	int nizBrojevi1[10] = {0};
	int nizBrojevi2[10] = {0};
	int nizBrojevi3[10] = {0};
	int i = 0, rez = 0;
	
	for(i = 0; i < vel1; i++) {
		
		if(nizBrojevi1[niz1[i]] < 1) nizBrojevi1[niz1[i]]++;
		
	}
	
	for(i = 0; i < vel2; i++) {
		
		if(nizBrojevi2[niz2[i]] < 1) nizBrojevi2[niz2[i]]++;
		
	}
	
	for(i = 0; i < vel3; i++) {
		
		if(nizBrojevi3[niz3[i]] < 1) nizBrojevi3[niz3[i]]++;
		
	}
	
	
	for(i = 0; i < 10; i++) {
		
		if(nizBrojevi1[i] + nizBrojevi2[i] + nizBrojevi3[i] == 2) rez++;
		
	}
	
	return rez;
	
}

int main() {
	
	/* AT4: Ponavljanje */
	int niz1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	int niz2[] = {3, 3, 3, 2, 2};
	int niz3[] = {1, 3, 4};
	int rez = dva_od_tri(niz1, 11, niz2, 5, niz3, 3);
	printf("%d ", rez);
	rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 3);
	printf("%d ", rez);
	rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 11);
	printf("%d ", rez);
	return 0;
}

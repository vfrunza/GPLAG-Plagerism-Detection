#include <stdio.h>
int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
	int HISTOGRAM [10000] = {0}, nadjen[10000] = {0}, POMOCNI_HISTOGRAM [10000] = {0};
	int i = 0;
	int brojac = 0;
	for(i = 0; i < vel1; i++) {
		if(niz1[i] < 0) {
			if(nadjen[-1 * niz1[i]] == 0) {
			
			POMOCNI_HISTOGRAM [-1 * niz1[i]]++;
			nadjen [-1 * niz1[i]] = 1;
		}
	}
	else {
			HISTOGRAM [niz1[i]]++; 
		
	}
			nadjen [niz1[i]] = 1;
			
	}
	for(i = 0; i < 10000; i++)
		nadjen[i] = 0;
	for(i = 0; i < vel2; i++) {
		if(niz2[i] < 0) {
		if(nadjen[-1 * niz2[i]] == 0) {
			
			POMOCNI_HISTOGRAM [-1 * niz2[i]] = 1;
			nadjen [-1 * niz2[i]] = 1;
		}
	}
	else {
			
			HISTOGRAM [niz2[i]]++; 
	}
		nadjen [niz2[i]] = 1;
	}
	for(i = 0; i < 10000; i++) 
		nadjen[i] = 0;
	for(i = 0; i < vel3; i++) {
		if(niz3[i] < 0) {
		if(nadjen[-1 * niz3[i]] == 0) {
			
			POMOCNI_HISTOGRAM [-1 * niz3[i]]++;
			nadjen [-1 * niz3[i]] = 1;
		}
	}
	else {
		
			HISTOGRAM [niz3[i]]++; 
		}
		nadjen [niz3[i]] = 1;
	}
	for(i = 0; i < 10000; i++) {
		
		if(HISTOGRAM [i] == 2) {
			brojac++;
		}
		if(POMOCNI_HISTOGRAM [i] == 2)
		brojac++;
	}
	return brojac;

}

int main() {
	int niz1[2000] = {0}, niz2[2000] = {0}, niz3 [2000] = {0};
	int i = 0;
	int vel1 = 0, vel2 = 0, vel3 = 0;
	int rez;
	printf("Unesite velicinu niza 1: ");
	scanf("%d", &vel1);
	for(i = 0; i < vel1; i++) {
		scanf("%d", &niz1[i]);
	}
	printf("Unesite velicinu niza 2: ");
	scanf("%d", &vel2);
	for(i = 0; i < vel2; i++) {
		scanf("%d", &niz2[i]);
	}
	printf("Unesite velicinu niza 3: ");
	scanf("%d", &vel3);
	for(i = 0; i < vel3; i++) {
		scanf("%d", &niz3[i]);
	}
	rez = dva_od_tri(niz1, vel1, niz2, vel2, niz3, vel3);
	printf("%d", rez);
	
	return 0;
}

#include <stdio.h>

int ima_element(int*niz, int vel, int element){
	
	int i;
	for(i=0; i<vel; i++)
		
		if(niz[i] == element)	return 1;
	
		return 0;
}

int dva_od_tri(int*nizA,int velA, int*nizB,int velB, int*nizC, int velC){
	
	int i;
	int brojac = 0;
	int koliko_istih;
	
	for(i=0; i<velA; i++){
		
		if(ima_element(nizA, i, nizA[i]))  continue;
		
		koliko_istih = 1;
			
		if(ima_element(nizB, velB, nizA[i]))	koliko_istih++;
			
		if(ima_element(nizC, velC, nizA[i]))	koliko_istih++;
		
		if(koliko_istih==2)						brojac++;
		
	}
	
	for(i=0; i<velC; i++) {
		
		if(ima_element(nizC, i, nizC[i]))		continue;
		
		if(ima_element(nizA, velA, nizC[i]))	continue;
		
		koliko_istih = 1;
		
		if(ima_element(nizB, velB, nizC[i]))	koliko_istih++;
		
		if(ima_element(nizA, velA, nizC[i]))	koliko_istih++;
		
		if(koliko_istih==2)		brojac++;
	}
	
	return brojac;
}


int main() {
	
	int niz1 [5] = {0, 1, 2, 3, 5};
	int niz2 [6] = {1, 2, -5, 4, 6, 7};
	int niz3 [5] = {1, 3, -8, 4, 0};
	int rezultat;
	
	rezultat = dva_od_tri(niz1, 5,niz2,6, niz3,5);
	
	printf("Tacno 2 razlicita ima: %d broja", rezultat);
	
	return 0;
}

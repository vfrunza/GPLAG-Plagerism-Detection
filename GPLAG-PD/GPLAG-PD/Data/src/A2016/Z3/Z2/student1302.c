#include <stdio.h>
#include <math.h>

void ubaci (int niz[10000], int vel) {
	int i, j, broj, dec, suma, n;
	
	n = vel;
	for (i = 0; i < vel*2 ; i+=2) {
		broj = niz[i];
		
		if( broj < 0) 
			broj = fabs(broj);
		
		suma = 0;
		
		while (broj != 0) {
			dec = broj%10;
			suma+=dec;
			broj = broj/10;
		}
		
		for (j = n; j > i+1; j--) { 
			niz[j] = niz[j-1];
		}
		
		niz[j] = suma;
		n = n+1;
	}
}

int provjeriSavrseniKvadrat (long long int n) {
	long long int x;
	x = sqrt(n);
	if (x*x == n)
		return 1;
	else 
		return 0;
}

int provjeriFibonaccijev (long long int n) {
	if ( (provjeriSavrseniKvadrat(5*n*n + 4)==1) || (provjeriSavrseniKvadrat(5*n*n-4)==1) ) 
		return 1;
	else 
		return 0;
}

int izbaci(int* niz, int vel) {
	int i, j, v = vel;
	
	for( i = 0; i < vel; i++) {
		if(niz[i] <= 0) 
			continue;
		if(vel > 1) { 
			if(provjeriFibonaccijev(niz[i]) == 1 ) {
				for(j = i; j < vel-1; j++) 
				niz[j] = niz[j+1];
				
			i--;
			vel--;
			//printf("\nvel: %d",vel);
			}
		}
		if(vel == 1) {
			//printf("uso");
			if(provjeriFibonaccijev(niz[0]) == 1) 
				vel = 0;
			else 
				vel = 1;
			
		}
	}
//	printf("!%d!", vel);
return vel;
}

int main() {
	int niz[20], i, vel=0, velicina;
	//int niz[6] = {123, 456, 789};
	printf("Unesite niz od 10 brojeva: ");
	for( i = 0; i < 10; i++) {
		scanf("%d ", &niz[i]);
		vel++;	
	}
	
	ubaci(niz,vel);

	velicina = izbaci(niz, vel*2);
	printf("Modificirani niz glasi: ");

	for(i = 0; i < velicina; i++) {
		if(i == velicina-1)
			printf("%d.", niz[i]);
		else
			printf("%d, ", niz[i]);
	}
	return 0;
}

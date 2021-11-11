#include <stdio.h>
#include <math.h>

void ubaci(int niz[], int duzina){
	
	int pomocni[500] = {0};
	int i;
	for(i = 0; i < duzina; i++)
		pomocni[i] = niz[i];
	for(i = 0; i < duzina * 2; i++){
		if(i % 2 == 0){
			niz[i] = pomocni[i / 2];
		}
		else{
			int suma = 0, broj = niz[i-1];
			while(broj != 0){
				suma += fabs(broj % 10);
				broj /= 10;
			}
			niz[i] = suma;
		}
	}
}

int daLiJeFibonacijev(const int n){
	int prvi = 1, drugi = 1;
	if(n == 1) return 1;
	if(n < 1) return 0;
	while(prvi + drugi < n){
		int temp = prvi;
		prvi = drugi;
		drugi += temp;
	}
	return n == prvi + drugi;
}


int izbaci(int niz[], int duzina){
	int i, novaDuzina = duzina, j;
	
	for(i = 0; i < novaDuzina; i++){
		if(daLiJeFibonacijev(niz[i])){
			
			for(j = i; j < novaDuzina - 1; j++)
				niz[j] = niz[j + 1];
			i--;
			novaDuzina--;
			
		}
	}
	
	return novaDuzina;
}


int main() {
	int niz[20];
	int i, duzina;
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i < 10; i++)
		scanf("%d", &niz[i]);
	ubaci(niz, 10);
	duzina = izbaci(niz, 20);
	printf("Modificirani niz glasi:");
	for(i = 0; i < duzina; i++){
		printf(" %d%c", niz[i], i == duzina - 1 ? '.' : ',');
	}
	return 0;
}

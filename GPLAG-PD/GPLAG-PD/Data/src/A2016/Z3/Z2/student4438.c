#include <stdio.h>
#include <math.h>

int saberiCifre(int broj) {
	if(broj < 0) broj *= -1;
	if(broj >= 0 && broj <= 9) return broj;
	
	int suma = 0;
	while(broj > 0) {
		suma += broj % 10;
		broj /= 10;
	}
	return suma;
}

void ubaci(int niz[], int vel) {
	int arr[1000];
	int i;
	int tmp = 0;
	
	for(i = 0; i < vel; i++) if(niz[i] > 0) tmp = 1;
	
	if(tmp == 1) {
		for(i = 0; i < 2 * vel; i++) arr[i] = -100000;
		
		for(i = 0; i < vel; i++) {
			if(niz[i] < 0) {
				arr[2 * i] = niz[i];
				arr[2 * i + 1] = saberiCifre(niz[i]);
				continue;
			}
			
			arr[2 * i] = niz[i];
			if(i != 0) {
				arr[2 * i + 1] = saberiCifre(niz[i]);
			}
			else {
				arr[1] = saberiCifre(niz[i]);
			}
		}
		
		for(i = 0; i < 2 * vel; i++) {
			if(arr[i] != -100000) {
				niz[i] = arr[i];
			}
		}
	}
}

int isFibonacci(int broj) {
	
	int i, prvi = 0, drugi = 1, iduci;
	
	if(broj <= 0) return 0;
	
	for(i = 0; i < broj + 10; i++) {
		if (i <= 1)
         	iduci = i;
      	else
      	{
          	iduci = prvi + drugi;
         	prvi = drugi;
         	drugi = iduci;
      	}
      	if(broj == iduci) return 1;
      	else if(iduci > broj) break; 
	}
	return 0;
}

int izbaci(int niz[], int vel) {
	int i;
	int br = 0;
	int arr[1000];
	int tmp = 0;
	
	for(i = 0; i < vel; i++) if(niz[i] > 0) tmp = 1;
	if(tmp == 0) return 10;
	
	for(i = 0; i < vel; i++) {
		if(isFibonacci(niz[i]) == 1) {
			continue;
		}
		else {
			arr[br] = niz[i];
			br++;
		}
	}
	
	for(i = 0; i < br; i++) niz[i] = arr[i];
	return br;
}

int main() {
	int niz[20], niz1[10] = {9227465, -9227465, 75025, -75025, 10946, -10946, 233, -233, 13, -13};
	int i;
	int vel = 0;
	
	for(i = 0; i < 20; i++) niz[i] = 0;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i < 10; i++) {
		scanf("%d ", &niz1[i]);
		niz[i] = niz1[i];
	}
	
	ubaci(niz, 10);
	vel = izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i = 0; i < vel; i++) {
		if(i == vel - 1) printf("%d.", niz[i]);
		else printf("%d, ", niz[i]);
	}
	return 0;
}

#include <stdio.h>

int stepen(int broj, int n) {
	
	int i;
	
	if(n==0) {
		
		return 1;
	}
	
	int pomocni = broj;
	
	for(i=1; i<n; i++) {
		
		broj*=pomocni;
	}
	
	return broj;
}

int ima_cifre(int broj, int* cifre, int vel) {
	
	int i;
	
	for(i=0; i<vel; i++) {
		
		if(broj == cifre[i]) {
			
			return 1;
			
		}
	}
	
	return 0;
}

int izbaci_cifre(int* niz, int vel, int* cifre, int vel2) {
	
	int i, j;
	int pomocni, pozitivan;
	int brojac;
	
	for(i=0; i<vel2; i++) {
		
		if((cifre[i] < 0) || (cifre[i] > 9)) return 0;
		
		for(j=0; j<i; j++) 
		
			if(cifre[i] == cifre[j])	return 0;
			
	}
	
	for(i=0; i<vel; i++) {
		
		pozitivan = 1;
		pomocni = 0;
		brojac = 0;
		
		if(niz[i] < 0) {
			
			niz[i] = (-1)*niz[i];
			pozitivan = 0;
		}
		
	do {
		
		if(ima_cifre((niz[i]%10), cifre, vel2) == 0)
			
			pomocni+=stepen(10, brojac++)*(niz[i]%10);
			niz[i]/=10;

	}while(niz[i]!=0);
	
		if(pozitivan){
		
			niz[i] = pomocni;
		
		}else{
		
		niz[i] = (-1)*pomocni;
		}
	}
	
	return 1;
}


int main() {
	
	int i;
	int test[5] = {147, 2, 7200, -1593, 10};
	int cifre[5] = {0, 7, 6, 4, 1};
	
	izbaci_cifre(test, 5, cifre, 5);
	
	for(i=0; i<5; i++){
		
		printf("%d ", test[i]);
	}
	
	return 0;
}

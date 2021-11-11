#include <stdio.h>
#include <math.h>
int izbaci_cifre(int cijeli[], int vel1, int cifre[], int vel2) {
	int i = 0, j = 0, k = 0, nadeno = 0, l = 1, negativan = 0;
	int pom = 0;
	int duzine[10000] = {0};
	for(i = 0; i < vel2; i++) {
		if(cifre[i] < 0 || cifre[i] > 9)
		return 0;
	}
	for(i = 0; i < vel2-1; i++) {
		for(j = i+1; j < vel2; j++) {
			if(cifre[i] == cifre[j]) 
			return 0;
		}
	}
	for(i = 0; i < vel1; i++) {
		pom = cijeli[i];
		do {
			pom/= 10;
			duzine[i]++;
		}
		while(pom != 0);
	}
	for(i = 0; i < vel1; i++) {
		pom = 0;
		negativan = 0;
		l = 1;
		for(j = 0; j < duzine[i]; j++) {
			int c = cijeli[i] % 10;
			if(c < 0) {
				negativan = 1;
				c = -c;
			}
		for(k = 0; k < vel2; k++) {
			if(c == cifre[k])
			nadeno = 1;
		}	
		if (nadeno == 0) {
			pom += c * l;
			l *= 10;
		}
		nadeno = 0;
		cijeli[i] /=  10;
		}
		if (negativan == 1)
		pom = -pom;
		cijeli[i] = pom;
	}
	return 1;
}
	


int main() {
	int cijeli[10000] = {0}, cifre[10000] = {-1,0,1,2,3};
	int vel1 = 0, vel2 = 0;
	int i; 
	int provjera;
	printf("Unesite velicinu prvog niza: ");
	scanf("%d", &vel1);
	printf("Unesite niz cijelih brojeva: ");
	for(i = 0; i < vel1; i++) {
		scanf("%d", &cijeli[i]);
		
	}
	printf("Unesite velicinu drugog niza: ");
	scanf("%d", &vel2);
	printf("Unesite niz cifara: ");
	for(i = 0; i < vel2; i++) {
	scanf("%d", &cifre[i]);	
	}
	provjera = izbaci_cifre(cijeli, vel1, cifre, vel2);
	if(provjera == 0)
		printf("Pogresan vam je niz cifara!\n");
	printf("Niz nakon izbacenih cifara: ");
	for(i = 0; i < 10; i++) {
		printf("%d ", cijeli[i]);
	}
	return 0;
}

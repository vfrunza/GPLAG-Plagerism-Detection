#include <stdio.h>
#define EPS 0.00001 
#include <math.h>

void ubaci(int niz[], int vel) {
	int suma, i,pom1;
	int pom[20];
	for(i = 0; i < vel; i++) {
		pom[i * 2] = niz[i];
	}
	for(i = 0; i < vel ; i++) {
		suma = 0;
		if(niz[i] < 0) {
			pom1 = fabs(niz[i]);
			while(pom1 > 0) {
				suma+= pom1 % 10;
				pom1 /= 10;
			}
		}
		else {
		while(niz[i] > 0) {
				suma+=niz[i] % 10;
				niz[i] /= 10;
			}
		}
		//if(niz[i] < 0) pom[i * 2 + 1] = suma * (-1);
		 pom[i * 2 + 1] = suma;
	}
	//for(i = 0; i < 20; i++) printf("%d ", pom[i]);
	for(i = 0; i < vel * 2; i++) {
		niz[i] = pom[i];
	}
	//for(i = 0; i < vel; i++) printf("%d ", niz[i]);
}

int izbaci(int niz[], int vel) {
	//int fib[20] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946,
		//17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040};
	int i,j,k;
	int fib[80]={1,1};
	for(i = 2; i < 80; i++) fib[i] = fib[i - 1] + fib[i - 2];
	for(i = 0; i < vel; i++) {
		for(j = 0; j < 80; j++) {
			if(fabs(niz[i] - fib[j]) < EPS) {
				for(k = i; k < vel - 1; k++) {
					niz[k] = niz[k+1];
				}
				vel--;
				i--;
				break;
			}
		}
		
	}
	return vel;
}

int main() {
	int niz[20];
	int i,z;
	//int j, niz1[5]={1,34,89,46368,4181};
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i < 10; i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(niz, 10);
	//for(i = 0; i < 20; i++) printf("%d ", niz[i]);
	z = izbaci(niz, 20);
	//z=izbaci(niz1,5);
	//printf("  z=%d\n",z);
	printf("Modificirani niz glasi: ");
	for(i = 0; i < z; i++){
		if(i < z - 1) printf("%d, ", niz[i]);
		else printf("%d.", niz[i]);
	} 
	return 0;
}

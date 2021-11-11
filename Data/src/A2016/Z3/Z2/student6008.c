#include <stdio.h>
#include <math.h>

void ubaci(int niz[], int n){
	int i, j, pom, suma_cifara;
	for(i=0; i<n; i++){
		pom = niz[i];
		suma_cifara=0;
		while(pom != 0){
			suma_cifara=suma_cifara + pom%10;
			pom /= 10;
		}
		for (j = n; j > (i+1); j--) {
			niz[j] = niz[j-1];
		}
		n++;
		i++;
		niz[i]=fabs(suma_cifara);
	}
}
int izbaci(int niz[], int n){
	int i, j, k;
	int fibb[47];
	fibb[0]=1;
	fibb[1]=1;
	for(i=2; i<47; i++){
		fibb[i]=fibb[i-1]+fibb[i-2];
	}
	for(i=0; i<47; i++){
		for(j=0; j<n; j++){
			if(niz[j]==fibb[i]){
				for (k = j; k < n-1; k++)
					niz[k]=niz[k+1];
				n--;
				j--;
			}
		}
	}
	return n;
	
}

int main() {
	int i, niz[100], n;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
		scanf("%d", &niz[i]);
	
	
	ubaci(niz, 10);
	n = izbaci(niz, 20);
	
	printf("Modificirani niz glasi: ");
	
	for (i = 0; i < n-1; i++)
		printf("%d, ", niz[i]);
	printf("%d.", niz[n-1]);
	return 0;
}

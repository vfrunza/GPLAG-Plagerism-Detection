#include <stdio.h>


 void ubaci (int *niz, int n) {
	int i=0,a, cifra, suma=0, niz2[100];
	
	niz2[0]=niz[0];
	int j=2;
	for(i=1; i<n; i++) {
		niz2[j]=niz[i];
		j+=2;
	}
	
	
	j=1;
	
	for(i=0; i<n; i++) {
		
				a=niz[i];
				suma=0;
				if(a<0) a*=-1;
				while(a!=0) {
					cifra=a%10;
					suma+=cifra;
					a/=10;
					
				}
				niz2[j]=suma;
				j+=2;
				
			}

 	for(i=0; i<2*n; i++ ) niz[i]=niz2[i];
 		
 	
 }

// IZBACIVANJE

int izbaci (int *niz,int n) {
	int fib[1000], i=0, j=0, k=0;
	fib[0]=1;
	fib[1]=1;
	
	for(i=2; i<1000; i++) {
		fib[i]=fib[i-1]+fib[i-2];
	}
	
	for(i=0; i<n; i++) {
		for(j=0; j<100; j++){
			if(niz[i]==fib[j]) {
				for(k=i; k<n-1; k++) {
					niz[k]=niz[k+1];
				}
				n--;
				i--;
				break;
			}
		}
	}
	
	return n;
}

int main() {
	
	int i=0, niz[1000], n=10;
	
	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0; i<n; i++) {
		scanf("%d", &niz[i]);
	}

	ubaci(niz, n);
	n+=n;
	n=izbaci(niz, n);
	printf("Modificirani niz glasi:");
	
	for(i=0; i<n; i++) {
		printf(" %d", niz[i]);
		if(i<n-1) printf(",");
		if(i==n-1) printf(".");
	}
	
	
	return 0;
	
} 


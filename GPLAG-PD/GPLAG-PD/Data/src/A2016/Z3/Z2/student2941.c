#include <stdio.h>
#include <stdlib.h>

int zbircifara(int x) {
	
	int suma=0,k;
	if(x<0) x=abs(x);
	while(x!=0) {
		k=x%10;
		x/=10;
		suma+=k;
	}
	return suma;
	
}

void ubaci(int niz[], int k) {
	
	int i,j;
	for(i=1;i<k*2;i+=2) {
		for(j=2*k-1;j>i;j--) {
			niz[j]=niz[j-1];
		}
		niz[i]=zbircifara(niz[i-1]);
	}
}

int izbaci(int niz[], int m) {
	int Fib[47],i,j,k,br=m;
	Fib[0]=1; Fib[1]=1;
	for(i=2;i<47;i++)  {
		Fib[i]=Fib[i-1]+Fib[i-2];
	}
	for(i=0;i<m;i++) {
		for(j=0;j<47;j++) {
			if(niz[i]==Fib[j]) {
				for(k=i;k<m-1;k++) {
					niz[k]=niz[k+1];
					
				}
				i--;
				br--;
				m--;
				break;
			}
		}
	}

	
	return br;
}

int main() {
	int i,k,niz[20];
	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0;i<10;i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	k=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<k;i++) {
		if(i==k-1) printf("%d.", niz[i]);
		else printf("%d, ", niz[i]);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void ubaci(int *niz) {
	int i,m;
	for(i=19;i>=0;i--) {
		niz[i]=niz[i/2];
	}
	for(i=0;i<20;i++) {
		m=fabs(niz[i]);
		if(i%2!=0) {
			niz[i]=0;
			do {
				niz[i]=niz[i]+(m%10);
				m=m/10;
			}
			while(m>0);
		}
	}
}
int izbaci(int *niz, int m) {
	int i,j,n,fniz[1000]={0};
	for(i=2;i<1000;i++) {
		fniz[i]=fniz[i-1]+fniz[i+2];
	}
	n=m+m;
	for(i=0;i<n;i++) {
		for(j=0;j<1000;j++) {
			if(niz[i]==fniz[j]) {
				niz[i]=niz[i+1];
				niz[m-1]=1;
				n--;
				m--;
				i--;
				}
			}
		}
	return m;
}
int main() {
	int niz[20]={0},i,n=20,m=10;
	printf("Unesite niz od 10 brojeva: \n");
	for(i=0;i<10;i++) {
		scanf(" %d",&niz[i]);
	}
	ubaci(niz);
	izbaci(niz, m); 
	printf("Modificirani niz glasi: %d",niz[0]);
	for(i=1;i<n;i++) {
		if(niz[i]!=1) {
			printf(", %d", niz[i]);
		}
	}
		printf(".");
	return 0;
}

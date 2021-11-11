#include <stdio.h>
#include <math.h>

int main() {
	int n, niz[100], i, j, nizB[100]={0}, x;
	
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++) {
		scanf("%d", &niz[i]);
		if(niz[i]<0) {
			i--;
			continue;
		}
	}
	for(i=0; i<n; i++) {
		printf("%d ", niz[i]);
	}
	
	j=0;
	for (i=n-1; i>=0; i--) {
		while(niz[i]!=0) {
			x=niz[i]%10;
			nizB[j]=x;
			niz[i]/=10;
			j+=2;
		}
	}
	
	for(i=0; i<100; i++) {
		printf("%d ", nizB[i]);
	}
/*	for(i=0; i<n; i++) {
		for(j=niz[i]; j>0; j=j/10) {
			x=niz[i]%10;
			nizB[i]=x;	
			printf("%d", nizB[i]);
			}
*/
		
	
	return 0;
}

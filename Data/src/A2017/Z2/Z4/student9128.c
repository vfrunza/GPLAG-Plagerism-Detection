#include <stdio.h>

int main() {
	int m, n, matA[100][100], matB[100][100], matC[100][100], i, j, niz[1000]={0}, nizneg[1000]={0}, nizB[1000]={0}, niznegB[1000]={0}, nizC[1000]={0}, niznegC[1000]={0}, lp, x;
	do {	
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	} while(m<0 || m>100 || n<0 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &matA[i][j]);
			if(matA[i][j]<0) {
				x=matA[i][j]*(-1);
				nizneg[x]++;
			}
		    else niz[matA[i][j]]++;
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &matB[i][j]);
			if(matB[i][j]<0) {
				x=matB[i][j]*(-1);
				niznegB[x]++;
			}
			else nizB[matB[i][j]]++;
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &matC[i][j]);
			if(matC[i][j]<0) {
				x=matC[i][j]*(-1);
				niznegC[x]++;
			}
			else nizC[matC[i][j]]++;
		}
	}
	
	lp=1;
	for(i=0; i<1000; i++) {
		if(nizB[i]!=niz[i]) {
			lp=0;
			break;
		}
		if(nizC[i]!=niz[i]) {
			lp=0;
			break;
		}
		if(niznegB[i]!=nizneg[i]) {
			lp=0;
			break;
		}
		if(niznegC[i]!=nizneg[i]) {
			lp=0;
			break;
		}
	}
	
	if(lp==0) 
		printf("NE");
	 else 
	 	printf("DA");
	return 0;
}

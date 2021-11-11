#include <stdio.h>
#define DUZINA  100
#define DUZINA1 150


int main() {
	int matricaA[DUZINA][DUZINA],matricaB[DUZINA][DUZINA],matricaC[DUZINA][DUZINA];
	int elemntiA[DUZINA1]={0},elementiB[DUZINA1]={0},elementiC[DUZINA1]={0};
	int i,j,k,m,n,istinitost=1;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	} while (n<0 || n>100 || m<0 || m>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d",&matricaA[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d",&matricaB[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d",&matricaC[i][j]);
		}
	}
	
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			for(k=0;k<DUZINA1;k++) {
				
				if(matricaA[i][j]>=0) {
					if(matricaA[i][j]==k) elemntiA[k]++;
				}
				
				if(matricaB[i][j]>=0) {
					if(matricaB[i][j]==k) elementiB[k]++;
				}
				
				if(matricaC[i][j]>=0) {
					if(matricaC[i][j]==k) elementiC[k]++;
				}
				
			}
		}
	}
	
	for(i=0;i<DUZINA1;i++) {
		if(elemntiA[i]!=elementiB[i]) {
			istinitost=0;
			break;
		}
		if(elemntiA[i]!=elementiC[i]) {
			istinitost=0;
			break;
		}
	}
	
	if(istinitost) printf("DA");
	else printf("NE");
	
	return 0;
}

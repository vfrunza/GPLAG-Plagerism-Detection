#include <stdio.h>
#define DUZINA 100

int main() {
	double matricaA[DUZINA][DUZINA],matricaB[DUZINA][DUZINA];
	int n,m,p,q,i,j,slicnost=1;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m,&n);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%lf",&matricaA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&q,&p);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<p;i++) {
		for(j=0;j<q;j++) {
			scanf("%lf",&matricaB[i][j]);
		}
	}
	
	if(m!=p || n!=q) {
		printf("NE");
		return 0;
	}
	
	for(i=0;i<p;i++) {
		for(j=0;j<q;j++) {
			if(matricaB[i][j]!=matricaA[n-j-1][i]) {
				slicnost=0;
				break;
			}
			
		}
	}
	
	if(slicnost) printf("DA");
	else printf("NE");
	
	return 0;
}

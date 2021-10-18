#include <stdio.h>

int main() {
	int mA[100][100],mB[100][100],mC[100][100],fB[100][100],fC[100][100],S,V,i,j,k,l;
	do {
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&S,&V);
	}
	while(S>100 || V>100 || V<0 || S<0);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<V; i++) {
		for(j=0; j<S; j++) {
			scanf("%d",&mA[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<V; i++) {
		for(j=0; j<S; j++) {
			scanf("%d",&mB[i][j]);
			fB[i][j]=0;
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<V; i++) {
		for(j=0; j<S; j++) {
			scanf("%d",&mC[i][j]);
			fC[i][j]=0;
		}
	}
	for(i=0; i<V; i++) {
		for(j=0; j<S; j++) {
			for(k=0; k<V; k++) {
				for(l=0; l<S; l++) {
					if(mA[i][j]==mB[k][l] && fB[k][l]==0) {
						fB[k][l]=1;
						k = V;
						l = S;
					}
					
				}
			}
		}
	}
	for(i=0; i<V; i++) {
		for(j=0; j<S; j++) {
			for(k=0; k<V; k++) {
				for(l=0; l<S; l++) {
					if(mA[i][j]==mC[k][l] && fC[k][l]==0) {
						fC[k][l]=1;
						k = V;
						l = S;
					}
				}
			}
		}
	}
	for(i=0; i<V; i++) {
		for(j=0; j<S; j++) {
			if(fB[i][j]==0 || fC[i][j]==0) {
				printf("NE"); 
				return 0;
			}
		}
	}
	printf("DA");
	return 0;
}

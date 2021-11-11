#include <stdio.h>
#define A 100
#define B 100

int main() {
	int matA[A][B]={{0}}, matB[A][B]={{0}}, i=0, j=0, mA=0, mB=0, nA=0, nB=0, ispisiDA=1; 
	printf("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &mA, &nA);
	printf("Unesite clanove matrice A: ");
	for (i=0; i<mA;i++) {
		for (j=0; j<nA;j++) {
			scanf ("%d", &matA[i][j]);
		}
	}
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &mB, &nB);
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<mB; i++) {
		for (j=0;j<nB;j++) {
			scanf ("%d", &matB[i][j]);
		}	}
		
		for (i=0;i<mA;i++) {
			for (j=0;j<nA;j++) {
				if((mB==mA && nA==nB && matA[i][j]!=matB[j][mA-1-i]) || (mA*nA!=mB*nB)) {
					ispisiDA=0; break;
				}
		
			else if(mA==1 && nA==mB && nB==1) {
				if(matA[0][j]!=matB[nA-j-1][0]) {ispisiDA=0;}
			}
				
			}
		
	if (ispisiDA==0) break;
			}

		
		
		if(ispisiDA) { printf("DA\n"); }
				else { printf ("NE\n"); }
	return 0;
}


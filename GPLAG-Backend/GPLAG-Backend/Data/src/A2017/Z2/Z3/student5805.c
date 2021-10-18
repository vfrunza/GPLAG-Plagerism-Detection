#include <stdio.h>
int main() {
	int vA,sA,i,j,vB,sB;
	int A[100][100],B[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &vA, &sA);
	printf("Unesite clanove matrice A: ");
	for(j=sA-1; j>=0; j--) {
		for(i=0; i<vA; i++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &vB, &sB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<sB; i++) {
		for(j=0; j<vB; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	if(vA!=sB && sA!=vB) { printf("NE\n");
	
		return 0;
	}
	if(vA*sA!=vB*sB) { printf("NE\n");
				return 0;
			}
	for(i=0; i<vA; i++) {
		for(j=0; j<sA; j++) {
			if(A[i][j]!=B[i][j]){ printf("NE\n");
			return 0;
			}
		}
	}
 printf("DA\n");
	return 0;
}

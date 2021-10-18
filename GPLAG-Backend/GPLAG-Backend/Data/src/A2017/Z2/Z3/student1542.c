#include <stdio.h>

int main()
{

	int lA,lB,hA,hB;
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &lA,&hA);
	double A[100][100];
	int i,j;
//unos matrice A//
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<hA; i++) {
		for(j=0; j<lA; j++) {
			scanf ("%lf",&A[i][j]);
		}
	}
//unos matrice B//
		printf ("Unesite sirinu i visinu matrice B: ");
		scanf ("%d %d", &lB,&hB);
		double  B[100][100];
		printf ("Unesite clanove matrice B: ");
		for (i=0; i<hB; i++) {
			for(j=0; j<lB; j++) {

				scanf ("%lf",&B[i][j]);
			}
		}
		//završen unos matrica//
		

		
		if(hA!=lB || hB!=lA) {
			printf("NE");
			return 0;
		}

		for(i=0; i<hB; i++)
			for(j=0; j<lB; j++) {
				if(A[hA-j-1][i]!=B[i][j]) { 
					printf("NE");
					return 0;
				}
			}
		printf("DA");
		return 0;
	}

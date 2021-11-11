#include <stdio.h>

int main()
{
	int matA[100][100], matB[100][100],va,sa,vb,sb,i,j,k,r,br=0;
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &va, &sa);
	printf ("Unesite clanove matrice A: ");

	for (i=0; i<sa; i++) {
		for (j=0; j<va; j++) {
			scanf ("%d",&matA[i][j]);
		}
	}

	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &vb, &sb);
	printf ("Unesite clanove matrice B: ");

	for (k=0; k<sb; k++) {
		for (r=0; r<vb; r++) {
			scanf ("%d", &matB[k][r]);
		}
	}
	
	for (i=0; i<va; i++) {
		for (j=(sa-1); j>=0; j--){
					if ((matA[j][i]==matB[i][vb-1-j]) && (va==sb) && (sa=vb)) 
					br++;
					else{
						printf ("NE\n");
						return 1;
					}
			
	}
}

if (br==(sb*vb))
printf ("DA\n");
else
printf ("NE\n");
	return 0;
}

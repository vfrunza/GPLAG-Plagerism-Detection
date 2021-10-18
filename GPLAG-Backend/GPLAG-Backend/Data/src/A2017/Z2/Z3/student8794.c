#include <stdio.h>

int main() {
	int sirinaa, visinaa, matA[100][100], sirinab, visinab, matB[100][100], i, j, jednakesu, matC[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &sirinaa, &visinaa);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<visinaa; i++)
	{
		for (j=0; j<sirinaa; j++)
		{
			scanf("%d", &matA[i][j]);
	}
		}
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &sirinab, &visinab);
	printf ("Unesite clanove matrice B: ");
	
	for (i=0; i<visinab; i++)
	{
		for (j=0; j<sirinab; j++)
		{
			scanf ("%d", &matB[i][j]);
		}
	}
  /*Rotiranje matrice A*/
	for (i=0; i<sirinaa; i++){
		for (j=0; j<visinaa; j++){
			matC[i][j]=matA[visinaa-j-1][i]; /*Takvu rotiranu matricu A upisujemo u matricu C*/
			
		}
	}
	if (sirinaa != visinab) printf ("NE");
	else if (visinaa != sirinab) printf ("NE");
	else{
	jednakesu=1;
	/*Provjeravamo da li je matrica C (koja je rotirana A) jednaka matrici B*/
	for (i=0; i<sirinaa; i++){
		for (j=0; j<visinaa; j++){
			if (matB[i][j]!=matC[i][j]){ 
				jednakesu=0;
				break;
				
			}
			
		}
	}
	if (jednakesu==1) printf ("DA");
	else printf ("NE");
	}
	return 0;
}

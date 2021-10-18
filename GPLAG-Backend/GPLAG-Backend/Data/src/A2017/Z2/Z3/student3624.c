#include <stdio.h>

int main() {
	
	int m,n,i,j;
	int prva[10][10],druga[10][10];
	
	/*Unos prve matrice*/
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &m, &n);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			scanf ("%d", &prva[i][j]);
			
	/*Unos druge matrice*/		
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &m, &n);
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<m; i++)
        for (j=0; j<n; j++)
          scanf ("%d", &druga[i][j]);
		
	/* Rotacija prve za 90 stepeni */	
	for (i=0; i<n; i++){
		for (j=i; j<m; j++){
			int l = prva[i][j];
			prva[i][j] = prva[j][i];
			prva [j][i] = l;
		}
	}
	
	for (i=0; i<m/2; i++){
		for (j=0; j<n; j++){
			int l = prva[j][i];
			prva [j][i] = prva [j][m-1-i];
			prva [j][m-1-i] = l;
		}
	}
	
	/* Poredjenje */
	int razlicito = 0;
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			if (prva[i][j] != druga[i][j]){
				razlicito = 1;
				break;
			}
		}
		if (razlicito) break;
	}
	
	if (razlicito == 0)
	printf ("DA\n");
	else
	printf ("NE\n");
	
	return 0;
}
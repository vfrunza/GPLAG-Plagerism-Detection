#include <stdio.h>

int main() {
	double a[100][100], b[100][100], za[100][100], zb[100][100];
	int v1, s1, v2,s2;
	int i, j, g, h;
	printf ("Unesite visinu i sirinu matrice A: ");
	scanf ("%d %d", &v1, &s1);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<v1; i++){
		for (j=0; i<s1; j++)
		scanf ("%lf", &a[i][j]);
	}
	printf ("Unesite visinu i sirinu matrice B: ");
    scanf ("%d %d", &v2, &s2);
    printf ("Unesite clanove matrice B: ");
   for (i=0; i<v2; i++){
   	for (j=0; j<s2; j++)
   	scanf ("%lf", &b[i][j]);
   }
    for (i=1; i<=v1; i++){
    	for (j=1; j<=s1; j++){
    		za[i][j]=a[j][v1-i+1];
    	}
     }
    for (g=1; i<=v2; i++){
    	for (h=1; j<=s2; j++){
    		zb[g][h]=b[h][v2-g+1];
    	}
    }
    if (za[i][j]==zb[g][h])
    printf ("DA!");
    else
    printf ("NE!");
    
	return 0;
}

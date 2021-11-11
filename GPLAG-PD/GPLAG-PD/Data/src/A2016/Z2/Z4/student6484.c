#include <stdio.h>

int main() {
	int m,n;
	 int i,j;
	 int brojac=0;
	 double mat[100][100];

	do {
	    printf("Unesite M i N: ");
	    scanf("%d %d",&m,&n);
	    if (m<1 ||m>100 ||n<1 ||n>100)
	    printf ("Pogresan unos!\n");
	} while (m<1 ||m>100 ||n<1 ||n>100);

	    printf("Unesite elemente matrice: ");
        for (i=0;i<m; i++)
            for(j=0; j<n; j++)
            scanf ("%lf", &mat[i][j]);

	    for(i=0; i<m-1; i++)
	    for(j=0; j<n-1; j++)
	    if(mat[i][j] != mat[i+1][j+1]) brojac++;
	    if(brojac !=0) printf("Matrica nije ni cirkularna ni Teplicova");
	    else {
	    	for(j=0; j<m-1; j++) if(mat[j][n-1] != mat[j+1][0]) brojac++;
	    	if(brojac !=0 ) printf("Matrica je Teplicova");
	    	else printf("Matrica je cirkularna");
	    }

return 0;
}

#include <stdio.h>

int main() {
	int m, n, i, j, p=1, q=1;
	double niz[200][200];
	
	do {
	printf("Unesite M i N: ");
	scanf ("%d  %d", &m, &n);
	if(n>100 || n<=0 || m>100 || m<=0)
	printf("Pogresan unos!\n");
	}while(n>100 || n<=0 || m>100 || m<=0);
	
	
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%lf", &niz[i][j]);
		}
	}

	for(i=0; i<(m-1); i++){
		for(j=0; j<(n-1); j++){
         		if(niz[i][j]!=niz[i+1][j+1]) p=0;
	
		}
	}

    for(i=0; i<(m-1); i++){
		
         		if(niz[i][n-1]!=niz[i+1][0]) q=0;
	
		
   }
   
   if(p==1 && q==0) printf("Matrica je Teplicova");
   else if(p==1 && q==1) printf("Matrica je cirkularna");
   else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
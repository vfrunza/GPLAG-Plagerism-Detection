#include <stdio.h>
#include <math.h>
int main(){
	int i, j;
	int m,n;
	double t[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || m>100 || n<=0 || n>100){
			printf ("Pogresan unos!\n");
		}
		} while(m<=0 || m>100 || n<=0 || n>100);
		printf ("Unesite elemente matrice: ");
		for(i=0;i<m;i++){
			for (j=0;j<n;j++){
				scanf("%lf", &t[i][j]);
			}
		}
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(t[i][j]!=t[i+1][j+1]){
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
		}
	}

		for (i=0;i<m-1;i++){
			if(t[i][n-1]!=t[i+1][0]){
                printf("Matrica je Teplicova");
                return 0;
			}
		}
		printf ("Matrica je cirkularna");

	return 0;
}
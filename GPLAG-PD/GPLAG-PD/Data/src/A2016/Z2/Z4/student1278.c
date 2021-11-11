#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 0.0000000000000000000000001
int main() {
	double niz[100][100];
	int m,n,k=0,a=0,j;
	do{
		if(k>0)
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d", &m,&n);
		k++;
	}while(m<=0 || m>100 || n<=0 || n>100);
	printf("Unesite elemente matrice: ");
	k=0;
	while(k<m){
		j=0;
		while (j<n){
			scanf("%lf",&niz[k][j]);
			j++;
		}
		k++;
	}
	for(k=0;k<m-1;k++){
		for(j=0;j<n-1;j++){
			if(fabs(niz[k][j]-niz[k+1][j+1])>g){
				a++;
				break;
			}
		}
		if(a==1){
			printf("Matrica nije ni cirkularna ni Teplicova");
		}
	}
	if(a==0){
		for(k=0;k<m-1;k++){
			if(m==1){
				break;
			}
			for(j=0;j<n;j++){
				if(fabs(niz[k][n-1]-niz[k+1][0])>g){
					a++;
					printf("Matrica je Teplicova ");
					break;
				}
			}
			if(a==1){
				break;
			}
		}
		if(a==0){
			printf("Matrica je cirkularna ");
		}
	}
	return 0;
}
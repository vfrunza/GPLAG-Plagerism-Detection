#include <stdio.h>
#include <math.h>
#define epsilon 0.000000000001

int main() {
	int m,n,i,j,br=1,br1=1;
	double matrica[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &m,&n);
		if(m>0 && m<101 && n>0 && n<101) break;
		else printf("Pogresan unos!\n");
	}while(1);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++)
    	for(j=0;j<n;j++) scanf("%lf", &matrica[i][j]);
    for(i=1;i<m;i++)
        for(j=1;j<n;j++)
        	if(!(fabs(matrica[i-1][j-1]-matrica[i][j])<epsilon)) br--; 
    if(br==1){
        for(i=1;i<m;i++)
           if(!(fabs(matrica[i-1][n-1]-matrica[i][0])<epsilon)) br1--;
           if(br1==1) printf("Matrica je cirkularna");
           else printf("Matrica je Teplicova");
    } 
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
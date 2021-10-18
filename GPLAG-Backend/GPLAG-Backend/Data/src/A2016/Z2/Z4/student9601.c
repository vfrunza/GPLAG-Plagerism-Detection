#include <stdio.h>
#define EPS 0.00000001
#include <math.h>

int main() {
	double matrica[100][100];
	int m,n,i,j,istina=2;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m<=0||n<=0||m>100||n>100)
			printf("Pogresan unos!\n");
	}while(m<=0||n<=0||m>100||n>100);
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&matrica[i][j]);
		}
	}
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(fabs(matrica[i][j]-matrica[i+1][j+1])>EPS){
				istina=0;
				break;
				}
			if(fabs(matrica[i][n-1]-matrica[i+1][0])>EPS){		
				istina=1;
				break;
				}
			}
		}
	
	if((n==1&&m==1)||(m==1&&n!=1))
		printf("Matrica je cirkularna");
	 else if(n==1&&m!=1)
	 	printf("Matrica je Teplicova");
	 else if(istina==2)
		printf("Matrica je cirkularna");
	 else if(istina==1)
		printf("Matrica je Teplicova\n");
		else if(istina==0)
			printf("Matrica nije ni cirkularna ni Teplicova\n");
	return 0;
}

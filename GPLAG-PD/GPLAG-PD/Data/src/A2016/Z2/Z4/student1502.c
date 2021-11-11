#include <stdio.h>

int main() {
	int m,n;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m, &n);
		if(m<=0 || m>100 || n<=0 || n>100)printf("Pogresan unos!\n");
	}while(m<=0 || m>100 || n<=0 || n>100);
	double mat[100][100];
	int i,j;
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
	int temp=0,cirk=0;
   	for(i=0;i<m-1;i++){
   		for(j=0;j<n-1;j++){
   			
   			if(mat[i][j]!=mat[i+1][j+1])
   				temp=1;
   		}
   	}
   for(i=0;i<m;i++){
   		for(j=0;j<n;j++){
	   		if(i-1<0){}else{
	   			if(mat[i][0]!=mat[i-1][n-1])
   				cirk=1;
}
   		}
   }
/*	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
		
	}
*/	
if(temp==0 && cirk==0)printf("Matrica je cirkularna");
else
if(temp==0 && cirk==1)printf("Matrica je Teplicova");


else
printf("Matrica nije ni cirkularna ni Teplicova" );

	return 0;
}

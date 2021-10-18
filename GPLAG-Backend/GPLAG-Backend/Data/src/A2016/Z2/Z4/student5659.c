#include <stdio.h>

int main() {
	int m,n,i,j,t=1,c=1;
	double matra[100][100];
	
	do {
		printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0 || m>100 || n<=0 || n>100) printf("Pogresan unos!\n");
	}
	while(m<=0 || m>100 || n<=0 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0 ;i<m ;i++ )	{
		for(j=0 ;j<n ;j++ )  {
		scanf("%lf",&matra[i][j]);
		}
	}
		
		for(i=0 ;i<m-1 ;i++) {
			for(j=0;j<n-1;j++) {
					if(matra[i][j]!=matra[i+1][j+1]) t=0;
				}
			}
		if(t==1){
			for(i=0;i<m-1;i++){
				for(j=0;j<n;j++){
					if(matra[i][n-1]!=matra[i+1][0]) c=0;
				}
			}
		}
		if(t==0) c=0;
	if(c==1) printf("Matrica je cirkularna");
	else if(t==1) printf("Matrica je Teplicova");
	else if(t==0) printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}

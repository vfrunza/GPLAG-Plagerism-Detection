#include <stdio.h>

int main() {
	int  m=0, n=0, i=0, j=0, teplicova=1, cirkularna=1;
	double mat[100][100]={0}, prvired[100]={0}, temp=0;
	
    	
	
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || n<=0 || n>100 || m>100)
		printf("Pogresan unos!\n");
		
	}
	while(m<=0 || n<=0 || n>100 || m>100);

		
	printf("Unesite elemente matrice: ");
		for(i=0;i<m;i++) {
			for(j=0;j<n;j++) {
				
				scanf("%lf", &mat[i][j]);
				
			}
		}
	for(i=0;i<n;i++)
		prvired[i]=mat[0][i];
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++)
			if(prvired[j]!=mat[i][j]){
				cirkularna=0;
				break;
			}
		if(cirkularna==0)
			break;
		temp=prvired[n-1];
		for(j=n-2;j>=0;j--)
			prvired[j+1]=prvired[j];
		prvired[0]=temp;
	}
	if(cirkularna==0)
		for(i=0;i<m-1;i++) {
			for(j=0;j<n-1;j++) {
				if(mat[i][j]!=mat[i+1][j+1])
				teplicova=0;
			}
		}
	if(cirkularna)
		printf("Matrica je cirkularna");
	else if(teplicova)
		printf("Matrica je Teplicova");
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
		
	
	return 0;
}

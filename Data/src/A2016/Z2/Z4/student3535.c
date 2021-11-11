#include <stdio.h>

int main() {
	int M,N,i,j,tp=0,cp=0;
	int matrica[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M>100||N>100||M<=0||N<=0)
		   printf("Pogresan unos!\n");
	}while(M>100||N>100||M<=0||N<= 0);
	printf("Unesite elemente matrice: ");
	for(i=0;i<1;i++)
	{
		for(j=0;j<1;j++)
		{
			scanf("%d",&matrica[i][j]);
		}
		
	}
	if(M==1) printf("Matrica je cirkularna");
	else{
	
	for(i=0;i<M;i++)
	{
		for(j=N;j<N;j++)
		{
			if(matrica[i][j]==matrica[i+1][j+1]&&
			matrica[i][j+(N-1)]!=matrica[i+1][j])
			tp=1;
		}
	}
		

	if(tp==1&&cp==0) printf("Matrica je Teplicova");
	else if(cp==1&&tp==0) printf("Matrica je cirkularna");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	}
	
	
	return 0;
}

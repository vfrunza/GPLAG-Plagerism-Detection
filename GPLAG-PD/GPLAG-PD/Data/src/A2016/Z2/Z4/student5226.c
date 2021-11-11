#include <stdio.h>

int main() {
	int M,N,i,j,mat[100][100],cirk=0,tip=0,zadnji, prvi;

	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M>0 && M<=100 && N>0 && N<=100)
		break;
		printf("Pogresan unos!\n");
	}
	while(M<=0 || M>=100 || N<=0 || N>=100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i!=0 && j==0)
			{
				if(zadnji==mat[i][j] && tip>0) cirk++;
				else {
					cirk=0;
					break;
				}
			}
			if(i!=M-1 && j!=N-1 && mat[i][j]!=mat[i+1][j+1])
			{
				tip=0;
				cirk=0;
				break;
			}
		    if(i!=0 && j!=0 && mat[i][j]!=mat[i-1][j-1])
		    {
		    	tip=0;
		    	cirk=0;
		    	break;
		    }
		    else tip++;
		    if(j==N-1) zadnji=mat[i][j];
		   }
		
		if(tip==0) break;
		if(i!=M-1) cirk=0;
	
		
	}
	if((cirk!=0 && tip!=0)|| N==1 || M==1) printf("Matrica je cirkularna");
	else if((cirk==0 && tip!=0) || (M==1 && N!=1)) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	

	
	return 0;
}

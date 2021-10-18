#include <stdio.h>
#include<math.h>
#define broj_el 100
int main() {
	int N, M;
	int teplicova=1, cirkularna=1; 
	int i,j;
long double mat[broj_el][broj_el];
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	} while(M<=0 || M>100 || N<=0 ||N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%Lf", &mat[i][j]);
		}
	}

	for(i=0;i<M-1;i++)
	{
		for(j=0;j<N-1;j++)
		{
			if(mat[i][j]!=mat[i+1][j+1])
			
			{	teplicova=0; break; }
			
			
		}
	}
	if(teplicova)
	{
		for(i=0;i<M-1;i++)
		{
			for(j=0;j<N-1;j++)
			{
				if(mat[i][N-1]!=mat[i+1][0])
				{
					cirkularna=0;
					break;
				} 
			}
			if(j<1) { cirkularna=0; break;}
		}
		if(cirkularna) printf("Matrica je cirkularna");
		else printf("Matrica je Teplicova");
	
	}
	

	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0; }
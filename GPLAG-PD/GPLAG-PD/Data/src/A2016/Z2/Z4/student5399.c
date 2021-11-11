#include <stdio.h>
#include <math.h>
int main() {
	float mat[100][100];
	int M, N=0, i, j, C=1, T=1, a=0;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || N<=0 || M>100 || N>100)
		{
			printf("Pogresan unos!\n");
			continue;
		}
		break;
	}while(1==1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%f", &mat[i][j]);
		}
	}
	a=N;
	for(i=1;i<M;i++)
	{
		for(j=1;j<N;j++)
		{
			if((mat[i-1][a-1] != mat[i][0]) || mat[i][j] != mat[i-1][j-1])
			{
				C=0;
				break;
			}
		}
		if(C==0)break;
		if(N==1)
			{
				C=0;
				break;
			}
	}
	for(i=1;i<M;i++)
	{
		for(j=1;j<N;j++)
		{
			if(mat[i][j] != mat[i-1][j-1])
			{
				T=0;
				break;
			}
		}
		if(T==0)break;
	}
	if(C==1) printf("Matrica je cirkularna");
	else if((T==1 && C==0) || (T==1 && C==1)) printf("Matrica je Teplicova");
	else if(C==0 && T==0) printf("Matrica nije ni cirkularna ni Teplicova");
	else return 0;
	
	return 0;
}

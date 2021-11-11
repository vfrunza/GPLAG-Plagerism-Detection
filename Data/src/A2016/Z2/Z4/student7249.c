#include <stdio.h>

int main() {
	int M, N, i, j, teplicova=1, cirkularna=1;
	double MxN[100][100], KxL[100][100];
	
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	} while(M<=0 || M>100 || N<=0 || N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++) scanf("%lf", &MxN[i][j]);
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++) if(i+1<M && j+1<N && MxN[i][j]!=MxN[i+1][j+1]) teplicova=0;
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++) 
		{
			KxL[0][j]=MxN[0][j];
			if(i>0)	
			{
			KxL[i][0]=KxL[i-1][N-1];
			KxL[i][i]=KxL[i-1][i-1];
			}
			if(i+1<M && j+1<N) KxL[i+1][j+1]=KxL[i][j];
		} 
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++) 
		{
			if(KxL[i][j]!=MxN[i][j]) cirkularna=0;
		}
	}
	if(teplicova==1 && cirkularna==0) printf("Matrica je Teplicova");
	else if(cirkularna) printf("Matrica je cirkularna");
	else if(teplicova==0 && cirkularna==0) printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}

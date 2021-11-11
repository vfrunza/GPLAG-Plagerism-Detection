#include <stdio.h>

int main() 
{
	double mat[100][100];
	int i,j,M,N,indeks;
	double nizRubni[200];
	int nijeTeplicova=0;
	int nijeCirkularna=0;
	
	printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	while(M<1 || M>100 || N<1 || N>100)
	{
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
	}
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf",&mat[i][j]);
		}
	}
	
	
	
	for(i=0;i<M;i++) nizRubni[i]=mat[M-1-i][0];
	for(j=1;j<N;j++) nizRubni[M-1+j]=mat[0][j];
	
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(mat[i][j] != nizRubni[M-1-(i-j)])
			{
				nijeTeplicova=1;
				break;
			}
		}
		if(nijeTeplicova==1) break;
	}
	
	if(nijeTeplicova==0 && M==1)  nijeCirkularna=0;
	else if(nijeTeplicova==0 && N==1)  nijeCirkularna=1;	
	
	else if(nijeTeplicova==0)
	{
		for(i=(M<N)? (M-2): (N-2) ; i>=0 ; i--)
		{
			indeks=	(M<N) ? (N+i): (M+i);
			if(nizRubni[i]!=nizRubni[ indeks ])
			{
				nijeCirkularna=1;
				break;
			}
			if(nijeCirkularna==1) break;
			
		}
	}
	else nijeCirkularna=1;
	
	if(nijeCirkularna==0)    printf("Matrica je cirkularna");
	else if(nijeTeplicova==0) printf("Matrica je Teplicova");
	else  printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}

#include <stdio.h>
#include<stdlib.h>

int main() {
	int M,N;
	int i,j;
 	int cirkularna, teplicova;
 	cirkularna=1;
 	teplicova=1;
 	double m[100][100];

do
{
printf("Unesite M i N: ");
scanf("%d %d" , &M, &N);
if(M>100 || N>100 || M<=0 || N<=0) { printf("Pogresan unos!\n"); }
}while(M>100 || N>100 || M<=0 || N<=0);



printf("Unesite elemente matrice: ");
	
for(i=0 ; i<M ; i++)
	{
	for(j=0 ; j<N ; j++)
	{
		scanf("%lf" , &m[i][j]);		
	}
	}
	
	
for(i=1 ; i<M ; i++)
	{
	for(j=1 ; j<N ; j++)
	{
	 if((m[i][j]!=m[i-1][j-1]))
	 {
	 	teplicova=0;
	
	 	}
	}	
}

for(i=1 ; i<M ; i++)
	{
	
	 if((m[i][0]!=m[i-1][N-1]))
	 {
	 	cirkularna=0;
	 	break;
	 	}
	
}


if(cirkularna && teplicova)
{
	printf("Matrica je cirkularna\n");
}

else if(teplicova && cirkularna==0)
{
	printf("Matrica je Teplicova\n");
}
	
else
{
	printf("Matrica nije ni cirkularna ni Teplicova");
}
	


	return 0;
}

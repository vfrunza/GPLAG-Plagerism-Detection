#include <stdio.h>
#include <math.h>
#define EPS 0.000001
int main() {
	double mat[100][100];
	int i,j,M=0,N=0,cir=1,tep=0;
  
	do {
		printf("Unesite M i N: ");
		scanf("%d%d",&M,&N);
		if (M>100 || N>100 || M<=0 || N<=0)
		printf("Pogresan unos!\n");
		if ((N>0 && N<100)  && (M>0 && M<100))
		break;
		
	} while (M>100 || N>100 || M<=0 || N<=0);
	
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
		{
			mat[i][j]=0;
		}
	}
	printf("Unesite elemente matrice: ");
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
		{
			scanf("%lf",&mat[i][j]);
		}
	}
	for(i=2; i<M-1; i++)
	{
		for(j=1; j<N-3; j++)
		{
		   tep=0; cir=0;
		   if(fabs(mat[i][j]-mat[i+1][j+1])<EPS && fabs(mat[i][j]-mat[i-1][j-1])<EPS)
		   tep=1;
		   else 
		   tep=0;
		   if (tep==0)
		   break;
		   
		   if (tep==1 && fabs(mat[i-1][j-1]-mat[i-2][j+3])<EPS && fabs(mat[i][j]-mat[i-2][j+3])<EPS) 
		    {
		    	cir=1;
		    }
		   else  
		   cir=0;
		   if (cir==0)
		   break;
		   }
		  
		   for (i=1;i<M;i++)
		   {
		      	for (j=0;j<N;j++)
		        {	
		     	if (j==0 && tep==1)
		     	{
		        	if (fabs(mat[i][j]-mat[j][N-i])>EPS)
		        	cir=0;
		        	break;
		        }
		        }
		        }
		   if (cir==0)
		   break;
	}

	if (cir)
		printf("Matrica je cirkularna");
	else if (tep)
		printf("Matrica je Teplicova");
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}

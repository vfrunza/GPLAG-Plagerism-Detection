#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 100 
int main() {
     double mat[max][max];
     int i, j, M=0,N=0, cirk;	
     int tep=1;
	 do{
	 	printf ("Unesite M i N: ");
	 	scanf ("%d %d", &M, &N);
	 	if (M>100 || M<1 || N>100 || N<1)
	 	{
	 	printf ("Pogresan unos!\n");
	 	continue;
	 	}
	 	else
	 	break;
	 	}
	 while (1);
	printf("Unesite elemente matrice: ");
	for (i=0; i<M; i++)
	{
		for (j=0; j<N; j++)
		{
			scanf ("%lf",&mat[i][j]);
		}
	}
    
   
	for (i=0; i<M-1; i++)
	{
		for (j=0; j<N-1; j++)
		{   
			if (abs(mat[i][j]-mat[i+1][j+1])!=0)
			{
				tep=0;
			}
		}
	}
	if (tep==1)
	{
		cirk=1;
		for (i=0; i<M-1; i++)
		{
			if (abs(mat[i][N-1]-mat[i+1][0])!=0)
			     cirk=0;
		}
	}
	if(tep==1)
    {
    	if(cirk==1) printf("Matrica je cirkularna");
    	else printf("Matrica je Teplicova");
    }
	else 
	{
		printf ("Matrica nije ni cirkularna ni Teplicova");
	}
	
	
	return 0;
}

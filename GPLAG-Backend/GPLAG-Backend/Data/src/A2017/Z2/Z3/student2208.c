#include <stdio.h>

int main()
{
	int M=0, N=0, K=0, R=0, i=0, j=0, matrix[100][100], matrixB[100][100],b[100][100], tacno=0;

	 printf ("Unesite sirinu i visinu matrice A: ");
	 scanf("%d %d", &N,&M);
	 printf ("Unesite clanove matrice A: ");
	 for (i=0; i<M; i++)
	   for (j=0; j<N; j++)
	     scanf ("%d", &matrix[i][j]);
	 
	 
	 printf ("Unesite sirinu i visinu matrice B: ");
	 scanf("%d %d", &K,&R);
	 printf ("Unesite clanove matrice B: ");
	 for (i=0; i<R; i++)
	   for (j=0; j<K; j++)
	     scanf ("%d", &matrixB[i][j]);  
	     
	   
for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			b[j][M-1-i]=matrix[i][j];



	 if (R==N && K==M)    
	 {for (i=0; i<R; i++)
	  for (j=0; j<K; j++)
	   {
	   	if (b[i][j]!=matrixB[i][j]) { tacno=0; break; } else tacno=1;
	   }
	 
	 if (tacno==1) printf ("DA\n");
	   else printf ("NE\n");
	 } 
	 else printf ("NE\n");
 	     
		
	return 0;
}

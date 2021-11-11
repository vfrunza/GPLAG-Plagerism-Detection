#include <stdio.h>
#include <stdlib.h>
int main() {
	int m[200][200],M,N,i,i1,i2,i3,j,j1,j2,j3,x;
	do
	{
	  printf("Unesite brojeve M i N:");
	  scanf("%d %d",&M,&N);
	  if(M <= 0 || N <= 0 || M > 200 || N > 200)
	  printf(" Brojevi nisu u trazenom opsegu.\n");
	
	}
	while(M <= 0 || N <= 0 || M > 200 || N > 200);
	 
	printf(" Unesite elemente matrice:");
	for(i=0;i<M;i++)
    	for(j=0;j<N;j++)
			scanf("%d",&m[i][j]);
	
	for(i1=0;i1<M;i1++)
	{
		for(i2=i1+1;i2<M;i2++)
		{
	    	if (m[i1][0]==m[i2][0])
		{
			x=0;
			for(j=0;j<N;j++)
			if(m[i2][j]!=m[i1][j])
			x=1;
			if(x == 0) 
			{
				if(i2 == M-1);
				else
				{
					i3=i2;
					while(i3 < M-1){
						for(j=0;j<N;j++)
						m[i3][j] = m[i3+1][j];
						++i3;
					}
				}	M--;
				i2--;
				
			}
			
			
		}
			
		}
		
	}

for(j1=0;j1<N;j1++)
{
	for(j2=j1+1;j2<N;j2++)
	{
		if(m[0][j1] == m[0][j2])
		{
			x=0;
			for(i=0;i<M;i++)
			if(m[i][j1] != m[i][j2])
			x=1;
			if(x ==0 ) 
			{
				if(j2 == N-1);
				else
				{
					j3 = j2;
					while(j3 < N-1){
						for(i=0;i<M;i++)
						m[i][j3] = m[i][j3+1];
						++j3;
					}
				}
				N--;
				j2--;
			}
		}
	}
	
}

printf(" Nakon izbacivanja redova/kolona matrica glasi:\n");

  for(i=0;i<M;i++)
  {
  	for(j=0;j<N;j++)
  	printf("%5d",m[i][j]);
  	printf("\n");
  }
  return 0;
}
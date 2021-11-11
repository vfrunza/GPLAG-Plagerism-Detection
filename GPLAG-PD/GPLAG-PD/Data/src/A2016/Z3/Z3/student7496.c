#include <stdio.h>

int main() {
	int i,j, matr[100][100], M=0, N=0, isto=1, k, r, n, q;
	do {
		printf("Unesi brojeve M i N : ");
		scanf("%d", &M);
		scanf("%d", &N);
		if(M<0|| M>200|| N<0|| N>200){
			printf("Brojevi nisu u opsegu.\n");
			continue;
		}
		else break;
		}
		while(1);
		printf("Unesite elemente matrice:");
		for(i=0;i<M;i++)
		{
			for(j=0;j<N; j++)
			{
				scanf("%d", &matr[i][j]);
			}
		}
	for(i=1;i<M;i++)
	{
		for(r=0;r<i;r++)
		{
			isto=1;
			for(j=0; j<N;  j++)
			{
				if(matr[i][j!=matr[r][j]])
				{
					isto=0;
					break;
				}
			}
			if(isto)
			{
				for(k=i; k<M-1;k++){
					
				}
				for(j==0; j<N; j++)
				{
					matr[k][j]=matr[k+1][j];
				}
			}
			M--;
			i--;
		}
	}
}
 for(j=1; j<N; j++)
{
	for(q=0;n<M;n++)
	{
		isto=1;
		for(n==;n<M, n++)
		{
			if(matr[n][j]!=matr[n][q])
			{
				isto=0;
				break; 
			}
		}
		if (isto)
		{
			for(i=j;i<N-1;i++)
			{
				for(k=0;k<M;k++)
				{
					mat[k][i]=matr[k][i+1];
				}
			}
			N--;
			j--;
		}
			}
		}
		printf("Nakon izacivanja matrica glasi:\n");
		for(i=0;i<M;i++)
	}
	for(j=0;j<N;j++)
}
printf("%5d", matr[i][j]);
					}
					printf("\n");
				}
			
				
			
		
	
	
	return 0;
}

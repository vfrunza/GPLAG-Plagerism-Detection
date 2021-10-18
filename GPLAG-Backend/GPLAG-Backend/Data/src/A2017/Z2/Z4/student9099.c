#include <stdio.h>

int main() {
	
	int A[100][100], B[100][100], C[100][100];
	int i,j,m,n;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}while(m<0 || m>100 || n<0 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &B[i][j]);
		}
	}
		printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &C[i][j]);
		}
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			int a,b;
			int b1=0,b2=0,b3=0;
			int clan=A[i][j];
			
			for(a=0;a<m;a++)
			{
				for(b=0;b<n;b++)
				{
					if(A[a][b]==clan) b1=b1+1;
					if(B[a][b]==clan) b2=b2+1;
					if(C[a][b]==clan) b3=b3+1;
				}
			}
			
			if(b1!=b2 || b2!=b3)
			{
				printf("NE\n");
				return 1;
			}
		}
	}
	
	printf("DA\n");
	return 0;
}

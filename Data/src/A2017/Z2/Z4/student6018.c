#include <stdio.h>

int main() {
	int A[10000],B[10000],C[10000],m,n,i,j,pom;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}
	while(m<0||n<0||m>100||n>100);
	
	
	
	printf("Unesite clanove matrice A: ");
	
	for(i=0;i<m*n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	printf("Unesite clanove matrice B: ");
	
	for(i=0;i<m*n;i++)
	{
		scanf("%d",&B[i]);
	}
	
	printf("Unesite clanove matrice C: ");
	
	for(i=0;i<m*n;i++)
	{
		scanf("%d",&C[i]);
	}
	
	
	for(i=0;i<m*n-1;i++)
	{
		for(j=0;j<m*n-1-i;j++)
		{
			if(A[j]>A[j+1])
			{
				pom=A[j+1];
				A[j+1]=A[j];
				A[j]=pom;
				j--;
			}
			else if(B[j]>B[j+1])
			{
				pom=B[j+1];
				B[j+1]=B[j];
				B[j]=pom;
				j--;
			}
			else if(C[j]>C[j+1])
			{
				pom=C[j+1];
				C[j+1]=C[j];
				C[j]=pom;
				j--;
			}
		}
	}
		for(i=0;i<m*n;i++)
	{
		if(A[i]!=B[i]||A[i]!=C[i]||B[i]!=C[i])
		{
			printf("NE\n");
			return 0;
		}
	}
	printf("DA\n");
	return 0;
}

#include <stdio.h>

int main() {
	int m,n,i,k=0,j,A[100][100],B[100][100],C[100][100];
	int nizA[10000],nizB[10000],nizC[10000],pom;
	do
	{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	}
	while (m<0||m>100||n<0||n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&C[i][j]);
		}
	}
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			nizA[k]=A[i][j];
			k++;
		}
	}
	k=0;
			for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			nizB[k]=B[i][j];
			k++;
		}
	}
	k=0;
			for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			nizC[k]=C[i][j];
			k++;
		}
	}
	for(i=0;i<m*n;i++)
	{
		for(j=i+1;j<m*n;j++)
		{
			if (nizA[j]<nizA[i])
			{
				pom=nizA[i];
				nizA[i]=nizA[j];
				nizA[j]=pom;
			}
		}
	}
	for(i=0;i<m*n;i++)
	{
		for(j=i+1;j<m*n;j++)
		{
			if(nizB[j]<nizB[i])
			{
				pom=nizB[i];
				nizB[i]=nizB[j];
				nizB[j]=pom;
			}
		}
	}
	for(i=0;i<m*n;i++)
	{
		for(j=i+1;j<m*n;j++)
		{
			if(nizC[j]<nizC[i])
			{
				pom=nizC[i];
				nizC[i]=nizC[j];
				nizC[j]=pom;
			}
		}
	}
	pom=0;
	for(i=0;i<m*n;i++)
	{
		if(nizA[i]==nizB[i]&&nizA[i]==nizC[i]) pom++;
	}
	if(pom==m*n) printf("DA\n");
	else printf("NE\n");
	return 0;
}

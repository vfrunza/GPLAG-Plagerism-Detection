#include <stdio.h>

int main() {
	int a[50][50],b[50][50],n,m,n1,m1,c[50][50],s,l,i,j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&n,&m);
	printf("Unesite clanove matrice A: ");
for (i=0;i<m;i++)
{
	for (j=0;j<n;j++)
	{
		scanf("%d",&a[i][j]);
	}
}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&n1,&m1);
	printf("Unesite clanove matrice B: ");
	for (i=0;i<m1;i++)
	{
		for (j=0;j<n1;j++)
		{
		scanf("%d",&b[i][j]);
		}
	}
	
		s=n;
if (n==m1 && m==n1)
{
for (i=0;i<s;i++)
		{
			l=m-1;
			
			for (j=0;j<m;j++)
			{
				c[i][j]=a[l][i];
				l--;
			}
		
		}
		for (i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if (b[i][j]!=c[i][j])
				{
					printf("NE");
					goto n;
				}
				
			}
			
	
		}
				
}		
else printf("NE");	
		
		if(i==n && j==m) printf("DA");
n:

	return 0;
}

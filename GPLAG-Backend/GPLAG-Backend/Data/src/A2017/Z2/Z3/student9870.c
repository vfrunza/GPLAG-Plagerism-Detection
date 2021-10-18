#include <stdio.h>

int main()
{
	float A[10][10]={{0}},B[10][10]={{0}},A1[10][10];
	int i,j,n,m,n1,m1,c;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&n,&m);
		printf("Unesite clanove matrice A: ");
	   for(i=0;i<n;i++)
	   {
	   	for(j=0;j<m;j++)
	   	{
	   		scanf("%f",&A[i][j]);
	   	}
	   	  }
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&n1,&m1);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			scanf("%f",&B[i][j]);
		}
	}
for(i=0;i<n;i++)
	c=n;
	{
	for(j=0;j<m;j++)
	{
	A1[i][j]=A[c][i];
	c--;
	}
}
if(B[i][j]=A1[i][j])
{
printf("DA");
}
else printf("NE"); 
return 0;
}
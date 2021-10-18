#include <stdio.h>

int main() {
	int av,as,bv,bs,i,j,br=0,A[100][100],B[100][100],A1[100][100],A2[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&as,&av);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<av;i++)
	{
		for(j=0;j<as;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&bs,&bv);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<bv;i++)
	{
		for(j=0;j<bs;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
if(av==as&&bs==bv)
{
	for(i=0;i<as;i++)
	{
		for(j=0;j<av;j++)
		{
		A1[i][j]=A[j][i];
		}
	}
	for(i=0;i<as;i++)
	{
		for(j=av-1;j>=0;j--)
		{
			A2[i][as-1-j]=A1[i][j];
		}
	}
	for(i=0;i<bv;i++)
	{
		for(j=0;j<bs;j++)
		{
		if(A2[i][j]==B[i][j])  br++;
		}
	}
	if(br==bv*bs) printf("DA");
	else printf("NE");
}
if(av!=as&&bv!=bs&&av==bs&&as==bv&&as!=1&&av!=1&&bv!=1&&bs!=1)
{
	for(i=0;i<as;i++)
	{
		for(j=0;j<av;j++)
		{
		A1[i][j]=A[j][i];
		}
	}
	for(i=0;i<as;i++)
	{
		for(j=av-1;j>=0;j--)
		{
			A2[i][as-j]=A1[i][j];
		}
	}
		for(i=0;i<bv;i++)
	{
		for(j=0;j<bs;j++)
		{
		if(A2[i][j]==B[i][j])  br++;
		}
	}
	if(br==bv*bs) printf("DA");
	else printf("NE");
}
if(av!=bs||as!=bv) printf("NE");
	return 0;
}

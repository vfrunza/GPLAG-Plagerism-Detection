#include <stdio.h>
int main() {
	int a[100][100],b[100][100],c[100][100];
	int d=0,n=0;
	int x1,y1,x2,y2,i,j;
	int x3=0,y3=0,br=0;
	int za=0,zb=0,br1=0,br2=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&x1,&y1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<y1;i++)
	{
	for(j=0;j<x1;j++)
	{
		scanf("%d",&a[i][j]);
		za=za+a[i][j];
		br1=br1+1;
	}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&x2,&y2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<y2;i++)
	{
	for(j=0;j<x2;j++)
	{
		scanf("%d",&b[i][j]);
		zb=zb+b[i][j];
		br2=br2+1;
	}
	}
if(za!=zb || br1!=br2)
{
	printf("NE");
	return 0;
}
	for(j=0;j<x1;j++)
	{
	for(i=y1-1;i>=0;i--)
	{
		c[x3][br]=a[i][j];
		br=br+1;
	}
	y3=br;
	br=0;
	x3=x3+1;
	}
	if(x2!=x3 || y2!=y3)
	{
		n=n+1;
	}
	for(i=0;i<y2;i++)
	{
	for(j=0;j<x2;j++)
	{
		
		if(c[i][j]!=b[i][j])
		{
			printf("NE");
			return 0;
		}
	}
	}
	d=d+1;
	if(d>=n)
	{
	printf("DA");
	}
	else
	{
		printf("NE");
	}
	return 0;
}

#include <stdio.h>

int main() {
	
	int x1,x2,y1,y2;
	double a[100][100],b[100][100];
	int i,j;
	int ibool=0;
	printf("Unesite sirinu i visinu matrice A: ");scanf("%d %d",&x1,&y1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<y1;i++)
	for(j=0;j<x1;j++)
	scanf("%lf",&a[i][j]);
	
	printf("Unesite sirinu i visinu matrice B: ");scanf("%d %d",&x2,&y2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<y2;i++)
	for(j=0;j<x2;j++)
	scanf("%lf",&b[i][j]);
	
	if((y1!=x2)||(x1!=y2)){printf("NE");return 0;}
	
	for(i=0;i<y2;i++)
	for(j=0;j<x2;j++)
	{
	if(a[y1-j-1][i]!=b[i][j]){ printf("NE");return 0;}
	//printf("\na[%d][%d] %d = b[%d][%d] %d",y1-j-1,i,a[y1-j-1][i],i,j,b[i][j]);
	
	
	}	
	printf("DA");

	
	return 0;
}

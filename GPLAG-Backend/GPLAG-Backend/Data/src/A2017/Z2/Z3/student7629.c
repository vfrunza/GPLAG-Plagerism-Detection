#include <stdio.h>
int main() {
	int dimenzija1,dimenzija2,dimenzija3,dimenzija4,i,j,jednakost=1;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&dimenzija1,&dimenzija2);
	double mat[100][100],mat2[100][100],nova[100][100],r[100][100];
	printf("Unesite clanove matrice A: ");
	for(i=0;i<dimenzija1;i++)
	{
		for(j=0;j<dimenzija2;j++)
		{
			scanf("%lf",&mat[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&dimenzija3,&dimenzija4);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<dimenzija3;i++)
	{
		for(j=0;j<dimenzija4;j++)
		{
			scanf("%lf",&mat2[i][j]);
		}
	}
	for(i=0;i<dimenzija1;i++)
	{
		for(j=0;j<dimenzija2;j++)
		{
		nova[j][i]=mat[i][j];	
		
		}
	}
	for(i=0;i<dimenzija1;i++)
	{
		for(j=0;j<dimenzija2;j++)
		{
			r[i][j]=nova[i][dimenzija1-j-1];
		}
	}
	
	
	jednakost=1;
	if(((dimenzija1==dimenzija3) && (dimenzija2==dimenzija4)) || ((dimenzija1==dimenzija3) || (dimenzija2==dimenzija4)) || (dimenzija1==dimenzija2) || (dimenzija3==dimenzija4) || (dimenzija1==dimenzija4) || (dimenzija2==dimenzija3))
	{
		for(i=0;i<dimenzija1;i++)
		{
			for(j=0;j<dimenzija2;j++)
			{
				if(mat2[i][j]!=r[i][j])
				{
				jednakost=0;
			
				}
				
			}
		}
	
	if(jednakost==1)
	{
		printf("DA");
		return 0;
	}
	if(jednakost==0)
	{
		printf("NE");
	}
	}
	
	
	return 0;
}

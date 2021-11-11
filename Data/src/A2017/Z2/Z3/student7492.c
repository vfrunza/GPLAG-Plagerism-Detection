#include <stdio.h>

int main() 
{
	int matricaA[100][100]={{0},{0}}, matricaB[100][100]={{0},{0}},i,j,redA,kolA,redB,kolB,temp,uslov;
	
	/*Unosenje matrica*/
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&redA,&kolA);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<redA;i++)
	{
		for(j=0;j<kolA;j++)
		{
			scanf("%d",&matricaA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&redB,&kolB);
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<redB;i++)
	{
		for(j=0;j<kolB;j++)
		{
			scanf("%d",&matricaB[i][j]);
		}
	}
	
	/*Formiranje rotirane matrice A*/
	for(i=0;i<redA;i++)
	{
		for(j=i+1;j<kolA;j++)
		{
			temp=matricaA[i][j];
			matricaA[i][j]=matricaA[j][i];
			matricaA[j][i]=temp;
		}
	}
	
	for(i=0;i<redA;i++)
	{
		for(j=0;j<kolA/2;j++)
		{
			temp=matricaA[i][j];
			matricaA[i][j]=matricaA[i][kolA-1-j];
			matricaA[i][kolA-1-j]=temp;
		}
	}
	
	uslov=1;
	for(i=0;i<redA;i++)
	{
		for(j=0;j<kolA;j++)
		{
			if( matricaA[i][j]!=matricaB[i][j] || matricaA[j][i]!=matricaB[j][i])
			{
				uslov=0;
				break;
			}
		}
	}
	
	if(uslov==1) { printf("DA"); }
	else { printf("NE"); }
	return 0;
	
}

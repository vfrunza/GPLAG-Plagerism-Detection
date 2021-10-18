#include <stdio.h>

int max(int mat[100][100],int vis,int sir)
{
	int i,j,m,n;
	int brojac_prosli=0,brojac_novi=0,max;
	max=mat[0][0];
	
	for(i=0;i<vis;i++)
	{
		for(j=0;j<sir;j++)
		{
			brojac_novi=0;
			for(m=0;m<vis;m++)
			{
				for(n=0;n<sir;n++)
				{
					if(mat[i][j]==mat[m][n])brojac_novi++;//
				}
			}
			if(brojac_novi>brojac_prosli)
			{
				brojac_prosli=brojac_novi;
				max=mat[i][j];
			}
			else if(brojac_novi==brojac_prosli)
			{
				if(mat[i][j]<max)max=mat[i][j];//
			}
		
		}
	}
	
	return max;
	
}

int izbaci_kolone(int mat[100][100],int vis,int sir,int x)
{
	int i,j,m,n;
	int temp;
	
	for(i=0;i<vis;i++)
	{
		for(j=0;j<sir;j++)
		{
			if(mat[i][j]==x)
			{
				for(m=0;m<vis;m++)
				{
					for(n=j;n<sir-1;n++)
					{
						temp=mat[m][n];
						mat[m][n]=mat[m][n+1];
						mat[m][n+1]=temp;
					}
				}
				j--;
				sir--;
			}
		}
	}
	
	return sir;
}

int main() {
	
	int mat[100][100];
	int sir,vis,maks;
	int i,j;
	int br=1;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sir,&vis);
	
	for(i=0;i<vis;i++)
	{
		printf("Unesite elemente %d. reda: ",i+1);
	for(j=0;j<sir;j++)
	scanf("%d ",&mat[i][j]);
	}
	
	
	
		maks=max(mat,vis,sir);
		sir=izbaci_kolone(mat,vis,sir,maks);
	
	while(sir!=0)
	{
		printf("\nNakon %d. prolaza matrica glasi: \n",br);
		br++;
		for(i=0;i<vis;i++)
		{
			for(j=0;j<sir;j++)
			{
				printf("%5d",mat[i][j]);
			}
			printf("\n");
		}
		
		maks=max(mat,vis,sir);
		sir=izbaci_kolone(mat,vis,sir,maks);
	}
	
	printf("\nNakon %d. prolaza matrica je prazna!",br);
	
	
	return 0;
	
}

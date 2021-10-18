#include <stdio.h>
int max(int matrica[100][100],int visina,int sirina)
{
	int i,j,pom,br=0,k,l;
	
	for(i=0;i<sirina;i++)
	{
		for(j=0;i<visina;j++)
		{
			pom=matrica[0][0];
			if(pom!=matrica[i][j])
			{
				break;
			}
			if(pom==matrica[i][j])
			{
				br++;
			}
			pom=matrica[i][j]++;
		}}
		for(k=0;k<sirina;k++)
		{
			for(l=0;l<visina;l++)
			{
				if(pom==(pom+1))
				{
					if(pom>(pom+1))
					return (pom+1),pom;
					
				}
			}
		}
	
}
int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N)
{
	int i,j,pom_mat[100][100];
	for(i=0;i<sirina;i++)
	{
		for(j=0;i<visina;j++)
		{
			if(matrica[i][j]==N)
			{
				
			}
			
		}}
}

int main() {
	int i,j,V,S,matrica[100][100];
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d,%d",&S,&V);
	for(i=0;i<S;i++)
	{
		for(j=0;j<V;j++)
		{
			printf("Unesite elemente %d. reda:",j+1);
		  	scanf("%d",&matrica[i][j]);
		}
	}
	return 0;
}

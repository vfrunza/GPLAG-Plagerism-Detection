#include <stdio.h>
int max(int matrica[100][100],int visina,int sirina)
{
	int broj1,broj_ponavljanja1=0,broj_ponavljanja2=0,i,j,l,k;
	broj1=matrica[0][0];
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			if(broj1==matrica[i][j])
			broj_ponavljanja1++;
		}
	}
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			if(i!=0 || j!=0)
			{
				for(l=0;l<visina;l++)
				{
					for(k=0;k<sirina;k++)
					{
						if(matrica[i][j]==matrica[l][k])
						{
							broj_ponavljanja2++;
						}
					}
				}
				if(broj_ponavljanja1<broj_ponavljanja2 && broj1!=matrica[i][j])
				{
					broj1=matrica[i][j];
					broj_ponavljanja1=broj_ponavljanja2;
				}
				else if(broj_ponavljanja1==broj_ponavljanja2 && broj1!=matrica[i][j] && matrica[i][j]<broj1)
				{
					broj1=matrica[i][j];
				}
				broj_ponavljanja2=0;
			}
		}
	}
	return broj1;
}
int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N)
{
	int i,j,k,l;
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			if(matrica[i][j]==N)
			{
				for(l=0;l<visina;l++)
				{
					for(k=j;k<sirina-1;k++)
					{
						matrica[l][k]=matrica[l][k+1];
					}
				}
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}
int main() {
	int visina,sirina,i,j,matrica[100][100],a,k,l;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0;i<visina;i++)
	{
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++)
		{
			scanf("%d",&matrica[i][j]);
		}
	}
	i=0;
	a=max(matrica,visina,sirina);
	sirina=izbaci_kolone(matrica,visina,sirina,a);
	while(sirina!=0)
	{
		printf("\nNakon %d. prolaza matrica glasi: \n",i+1);
		for(l=0;l<visina;l++)
		{
			for(k=0;k<sirina;k++)
			{
				printf("%5d",matrica[l][k]);
			}
			printf("\n");
		}
		a=max(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica,visina,sirina,a);
		i++;
	}
	printf("\nNakon %d. prolaza matrica je prazna!",i+1);
	return 0;
}

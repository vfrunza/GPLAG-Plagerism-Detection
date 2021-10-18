#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,e,f;
	int broj=0;
	int najvise_ponavljanja=0;
	int izbaci = matrica[0][0];
	int minimalna_vrijednost = matrica[0][0];
	
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			for(e=0;e<visina;e++)
			{
				for(f=0;f<sirina;f++)
				{
					if(matrica[i][j]==matrica[e][f]) broj++;
				}
			}
			
			if(broj>najvise_ponavljanja)
			{
				najvise_ponavljanja=broj;
				minimalna_vrijednost=matrica[i][j];
				izbaci=matrica[i][j];
			}
			else if(broj==najvise_ponavljanja) if(matrica[i][j]<minimalna_vrijednost) izbaci=matrica[i][j];
			broj=0;
			
		}
	}
	return izbaci;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i,j,e,f,r=0;
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			if(matrica[i][j]==N)
			{
				for(e=0;e<visina;e++)
				{
					for(f=j;f<sirina;f++)
					{
						 matrica[e][f]=matrica[e][f+1];
					}
				}
				sirina--;
				j--;
			}
		}
	}
	r=sirina;
	return r;
}

int main()
{
	int mat[100][100]={0};
	int i,j,sirina,visina,r=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d%d", &sirina, &visina);
	for(i=0;i<visina;i++)
	{
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0;j<sirina;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("\n");
	while(sirina>1)
	{
		izbaci_kolone(mat,visina,sirina,max(mat,visina,sirina));
		sirina=izbaci_kolone(mat,visina,sirina,max(mat,visina,sirina));
		if(sirina==0) break;
		printf("Nakon %d. prolaza matrica glasi:\n",r+1);
		for(i=0;i<visina;i++)
		{
			for(j=0;j<sirina;j++)
			{
				printf("%5d", mat[i][j]);
			}
			printf("\n");
		}
		
		r++;
	}
	
	printf("Nakon %d. prolaza matrica je prazna!", r+1);
	
	return 0;
}














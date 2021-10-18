#include <stdio.h>


int max (int mat[100][100], int visina, int sirina)
{
	int max, pomocni_brojac, i, j, k, pomocna_varijabla, brojac;
	int niz[10000]; k=0; 
	
	for(i=0; i<visina; i++)
	{
		for(j=0; j<sirina; j++)
		{
			niz[k]=mat[i][j]; k++;
		}
	}
	
	max=niz[0]; pomocni_brojac=0;
	
	for(i=0; i<k; i++)
	{
		pomocna_varijabla=niz[i]; brojac=0;
		for(j=0; j<k; j++)
		{
			if(pomocna_varijabla==niz[j]) brojac++;
		}
		if(brojac>pomocni_brojac || (pomocna_varijabla<=max && brojac==pomocni_brojac)) {pomocni_brojac=brojac; max=pomocna_varijabla;}
	}
	return max;
}


int izbaci_kolone (int (*matrica)[100][100], int visina, int sirina, int N)
{
	int i, j, brisi, l;
	int mat[100][100];
	l=0;
	
	for(j=0; j<sirina; j++)
	{
		brisi=1;
		for(i=0; i<visina; i++)
		{
			if((*matrica)[i][j]==N) brisi=0; 
		}
		if(brisi==1)
		{
			for(i=0; i<visina; i++)
			{
				mat[i][l]=(*matrica)[i][j];
			}
			
			l++;
		}
	}
	
	
	for(i=0; i<visina; i++)
	{
		for(j=0; j<l; j++)
		{
			(*matrica)[i][j]=mat[i][j];
		}
	}
	
	return l;
}




int main() {
	int i,j, visina, sirina,a,k,b;
	int matrica[100][100];
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	
	for(i=0; i<visina; i++)
	{
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++)
		{
			
			scanf("%d", &matrica[i][j]);
		}
	}
	
	printf("\n");
	k=1;
	do
	{
		a=max(matrica, visina, sirina);
		b=izbaci_kolone(matrica, visina, sirina, a);
		sirina=b;
		if(sirina==0) printf("Nakon %d. prolaza matrica je prazna!", k);
		else
		{
			printf("Nakon %d. prolaza matrica glasi:\n", k);
			for(i=0; i<visina; i++)
			{
				for(j=0; j<sirina; j++)
				{
					if(matrica[i][j]>9 && matrica[i][j]<100)
					printf("   %d", matrica[i][j]);
					else if (matrica[i][j]>99 && matrica[i][j]<1000)
					printf("  %d", matrica[i][j]);
					else if (matrica[i][j]>999 && matrica[i][j]<10000)
					printf(" %d", matrica[i][j]);
					else if (matrica[i][j]>9999 && matrica[i][j]<100000)
					printf("%d", matrica[i][j]);
					else printf("    %d", matrica[i][j]);
				}
				printf("\n");
			}
		}
		k++;
	}while(sirina!=1 && sirina!=0);
	
	if (sirina==1) printf("Nakon %d. prolaza matrica je prazna!", k);
	return 0;
}

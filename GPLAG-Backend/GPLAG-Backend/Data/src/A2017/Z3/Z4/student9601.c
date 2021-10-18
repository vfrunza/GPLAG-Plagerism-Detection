#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int nizbrojac[1000]={0};
	int i,j,brojac=0,l,dodaj=1;
	/*Formiramo niz brojaca od svih razlicitih brojeva koji se nalaze u matrici*/
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			dodaj=1;
			for(l=0;l<brojac;l+=2)
			{
				if(matrica[i][j]==nizbrojac[l]) 
				{
					dodaj=0;
					break;
				}
			}
			if (dodaj)
			{
				nizbrojac[brojac]=matrica[i][j];
				brojac+=2;
			}
		}
	}
	/*Prebrajamo koliko se koji brojevi puta ponavljaju*/
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			for(l=0;l<brojac;l+=2)
			{
				if(nizbrojac[l]==matrica[i][j])
					nizbrojac[l+1]++;
			}
		}
	}
	/*Trazimo broj koji se najvise puta ponavlja*/
	int max=nizbrojac[1];
	int min=nizbrojac[0];
	for(i=1;i<brojac;i+=2) 
	{
		if(nizbrojac[i]>max) 
		{
			max=nizbrojac[i];
			min=nizbrojac[i-1];
		}
	}
	/*Gledamo da li postoji broj koji se ponavlja isti broj puta te uzimamo manji*/
	for(i=0;i<brojac;i+=2)
	{
		if(nizbrojac[i+1]==max)
		{
			if(nizbrojac[i]<min) min=nizbrojac[i];
		}
	}
	return min;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n)
{
	int i,j,k,l,brojac=0;
	
	/*Izbacujemo sve kolone koje sadrze broj koji smo nasli u funkciji max*/
	for(i=0;i<sirina;i++)
	{
		for(j=0;j<visina;j++)
		{
			if(matrica[j][i]==n) 
			{
				brojac++;
				for(k=0;k<visina;k++)
				{
					for(l=i;l<sirina-1;l++)
					{
						matrica[k][l]=matrica[k][l+1];
					}
				}
				if(i>0) i--;
				sirina--;
			
			}
		}
	}
	if(sirina==1)
	{
		for(i=0;i<visina;i++) if(matrica[i][0]==n) return 0;
	}
	return sirina;
}

int main() 
{
	int i,j,visina,sirina,niz[100][100],broj=1;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);

	for(i=0;i<visina;i++)
	{
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++)
		{
			scanf("%d",&niz[i][j]);
		}
	}
	printf("\n");
	while(sirina>0)
	{
		sirina=izbaci_kolone(niz,visina,sirina,max(niz,visina,sirina));
		if(sirina==0) break;
		printf("Nakon %d. prolaza matrica glasi: \n",broj);
		for(i=0;i<visina;i++)
		{
			for(j=0;j<sirina;j++)
			{
				printf("%5d",niz[i][j]);
			}
			printf("\n");
		}
		broj++;
		printf("\n");
	}
	printf("Nakon %d. prolaza matrica je prazna!",broj);


	return 0;
}

#include <stdio.h>
Funkcija vraća član matrice koji se najviše puta ponavlja. 
Ako se više članova ponavljaju jednak (najveći) broj puta, funkcija treba vratiti najmanji od tih članova.
Zatim napisati funkciju izbaci_kolone koja prima matricu (kao iznad) i jedan broj N, 
a zatim iz matrice izbacuje sve kolone u kojima se javlja član N. 

int max(int mat[100][100], int visina, int sirina)
{
	int i, j, id, jd, max_clan, testni_clan, brojac1=0, brojac2;
	
/*	if (visina==0 || sirina==0)
		return 0;*/
		
	max_clan=mat[0][0];
		
	for(i=0; i<visina; i++)
	{
		for(j=0; j<sirina; j++)
		{
			brojac2=0;
			testni_clan=mat[i][j];
			/*ponovni prolazak krzo clanove matrice zbog trazenja maksimuma*/
			for(id=0; id<visina; id++)
			{
				for(jd=0; jd<sirina; jd++)
				{
					if (mat[id][jd]==testni_clan)
						brojac2++;
				}
			}
			if (brojac2>brojac1)
			{
				max_clan=testni_clan;
				brojac1=brojac2;
			}	
			else if (brojac2==brojac1 && testni_clan<max_clan)
			{
				max_clan=testni_clan;
				brojac1=brojac2;
			}	
		}
	}
	return max_clan;
}

int izbaci_kolone(int mat[100][100], int visina, int sirina, int n)
{
	int i, j, id, jd, brojac=0, vracaj, stara_sirina;
	
	stara_sirina=sirina;
	for(i=0; i<visina; i++)
	{
		for(j=0; j<sirina; j++)
		{
			if (mat[i][j]==n)
			{
				/*pomjeranje kolona*/
				for(id=0; id<visina; id++)
				{
					for(jd=j; jd<sirina-1; jd++)
					{
						mat[id][jd]=mat[id][jd+1];
					}
				}
				sirina--;
				j--;
				brojac++;
			}
		}
	}
	vracaj=stara_sirina-brojac;
	return vracaj;
}

int main() {
	int i,j,visina,sirina,mat[100][100],vraceni_max,brojac=0,nova_sirina,salji_sirinu;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	
	for(i=0; i<visina; i++)
	{
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++)
			scanf("%d",&mat[i][j]);
	}
	printf("\n");
	salji_sirinu=sirina;
	while(1)
	{
		vraceni_max=max(mat,visina,salji_sirinu);
		nova_sirina=izbaci_kolone(mat,visina,salji_sirinu,vraceni_max);
		salji_sirinu=nova_sirina;
		brojac++;
		if (nova_sirina==0)
		{
			printf("Nakon %d. prolaza matrica je prazna!",brojac);
			break;
		}	
		else
			{
				printf("Nakon %d. prolaza matrica glasi:\n",brojac);
				for(i=0; i<visina; i++)
				{
					for(j=0; j<nova_sirina; j++)
						printf("%5d",mat[i][j]);
					printf("\n");	
				}
			}
	}
	
	return 0;
}

#include <stdio.h>






int izbaci_kolone(int matrica[100][100], int visina, int sirina)
{
	int elemenat=0;
	int brojac=0,i, j;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if (matrica[i][j]==elemenat)
				brojac=elemenat;
				
			matrica[i][j]=matrica[i-1][j];
		}
	}
	return brojac;
}



int max(int matrica[100][100], int visina, int sirina)
{
	int max, i ,j,k,g, broj, brojac,brojac1;
	max=matrica[0][0];
	brojac1=0;
	for(i=0; i<visina; i++)
	{
		
		
		for(j=0; j<sirina; j++)
		{
			brojac=0; 
			broj=matrica[i][j];
			for(k=0; k<visina; k++)
			{
				for(g=0; g<sirina; g++)
				{
					if(matrica[i][j]==matrica[k][g]) 
					brojac++;
				}
			}
			if(brojac>brojac1 || (brojac==brojac1 && broj<=max))
			{
				brojac1=brojac;
				max=broj;
			}
		}
	}
	
	
	return max;
}




int main()
{
	int matrica[100][100], visina, sirina, rez, rez1;
	printf("Unesite sirinu i visinu matrice");
	scanf("%d %d", &visina, &sirina);
	int i, j, elemenat;
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d reda", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d ", &matrica[i][j]);
		}
	}

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			printf("Nakon %d. prolaza matrica glasi: ", i+1);
			rez=max(matrica[100][100], visina, sirina);
			rez1=izbaci_kolone(matrica[100][100], visina, sirina);
			printf("%d", matrica[i][j]);
		}
		printf("\n");
	}
	printf("Nakon %d. prolaza matrica je prazna", sirina);

	return 0;
}

#include <stdio.h>
#include <math.h>
#define BROJ_EL 200
#define EPSILON 0.0001

int main() {
	int m, n, i, j, k, l, o, logic=1, a=0, b=0;
	double matrica[BROJ_EL][BROJ_EL];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if (m<=0 || n<=0 || m>200 || n>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<=0 || n<=0 || m>200 || n>200);   			/*Ovim uslovom omogucavamo da uneseni brojevi budu u odgovarajucem opsegu*/
	
	printf("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf("%lf", &matrica[i][j]);
		}
	}
	

	for (i=0; i<m-1; i++)   							
	{
		a=0;
		for (j=i+1; j<m; j++)
		{
			logic=1;									
			for (k=0; k<n; k++)
			{
				if (fabs(matrica[i][k]-matrica[j][k])>EPSILON)
				{
					logic=0;					/*Po pronalasku onog para razlicitih clanova petlja se prekine, nema potrebe za daljnjom provjerom*/
					break;
				}
			}
			
			if (logic==1)						/*Neizmjenjena logicka vrijednost znaci da su svi clanovi reda jednaki*/
			{
				for(l=j; l<m-1; l++) 
				{
					for (o=0; o<n; o++)
					{
						matrica[l][o]=matrica[l+1][o];  /*Red po red biva pomjeren preko onog reda koji biva poredjen*/
					}
				}
				a++;									/*Pamti da je doslo do izmjene dimenzije matrice*/
			}
		}
		m-=a;											/*Smanjuje se broj redova u matrici, nema potrebe za poredjenjem "izbrisanih" redova*/
	}
	
	 
	for (j=0; j<n-1; j++) 						/*Na analogan nacin se vrsi "brisanje" kolona, uz podesavanje varijabli*/
	{
		b=0;
		for (k=j+1; k<n; k++)
		{
			logic=1;
			for (i=0; i<m; i++)
			{
				if(fabs(matrica[i][j]-matrica[i][k])>EPSILON)
				{
					logic=0;
					break;
				}
			}
			
			if (logic==1)
			{
				for(l=k; l<n-1; l++)
				{
					for(o=0; o<m; o++)
					{
						matrica[o][l]=matrica[o][l+1];
					}
				}
				b++;
			}
		}
		n-=b;
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%5g", matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}

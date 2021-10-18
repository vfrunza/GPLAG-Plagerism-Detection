#include <stdio.h>

int max (int matrica[100][100], int visina, int sirina)
{
	int N,i,j,k,p,brojac,matricab[100][100],maxb;

	
	for (i=0; i<visina; i++)
	{
		for (j=0; j<sirina; j++)
		{
		
			brojac=0;
			for (k=0; k<visina; k++)
			{
				for (p=0; p<sirina; p++)
				{
					if (matrica[i][j]==matrica[k][p]) brojac++;
					
				}
			}
			matricab[i][j]=brojac;
        }
    }
	
	maxb=matricab[0][0];
	N=matrica[0][0];
	for (i=0; i<visina; i++)
	{
		for(j=0; j<sirina; j++)
		{
			if (matricab[i][j]>maxb)
			{
				maxb=matricab[i][j];
				N=matrica[i][j];
			}
			if (matricab[i][j]==maxb && matrica[i][j]<N)
			{
				N=matrica[i][j];
			}
		}
	}
	
	return N;
}

int izbaci_kolone (int matrica [100][100], int visina, int sirina, int N)
{
	int i,j,k,p,var;
	
	for (i=0; i<visina; i++)
	{
		for (j=0; j<sirina; j++)
		{
			if (matrica[i][j]==N)
			{
				if (sirina>1)
				{
				for (k=0; k<visina; k++)
				{
					for (p=j; p<sirina-1; p++)
					{
						var=matrica[k][p];
			        	matrica[k][p]=matrica[k][p+1];
				        matrica[k][p+1]=var;
					}
				
				}
				j--;
				sirina--;
			}
			else
			return 0;
			}
		}
	}
	return sirina;
	
}
int main() {
int matrica[100][100], visina,sirina,i,j,N,prolaz=1;

printf ("Unesite visinu i sirinu matrice: ");
scanf ("%d %d", &visina, &sirina);

for (i=0; i<visina; i++)
{
	printf("Unesite elemente %d. reda matrice: ", i+1);
	for (j=0; j<sirina; j++)
	{
	
		scanf ("%d", &matrica[i][j]);
	  	
	}
}

while (sirina>0)
{
N=max (matrica,sirina,visina);
sirina=izbaci_kolone(matrica,sirina,visina,N);

if (sirina!=0)
{
	prolaz++;
printf ("Nakon %d. prolaza matrica glasi:\n", prolaz);
for (i=0; i<visina; i++)
{
	for (j=0; j<sirina; j++)
	{
		printf ("%5d", matrica[i][j]); 
	}
	printf ("\n");
	
}
}

}	
printf ("Nakon %d. prolaza matrica je prazna!", prolaz);
	return 0;
}

#include <stdio.h>

int main() {
	int M, N, i, j, z, k, w, p, r, b, t, d, x, c, a, h, niz[200], niz2[200], niz3[200];
	int matrica[200][200];

	do //unos dimenzija matrice i provjera 
	{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || N<=0 || M>200 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
		
	} while(M<=0 || N<=0 || M>200 || N>200);
	
	//unos matrice 
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) 
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &matrica[i][j]);
		}
	}
	
	for(i=0; i<M; i++)
	{

		
		for(j=0; j<N; j++)
		{
			niz[j]=matrica[i][j]; 
		}
		
	

		for(t=i+1; t<M; t++)
		{
			niz2[t]=1;
		}
		for(z=i+1; z<M; z++)
		{
			for(k=0; k<N; k++)
			{
				if(niz[k]!=matrica[z][k]) //provjeravamo svaki clan niza da li je jednak clanu matrice i ako nije dodjeljujemo mu vrijednost nula umjesto jedinice 
				{
					niz2[z]=0;
				}

				
			}
		}

		
	int ch=0; //broj promijenjenih 
		for(w=i+1; w<M; w++)
		{
			if(niz2[w]==1) //ako su svi elementi isti 
			{
				if(ch>0) i++;
				ch++;
				for(r=w; r<M-1; r++)
				{
					for(p=0; p<N; p++)
					{
						matrica[r][p]=matrica[r+1][p]; //izbacivanje reda matrice tako sto prepisemo naredni u taj koji zelimo izbaciti 
					}
				niz2[r]=niz2[r+1];	
				}
			
			M--; //smanjuje se dimenzija jer smo izbacili red 
			i--; //smanjuje se broj indeksa takodjer zbog izbacivanja 
			}
		}
	}
	
//provjera kolona na isti nacin kao sto smo provjeravali i redove 
for(j=0; j<N; j++)
{
		
		for(i=0; i<M; i++)
		{
			niz[i]=matrica[i][j];
		}
		
	
		
		for(h=j+1; h<N; h++)
		{
			niz3[h]=1; //niz jedinica koji cemo po potrebi prebacivati u nule nakon provjere da li su clanovi isti 
		}
		
	
	
	    for(a=j+1; a<N; a++)
	    {
		for(b=0; b<M; b++)
		{
			if(niz[b]!=matrica[b][a]) //da li je clan niza jednak clanu matrice 
			{
				niz3[a]=0; //umjesto jedinica u nizu smo stavili nule jer clanovi nisu isti 
			}
		}
	    }
	int ch=0;
	for(x=1+j; x<N; x++)
	{
		if(niz3[x]==1)
		{
			if(ch>0) j++;
			ch++;
			
			for(d=x; d<N-1; d++)
			{
				for(c=0; c<M; c++)
				{
					matrica[c][d]=matrica[c][d+1]; //prepisivanje naredne kolone u prethodnu 
				}
				niz3[d]=niz3[d+1];
			}
			N--; //smanjenje dimenzije kolona matrice 
			j--; //smanjenje indeksa kolone 
		}
	}
}
	
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%5d", matrica[i][j]); //ispis matrice nakon izbacivanja sa 5 mjesta rezervisanih u memoriji 
		}
		printf ("\n"); //nakon svakog ispisanog reda matrice prebacujemo u novi red 
	}
	
	
	
	
	
	
	
	return 0;
	
	
}

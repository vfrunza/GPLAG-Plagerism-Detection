#include <stdio.h>


int main()
{
	int matrica[200][200];
	int i,j,k,x;
	int M,N;
	int isto=1;
	
	printf("Unesite brojeve M i N: "); /*unos broja vrsta i kolona matrice*/
	do {
		scanf("%d %d", &M, &N);
		if(M<=0 || N<=0 || M>200 || N>200) {
			printf("Brojevi nisu u trazenom opsegu.");
			printf("\nUnesite brojeve M i N: "); /*dati opseg*/
		}

	} while(M<=0 || N<=0 || M>200 || N>200);

	printf("Unesite elemente matrice: "); /*unos matrice*/
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}


/* izbacivanje duplih vrsta */
x=1; /* krecemo od vrste sa indeksom 1 jer ona sa indeksom nula nema iznad sebe vrstu koji se ponavlja*/


for(i=1;i<M;i++) /*idemo po vrstama*/
{
	for(j=i-1;j>=0;j--) /*gledamo sve vrste iznad i-te vrste*/
	{
		isto=1; /*pretpostavka da su te vrste jednake*/
		for(k=0;k<N;k++) /* imamo vrste i,j, sada idemo po njihovim kolonama*/
		{
			if(matrica[i][k]!=matrica[j][k]) /*dokaz da nisu iste*/
			{
			isto=0;
			break;
			}
		}
		
	if(isto) break; /*ako su iste prekidamo potragu,a inace trazimo dalje*/
	}
	
if(!isto)
{
	for(k=0;k<N;k++) matrica[x][k]=matrica[i][k]; /*ako nisu iste, upisujemo tu vrstu na mjesto x, u suprotnom je preskacemo*/
	x++; /*sljedeci slobodan indeks*/
}
}

M=x; /*broj vrsta nove matrice*/


/* izbacivanje duplih kolona*/
x=1; /* krecemo od kolone sa indeksom 1*/

for(i=1;i<N;i++) /*idemo po kolonama*/
{
	for(j=i-1; j>=0;j--) /* gledamo sve kolone lijevo od i-te kolone*/
	{
		isto=1; /*pretpostaka da su te kolone jednake*/
		for(k=0;k<M;k++) /*imamo kolone i,j , sada idemo po vrstama tih kolona*/
		{
			if(matrica[k][i]!=matrica[k][j]) /*dokaz da kolone nisu jednake*/
			{
				isto=0;
				break;
			}
		}
		
	if(isto) break; /*ako su iste prekidamo petlju*/
	}
	
if(!isto) {
	for(k=0;k<M;k++) matrica[k][x]=matrica[k][i]; /*ako nisu iste, kolonu upisujemo na mjesto x,inace je preskacemo*/
	x++; /*sljedeci slobodan indeks*/
}
}

N=x; /*broj kolona nove matrice*/


printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
for(i=0;i<M;i++)
{
	for(j=0;j<N;j++)
	{
		printf("%5d", matrica[i][j]); /*nova matrica*/
	}
	
printf("\n");
}
return 0;
}

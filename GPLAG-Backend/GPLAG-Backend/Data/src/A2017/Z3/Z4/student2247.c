#include <stdio.h>

int max (int matrica[100][100], int visina, int sirina)
{
	int matPonavljanja[100][2]={0}, jelSePonavlja=0, brojac=0;
	int i, j, k;
	int maxIndeks=0, maxBroj=0;
	
	/*prolazimo kroz matricu koju je korisnik unio*/
	
	for (i=0; i<visina; i++)
	{
		for (j=0; j<sirina; j++)
		{
			/*Provjeravamo da li se element iz matrice koju je korisnik unio nalazi u novoj matrici
			odnosno matPonavljanja[k][0], pretpostavimo da se ne nalazi*/
			jelSePonavlja=0;
			for (k=0; k<brojac; k++)
			{
			
				if (matrica[i][j]==matPonavljanja[k][0])
				{
					jelSePonavlja=1;
					matPonavljanja[k][1]++;
				}
			}
			/*ukoliko se element matrice koju je korisnik unio ne nalazi u novoj matrici
			odnosno matPonavljanja[k][0] dodajemo ga u tu matricu i povecavamo brojac
			da bi se novi element koji se ne nalazi u novoj matrici smjestio u novi red */
			if (jelSePonavlja==0){
				matPonavljanja[brojac][0]=matrica[i][j];
				matPonavljanja[brojac][1]=1;
				brojac++;
			}
		}
	}
	/*Provjeravamo da li postoje brojevi koji se ponavljaju isti broj puta koji je ujedno i najveci broj puta*/
	for (i=0; i<brojac; i++){
		if (matPonavljanja[i][1]>matPonavljanja[maxIndeks][1]){
			maxIndeks=i;
			
		}		
	}
	maxBroj=matPonavljanja[maxIndeks][1];
	/*Ukoliko postoje brojevi koji su se pojavili isti broj puta i ujedno najvci broj puta,
	program po uslovu zadatka treba vratiti najmanji broj od tih brojeva*/
	for (i=0; i<brojac; i++){
		if (maxBroj==matPonavljanja[i][1] && matPonavljanja[i][0]<matPonavljanja[maxIndeks][0]){
			maxIndeks=i;
		}
	}
	return matPonavljanja[maxIndeks][0];
}

int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N)
{
	int i, j, k, jelSeNalaziUKoloni=0;
	
	for (j=0; j<sirina; j++)
	{
		jelSeNalaziUKoloni = 0;
		for (i=0; i<visina; i++)
		{
			if(N == matrica[i][j]) jelSeNalaziUKoloni=1;
		}
		if(jelSeNalaziUKoloni==1){
			i=0;
			for(k=j;k<sirina-1;k++){
				for(i=0;i<visina;i++){
					matrica[i][k]=matrica[i][k+1];
				}
				
				
			}
			sirina--;
			j--;
			
		}
	}
/*	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			printf("%d ",matrica[i][j]);
		}
		printf("\n");
	}*/
	return sirina;
}


int main(void) {
	int sirina, visina, matrica[100][100];
	int i, j, br_kolona, N;
	printf("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d", &sirina, &visina);
	for (i=0; i<visina; i++)
	{
		printf ("Unesite elemente %d. reda: ", i+1);
		
		for (j=0; j<sirina; j++)
			scanf ("%d", &matrica[i][j]);
		
	}
	/*br_kolona = izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));

	while(br_kolona!=0){
		printf ("Matrica nakon prvog prolaza glasi: ");
    for(i=0;i<visina;i++){
    	for(j=0; j<sirina; j++){
    		
    		printf("%4d ",matrica[i][j]);
    	}
    	printf("\n");
    }
	izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
	}
   printf ("%d", max(matrica, visina, sirina));
   izbaci_kolone(matrica,visina,sirina,2);*/
	return 0;
}

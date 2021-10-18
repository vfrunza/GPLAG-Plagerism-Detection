/*3. (0,5 bodova) Najprije treba omogućiti korisniku da unese matricu proizvoljnih dimenzija MxN. Korisnik najprije unosi prirodne brojeve
M i N koji su manji ili jednaki 200. Petljom do-while treba osigurati da su brojevi u traženom opsegu. Nakon toga, unose se elementi 
matrice.


Nakon unosa, program treba izbaciti iz matrice sve redove koji se ponavljaju (svi elementi redova su jednaki) tako da u matrici ostane
samo prvi odozgo takav red. Nakon toga treba izbaciti i sve kolone koje se ponavljaju, tako da u matrici ostane samo prva slijeva takva 
kolona. Konačno treba ispisati tako promijenjenu matricu.


Pri rješavanju obavezno koristiti izbacivanje redova/kolona iz matrice uz očuvanje redoslijeda! Rješenja u kojem suvišni redovi/kolone 
budu samo preskočeni prilikom ispisa na ekran biće bodovana sa 0 bodova.


Primjer ulaza i izlaza:
	Unesite brojeve M i N: 50 205
	Brojevi nisu u trazenom opsegu.
	Unesite brojeve M i N: -4 5
	Brojevi nisu u trazenom opsegu.
	Unesite brojeve M i N: 4 4
	Unesite elemente matrice:
	1 2 3 2
	4 5 6 5
	1 2 3 2
	7 8 9 8
	Nakon izbacivanja redova/kolona matrica glasi:
	    1    2    3
	    4    5    6
	    7    8    9
*/



#include <stdio.h>

int main() {
	int M,N,i,j,MAT[200][200],isti,s=0,l=0;
	do {
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M,&N);
			if(M>200 || M<=0 || N>200 || N<=0)
				printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while (M>200 || M<=0 || N>200 || N<=0);
	
	printf("Unesite elemente matrice: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++) {
			scanf("%d", &MAT[i][j]);
		}
	}

for(i=0;i<M-1;i++){
		for(j=i+1; j<M; j++){
		int	isti=1;	s=0;
				for (s=0; s<N; s++)
					if(MAT[i][s]!=MAT[j][s]){
						isti=0;
						
					}
					if (isti==1){
								for (s=j; s<M-1;s++){
									for (l=0;l<N;l++)
								
									MAT[s][l]=MAT[s+1][l];}
									M--;
									i--;
									
									
						}
						
					
				}
		}	

for(i=0;i<N-1;i++){
		for(j=i+1; j<N; j++){
		int	isti=1;	s=0;
				for (s=0; s<M; s++)
					if(MAT[s][i]!=MAT[s][j]){
						isti=0;
							
					}
					if (isti==1){
								for (s=j; s<N-1;s++){
									for (l=0;l<M;l++)
								
									MAT[l][s]=MAT[l+1][s];}
									N--;
									j--;
									
									
						}
						
					
				}
		}	




printf("Nakon izbacivanja redova/kolona matrica glasi:\n");

	for (i=0; i<M; i++){
		for (j=0; j<N; j++) {
			printf("%5d", MAT[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

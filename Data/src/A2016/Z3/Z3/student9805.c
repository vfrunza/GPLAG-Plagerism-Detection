#include <stdio.h>

int main() {
	int matrica[200][200],M,N,red,kolona,pocetnired,pocetnakolona,jednakost,zavrsni;
	do{
		printf("Unesite brojeve M i N:");
		scanf("%d %d",&M,&N);
		if (M<=0 || M>200 || N<=0 || N>200){
			printf (" Brojevi nisu u trazenom opsegu.\n");
			continue;
		}
	} while (M<=0 || M>200 || N<=0 || N>200);
	printf (" Unesite elemente matrice: ");
	for (red=1;red<=M;red++){
		for (kolona=1;kolona<=N;kolona++){
			scanf ("%d",&matrica[red][kolona]);
		}
	}
	for (pocetnired=1;pocetnired<=M;pocetnired++){
		for(red=pocetnired+1;red<=M;red++){
			//Uslov za jednakost redova//
			jednakost=1;
			for(kolona=1;kolona<=N;kolona++){
				if (matrica[pocetnired][kolona]!=matrica[red][kolona]) jednakost=0;
			}
			//izbacivanje reda uz ocuvanje redoslijeda//
			if (jednakost) {
				for(zavrsni=red;zavrsni<=M;zavrsni++){
					for(kolona=1;kolona<=N;kolona++){
						matrica[zavrsni][kolona]=matrica[zavrsni+1][kolona];
					}
				}
				red--;
				M--;
			}
		}
	}

	for (pocetnakolona=1;pocetnakolona<=N;pocetnakolona++){
		for(kolona=pocetnakolona+1;kolona<=N;kolona++){
			//uslov za jednakost kolone//
			jednakost=1;
			for(red=1;red<=M;red++){
				if (matrica[red][pocetnakolona]!=matrica[red][kolona]) jednakost=0;
			}
			if (jednakost) {
				//izbacivanje kolone uz ocuvanje redoslijeda//
				for(red=1;red<=M;red++){
					for(zavrsni=kolona;zavrsni<=N;zavrsni++){
						matrica[red][zavrsni]=matrica[red][zavrsni+1];
					}
				}
				kolona--;
				N--;
			}
		}
	}
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (red=1;red<=M;red++){
		printf (" ");
		for (kolona=1;kolona<=N;kolona++){
			printf("%4d ", matrica[red][kolona]);
		}
		printf ("\n");
	}
	return 0;
}

#include <stdio.h>

int main() {
	int mat[200][200]={{0}}, tp[200][200], m, n, br, i, j, k, l, a, x;
	
	/* Unos dimenzija matrice */
	while(1){
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		
		/* Provjera pripadnosti intervalu [0,200] */
		if((m<1 || m>200) || (n<1 || n>200)) {
			printf("Brojevi nisu u trazenom opsegu.\n");
			continue;
		}
		
		break;
	}
	
	/* Unos elemenata matrice */
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	
	/* Za Redove */
	for(i=0; i<m; i++){
		/* Poredi se sa X, koje je za 1 vece tako da ne detektuje i obrise samo sebe */
		x=i+1;
		while(x<m){
			br=0;
			for(j=0; j<n; j++){
				/* Da ne izadje van opsega niza u neinicijalizirane */
				if(i!=m-1){
					/* Ako su clanovi isti, inkrementuje se brojac */
					if(mat[i][j]==mat[x][j]){
						br++;
						/* Ako su SVI clanovi isti, onda je brojac jednak ukupnom broju clanova reda, tj. jednak je broju kolona */
						if(br==n){
							/* Zamjena clanova i brisanje reda */
							for(k=x; k<m; k++){
								for(l=0; l<n; l++){
									mat[k][l]=mat[k+1][l];
								}
							}
						/* X se vraca na i tako da k=x bude ispravno */
						x=i;
						/* Smanjujemo broj redova jer smo obrisali jedan */
						m--;
						}
					}
				}
			}
		/* Inkrementuje se X tako da prolazi kroz ostatak matrice */
		x++;
		}
	}
	
	
	/* Za Kolone */
	for(j=0; j<n; j++){
		/* Da ne izadje van opsega niza u neinicijalizirane */
		if(j!=n-1){
			/* Poredi se sa X, koje je za 1 vece tako da ne detektuje i obrise samo sebe */
			x=j+1;
			while(x<n){
				/* Moraju im prvi clanovi biti isti tako da bi svi bili isti */
				if(mat[0][j]==mat[0][x]){
					br=0;
					for(k=0; k<m; k++){
						/* Ako su clanovi isti, inkrementuje se brojac */
						if(mat[k][j]==mat[k][x]){
							br++;
							/* Ako su SVI clanovi isti, onda je brojac jednak ukupnom broju clanova kolone, tj. jednak je broju redova */
							if(br==m){
								/* Zamjena clanova i brisanje kolone */
								for(a=0; a<m; a++){
									for(l=x; l<n; l++){
										mat[a][l]=mat[a][l+1];
										/* Specijalni slučaj kada imamo samo jedan red */
										if(m==1) x=j;
									}
								}
							/* Smanjujemo broj kolona jer smo obrisali jednu */
							n--;
							}
						}	
					}
				}
				/* Inkrementuje se X tako da prolazi kroz ostatak matrice */
				x++;
			}
		}
	}
	
	/* Ispis */
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
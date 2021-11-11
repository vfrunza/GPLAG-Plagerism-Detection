#include <stdio.h>

int main() {
	int M,N,i,j,k,matrica[200][200],brojac=0,isticlan=0,z,t;
	/*Petlja koja omogucava unos dimenzija matrice u trazenom opsegu*/
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&M,&N);
		if (M>200 || N>200 || M<=0 || N<=0) printf("Brojevi nisu u trazenom opsegu.\n");
	}while (M>200 || N>200 || M<=0 || N<=0);
	printf("Unesite elemente matrice: ");
	/*Unos elemenata matrice*/
	for (i=0;i<M;i++)
	     for (j=0;j<N;j++)
	          scanf("%d",&matrica[i][j]);
	/*While petlja koja izbacuje redove sa istim clanovima izuzev prvog takvog reda*/
	while (1){
		isticlan=0;
		for(i=0;i<M;i++){ /*petlje 'i' i 'k' prolaze kroz redove matrice*/
		    for(k=i+1;k<M;k++){
		     	for (j=0;j<N;j++){ /*petlja 'j' prolazi kroz kolone matrice*/
		     		if (matrica[i][j]==matrica[k][j]) brojac++; /*trazenje istih clanova u redovima matrice*/
		     	}
		     	if (brojac==N){ /*ako je brojac jednak broju kolona to znaci da red 'k' ima sve iste clanove kao i red 'i' */
		     		isticlan=1;
		     		/*izbacivanje reda iz matrice*/
		     		for (z=k;z<M-1;z++){
		     		     for(t=0;t<M;t++){
		     		         matrica[z][t]=matrica[z+1][t];
		     		     }
		     		}
		     		M=M-1;
		     	}
		     	brojac=0;
		     }
	    }
	if (isticlan==0) break;
	}
	/*potpuno isti postupak se ponavlja pri izabcivanju redova matrice sa istim clanovima*/
		while (1){
			isticlan=0;
		for(j=0;j<N;j++){
		    for(k=j+1;k<N;k++){
		     	for (i=0;i<M;i++){
		     		if (matrica[i][j]==matrica[i][k]) brojac++;
		     	}
		     	if (brojac==M){
		     		isticlan=1;
		     		for (z=k;z<N-1;z++){
		     		     for(t=0;t<M;t++){
		     		         matrica[t][z]=matrica[t][z+1];
		     		     }
		     		}     
		     		N--;
		     	}
		     brojac=0;
	    	}
		}
	    if (isticlan==0) break;
		}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i=0;i<M;i++){
	     for (j=0;j<N;j++)
	          printf("%5d",matrica[i][j]);
	                 printf("\n");}
	return 0;
}

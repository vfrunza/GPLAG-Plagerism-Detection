#include <stdio.h>

/*Funkcija trazi iste clanove uporedjujuci dva niza*/
int isti (int niz1[],int niz2[],int vel) {
	int i;
	for (i=0; i<vel;i++) {
		if(niz1[i]!=niz2[i]) return 0;
	}
	return 1;
}


int main() {
	int M,i,j,N,p,k=0,mat[200][200],niz[40000];
	/*Uvodim niz, jer cu raditi tako da sve elemente,red po red,smjestim u jedan niz*/
	/*Niz ima max 40000 elemenata, jer matrica moze imati max 200 kolona i 200 redova*/
	/*Unos visine i sirine matrice*/
	do {
		printf("\nUnesite brojeve M i N: ");
		scanf("%d %d",&M, &N);
		if (M<0 || M>200 || N<0 || N>200) {
			printf("Brojevi nisu u trazenom opsegu.");
		}
	} while (M<0 || N<0 || M>200 || N>200);
	int vel=M*N;
	
	/*Unos elemenata matrice*/
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &mat[i][j]);
		}
	
	}
	
	k=0;
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			niz[k++]=mat[i][j];
		}
	}
	
	for (i=0;i<vel;i+=N) {
		for (j=i+N;j<vel;j+=N) {
			if (isti(niz+i,niz+j,N)==1) {
				/*izbacivanje*/
				for (p=j;p<vel-N;p++) {
					niz[p]=niz[p+N];
					
				}
				vel-=N;
				M--; /*za matricu*/
				j-=N;
			}
		}
	}
	k=0;
	/*vracanje u matricu*/
	for(i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			mat[i][j]=niz[k++];
		}
	}
	
	int ista=0,o,r;
	i=0;
	for(i=0;i<N;i++) {
		for (j=i+1;j<N;j++) {
			ista=0;
			for (r=0;r<M;r++) {
				if(mat[r][i]!=mat[r][j]) ista++;
			}
			if (ista==0) {
				/*izbacivanje*/
				for (p=j;p<N-1;p++) {
					for (o=0;o<M;o++) {
						mat[o][p]=mat[o][p+1];
						
					}
				}
				N--;
				j--;
			}
		}
		
	}
	
	
	/*Ispis programa*/
	printf("Nakon izbacivanja redova/kolona matrica glasi: ");
	printf("\n");
	for(i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}

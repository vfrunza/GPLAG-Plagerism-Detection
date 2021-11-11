#include <stdio.h>

int main() {

int M,N,i,j,k,s,t,m,n,mat[200][200],izbacivanje;

/* Unos i provjera ispravnosti dimenzija matrice */

do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	if(M>200 || N>200 || M<1 || N<1)
	printf("Brojevi nisu u trazenom opsegu.\n");
}
while(M>200 || N>200 || M<1 || N<1);

printf("Unesite elemente matrice: ");
for(i=0; i<M; i++){
	for(j=0; j<N; j++){
		scanf("%d", &mat[i][j]);
	}
}

/* Provjeravamo da li se kolone u matrici ponavljaju, ukoliko se ponavljaju izbacujemo ih */
/* Nakon izbacivanja smanjujemo dimenziju matrice */

for(i=0; i<N-1; i++){
	for(j=i+1; j<N; j++){
		izbacivanje=1;
		for(k=0; k<M; k++){
			if(mat[k][i]!=mat[k][j])
			izbacivanje=0;
			break;
		}
		if(izbacivanje==1){
			for(s=j; s<N-1; s++){
				for(t=0; t<N; t++){
					mat[t][s]=mat[t][s+1];
					}
				}
				N--;
				j--;
			}
		}
}
/* Izbacivanje redova koji se ponavljaju u matrici */
/* Smanjivanje dimenzije */

for(i=0; i<M; i++){
	for(j=0; j<M; j++){
		izbacivanje=1;
		if(j==i)
		continue;
		for(k=0; k<N; k++){
			if(mat[i][k]!=mat[j][k]){
			izbacivanje=0;
			break;
		}
	}
	
	if(izbacivanje==1){
		for(m=j; m<M-1; m++){
			for(n=0; n<N; n++){
				mat[m][n]=mat[m+1][n];
			}
		}
		j--;
		M--;
	}
}
}

/* Ispisivanje matrice */ 

printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
for(i=0; i<M; i++){
	for(j=0; j<N; j++){
		printf("%5d", mat[i][j]);
	}
	printf("\n");
}

return 0;
}
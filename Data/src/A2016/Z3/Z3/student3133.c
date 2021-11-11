#include <stdio.h>

int main() {
	int mat[200][200], i, j, k, l, m, M, N, jednaki=1;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0||M>200||N<=0||N>200) printf("Brojevi nisu u trazenom opsegu.\n");
		else break;
	} while(M<=0||M>200||N<=0||N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0;i<M-1;i++){
		for(j=i+1;j<M;j++){
			jednaki=1;
			for(k=0;k<N;k++) //ova petlja provjerava da li su redovi jednaki po principu da gleda n-ti i n-ti clan dva reda, ako bar jedan par nije jednak logicka varijabla postaje 0
				if(mat[i][k]!=mat[j][k]){ 
					jednaki=0;
					break;
				}
			
			if(jednaki) { //ako jesu jednaki red se izbacuje
				for(l=j+1;l<M;l++)
					for(m=0;m<N;m++)
						mat[l-1][m]=mat[l][m];
				M--;
				j--;
			}
		}
	}
	for(i=0;i<N-1;i++){
		for(j=i+1;j<N;j++){
			jednaki=1;
			for(k=0;k<M;k++) //istim principom se provjerava jednakost kolona
			if(mat[k][i]!=mat[k][j]){
				jednaki=0;
				break;
			}
			if(jednaki){ //ako jeste desava se izbacivanje
				for(l=j+1;l<N;l++)
				    for(m=0;m<N;m++)
				       mat[m][l-1]=mat[m][l];
				       N--;
				       j--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d", mat[i][j]); //ispisivanje matrice
		}
		printf("\n");
	}
	return 0;
}

#include <stdio.h>

int main() {
	int M,N,mat[200][200],i,j,k,m,visak,visak1,br=0,br1=0,niz[100]={-1},niz1[100]={-1};
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&M,&N);
		if(M<=0 || M>200 || N<=0 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(M<=0 || M>200 || N<=0 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) 
		for(j=0;j<N;j++)
		scanf("%d",&mat[i][j]);
	//prebrojavanje jednakih redova i smijestanje indexa tih redova u niz
	for(i=0;i<M;i++) {
		if(M==1) break;
		for(m=0;m<br;m++)
			if(niz[m]==i) break;
		if(niz[m]==i)	continue;
		for(k=1;k<M;k++) {
			if((i+k)>=M) break;
			for(j=0;j<N;j++) {
				if(mat[i][j]!=mat[i+k][j]) break;
 				else if(j==(N-1) ) {visak=(i+k); niz[br]=visak; br++;} 
			}
		}
	}
	//prebrojavanje jednakih kolona i smijestanje indexa tih kolona u niz
	for(j=0;j<N;j++) {
		for(m=0;m<br1;m++)
			if(niz1[m]==j) break;
		if(niz1[m]==j)	continue;
		for(k=1;k<N;k++) {
			if((j+k)>=N) break;
			for(i=0;i<M;i++) {
				if(mat[i][j]!=mat[i][j+k]) break;
 				else if(i==(M-1) ) {visak1=(j+k); niz1[br1]=visak1; br1++;} 
			}
		}
	}

	//izbacivanje redova
	if(N>1) {
		for(k=0;k<br;k++) {
			for(j=0;j<N;j++)
				mat[niz[k]][j]=mat[M-1][j];
			M--;
		}
	}
	//izbacivanje kolona
	if(M>1) {
		for(k=0;k<br1;k++) {
			for(i=0;i<M;i++)
				mat[i][niz1[k]]=mat[i][N-1];
			N--;
		}
	}
	//izbacivanje redova za kolona matricu 
	if(N==1) {
		for(k=0;k<br;k++) {
			for(j=0;j<N;j++)
				mat[niz[k]][j]=mat[niz[k+1]][j];
			M--;
	
		}
		mat[M-1][0]=(mat[M-1][0]+1);
	}
	//izbacivanje kolona za red matricu 
	if(M==1) {
		for(k=0;k<br1;k++) {
			for(i=0;i<M;i++)
				mat[i][niz1[k]]=mat[i][niz1[k]+1];
			N--;
		}
		mat[0][N-1]=(mat[0][N-1]+1);

	}

	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++)
			printf("%5d",mat[i][j]);
		printf("\n");
	}
	return 0;
}

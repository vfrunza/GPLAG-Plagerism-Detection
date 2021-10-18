#include <stdio.h>

int main() {
	int i,j,l,m,k,M,N;
	int br=0;
	int mat[200][200];
    /*Unos redova i kolona matrice i provjera da li su u trazenom opsegu*/
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1||M>=200||N<1||N>=200)
		{
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
		}while(M<1||M>=200||N<1||N>=200);
		
	/*Unos elemenata matrice*/
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	/*Izbacivanje istih redova*/
	for(i=0;i<M;i++){
		for(j=i+1;j<M;j++){
			br=0;
			for(k=0;k<N;k++){
			if(mat[i][k]==mat[j][k])
			{
				br++;
			}
			if(br==N)
			{
				for(l=j+1;l<M;l++){ 
					for(m=0;m<N;m++){
			    
			    mat[l-1][m]=mat[l][m];
					
					}}
			M--;
			j--;
    }}}}
	/*Izbacivanje istih kolona*/
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			br=0;
			for(k=0;k<M;k++){
			if(mat[k][i]==mat[k][j])
			{
				br++;
			}
			if(br==M)
			{
				for(l=j+1;l<N;l++){
					for(m=0;m<M;m++){
						
				mat[m][l-1]=mat[m][l];
				
					
						
					}}
				N--;
				j--;
	}}}}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
		return 0;
	}
	

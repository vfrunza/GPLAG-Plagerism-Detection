#include <stdio.h>

int main() {
	int m,n,i,j,k,l,matA[100][100],matB[100][100],matC[100][100],brojacA=0,brojacB=0,brojacC=0;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n); 
	}while(m<0||n<0||m>100||n>100);
	
	printf("Unesite clanove matrice A: ");

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matA[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matB[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matC[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			brojacA=0;
			brojacB=0;
			brojacC=0;
	for(k=0;k<m;k++){
		for(l=0;l<n;l++){
			
			if(matA[k][l]==matA[i][j]) 
			brojacA++;
			if(matB[k][l]==matA[i][j])
			brojacB++;
			if(matC[k][l]==matA[i][j])
			brojacC++;
		}}
		if(brojacA!=brojacB||brojacB!=brojacC){
		printf("NE\n");
		return 1;
	}}}
	printf("DA\n");
	return 0;
}
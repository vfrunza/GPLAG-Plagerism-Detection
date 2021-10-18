#include <stdio.h>

int main() {
	int red, kolona, A[100][100], B[100][100], C[100][100], i=0, j=0, brojacA=0, brojacB=0, brojacC=0, broj, k, p;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &red, &kolona);
	}while(red>100 || kolona>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<red; i++){
		for(j=0; j<kolona; j++){
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<red; i++){
		for(j=0; j<kolona; j++){
			scanf("%d", &B[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<red; i++){
		for(j=0; j<kolona; j++){
			scanf("%d", &C[i][j]);
		}
	}
	for(k=0; k<red; k++){
		for(p=0; p<kolona; p++){
			broj=A[k][p];
	        for(i=0; i<red; i++){
		        for(j=0; j<kolona; j++){
			        if(A[i][j]==broj) brojacA++;
		 	        if(B[i][j]==broj) brojacB++;
			        if(C[i][j]==broj) brojacC++;
		        }
	        }
	        if(brojacA==brojacB && brojacA==brojacC) continue;
	        else{
	        	printf("NE");
	        	return 0;
	        }
		}
	}
	
	printf("DA");
	return 0;
}
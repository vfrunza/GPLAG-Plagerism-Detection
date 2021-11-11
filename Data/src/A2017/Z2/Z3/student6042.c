#include <stdio.h>

int main() {
	int A[10][10], B[10][10], C[10][10], i, j, red, kolona, isti=1, red2, kolona2, tmp;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &kolona, &red);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<red; i++){
		for(j=0; j<kolona; j++){
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &kolona2, &red2);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<red2; i++){
		for(j=0; j<kolona2; j++){
			scanf("%d", &B[i][j]);
		}
	}
	
	for(i=0; i<red; i++){
		for(j=0; j<kolona; j++){
			C[j][red-1-i]=A[i][j];
		}
	}
	
	tmp=red;
	red=kolona;
	kolona=tmp;
	if(kolona!=kolona2 || red!=red2){
		printf("NE\n");
		return 0;
	}
	
	for(i=0; i<red2; i++){
		for(j=0; j<kolona2; j++){
			if(C[i][j]!=B[i][j]){
				isti=0;
				break;
			}
		}
	}
	
	if(isti) printf("DA\n");
	else printf("NE\n");
	
	return 0;
}

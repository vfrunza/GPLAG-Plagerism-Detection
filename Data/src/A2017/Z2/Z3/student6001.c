#include <stdio.h>

int main() {
	
	int i, j, rA, rB, kA, kB;
	int A[100][100], B[100][100], C[100][100];

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &rA, &kA);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<rA;i++){
	for(j=0;j<kA;j++){
	scanf("%d", &A[i][j]);
	}
	}

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &rB, &kB);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<rB;i++){
	for(j=0;j<kB;j++) {
		scanf("%d", &B[i][j]);
	}
	}
			
if(kA!=rB || kB!=rA){
		printf("NE");
		return 0;
		}
/*C od A 2x3   jxi */

for(i=0;i<kA;i++){
	for(j=0;j<rA;j++) {
		C[i][j]=A[rA-1-j][i];
	}
}

for(i=0;i<kA;i++){
	for(j=0;j<rA;j++){
if(B[i][j]!=C[i][j]) {
	printf("NE");
	return 0;
}
}
}
printf("DA");

	return 0;
}

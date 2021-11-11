#include <stdio.h>
#include <math.h>
#define N 100
#define EPSILON 0.0001

int main() {
	double A[N][N], B[N][N], C[N][N];
	int i, j, sA, vA, sB, vB, temp=0, counter=0;
	/* C je transponovana matrica matrice A*/
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sA, &vA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<vA; i++){
		for(j=0; j<sA; j++){
			scanf("%lf", &A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sB, &vB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<vB; i++){
		for(j=0; j<sB; j++){
			scanf("%lf", &B[i][j]);
		}
	}
	
	/*transponovanje*/
	for(i=0; i<sA; i++){
		for(j=0; j<vA; j++){
			C[i][j]=A[j][i];
		}
	}
	

	/*zamjena kolona*/
	for(i=0; i<vA-i; i++){
		for(j=0; j<sA; j++){
			temp=C[j][i];
			C[j][i]=C[j][vA-1-i];
			C[j][vA-1-i]=temp;
		}
	}
	

	if(sA==vB && vA==sB){
	
	counter=1;
	for(i=0;i<vB;i++){
		for(j=0;j<sB;j++){
			if( ((C[i][j])-(B[i][j]))>EPSILON ){
				counter=0;
				break;
			}
		}
	}
	}
	
	if(counter){
		printf("DA\n");
	}
	else {
		printf("NE\n");
	}
	
	return 0;
}

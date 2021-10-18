#include <stdio.h>

#define BR_RED 100 
#define BR_KOL 100
int main() {
	int A[BR_RED][BR_KOL], B[BR_RED][BR_KOL];
	int sirinaA,visinaA,sirinaB,visinaB,i,j,iste;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirinaA,&visinaA);
	
	printf("Unesite clanove matrice A: ");
	for ( i = 0; i < visinaA; i++) {
		for ( j = 0; j < sirinaA; j++) {
			scanf("%d",&A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirinaB,&visinaB);
	
	printf("Unesite clanove matrice B: ");
	for ( i = 0; i < visinaB; i++) {
		for ( j = 0; j < sirinaB; j++) {
			scanf("%d",&B[i][j]);
		}
	}
	

	
	iste=1;
	if(visinaA!=sirinaB || sirinaA!=visinaB){
		iste=0;
		
	}
	else{
		for ( i = 0; (i < visinaA)&&iste; i++) {
			for ( j = 0; (j < sirinaA)&&iste; j++) {
			
				
				if(A[i][j] != B[j][sirinaB-1-i]){
					iste=0;
				}
			}
		}
	}
	
	
	if(iste){
		printf("DA");
	}
	else{
		printf("NE");
	}
	printf("\n");
	
	
	
	return 0;
}

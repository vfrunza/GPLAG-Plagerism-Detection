#include <stdio.h>

int main() {
    int A[100][100]={{0}}; 
    int B[100][100]={{0}};
    int i,j,sA,vA,sB,vB,a;
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d", &sA,&vA);
    printf("Unesite clanove matrice A: ");
    for(i=0;i<vA;i++) {
    	for(j=0;j<sA;j++) {
    		scanf("%d", &A[i][j]);
    	} 
    }
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &sB,&vB);
    printf("Unesite clanove matrice B: ");
    for(i=0;i<vB;i++) {
    	for(j=0;j<sB;j++) {
    		scanf("%d", &B[i][j]);
    	} 
    }
    
    if(sA==vB && vA==sB){
	for(i=0; i<sA; i++){
		for(j=0; j<vB; j++){
			if(A[i][j]!=B[j][sB-1-i]){
				printf("NE\n");
				a=0;
			}
			if(a==0) break;
		}
		if(a==0) break;
	}
	printf("DA\n");
	}
	return 0;
}
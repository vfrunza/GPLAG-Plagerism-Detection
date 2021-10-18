#include <stdio.h>
#define MAX_EL 100

int main() {
	int A[MAX_EL][MAX_EL],B[MAX_EL][MAX_EL],i,j,sA,vA,sB,vB,k,n,jest=0,jest1=0,temp;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sA, &vA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<vA; i++){
		for(j=0; j<sA; j++){
		scanf("%d", &A[i][j]);}}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sB, &vB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<vB; i++){
		for(j=0; j<sB; j++){
		scanf("%d", &B[i][j]);}}
		if(vA==sB && sA==vB){
		if(vA!=sA){
		temp=vA;
		vA=sA;
		sA=temp;
		}
		i=0; j=0; n=0; k=sA-1;
		do{
		if(A[k][n]==B[i][j])
		jest=1;
		else{
		jest=0;
		break;}
		i++; j++; n++; k--;}
		while(i<=vB-1 && j<=sB-1 && n<=vA-1 && k<=0);}
		if(jest==1)
		printf("DA\n");
		else
		printf("NE\n");
	return 0;
}

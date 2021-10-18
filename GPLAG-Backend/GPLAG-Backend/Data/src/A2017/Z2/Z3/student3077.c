#include <stdio.h>

int main() {
	int i,j,n,m,l,k,matricaA[100][100],matricaB[100][100];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m,&n);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&matricaA[i][j]);}}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&l,&k);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<k;i++){
		for(j=0;j<l;j++){
			scanf("%d",&matricaB[i][j]);}}
			
			
	if ((m!=k) || (n!=l)){
		printf("NE");return 0;}
		
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
	
	if(matricaA[i][j]!=matricaB[j][l-i-1]){
		printf("NE");return 0;}}}
	
	printf("DA");
		
	return 0;
}

#include <stdio.h>
#define duzina 100
#define sirina 100
int main() {
	int i,j,matA[duzina][sirina],matB[duzina][sirina],a1,b1,a2,b2;

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&b1,&a1);

	printf("Unesite clanove matrice A: ");

	for(i=0;i<a1;i++){
		for(j=0;j<b1;j++){
			scanf("%d",&matA[i][j]);
	}}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&b2,&a2);
	
	printf("Unesite clanove matrice B: ");
	
	for(i=0;i<a2;i++){
		for(j=0;j<b2;j++){
			scanf("%d",&matB[i][j]);
	}}
	
	
	if(a1!=b2||a2!=b1){
		printf("NE\n");
	}else{
		
	for(i=0;i<a2;i++){
		for(j=0;j<b2;j++){
			if(matB[i][j]!=matA[b2-j-1][i]){
				printf("NE\n");
				return 0;
			}
}}

	printf("DA\n");}

return 0;
}
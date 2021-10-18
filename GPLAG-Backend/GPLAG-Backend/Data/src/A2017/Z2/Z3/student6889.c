#include <stdio.h>

int main() {
	
	int i,j,V,S,V2,S2,matA[10][10],matB[10][10];

	printf("Unesite sirinu i visinu matrice A: ");
		scanf("%d%d",&V,&S);
	
		printf("Unesite clanove matrice A: ");
	for(i=0;i<V;i++){
		for(j=0;j<S;j++){
	scanf("%d",&matA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
		scanf("%d%d",&V2,&S2);
	
		printf("Unesite clanove matrice B: ");
	for(i=0;i<V2;i++){
		for(j=0;j<S2;j++){
	scanf("%d",&matB[i][j]);
		}
	}
int temp;
for(i=0;i<S;i++){
	for(j=i+1;j<V;j++){
	
	temp=matA[i][j];
	matA[i][j]=matA[j][i];
	matA[j][i]=temp;
}}


	for(i=0;i<V/2;i++){
	for(j=0;j<S;j++){
	
	temp=matA[j][i];
	matA[j][i]=matA[j][V-1-i];
	matA[j][V-1-i]=temp;
		
	}}

	int DA=1;
	
		for(i=0;i<V;i++){
		for(j=0;j<S;j++){
			
	
		
		if(matB[i][j]!=matA[i][j]){
			DA=0;
			break;
		}
		}}
		
		if(DA==1){
			printf("DA\n");
			}
		else if(DA==0){
			printf("NE\n");
			
		}
		
	return 0;
}

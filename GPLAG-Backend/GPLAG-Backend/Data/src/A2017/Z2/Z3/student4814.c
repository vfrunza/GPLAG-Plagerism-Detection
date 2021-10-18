#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 100


int main() {


	int i,j;
	int A[SIZE][SIZE]={{0}},B[SIZE][SIZE]={{0}};

	int ma,na,mb,nb,y;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&ma,&na);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<ma;i++){
		for(j=0;j<na;j++){
			scanf("%d",&A[i][j]);
		}
	}
		printf("Unesite sirinu i visinu matrice B: ");
		scanf("%d %d",&mb,&nb);
		printf("Unesite clanove matrice B: ");
	for(i=0;i<mb;i++){
		
		
		for(j=0;j<nb;j++){
		
			scanf("%d",&B[i][j]);
			
		}
		
	}
	y=nb-1;
	if(nb>mb){
			y=nb-1;
	}else if(mb>nb){
		y=mb-1;
	}
	
if(ma==mb&&na==nb){
	for(i=0;i<na;i++){
		for(j=0;j<ma;j++){
			
			if(A[y-j][i]!=B[i][j]){
				printf("NE");
				return 0;
			}
			
			
		}
		
	}
}else{
	for(i=0;i<ma;i++){
		for(j=0;j<na;j++){
			
			if(B[y-j][i]!=A[i][j]){
				printf("NE");
				
				return 0;
			}
			
			
		}
		
	}
	
}

	
		printf("DA");
	
	
	
	return 0;
}

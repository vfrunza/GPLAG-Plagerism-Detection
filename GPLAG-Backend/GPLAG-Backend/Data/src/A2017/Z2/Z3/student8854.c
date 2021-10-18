#include <stdio.h>

int main() {
	int mat1[50][50]={{0}},mat2[50][50]={{0}},i,j,sirina1,visina1,sirina2,visina2,mat3[50][50]={{0}},temp,true=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirina1,&visina1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visina1;i++){
		for(j=0;j<sirina1;j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirina2,&visina2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visina2;i++){
		for(j=0;j<sirina2;j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	if(sirina1!=visina2){
		printf("NE");
		return 0;
		}
	if(visina1!=visina2 && sirina1!=sirina2){
		sirina1=sirina2;
		visina1=visina2;
	}
	for(i=0;i<visina1;i++){
		for(j=0;j<sirina1;j++){
			mat3[i][j]=mat1[j][i];
			
		}
	}
	
	for(i=0;i<visina1;i++){
		for(j=0;j<sirina1/2;j++){
			temp=mat3[i][j];
			mat3[i][j]=mat3[i][sirina1-j-1];
			mat3[i][sirina1-1-j]=temp;
			
		}
	}
	
	
	
	for(i=0;i<visina1;i++){
		for(j=0;j<sirina1;j++){
			if(mat3[i][j]!=mat2[i][j]) true=1;
		}
	}
	if(true) printf("NE");
	else printf("DA");
	
	return 0;
}

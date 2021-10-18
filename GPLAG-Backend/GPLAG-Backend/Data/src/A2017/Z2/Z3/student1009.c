#include <stdio.h>

int main() {
	double mat1[10][10]={0},mat2[10][10]={0},zarotirana[10][10]={0};
	int sirina_1,sirina_2,visina_1,visina_2,i,j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirina_1,&visina_1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visina_1;i++){
		for(j=0;j<sirina_1;j++){
			scanf("%lf",&mat1[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirina_2,&visina_2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visina_2;i++){
		for(j=0;j<sirina_2;j++){
			scanf("%lf",&mat2[i][j]);
		}
	}
	if(visina_1==1){
		for(i=0;i<sirina_1;i++){
			zarotirana[i][0]=mat1[0][i];
		}
	}
	else if(sirina_1==1){
		for(i=0;i<visina_1;i++){
			zarotirana[0][i]=mat1[i][0];
		}
	}
	else{
	for(i=0;i<sirina_1;i++){
		for(j=0;j<visina_2;j++){
			zarotirana[j][sirina_1-1-i]=mat1[i][j];
		}
	}}
	

	for(i=0;i<visina_2;i++){
		for(j=0;j<sirina_2;j++){
			if(zarotirana[i][j]!=mat2[i][j]){
				printf("NE\n");
				return 0;
			}
			}
		}
	printf("DA\n");
	return 0;
}

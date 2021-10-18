#include <stdio.h>

int main() {
	int m,n,i,j,brojElemenata;
	int matA[101],matB[101],matC[101];
	int temp;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}while(m<0 || n<0 || m>100 || n>100);
	
	brojElemenata=m*n;
	printf("Unesite clanove matrice A: ");
	for(i=0;i<(brojElemenata);i++){
		scanf("%d",&matA[i]);
	}
	for(i=0;i<(brojElemenata);i++){
		for(j=i+1;j<(brojElemenata);j++){
			if(matA[j]<matA[i]){
				temp=matA[i];
				matA[i]=matA[j];
				matA[j]=temp;
			}}}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<(brojElemenata);i++){
		scanf("%d",&matB[i]);
	}
	for(i=0;i<(brojElemenata);i++){
		for(j=i+1;j<(brojElemenata);j++){
			if(matB[j]<matB[i]){
				temp=matB[i];
				matB[i]=matB[j];
				matB[j]=temp;
			}}}
		printf("Unesite clanove matrice C: ");
	for(i=0;i<(brojElemenata);i++){
		scanf("%d",&matC[i]);
	}
	for(i=0;i<(brojElemenata);i++){
		for(j=i+1;j<(brojElemenata);j++){
			if(matC[j]<matC[i]){
				temp=matC[i];
				matC[i]=matC[j];
				matC[j]=temp;
			}}}
	int Z=1;
	for(i=0;i<(brojElemenata);i++){
		if((matA[i]!=matB[i]) || (matA[i]!=matC[i])){
			Z=0;
			break;
		}}
	if (Z==1){
		printf("DA \n");
	}
	else if(Z==0){
		printf("NE \n");
	}
	return 0;
}

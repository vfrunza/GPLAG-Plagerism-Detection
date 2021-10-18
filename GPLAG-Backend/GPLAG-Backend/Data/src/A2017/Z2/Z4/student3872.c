#include <stdio.h>

int main() {
	
	int M, N, i, j,z,k,temp;
	int matA[100][100], matB[100][100], matC[100][100];
	int AB=1, BC=1, AC=1,a,b,min1,min2,min3,min4,min5,min6;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	} while (M>100 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++) 
		scanf("%d", &matA[i][j]);
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++) 
		scanf("%d", &matB[i][j]);
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++) 
		scanf("%d", &matC[i][j]);
	}
	
	a=i;
	b=j;
	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			min1=i;
			min2=j;
			for(k=i+1; k<a; k++){
				for(z=j+1;z<b; z++){
				if(matA[k][z]<matA[min1][min2])
				min1=k;
				min2=z;}
			}
		} temp=matA[i][j];
		  matA[i][j]=matA[min1][min2];
		  matA[min1][min2]=temp;}
	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			min3=i;
			min4=j;
			for(k=i+1; k<a; k++){
				for(z=j+1;z<b; z++){
				if(matB[k][z]<matB[min3][min4])
				min3=k;
				min4=z;}
			}
		} temp=matB[i][j];
		  matB[i][j]=matB[min3][min4];
		  matB[min3][min4]=temp;
	}
		  
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			min5=i;
			min6=j;
			for(k=i+1; k<a; k++){
				for(z=j+1;z<b; z++){
				if(matC[k][z]<matC[min5][min6])
				min5=k;
				min6=z;}
			}
		} temp=matC[i][j];
		  matC[i][j]=matC[min5][min6];
		  matC[min5][min6]=temp;}


  for(i=0;i<M;i++) {
  	for(j=0;j<N; j++){
		if(matA[i][j]!=matB[i][j]){
			AB=0;
			break;
		}
  	}
  }
  	
  	for(i=0;i<M;i++) {
  	for(j=0;j<N; j++){
		if(matA[i][j]!=matC[i][j]){
			AC=0;
			break;
		}
  	}
  	}
  	
  	for(i=0;i<M;i++) {
  	for(j=0;j<N; j++){
		if(matB[i][j]!=matC[i][j]){
			BC=0;
			break;
		}
  	}
  	}
  	
  	if(AB==1 && BC==1 && AC==1)
  	printf("DA");
  	else printf("NE");
  	
	return 0;
}

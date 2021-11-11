#include <stdio.h>

int main() {
	int matA[100][100]={{0}},matB[100][100]={{0}},matC[100][100]={{0}},temp=0,k=0,z=0,jel=1,i,j,m,n;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	} while(m>100 || n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matA[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matB[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matC[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(matA[i][j]<matA[k][z] && matA[i][j]!=matA[k][z]){
				temp=matA[k][z];
				matA[k][z]=matA[i][j];
				matA[i][j]=temp;
				i=k;
				j=z;
				}
	         	if(i==(m-1) && j==(n-1) && z!=(n-1)){
	         		z++;
	         		i=k;j=z;
	         	}
	         	if(k!=(m-1) && i==(m-1) && j==(n-1) && z==(n-1)){
	         		z=0;
	         		k++;
	         		i=k;j=z;
	         	
	         	}
		    }
		}
		k=0;z=0;
		for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(matB[i][j]<matB[k][z] && matB[i][j]!=matB[k][z]){
				temp=matB[k][z];
				matB[k][z]=matB[i][j];
				matB[i][j]=temp;
				i=k;
				j=z;
				}
					if(i==(m-1) && j==(n-1) && z!=(n-1)){
	         		z++;
	         		i=k;j=z;
	         	}
	         	if(k!=(m-1) && i==(m-1) && j==(n-1) && z==(n-1)){
	         		z=0;
	         		k++;
	         		i=k;j=z;
	         	
	         	}
		    }
		}
		k=0;z=0;
		for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(matC[i][j]<matC[k][z] && matC[i][j]!=matC[k][z]){
				temp=matC[k][z];
				matC[k][z]=matC[i][j];
				matC[i][j]=temp;
				i=k;
				j=z;
				}
					if(i==(m-1) && j==(n-1) && z!=(n-1)){
	         		z++;
	         		i=k;j=z;
	         	}
	         	if(k!=(m-1) && i==(m-1) && j==(n-1) && z==(n-1)){
	         		z=0;
	         		k++;
	         		i=k;j=z;
	         	
	         	}
		    }
		}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(matA[i][j]!=matB[i][j] || matA[i][j]!=matC[i][j]) jel=0;
		}
	}
	if(jel) printf("DA\n");
	else printf("NE\n");
	return 0;
}

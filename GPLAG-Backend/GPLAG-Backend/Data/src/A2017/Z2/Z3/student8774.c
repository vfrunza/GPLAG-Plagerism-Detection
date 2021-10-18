#include <stdio.h>

int main() {
	int i,j,visina1,sirina1,visina2,sirina2,A[100][100],B[100][100],pom[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirina1,&visina1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visina1;i++){
		for(j=0;j<sirina1;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirina2,&visina2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visina2;i++){
		for(j=0;j<sirina2;j++){
			scanf("%d",&B[i][j]);
		}
	}
		if(sirina1!=visina2 || visina1!=sirina2){
		printf("NE"); return 0;
	}
	
	for(i=0;i<sirina1;i++){
		for(j=0;j<visina1;j++){
		
		   pom[i][j]=A[visina1-j-1][i];
		}
	}

	for(i=0;i<visina2;i++){
		for(j=0;j<sirina2;j++){
			if(B[i][j]!=pom[i][j] ){
				printf("NE");
				return 0;
			}
		}
	}
	printf("DA");
	
	
	

	return 0;
}

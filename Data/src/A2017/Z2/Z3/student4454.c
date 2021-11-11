#include <stdio.h>

int main() {
	int mat1[100][100];
	int mat2[100][100];
	int sirina1,visina1,sirina2,visina2;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina1, &visina1);
	int i,j;
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visina1;i++){
	    for(j=0;j<sirina1;j++){
	        scanf("%d", &mat1[i][j]);
	    }
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina2, &visina2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visina2;i++){
	    for(j=0;j<sirina2;j++){
	        scanf("%d", &mat2[i][j]);
	    }
	}
	int brojac=0;
	
	if(visina1!=sirina2 && sirina1!=visina2) {
		printf("NE");
		return 0;
	}
	for(i=0;i<visina2;i++){
	    for(j=0;j<sirina2;j++){
		 if(mat2[i][j]==mat1[visina1-1-j][i]) brojac++;
		}
	}    
	if (brojac==visina1*sirina1 && sirina1==visina2 && visina2==sirina1) printf("DA");
	else printf("NE");
	
	return 0;
}

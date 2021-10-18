#include <stdio.h>

int main() {
	int mat1[100][100],mat2[100][100];
	int m,n;
	int i ,j;
	
	int provjera = 0 ;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m,&n);
	printf("Unesite clanove matrice A: ");
	for(i = 0 ; i < m; i++){
		for(j = 0 ; j < n; j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&m,&n);
	printf("Unesite clanove matrice B: ");
	for( i = 0 ; i < m ; i++){
		for(j = 0 ; j < n ; j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	
	//svrha zadatka 
	
	for( i = 0 ; i < m ; i++){
		for(j= 0 ; j < n ; j++){
			if(mat1[i][j] == mat2[j][m - 1 -i]) provjera++;
		}
	}
	
	if(provjera == m*n) printf("DA");
	else printf("NE");
	return 0;
}

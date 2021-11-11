#include <stdio.h>

int main() {
	int mat1[100][100], mat2[100][100], mat3[100][100];
	int m,n;
	int i,j,k,t;
	int vel1, vel2,vel3;
	int niz1[100],niz2[100],niz3[100];
	int brojac = 1 ;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if( m <= 0 || n <= 0 ) printf("Ponovo unesite brojeve!");
	}while(m <= 0 || n <= 0);
	
	printf("\nUnesite clanove matrice A: ");
	for( i = 0 ; i < m ; i++){
		for(j = 0 ; j < n; j++){
			scanf("%d",&mat1[i][j]);
		}
	}
/*	
	printf("\nUnesite clanove matrice B: ");
	for( i = 0 ; i < m ; i++){
		for( j = 0 ; j < n ; j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	
	printf("\nUnesite clanove matrice C: ");
	for( i = 0 ; i < m ; i++){
		for( j = 0 ; j < n ; j++){
			scanf("%d",&mat3[i][j]);
		}
	}
	
	*/
	
	//prolazim kroz svaku matricu i koliko se koji element puta ponavlja zapisujem u niz
	vel1 = 0;
	for( i = 0 ; i < m ; i++){
		brojac = 0;
		for(j = 0 ; j < n ; j++){
			if(mat1[i][j] == mat1[i+1][j+1] && mat1[i][j] == mat1[i][j+1] && mat1[i][j] == mat1[i+1][j]) brojac++;
		}
		niz1[vel1] = brojac;
		vel1++;
	}
	
	printf("\nELEMENTI NIZA: ");
	for(i = 0 ; i < vel1; i++){
		printf("%d ",niz1[i]);
	}
	return 0;
}

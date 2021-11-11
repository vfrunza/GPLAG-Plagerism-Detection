#include <stdio.h>
#define f 20
#define r 20
int main() {
	
	int tacke,j,z,i,g,o;
	int mat[f][r]={0};
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &tacke);
	if (tacke>10 || tacke<=0) {printf("Pogresan unos \n"); }
	
	} while(tacke<=0  || tacke>10);
	
	for (z=1; z<=tacke; z++) 
	{
		printf("Unesite %d. tacku: ", z);
		scanf("%d %d", &g, &o);
		if (g<0 || g>19 || o<0 || o>19)
		{ printf("Pogresan unos\n"); z--;} 
		else mat[o][g]=1; 
		
	}
	
	for(i=0; i<f; i++){ 
		for(j=0; j<r; j++){ 
			
			if (mat[i][j]==1) { printf("*");} else { printf(" ");	}
			
		}
		printf("\n");
	}
	
		
		
	
	
	

	return 0;
}

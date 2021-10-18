#include <stdio.h>
#define BROJ_K1 20
#define BROJ_K2 20

int main() {
	int i, j, n, x, y, brojac=1;
	float dvod_niz[BROJ_K1][BROJ_K2]={0};
    
    
	do{ 	
	printf("Unesite broj tacaka: "); scanf("%d", &n);
	if(n<=10 && n>0){
	
	
			while(brojac<n+1) {
			printf("Unesite %d. tacku: ", brojac); scanf("%d %d", &x ,&y);
			if(x<0 || x>=20 || y<0 || y>=20  ){
			printf("Pogresan unos\n");
			}
		
			else{
			brojac++;
			dvod_niz[y][x]=1;
			}
		}
	
	}
	else if (n<=0  || n>10){
		printf("Pogresan unos\n");
	}
	
	}while(n<=0 || n>10);

	for(i=0; i<BROJ_K1; i++){
		for(j=0; j<BROJ_K2; j++){
		dvod_niz[i][j];
		
		if(dvod_niz[i][j]==1){
			printf("*");
		}
		else{
			printf(" ");
		}
				
			}
			printf("\n");
		
		}
		
		return 0;
	}



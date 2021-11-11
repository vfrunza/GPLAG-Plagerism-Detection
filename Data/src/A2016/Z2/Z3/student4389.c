#include <stdio.h>
#define VISINA 20
#define SIRINA 20

int main() {
    char  mat[VISINA][SIRINA];
	int n, i, j, k, x[20], y[20];
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10) printf("Pogresan unos\n");
	}while(n<=0 || n>10);
	
	for(i=0; i<VISINA; i++){
		for(j=0; j<SIRINA; j++){
			mat[i][j]=' ';
		}
	}
	
	for(i=0; i<n; i++){
	    printf("Unesite %d. tacku: ", i+1);
	    scanf("%d %d", &x[i], &y[i]);
	    if((x[i]<0 || x[i]>19) || (y[i]<0 || y[i]>19)){
	    	printf("Pogresan unos\n");
	    	i--;
	    }else{
	    	mat[y[i]][x[i]] = '*';
	    }
	}
	
	for(i=0; i<VISINA; i++){
	   	for(j=0; j<SIRINA; j++){
	        printf("%c", mat[i][j]);
	    }
		printf("\n");
	}
	return 0;
}
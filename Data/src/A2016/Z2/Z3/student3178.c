#include <stdio.h>
#define VISINA 20
#define SIRINA 20

int main() {
	int n=0, i=1, x=0, y=0, k=0, j=0;
	int mat[VISINA][SIRINA];
	
	
	   for(i=0; i<20; i++){
    	for(j=0; j<20; j++){
    		mat[i][j]=0;
    	}
    }
    
	
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0 || n>10)
	printf("Pogresan unos\n");
	
	}while(n<=0 || n>10);
	
	i=1;
	
	do{
	printf("Unesite %d. tacku: ",i);
	scanf("%d %d", &x,&y);
		mat[x][y]=66;

	if(	x<0 || x>19 ||  y<0 || y>19 ){
	printf("Pogresan unos\n");
		mat[x][y]=0;
	i--;
	n++;

	}

	i++;
	n--;
	}while(n!=0);
	
		for(j=0; j<VISINA; j++){
		for(k=0; k<SIRINA; k++){
		
	        if(mat[k][j]==66)  
			printf("*");
			else {
			printf(" ");	
			}
		}
		printf("\n");
	}
	

	return 0;
}


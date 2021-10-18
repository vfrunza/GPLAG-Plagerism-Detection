#include <stdio.h>
#define V 20

int main() {
	int a, b, c, mat[V][V]={0}, x, y, brt;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &brt);
		if(brt<1 || brt>10) printf("Pogresan unos\n");
	}
	while(brt<1 || brt>10);
	
	for(a=0; a<brt; a++) {
		printf("Unesite %d. tacku: ",a+1);
		scanf("%d %d", &x, &y);
		if(x<0 || y<0 || x>19 || y>19) { a--; printf("Pogresan unos\n"); continue;}
		mat[x][y]=1;}
		
		for(b=0; b<V; b++) {
			for(c=0; c<V; c++){
				if(mat[c][b]==1) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	
	
	
	return 0;
}

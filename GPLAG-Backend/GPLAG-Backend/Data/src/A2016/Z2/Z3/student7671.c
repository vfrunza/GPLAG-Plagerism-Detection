#include <stdio.h>
#include <math.h>
#define SIRINA 20
int main() {
	int broj_tacaka, k, x, y, i, j, mat[SIRINA][SIRINA];
	
	printf ("\nUnesite broj tacaka: ");
	scanf ("%d", &broj_tacaka);
	while(broj_tacaka>10 || broj_tacaka<=0) {
		/*if(broj_tacaka>10 || broj_tacaka<=0)*/ 
		printf ("Pogresan unos");
		printf ("\nUnesite broj tacaka: ");
		scanf ("%d", &broj_tacaka);
	}
	for(i=0;i<SIRINA;i++){
		for(j=0;j<SIRINA;j++) {
			mat[i][j]=0;
		}
	}
	for(k=0;k<broj_tacaka;k++) {
		printf("Unesite %d. tacku: ", k+1);
		scanf ("%d %d", &y, &x);
			if(x<0 || x>19 || y<0 || y>19) {
				printf ("Pogresan unos\n");
				k--;	}
			else
				mat[y][x]=1;
	}
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			x=i;
			y=j;
			if (mat[y][x]==1) 
				printf ("*");
			else if (mat[y][x]==0)
				printf (" ");
		}
				printf("\n");
	}
	 return 0;
	
}

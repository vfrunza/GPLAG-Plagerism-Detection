#include <stdio.h>
int main() {
	//printf("Zadaća 2, Zadatak 4");
	int i,j,x,y;
	double matrica[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d%d", &x, &y);
		if(x<=0 || x>100 || y<=0 || y>100)
			printf("Pogresan unos!\n");
	}while(x<=0 || x>100 || y<=0 || y>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<x; i++){
		for(j=0; j<y; j++)
			scanf("%lf", &matrica[i][j]);
	}
	printf("Matrica je Teplicova");
	return 0;
}

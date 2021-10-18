#include <stdio.h>

int main() {
	int i,j,m,n;
	int cirkularna=1;
	int teplicova=0;
	float matrica[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if((m<1)||(m>100)||(n<1)||(n>100)){
			printf("Pogresan unos!\n");
			continue;}
		}while((m<1)||(m>99)||(n<1)||(n>99));
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%f",&matrica[i][j]);
			}
	}
	
	printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}

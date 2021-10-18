#include <stdio.h>
#include <math.h>

int main() {
	int unos[10][2];
	int broj,i,j,k,pronadjena;
	printf("Unesite broj tacaka: ");
	scanf("%d",&broj);
	for(i=0;i<broj;i++){
		printf("Unesite %d. tacku: ",i+1);
		for(j=0;j<2;j++){
			scanf("%d",&unos[i][j]);
			if(unos[i][j]<0 || unos[i][j]>=20){
				printf("Pogresan unos\n");
				i--;
			}
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			pronadjena=0;
			for(k=0;k<broj;k++){
				if(unos[k][0]==j && unos[k][1]==i){
					pronadjena=1;
					break;
				}
			}
			if (pronadjena==1)
			printf("*");
			else 
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}

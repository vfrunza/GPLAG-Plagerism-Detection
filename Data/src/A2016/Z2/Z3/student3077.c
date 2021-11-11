#include <stdio.h>

int main() {
	int brojtacaka,prvakoordinata[10],drugakoordinata[10],i,j,k,matrica[20][20]={{0},{0}};
pocetak:
	printf("Unesite broj tacaka: ");
	scanf("%d", &brojtacaka);
	if(brojtacaka>10 || brojtacaka<=0) {
		printf("Pogresan unos\n");
		goto pocetak;}
	for(i=0;i<brojtacaka;i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &prvakoordinata[i],&drugakoordinata[i]); 
	if(prvakoordinata[i]<0 || prvakoordinata[i]>19 || drugakoordinata[i]<0 || drugakoordinata[i]>19) {
		printf("Pogresan unos\n");
		i--;}
	} for(i=0;i<brojtacaka;i++){
	   for(j=0;j<20;j++){
		for(k=0;k<20;k++){
			if(j==drugakoordinata[i] && k==prvakoordinata[i]) {matrica[j][k]=1;}
		} 
	  } 
	} for(i=0;i<20;i++) {
		for(j=0;j<20;j++){
			if(matrica[i][j]==1)
			printf("*", matrica[i][j]);
			else printf(" ");
		} printf("\n");
	}
	return 0;
}

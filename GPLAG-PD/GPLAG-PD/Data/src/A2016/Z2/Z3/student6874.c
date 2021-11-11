#include <stdio.h>

int main() {
	int matrica [20][20];
	int k,i,n,m,j;
	for(i=0; i<20; i++)
	for(j=0; j<20; j++)
	matrica[i][j]=-1;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &k);
	if(k>10 ||k<1) printf("Pogresan unos\n");
	}while(k>10 || k<1);
	for(i=0; i<k; i++)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &m, &n);
		while(m>19 || m<0 || n>19 || n<0){
			printf("Pogresan unos\nUnesite %d. tacku: ",i+1);
			scanf("%d %d ", &m,&n);
		}
		matrica[n][m]=1;
	}
	for(i=0; i<20; i++){
	for(j=0; j<20; j++)
	{
		if(matrica[i][j]==1) printf("*");
		else printf(" ");
	}
	printf("\n");
	}
	return 0;
}

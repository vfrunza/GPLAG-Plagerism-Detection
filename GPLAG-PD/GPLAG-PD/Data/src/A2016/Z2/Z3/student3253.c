#include <stdio.h>
#include <math.h>
#define SIR 20
#define VIS 20

int main() {

	int n, k, a, b, i, j, matrica[SIR][VIS]={0};

	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0 || n>10){
		do{
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	}while(n<=0 || n>10);}
	
	for(k=0;k<n;k++){
		printf("Unesite %d. tacku: ", k+1);
		scanf("%d %d", &a, &b);
		while(a<0 || a>19 || b<0 || b>19){
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ", k+1);
			scanf("%d %d", &a, &b);
		}
		matrica[b][a]='*';
	}
		for(i=0;i<SIR;i++){
			for(j=0;j<VIS;j++){
				if(matrica[i][j]=='*'){
							printf("*");
						}else {
							printf(" ");
						}
			}printf("\n");
		}
	return 0;
}
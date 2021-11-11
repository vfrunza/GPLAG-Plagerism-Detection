#include <stdio.h>
int main(){
	int mat[20][20], i, j, br=0, n, brPROVJERE=0, nemaZVIJEZDE=0, popunjeno=0, x[10], y[10];
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n>10 || n<=0){
			printf("Pogresan unos\n");
		}
	}
	while(n>10 || n<=0);
	while(br<n){
		printf("Unesite %d. tacku: ", br+1);
		scanf("%d %d", &x[br], &y[br]);
		if(x[br]<0 || x[br]>=20 || y[br]<0 || y[br]>=20){
			printf("Pogresan unos\n");
		}
		else{
			br++;
		}
	}
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			while(brPROVJERE<n){
				if(x[brPROVJERE]==j && y[brPROVJERE]==i && popunjeno==0){
					printf("*");
					popunjeno++;
				}
				brPROVJERE++;
			}
			if(popunjeno==0){
				printf(" ");
			}
			popunjeno=0;
			brPROVJERE=0;
		}
		printf("\n");
	}
	return 0;	
}
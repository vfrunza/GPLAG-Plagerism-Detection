#include <stdio.h>

int main() {
	int x1[20], y1[20], n, i, j, k, t;
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<1 || n>10)
			printf("Pogresan unos\n");
	}
	while(n<1 || n>10);
	for(k=0; k<n; k++){
		printf("Unesite %d. tacku: ", k+1);		
		scanf("%d %d", &x1[k], &y1[k]);
		if(x1[k]<0 || x1[k]>19 || y1[k]<0 || y1[k]>19){
			printf("Pogresan unos\n");
			k--;
		}
	}
	for(i=0; i<=19; i++){
		for(j=0; j<=19; j++){
			t=0;
			for(k=0; k<n; k++){
				if(x1[k]==j && y1[k]==i){
					printf("*");
					t=1;
					break;
				}
			}
		if(t==0)
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}

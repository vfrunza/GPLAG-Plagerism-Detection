#include <stdio.h>

int main() {
	int mat[20][20]={{0},{0}}, n, i, j, k;
	
	clan: printf("\nUnesite broj tacaka: ");
	scanf("%d", &n);
	
	if (n<=0 || n>10){
		printf("Pogresan unos");
		goto clan;
	}

	
    for (i=0; i<n; i++){
		
	tacka:	printf("Unesite %d. tacku: ", i+1);
		
			scanf("%d", &j);
			scanf("%d", &k);
			
			if (j<0 || j>=20 || k<0 || k>=20){
				printf("Pogresan unos\n");
				goto tacka;
			}
				mat[j][k]++;
	}
	
	for (k=0; k<20; k++){
		for (j=0; j<20; j++){
			
			if (mat[j][k]!=0){
				printf("*");
			} else {
				printf(" ");
			}
			
			
		}
		printf("\n");
	}
	
	
	return 0;
}

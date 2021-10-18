#include <stdio.h>

#define tacka 10
#define visina 20
#define sirina 20

int main() {
	
	int t, i, j, k;
	int a, a1;
	int mat[visina][sirina]={0};

ponovi:	
	printf("Unesite broj tacaka: ");
	scanf("%d", &t);
	if((t<=0) || (t>10)) {
		printf("Pogresan unos\n");
		goto ponovi;
	}
	
	for(i=0; i<t; i++) {
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &a, &a1);
			if(((a<0) || (a>19)) || ((a1<0) || (a1>19))) {
				printf("Pogresan unos\n");
				i--;
				
		} else {
	
	for(j=0; j<visina; j++) {
		for(k=0; k<sirina; k++) {
			if(mat[j][k]==mat[a][a1]) {
				mat[a][a1]=1;
			}
		}
	}
	}
	}
	
	for(a=0; a<visina; a++) {
		for(a1=0; a1<sirina; a1++) {
			if(mat[a1][a]==1) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

#include <stdio.h>

int main() {
	int M[20][20]={0}, n, x, y, i, j;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	
		if(n<1 || n>10) printf("Pogresan unos \n");
	}while(n<1 || n>10);
	for(i=0;i<n;i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x, &y);
		if(x<0 || x>19 || y<0 || y>19) {printf("Pogresan unos\n");
		i--;}
		else M[x][y]= 50;
		
	}
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			if (M[j][i]==50) printf("*");
			else printf(" ");
		} printf("\n");
	}
	return 0;
}

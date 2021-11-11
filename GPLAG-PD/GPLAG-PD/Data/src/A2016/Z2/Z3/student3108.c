#include <stdio.h>
#define A 20
#define B 20


int main() {
	int n,i,j,a,b;
	int mat[A][B];
	
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			mat[i][j]=0;
		}
	}
	for(;;) {
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=10 && n>0)
	break;
	else
	printf("Pogresan unos\n");}
	for(i=0; i<n;i++) {
		for(;;) {
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &a, &b);
			if(a>=0 && a<=19 && b>=0 && b<=19)
			break;
			else
			printf("Pogresan unos\n");
		}
		mat[b][a]=1;
	}
	
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			if(mat[i][j]==1)
			printf("*");
			else 
			printf(" ");
		}
printf("\n");
	}
	
	

		
	
	return 0;
}

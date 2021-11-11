#include <stdio.h>

#include <stdio.h>

int main() {
	
	int mat[20][20];
	int i, j, C, x, y;
	
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			mat[i][j]=0;
			}
	}
		
	do {
	printf("Unesite broj tacaka: ");
	scanf("%d", &C);
	if(C>10 || C<1) printf("Pogresan unos\n");
	}
	while(C>10 || C<1);
	
	for(i=0; i<C; i++) {
		do{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x, &y);
		if(x<0 || x>19 || y<0 || y>19) printf("Pogresan unos\n");
		}
		while(x<0 || x>19 || y<0 || y>19);
		mat[y][x]='*';
	}
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			if(mat[i][j]=='*') printf("*");
			else {
				printf(" ");
			}
			
		}
		printf("\n");
	}
	
	
return 0;	
	
	
}
#include <stdio.h>

int main()
{
	int i=0,j=0,x=0,y=0,n=0;
	int mat[20][20]= {0};
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<1 || n>10) printf("Pogresan unos\n");
	} while(n<1 || n>10);
	i=0;
	do {
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d", &x,&y);
		if(x<0 || x>=20 || y<0 || y>=20) {
			printf("Pogresan unos\n");

			i--;
		} else {
			mat[y][x]=1;
		}
		i++;
	} while(i<n);

	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			if(mat[i][j]==1) {
				printf("*");

			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;

}

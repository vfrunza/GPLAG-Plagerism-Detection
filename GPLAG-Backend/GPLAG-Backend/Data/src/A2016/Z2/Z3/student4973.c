#include <stdio.h>

int main()
{
	int a,b,c,i,j;
	int mat[20][20]= {0};
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d",&a);
		if(a<=0 || a>10) printf("Pogresan unos\n");
	} while(a<=0 || a>10);
	for(i=0; i<a; i++) {

		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d",&b,&c);
		if(b<0 || b>=20 || c<0 || c>=20) {
			printf("Pogresan unos\n");
			i--;
		} else mat[c][b]=1;
	}

	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			if(mat[i][j]==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}

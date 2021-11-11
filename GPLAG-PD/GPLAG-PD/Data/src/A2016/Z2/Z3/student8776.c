#include <stdio.h>
#include <math.h>

int main()
{
	int brtacaka=0, x,y;
	char mat[20][20];
	int i, m, n;
	for(;;)
	{
		
	printf("Unesite broj tacaka: ");
	scanf("%d", &brtacaka);
	if(brtacaka<=0 || brtacaka>10) printf("Pogresan unos\n");
	else break;
	}
	for(m=0; m<20; m++){
		for(n=0; n<20; n++){

			mat[m][n]=' ';
		}
	}


	for(i=1; i<=brtacaka; i++) {
		printf("Unesite %d. tacku: ",i);
		scanf("%d %d", &x, &y);
	if(x<0 || x>=20) {
		printf("Pogresan unos\n");
		i--;
		continue;
	} 
	if(y<0 || y>=20) {
		printf("Pogresan unos\n");
		i--;
		continue;
	}
	else mat[x][y]='*'; }


	for(m=0; m<20; m++){
		for(n=0; n<20; n++){
			printf("%c", mat[n][m]); }
		printf("\n");
	}

	return 0;
}

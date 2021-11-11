#include <stdio.h>
#define x 20
#define y 20
int main() {
	char matrica[x][y];
	int i,j,t1,t2,n,k;
	for (i=0;i<x;i++) {
		for (j=0;j<y;j++){
			matrica [i][j]=' ';
		}
	}
	do {
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
		if (n<=0 || n>10) {
			printf ("Pogresan unos \n");
		}
		else break;
	}
	while (1);
	for (k=1;k<=n;k++){
		printf ("Unesite %d. tacku: ", k);
		scanf ("%d %d", &t1,&t2);
		while (t1<0 || t2<0 || t1>19 || t2>19) {
			printf ("Pogresan unos \n");
			printf ("Unesite %d. tacku: ", k);
			scanf ("%d %d", &t1,&t2);
		}
		for (i=0;i<x;i++){
				for (j=0;j<y;j++){
					matrica [t2][t1]='*';
				}
			}
		
	}
	for (i=0;i<x;i++){
		for (j=0;j<y;j++){
			printf ("%c", matrica[i][j]);
		}
		printf ("\n");
	}
	
	return 0;
}

#include <stdio.h>

int main() {
	char a[20][20];
	int n, d, f, x, y;
	do{
	printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
			if (n<1 || n>10){
				printf ("Pogresan unos\n");
			}
	}while (n<1 || n>10);
	for (d=0;d<20;d++){
		for (f=0;f<20;f++){
			a[d][f]=' ';
		}
	}
		for (d=0;d<n;d++) {
			do {
			printf ("Unesite %d. tacku: ",d+1);
			scanf ("%d %d" , &x, &y);
		if (x<0 || x>=20 || y<0 || y>=20){
			printf ("Pogresan unos\n");
			}
	}while (x<0 || x>=20 || y<0 || y>=20);
	a[x][y]='*';
		}
	for (d=0;d<20;d++){
		for (f=0;f<20;f++){
			printf ("%c",a[f][d]);
		}
		printf ("\n");
	}	
		
	
	return 0;
}

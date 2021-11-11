#include <stdio.h>

int main() {
	int i, j, k, z, r, n, l;
	int h;
	do{
	printf ("Unesite broj redova: ");
	scanf ("%d", &n);
	} while (n<=0 || n>10);
	do{
	printf ("Unesite broj kolona: ");
	scanf ("%d", &z);
	}while (z<=0 || z>10);
	do{
	printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d", &k);
	} while (k<=0 || k>10);

	for (i=0; i<(n*2+1);i++){
		if (i%2==1){
			for (r=0; r<=z; r++){
			printf ("|");
			for (l=0; l<k; l++)
			printf (" ");
			}
			printf ("\n");
		}
	    else {
	    for (j=0; j<=z;j++){
			printf ("+");
			if (j==z){
			continue;
			}
			for (h=0; h<k; h++)
			printf ("-");
			
			}
			printf ("\n");
	    }
		}

		
		
	

return 0;
}

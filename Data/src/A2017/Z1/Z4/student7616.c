#include <stdio.h>

int main() {
	int i, j, r, k, sk;
	do{
		printf ("Unesite broj redova: ");
		scanf ("%d", &r);
	}
	while (r<=0 || r>10);
	do{
		printf ("Unesite broj kolona: ");
		scanf ("%d", &k);
	}
	while (k<=0 || k>10);
	do{
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &sk);
	}
	while (sk<=0 || sk>10);
	
	
	for (i=0; i<=2*r; i++){
		for (j=0; j<=k*sk+k; j++){
			if (i%2==0){
				if (j%(1+sk)==0){
					printf ("+");
				}
				else printf ("-");
			}
			if (i%2==1){
				if (j%(1+sk)==0){
					printf ("|");
				}
				else printf (" ");
			}
			}
			printf ("\n");
	}
	return 0;
}

#include <stdio.h>
int main () {
	int i,n;
	do {
		printf ("Unesite broj n: ");
		scanf ("%d",&n);
		if (n<=0 || n>=51) printf ("Pogresan unos\n");
	} while (n<=0 || n>=51);
	int j;
	int sirina = (2*n-3)* 2+3;
	if (n==1) {printf ("***"); } else {
		for (i=0;i<n;i++) {
			for (j=0 ; j<sirina; j++) {
				if (i==j) printf ("*"); else
				if(j-2*n+2==i) printf ("*"); else
				if (i+j-n+1==n-1) printf ("*"); else
				if (i+j-3*n+3==n-1) printf ("*"); else printf ("*");
			}
	        printf ("\n");
}
}

	return 0;
}


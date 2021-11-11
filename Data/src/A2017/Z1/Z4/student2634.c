#include <stdio.h>

int main() {
	
	int r,k,i,j,s;
	
	
	do {
			printf ("Unesite broj redova: ");
		scanf ("%d", &r); }
		while (r<=0 || r>10);
		
	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &k); }
		while (k<=0 || k>10);
		
	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &s); }
		while (s<=0 || s>10);

for (i=0; i<(r*2)+1; i++) {
	for (j=0; j<k*s + k+1; j++) {
		if ((i==0 || i%2==0) && (j==0 || j%(s+1)==0)) printf ("+");
		else if (i==0 || i%2==0) printf ("-");
		else if (i%2!=0 && (j==0 || j%(s+1)==0) ) printf ("|");
		else printf (" ");
	}
	printf ("\n");
}

return 0;
}

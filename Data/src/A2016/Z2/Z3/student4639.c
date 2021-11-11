#include <stdio.h>

int main() {
	int i,n,j,k;
	int x[10];
	int y[10];
	do {
	printf("Unesite broj tacaka: ");
	scanf ("%d",&n);
	if (n<=0 || n>10) printf ("Pogresan unos\n"); 
	} while (n<=0 || n>10);
	for (i=0;i<n;i++) {
		do {
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x[i],&y[i]);
		if (x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19) printf ("Pogresan unos\n");
		} while (x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19);
	}
	for (i=0;i<20;i++) {
		for (j=0;j<20;j++) {
			for (k=0;k<n;k++) { 
			if (x[k]==j && y[k]==i)
			{
			printf ("*"); break;
			}
			}
			if (k==n) printf (" "); 
		}
		printf ("\n");
	}
	return 0;
}

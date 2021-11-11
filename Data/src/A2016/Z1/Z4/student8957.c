#include <stdio.h>

int main() {
	int i,j,n,m;
	do{
	printf ("Unesite broj n: ");
	scanf ("%d",&n);
	if (n<=0 || n>50) printf ("Pogresan unos\n");
	} while (n<=0 || n>50);
	
		if (n>1) m=((n-2)*4)+5;
		else if (n==1) m=3;
		
		for (i=0;i<n;i++){
			for (j=0;j<m;j++){
				if (j==i || (i==j-(m-1)/2))
					printf ("*");
				else if (i+j==(m-1)/2 || i+j==m-1)
					printf ("*");
				else 
					printf (" ");
			}
		printf ("\n");
		}	
	return 0;
}

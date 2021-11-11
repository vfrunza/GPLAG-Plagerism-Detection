#include <stdio.h>

int main() {
	int n, i, j;
	do {
		printf ("Unesite broj N: ");
		scanf ("%d", &n);
		if (n<8 || n%4==1) printf ("Neispravno N!\n");
		else printf ("\n");
	}while (n<8 || n%4==1); /*po uslovu zadatka da n mora biti vece od 8 i djeljivo sa 4, sve dok to nije zadovoljeno izvrsavamo petlju*/
	
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			/*crtanje znaka X u gornjem lijevom uglu*/
			if ((i==j) && (i<=n/2-1) && (j<=n/2-1)) printf ("\\");
			else if ((i+j==n/2-1) && (i<=n/2-1) && (j<=n/2-1)) printf ("/");
			
			
			/*crtanje kvadrata sa +, - i | u gornjem desnom uglu*/
			else if ((i==0 && ((j==n/2) || (j==(n-1)))) || ((i==n/2-1) && ((j==(n/2)) || (j==n-1)))) printf ("+");
			else if ((j==n/2  && i<n/2 && i!=0 && i!=n/2-1) || (j==(n-1) && i<n/2 && i!=0 && i!=n/2-1)) printf ("|");
			else if ((i==0 && j>n/2 && j<n-1) || (i==n/2-1 && j>n/2 && j<n-1)) printf ("-");
			
			
			/*crtanje kvadrata sa +, - i | u donjem lijevom uglu*/
			else if ((i==n/2 && (j==0 || j==n/2-1)) || (i==n-1 && (j==0 || j==n/2-1))) printf ("+");
			else if ((j==0 && i>n/2 && i!=n-1) || (j==n/2-1 && i>n/2 && i!=n-1)) printf ("|");
			else if ((i==n/2 && j>0 && j<n/2-1) || (i==n-1 && j>0 && j<n/2-1)) printf ("-");
			
			
			/*crtanje znaka "+" sastavljenog od -, + i | u donjem desnom uglu*/
			else if ((i>=n/2 && i!=j && (i+j)!=(n+(n/2)-1) && (j==(n/2+n/4)))||(i>=n/2 && i!=j && (i+j)!=(n+(n/2)-1) && j==(n/2+n/4-1))) printf ("|");
			else if ((i>=n/2 && (j==(n/2+n/4)) && (i==j || (i+j)==(n+(n/2)-1))) || (i>=n/2 && j==(n/2+n/4-1) && (i==j || (i+j)==(n+(n/2)-1)))) printf ("+");
			else if ((i==(n/2+n/4) && j>=n/2) || (i==(n/2+n/4-1) && j>=n/2)) printf ("-");
			
			else printf (" "); /*u svakom drugom slucaju da napise razmak (da to nisam uradila sve bi bilo sastavljeno) */
		}
		printf ("\n");
	}
	return 0;
}

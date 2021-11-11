#include <stdio.h>

int main() 
{
	int n, i, j;
	
	do
	{
		printf ("Unesite broj N: ");
		scanf ("%d", &n);
		if (n<8 || n%4!=0) printf ("Neispravno N!\n");
	}while(n<8 || n%4!=0);
	printf("\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			//if (i == n/2 || j == n/2) printf ("+");
			//if (((i >= 0 && i <= n/2) && (j>=0 && j<=n/2)) || (i==j)) printf  ("\\");
			//else printf (" ");
			//if (((i>= 0 && i <= n/2) && (j>=0 && j>= n/2)) || (i == n/2-j-1)) printf ("/");
			if (i < n/2 && j < n/2) 
			{
				//PRVI KVADRANT
				//printf ("1");
				if (i==j) printf ("\\");
				else if (i==(n/2)-j-1) printf("/");
				else printf (" ");
			}
			if (i < n/2 && j >= n/2) 
			{
				//DRUGI KVADRANT
				//printf ("2");
				if (i==0 && j == (n/2) ) printf ("+"); //gornji lijevi +
				else if (i==0 && j==n-1) printf ("+"); //gornji desni +
				else if (j==(n/2) && i == (n/2)-1) printf ("+"); //donji lijevi +
				else if (i==(n/2)-1 && j==n-1) printf ("+"); //donji desni +
				else if (i==0 || i==n/2-1) printf("-");
				else if (j==(n/2) || j==n-1) printf ("|");
				else printf(" ");
			}
			if (i >= n/2 && j < n/2) 
			{
				//TRECI KVADRANT
				//printf ("3");
				if (i==(n/2) && j==0) printf ("+"); //gornji lijevi +
				else if (i==(n/2) && j==(n/2)-1) printf ("+"); //gornji desni +
				else if (i==n-1 && j==0) printf("+"); //donji lijevi +
				else if (i==n-1 && j==(n/2)-1) printf("+"); //donji desni +
				else if (i==(n/2) || i==n-1) printf("-");
				else if (j==0 || j==(n/2)-1) printf ("|");
				else printf(" ");
			}
			if (i >= n/2 && j >= n/2) 
			{
				//CETVRTI KVADRANT
				if (i==(3*n)/4 && j==(3*n)/4) printf ("+"); // donji desni plus +
				else if (i==(3*n)/4 && j == (3*n)/4-1) printf ("+"); // donji lijevi +
				else if (i==(3*n)/4-1 && j == (3*n)/4) printf ("+"); // gornji desni +
				else if (i==(3*n)/4-1 && j == (3*n)/4-1) printf ("+"); // gornji lijevi +
				else if (i==(3*n)/4) printf("-");
				else if (i==(3*n)/4-1) printf("-");
				else if (j==(3*n)/4) printf("|");
				else if (j==(3*n)/4-1) printf("|");
				else printf (" ");
			}
			//else printf (" ");
		}
		printf ("\n");
	}
	
	return 0;
}

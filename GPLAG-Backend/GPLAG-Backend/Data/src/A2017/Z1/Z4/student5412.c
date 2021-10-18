#include <stdio.h>

int main() 
{
	int br_red, br_kol, n, i, j, p, r, k;
	do
	{
		printf ("Unesite broj redova: ");
	    scanf ("%d", &br_red);
	} while(br_red <= 0 || br_red > 10);
	do
	{
	printf ("Unesite broj kolona: ");
	scanf ("%d", &br_kol);
	
	}while (br_kol <= 0 || br_kol > 10);
	
	do
	{
	printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d", &n);
	} while (n <= 0 || n > 10);
	
	p = 2*br_red+1;
	r = br_kol*(n)+br_kol+1;
	
	// for  (i=0; i<p; i++)
	// {
	// 	for (j=0; j<r; j++)
	// 	{
	// 		if ((i==0 && j==0) || (i==0 && j== n) || (i==0 && j== 2*n) || (i==0 && j==3*n) || (i==0 && j==4*n) || (i==0 && j==5*n) || (i==0 && j==r)) printf ("+");
			
	// 		if ((i==1 && j==0) || (i==1 && j== n) || (i==1 && j== 2*n) || (i==1 && j==3*n) || (i==1 && j==4*n) || (i==1 && j==5*n) || (i==1 && j==r)) printf ("|");
			
	// 		if ((i==p-1 && j==0) || (i==p-1 && j== n) || (i==p-1 && j== 2*n) || (i==r-1 && j==3*n) || (i==r-1 && j==4*n) || (i==r-1 && j==5*n) || (i==r-1 && j==r)) printf ("|");
			
	// 		if ((i==p-1 && j==0) || (i==p-1 && j==n + 1) || (i==p-1 && j==2*n + 2) || (i==p-1 && j==3*n + 3) || (i==p-1 && j==4*n + 4) || (i==p-1 && j==5*n + 5) || (i==p-1 && j== r)) printf ("+");
			
	// 		else printf (" ");
	// 	}
		
	// 	printf ("\n");
	// }
	
		
	// for  (i=0; i<p; i++)
	// {
	// 	for (j=0; j<r; j++)
	// 	{
	// 		for (k=j+1; k<r/(n); k++)
	// 		{
	// 			if ((i==0 && k==1) || (i==0 && k==j*n + j)) printf ("+");
	// 		else printf ("-");
	// 		}
			
	// 	}
		
	// 	printf ("\n");
	// }
	// 	for  (i=0; i<p; i++)
	// {
	// 	for (j=0; j<r; j++)
	// 	{
	// 		for (k=j+1; k<r/(n); k++)
	// 		{
	// 			if ((i==0 && k==1) || (i==0 && k==j*n + j)) printf ("|");
	// 		else printf (" ");
	// 		}
			
	// 	}
		
	// 	printf ("\n");
	// }
	// 	for  (i=0; i<p; i++)
	// {
	// 	for (j=0; j<r; j++)
	// 	{
	// 		for (k=j+1; k<r/(n); k++)
	// 		{
	// 			if ((i==0 && k==1) || (i==0 && k==j*n + j)) printf ("+");
	// 		else printf ("-");
	// 		}
			
	// 	}
		
	// 	printf ("\n");
	// }
	// 	for  (i=0; i<p; i++)
	// {
	// 	for (j=0; j<r; j++)
	// 	{
	// 		for (k=j+1; k<r/(n); k++)
	// 		{
	// 			if ((i==0 && k==1) || (i==0 && k==j*n + j)) printf ("|");
	// 		else printf (" ");
	// 		}
			
	// 	}
		
	// 	printf ("\n");
	// }
	// 	for  (i=0; i<p; i++)
	// {
	// 	for (j=0; j<r; j++)
	// 	{
	// 		for (k=j+1; k<r/(n); k++)
	// 		{
	// 			if ((i==0 && k==1) || (i==0 && k==j*n + j)) printf ("+");
	// 		else printf ("-");
	// 		}
			
	// 	}
		
	// 	printf ("\n");
	// }
	
	for (i=0; i<br_red; i++)
	{
		for (j=0; j<br_kol; j++)
		{
			
		}
	}
	
	return 0;
}

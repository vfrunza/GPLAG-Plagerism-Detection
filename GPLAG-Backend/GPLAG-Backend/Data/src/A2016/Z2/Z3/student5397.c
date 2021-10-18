#include <stdio.h>

int main() 
{
   int n, m, k, h, x, y, z, i, j;
   char kord[20][20]={{'\0'}};
   j=0;
   while (j==0)
   {
   printf ("Unesite broj tacaka: ");
   scanf ("%d", &n);
   if (n>10 || n<1)
	    {
         printf ("Pogresan unos\n");
	    }
	    else 
	    {j=-1;}
   }
   
   m=0;
   while (m<n)
   {
   	z=0;
   	while (z==0)
   	{
   	 i=m+1;
   	 printf ("Unesite %d. tacku: ", i);
   	 scanf ("%d %d", &x, &y);
   	 if (x>=20 || x<0 || y>=20 || y<0)
	    {
         printf ("Pogresan unos\n");
	    }
	    else 
	    {z=-1;}
   	}
	kord [y][x]='*';
	m++;
   }
	for (k=0; k<20; k++)
	{
		for (h=0; h<20; h++)
		{
		 if (kord [k][h]==NULL)
		 {printf (" ");}
		 else
		 {printf ("%c", kord [k][h]);}
		}
		printf ("\n");
		
	}
	return 0;
}

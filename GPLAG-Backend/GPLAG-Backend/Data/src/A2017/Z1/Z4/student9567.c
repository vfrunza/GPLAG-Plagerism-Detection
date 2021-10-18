#include <stdio.h>

int main() {
int i,j,k,z,skol,kol,red,m,n,t;
do {printf ("Unesite broj redova: ");
scanf ("%d", &red);
} while (red<=0 || red>10);
do {printf ("Unesite broj kolona: ");
scanf ("%d", &kol); } while (kol<=0 || kol>10 );
do {printf ("Unesite sirinu jedne kolone: ");
scanf ("%d", &skol); } while (skol<=0 || skol>10);
for (i=0 ; i<red ; i++)
{
for (j=0 ; j<kol ; j++)
  {
  	for (k=0 ; k<1 ; k++)
  	{ printf ("+"); }
  	for (z=0 ; z<skol; z++ )
  	{ printf ("-"); }
  	}
printf ("+");
printf ("\n");
for (j=0 ; j<kol ; j++)
{
	for (k=0 ; k<1 ; k++)
  	 printf ("|");
  	for (z=0 ; z<skol; z++ )
  	 printf (" "); }
  	  printf ("|\n");
  }
	for (m=0 ; m<kol ; m++)
  {
  	for (n=0 ; n<1 ; n++)
  	{ printf ("+"); }
  	for (t=0 ; t<skol; t++ )
  	{ printf ("-"); }
  	}
printf ("+"); 
return 0;
}

#include <stdio.h>

int main() {
	int br_kol, br_red, sirina, i, j;
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &br_red);
    }	while (br_red<=0 || br_red>10);
	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &br_kol);
	}  while (br_kol<=0 || br_kol>10);
	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &sirina);
	}  while (sirina<=0 || sirina>10);	
	
		for (i=0; i<=2*br_red; i++)
	       {
	       	 for (j=0; j<br_kol*sirina+br_kol+1; j++)
	       	     {
	       	     	if (i%2==0 && j%(sirina+1)==0) printf ("+");
	       	     	else if (i%2==0 && j%(sirina+1)!=0) printf ("-");
	       	     	else if (i%2!=0 && j%(sirina+1)==0) printf ("|");
	       	     	else printf (" ");
	       	     }
		     printf ("\n");
		   }
	return 0;
}

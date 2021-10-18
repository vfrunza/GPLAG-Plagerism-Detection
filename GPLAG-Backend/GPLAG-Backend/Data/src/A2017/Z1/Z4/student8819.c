#include <stdio.h>

int main() {
int r,k,s,i,j,z;
	printf ("Unesite broj redova: ");
	scanf ("%d",&r);
	printf("\n");
	printf ("Unesite broj kolona: ");
	scanf ("%d", &k);
	printf ("\n");
	printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d", &s);
	printf ("\n");
	for (i=0;i<r;i++){
	    for (j=0;j<k;j++){
	    for (z=0;z<s;z++){
	    if ((i==0 || i==r-1) && (j==0 || j==k-1))
	    printf ("+");
	    else if (i==0 || i==r-1)
	    printf ("-");
	    else if (i==s+1)
	    printf ("+");
	    else if (j==0 || j==k-1)
	    printf ("|");
	    else if (j==s+1)
	    printf ("|");
	    else 
	    printf (" ");}
	    }
	    printf ("\n");
	    	
	    
	}
	
		

	return 0;
}

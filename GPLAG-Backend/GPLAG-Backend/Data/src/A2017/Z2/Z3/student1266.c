#include <stdio.h>
#include <math.h>

int main() {
	int  matA[10][10], matprim[10][10], matB[10][10];
	int i, j, k, sirina1, visina1, sirina2, visina2, podudarne=1;
	
	/*unos dimenzija matrice A*/
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &sirina1, &visina1);
	/*unos clanova matrice A*/
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<visina1; i++)
	    {   
	    	for (j=0; j<sirina1; j++)
	    	    	scanf ("%d", &matA[i][j]);
	    }	
	/*unos dimenzija matrice B*/   
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &sirina2, &visina2);
	/*unos clanova matrice B*/
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<visina2; i++)
	   {
	   	   for (j=0; j<sirina2; j++)
	   	         scanf ("%d", &matB[i][j]);
	   }  
	   
	/*formiranje zarotirane matrice*/
	if (visina1==sirina2 && sirina1==visina2) 
	  {
	for (i=0; i<visina1; i++)
	    {
	    	for (k=visina1-1-i; k>=0; k--)
	    	    {
	            	for (j=sirina1-1; j>=0; j--)
	    	            matprim [j][k]=matA [i][j];
	    	    }
	    }
	/*provjera podudarnosti matrica*/
	for (i=0; i<visina1; i++)
	    {
	    	for (j=0; j<sirina1; j++)
	    	   {
	    	   	  if (matprim[i][j]!=matB[i][j]) 
	    	   	     {
	    	   	     	podudarne=0;
	    	   	     	break;
	    	   	     }
	    	   }
	    }
	 if (podudarne) printf ("DA\n");
	 else printf ("NE\n");
	    }

	return 0;
}

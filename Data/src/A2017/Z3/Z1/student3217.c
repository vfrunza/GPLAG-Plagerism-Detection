#include <stdio.h>

int dva_od_tri (int *niz1, int vel1, int *niz2, int vel2, int *niz3, int vel3) {
	int brojac1[100]={0}, brojac2[100]={0}, brojac3[100]={0}, i, pon=0;
	
    	for (i=0; i<vel1; i++)
    	     brojac1[niz1[i]]++;
        
	   for (i=0; i<vel2; i++)
	        brojac2[niz2[i]]++;
     
	   for (i=0; i<vel3; i++)
	        brojac3[niz3[i]]++;
	    
	for (i=0; i<100; i++)
	    if ((brojac1[i]>=1 && brojac2[i]>=1 && brojac3[i]>=1) || (brojac2[i]>=1 && brojac1[i]>=1) || (brojac1[i]>=1 && brojac3[i]>=1) || (brojac2[i]>=1 && brojac3[i]>=1))
	      {
	      	if ((brojac1[i]==brojac2[i] && brojac1[i]!=brojac3[i] && brojac2[i]!=brojac3[i]) || (brojac1[i]==brojac3[i] && brojac1[i]!=brojac2[i] && brojac3[i]!=brojac2[i]) || (brojac3[i]==brojac2[i] && brojac3[i]!=brojac1[i] && brojac2[i]!=brojac1[i])) 
	      	   pon++;
	      	else continue;  
	      }
	return pon;      
}
int main() {
	int prvi_niz[100], drugi_niz[100], treci_niz[100], i=0, vel1, vel2, vel3;
    scanf ("%d", &vel1);
	for (i=0; i<vel1; i++)
	    scanf ("%d", &prvi_niz[i]);
	scanf ("%d", &vel2);  
	for (i=0; i<vel2; i++)
	   	scanf ("%d", &drugi_niz[i]);
	scanf ("%d", &vel3);   	
	for (i=0; i<vel3; i++)
	     scanf ("%d", &treci_niz[i]);
	   	 
	printf ("%d", dva_od_tri(prvi_niz, vel1, drugi_niz, vel2, treci_niz, vel3));    
	return 0;
}

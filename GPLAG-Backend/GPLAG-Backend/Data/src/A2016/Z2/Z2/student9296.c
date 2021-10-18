#include <stdio.h>
#define PI 3.1415926
#include <stdlib.h>
#include <math.h>

int main() {

	
	int ustep=0, umin=0, sec=0, n, i, j;
	
	double usec=0, ugl[500];

	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
    {
	    scanf("%lf", &ugl[i]);
	    
    }
	 
	 printf("Uglovi su:\n");
	 
	 for(i=0; i<n; i++)
	 {
	 	
	     usec = fabs(ugl[i]*180/PI)*3600; //ukupan broj sekundi, iz tog dalje pretvaramo u min i step i sta nam ostane za sekunde
	     
	     usec = abs((int)(usec+0.5)); //zaokruzivanje
	     
	     ustep = (usec/3600);
	     
	     umin = abs((usec-ustep*3600)/60);  //ucoravo na slijepo, valjda valja 
	     
	     sec = abs((usec-ustep*3600-umin*60));
	     
	     if(sec>=60)		//za slucaj da dobijemo preko 60 sekundi
	     {
	     	umin+=1;
	     	sec-=60;
	     }
	     
	     if(umin>=60)
	     {
	     	ustep+=1;
	     	umin-=60;;
	     }
	    
	    if(sec>30)
	    {
	        for(j=i; j<n-1; j++)
	        {
	            ugl[j] = ugl[j+1];
	        }
	        
	        n--;
	        i--;
	    }
	    else if (ugl[i]<0) printf("-%d stepeni %d minuta %d sekundi\n", ustep, umin, sec);
	    else printf("%d stepeni %d minuta %d sekundi\n", ustep, umin, sec);
	 }
	
	
	return 0;
}

#include <stdio.h>

int main() {
	
	int i, r, k , sk, j;
	
	
	do {
    printf ("Unesite broj redova: ");
	scanf ("%d", &r);  
    } while (r<=0 || r>10);
 
    
    do {
    printf ("Unesite broj kolona: ");
	scanf ("%d", &k);
    } while (k<=0 || k>10);
 
     
    do {
    printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d", &sk);	
    } while (sk<=0 || sk>10);
    
    for (i=0; i<=2*r; i++) {
        for (j=0; j<=k+(k*sk); j++)
        {
        
        if (i%2==0) {
        if (j%(sk+1)==0) printf ("+"); 
        if (j%(sk+1)!=0) printf ("-"); 
        
        
        
        } 
        
        if (i%2!=0) {
        if (j%(sk+1)==0) printf ("|"); 
        if (j%(sk+1)!=0) printf (" "); 
        }
            
    }
        
        
        printf ("\n");
        
        
        }
    
    
    
return 0;
}

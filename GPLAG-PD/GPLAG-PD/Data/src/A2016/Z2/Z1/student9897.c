#include <stdio.h>
#include <stdlib.h>

int main() { 
    
    int br, n, m, br1; 
    int suma=0, brojac=1;  

    printf ("Unesite broj: "); 
    scanf ("%d", &br); 
    
    
    if (br<0) 
    br=abs(br);
   
    while (br>=10) { 
        
        n=br%10;
        br=br/10; 
        m=br%10; 
        br1=abs(m-n); 
        
        suma=suma+br1*brojac; 
        brojac=brojac*10; 
    }
        
        printf ("%d", suma); 
        
	return 0;
}
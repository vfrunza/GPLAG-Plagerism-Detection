#include <stdio.h>
#include <math.h>

/*Funkcija koja svaki put vraća sljedeći prost broj*/

int daj_prost () 
{   
    static int prost=1; 
    int a; 
    int b;  
    
    for (b=prost+1; ; b++) {
    for (a=2; a<b; a++) {
        if (b%a==0)
            break;
        
    } 
    
    if (b==a) {
    prost=a; 
    break; 
    }
}

return prost; 
}

/*Main funkcija, računa sumu prostih brojeva*/

int main() { 
    
    int A;
    int suma=0; 
    int B;
    int i;
    int prost; 
    
    prost=daj_prost(); 
    
    for (;;) { 
    printf ("\nUnesite brojeve A i B: ");                            
    scanf ("%d %d", &A, &B);                                        
    
    if (A<1)    
    printf ("A nije prirodan broj."); 
    
    else if (A>=B)    
    printf ("A nije manje od B."); 

    else if (B==2) {
        printf ("Suma prostih brojeva izmadju %d i %d je 2.", A,B); 
        break; 
    }
    else {
        
        for (i=0; i<B; i++) { 
            if (prost>A) suma=suma+prost; 
            if (prost>B) break; 
        }
      
        printf ("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma); 
        break; 
    }
    
    }
    
	return 0;
}
#include <stdio.h>

/*Funkcija provjerava da li je broj prost i vraca taj broj ukoliko jeste.
Static cuva varijablu, odnosno pamti je nakon svakog izvrsavanja funkcije. */ 

int daj_prost(){
    static int x=1;
    int i=2 ;
    x++;
    
    while(i<x){
        if(x%i==0){
            x++;
            i=1;
        }
        
        i++;
    }
    
    return x;
}

int main() {
    
    int A, B, S=0, i, pom_varijabla=0;
    
    do {
    
    printf("Unesite brojeve A i B: ");
        
    scanf("%d%d", &A, &B);
    
    
    /* Uslovi kojima se osigurava da A i B ne izadju van opsega. */
    
    if(A <= 0) {
        
        printf("A nije prirodan broj.\n");
        continue;
        
    } else if(B <= 0){
        printf("A nije manje od B.\n");
        continue;
        
    } else if(A >= B){
        printf("A nije manje od B.\n");
        continue;
        
    } else break;
     
    } while(1);
    
    i = A+1;
    
    /*Racunanje sume u datom opsegu. */ 
    /*Pomocna varijabla kojoj se dodjeljuje vrijednost koju funkcija izracuna. */
    
    while(i < B){
	    
	    pom_varijabla = daj_prost();
	    
	    if(pom_varijabla > A && pom_varijabla < B){
	        S+= pom_varijabla;
	    }
	    
	    i++;
	    
	}
	
	/* For petlja koja osigurava da pomocna varijabla ne izlazi izvan zadatog opsega */
	
	for(;;){
	    pom_varijabla = daj_prost();
	    
	    if(pom_varijabla > A && pom_varijabla < B)
	    
	    S+= pom_varijabla;
	    
	    if (pom_varijabla > B) 
	    break;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, S);
	
	return 0;
}

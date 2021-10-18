#include <stdio.h>

/* funkcija koja svaki put kada se pozove vraća sljedeći prost broj */

int daj_prost(){
    int i=0;
    static int prost_br=1;

    while(prost_br!=i){
        prost_br++;
        for(i=2; i<prost_br; i++){
            if(prost_br%i==0) break;
        }
    }
    
   return prost_br;
}

int main() {
    int prvi_broj, drugi_broj;
    int i, pom_var, suma=0;
    
    do{
        printf("\nUnesite brojeve A i B: ");
        scanf("%d %d", &prvi_broj, &drugi_broj);
        
        if(prvi_broj>=drugi_broj) 
            printf("A nije manje od B.");
        else if(prvi_broj<1 || drugi_broj<1)
            printf("A nije prirodan broj.");
        
    }while(prvi_broj>=drugi_broj || prvi_broj<1 || drugi_broj<1);
    
    /* petlja koja sabira proste brojeve izmedju prvi_broj i drugi_broj */
    
    for(i=prvi_broj+1; i<drugi_broj;i++){
        do{
            pom_var=daj_prost();
        }while(pom_var<prvi_broj+1);
        if(drugi_broj<=pom_var)
            break;
        suma=suma+pom_var;    
    }    
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", prvi_broj, drugi_broj, suma);
	
	
	return 0;
}

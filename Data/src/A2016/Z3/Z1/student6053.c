#include <stdio.h>

int daj_prost (){
    static int a=1;
    int i, prost_br=0;
    a++;
    for(i=2;i<a;i++) {
        if(a%i==0){
            
            prost_br=1;
            break;
        }
        
        
    }
    if(prost_br==0) {
        return a;
    }
    else {
        return daj_prost();
    }
    
}

int main() {
	
	int A;
	int B;
	int i;
	int suma=0;
	int br;
	int element;
	
	do {
	    
	    printf("Unesite brojeve A i B: ");
	    scanf("%d%d",&A, &B);
	    element=A;
	    if(A<=0){
	        printf("A nije prirodan broj.\n");
	        
	    }
	    else if(B<=0) {printf("A nije manje od B.\n");}
	    else if(A>=B){printf("A nije manje od B.\n");
	    
	}
	}
	while (A>=B || A<=0 || B<=0);
	
	while(1)
	{
	   br=daj_prost();
	   if(br>A && br<B)
	   suma+=br;
	   if(br>=B) break;
	   i++;
	   
	    
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",element,B,suma);
	
	return 0;
}

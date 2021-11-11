#include <stdio.h>

 int daj_prost (){
    
    static int x=2;
     int i,j,g=0;
    
    if (x==2){
    	x++;
    	return 2;
    }
    
    for (i=2; i<x; i++){
    	g=0;
    	for (j=2; j<x; j++){
    		if (x%j==0){
    			g++;
    		}
    	}
    	if (g==0){
    		x++;
    		return (x-1);
    	} else x++;
    }
   
  return x;
}

int main() {
	 int A,B,x,i,suma=0;
	do{
	printf("\nUnesite brojeve A i B: ");
	scanf("%d%d", &A, &B);
	    if (A<=0){
	        printf("A nije prirodan broj.");
	    } else if (A>=B){
	        printf("A nije manje od B.");
	    }
	}while(A<=0 || B<=0 || A>=B);
	
	
	for (i=0; i<B; i++){
	    
	    x=daj_prost();
	    
	    if (x>A && x<B){
	        suma=suma + x;
	    }
	    
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}

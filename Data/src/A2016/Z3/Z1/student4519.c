#include <stdio.h>
int daj_prost(){
	    /*racunamo prost broj najblizi trenutnom clanu intervala*/ 
		static int zadnji_prost=1; 
		int broj, j, prost=0;
		
        /*racunamo sljedeci prost broj*/                  
		broj=zadnji_prost;        	
		do{
		  	broj++;	
			for (j=2; j<broj; j++)
        		if (broj % j == 0) break;
			if (j == broj) {
	   			prost = 1;
   				zadnji_prost=broj;
	    	} 
		} while (prost == 0);
		return zadnji_prost;
}
int main() {
   		int A, B, x, suma = 0;
   		do{
    		printf("Unesite brojeve A i B: ");
    		scanf("%d %d", &A, &B);
    	
	   	    /*provjeravamo ispravnost granica intervala*/
			if (A <= 0) printf("A nije prirodan broj.\n");
		    else if (A >= B) printf("A nije manje od B.\n");
		}while (A<=0  ||  A>=B);
   
		/*nalazimo prvi prosti broj koji pripada intervalu*/
		x = daj_prost();
		while (x<=A && x<B)
		 	x=daj_prost();
	 	
		/*racunamo sumu prostih brojeva*/   
		if (x > B) {
   			printf("Suma prostih brojeva izmedju %d i %d je 0.", A, B);
		 	return 0;
	    }
		suma+=x;
		x=daj_prost();
	    while (x < B){
		  	suma+=x;
	 	    x=daj_prost();
    	} 
		printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
		return 0;
}

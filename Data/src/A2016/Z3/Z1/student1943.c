#include <stdio.h>

int daj_prost() {
	int i;
	static int a=1;
	a++;
	for(i=2;i*i<=a;i++) {
		
			if(a%i==0) { a++; i=1; continue; }  
			}
      return a;
}
int main() {
              int suma=0,prostbroj=0,A,B;
              
     printf("Unesite brojeve A i B: ");
     do {
             scanf("%d",&A);
             scanf("%d",&B);
             if(A<=0) { 
         	        printf("A nije prirodan broj.\n");
                    printf("Unesite brojeve A i B: ");
             }
            
            else if(A>=B) {
            	printf("A nije manje od B.\n");
            	printf("Unesite brojeve A i B: ");
            }
            
     }  while(A<=0 || B<=0 || A==B);
     do {
        prostbroj=daj_prost();
        if(prostbroj>A && prostbroj<B) {
        suma+=prostbroj;
        }
     } while(prostbroj<=B);
     printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}

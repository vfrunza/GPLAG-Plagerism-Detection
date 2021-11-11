#include <stdio.h>


int daj_prost() {
   int i,prost=1;
   static int broj=1;
   broj++;
   while(1){ 
       prost=1;          /*ispitivanje da li je broj prost*/
       for(i=2;i<broj;i++){
           if(broj%i==0) {
             prost=0;
             break;
           }
        }
        if (prost) return broj;
        broj++;
   }
}
int main() {
   
    int a,b,i,suma=0,broj;
    do {
      printf("Unesite brojeve A i B: ");
      scanf("%d %d",&a,&b);
      if(a<=0) printf("A nije prirodan broj.\n");
      if(a>=b) printf("A nije manje od B.\n");
    } while(a<=0 || b<=0 || a>=b);
    for(i=1;i<b;i++) {         /*racunanje sume prostih brojeva u unesenom intervalu*/
        broj=daj_prost();
        if(broj>a && broj<b)
        suma=suma+broj;
    }
    printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}

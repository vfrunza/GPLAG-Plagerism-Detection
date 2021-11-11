#include <stdio.h>
int DalijeProst(int prost_broj) {
    int i=2, rez, ind=1;
    for (i=2; i<prost_broj; i++) {
        if (prost_broj%i==0) {
            ind=0;
            break;
        }
    }
    if (ind==1)
       rez=1;
    else 
      rez=0;
    return rez;
}
int daj_prost() {
    static int prost_broj=2;
    while(DalijeProst(prost_broj)==0){
        prost_broj++;
    }
    prost_broj++;
    return prost_broj-1;
}
int main () {
    int i,A,B,suma=0,prost;
    do {
        printf ("Unesite brojeve A i B: ");
        scanf ("%d %d", &A,&B);
         if (A>=B)
            printf ("A nije manje od B.\n");
         else if (A<1)
            printf ("A nije prirodan broj.\n");
         else if (B<1)
            printf ("B nije prirodan broj.\n");
          } while (A<1 || B<1 || A>=B);
    
    
    while((prost=daj_prost())<=A) {
        suma=0;
    }
    for(i=A+1; i<B; i++){
        if(prost>=B)
          break;
        suma+=prost;
        prost=daj_prost();
    }
    printf ("Suma prostih brojeva izmedju %d i %d je %d.\n", A, B, suma);
    return 0;
}
         
         
            
            
            
            
            
            
            
            
            
            
            
 
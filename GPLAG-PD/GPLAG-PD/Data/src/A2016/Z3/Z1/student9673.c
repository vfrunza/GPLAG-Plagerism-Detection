#include <stdio.h>

/* pomocna funkcija - postavljanje brojaca poziva do donje granice intervala A */
int uvecaj_brojac(){
    static int a=0;
    a=a+1;
    return a;
}
/* funkcija daj_prost vraca broj ukoliko je on prost */

int daj_prost() {
int i,a=0;
a=uvecaj_brojac();
for(i=2;i<a;i++){
    if(a%i==0){
        return 0;
    }
}
return a;
}

int main() {
    
int A,B,i,suma=0;

/* prirodni brojevi A i B takvi da je A manje od B */

while(1==1) {
    printf("Unesite brojeve A i B: ");
    scanf("%d %d",&A,&B);
    if(A>0 && B>0 && A<B){
            break;
                }
    else    {
        if(A<=0){ 
            printf("A nije prirodan broj.\n");
            continue; }
        else if(A>=B){
            printf("A nije manje od B.\n");
             continue;
                     }
      
            }
}

/* postavljanje staticke promjenjive do vrijednosti A */
for(i=0;i<A;i++){
    uvecaj_brojac();
}

/* prolazi u intervalu (A,B) i vraca broj ukoliko je on prost */

for(i=A+1;i<B;i++){
    suma+=daj_prost();
}
printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
return 0;
}
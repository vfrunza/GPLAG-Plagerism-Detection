#include <stdio.h>

int daj_prost(){
static int broj=2;
int temp=2,prost=1;
while(broj<10000){
    while(temp!=broj && prost==1){
        if(broj%temp==0){
            prost=0;
            temp=2;
        }
        else temp++;
    }
    if(prost) return broj++;
    prost=1;
    broj++;
}
}

int main() {
int A,B,suma=0,tempProst=0,unos=0;
do{
    printf("\nUnesite brojeve A i B: ");
    scanf("%d %d",&A,&B);
    if(A<=0) printf("A nije prirodan broj.");
    else if(A>=B) printf("A nije manje od B.");
    else if(B<=0) printf("B nije prirodan broj.");
 
    else unos=1;
}while(!unos);
unos=1;
do{
    tempProst=daj_prost();
    if(tempProst>A && tempProst<B) suma+=tempProst;
}while(tempProst<B);
printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);

	return 0;
}

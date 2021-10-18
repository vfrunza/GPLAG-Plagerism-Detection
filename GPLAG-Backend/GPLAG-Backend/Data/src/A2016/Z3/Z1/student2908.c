#include <stdio.h>

int daj_prost(){
   int i,j;
    for(i=2;i<100;i++){
        for(j=2;j<(i/2)+1;j++){
            if(i%j==0) break;
        }
        if(j==i/2+1){
             
        }
    }
}

int main (){
     int A,B,suma=0,i;
    do{
        printf("\nUnesite brojeve A i B: ");
        scanf("%d %d",&A,&B);
        if(A<=0 ){
            printf("A nije prirodan broj.");
        }
        if(A==B || A>B){
            printf("A nije manje od B.");
        }
    }while(A<=0 || B<=0 || A==B || A>B);
    for(i=A;i<B;i++)
        suma+=daj_prost();
 printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
 return 0;
}

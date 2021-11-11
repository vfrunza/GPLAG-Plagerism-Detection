#include <stdio.h>

    int pomocna_funkcija(int broj){
        int i;
        if(broj==1 || (broj%2==0 && broj>2)){
            return 0;
        }
        for (i=3; i<(broj/2); i=i+2){
            if (broj%i==0){
              return 0;
            }
        }
        return 1;
    }
    
    int daj_prost(void){
        static int vrati=0;
        vrati++;
        while(!pomocna_funkcija(vrati)){
            vrati++;
        }
        return vrati;
        }

    int main() {
    int donja_granica,gornja_granica,i;
    int suma=0;
    int broj;
    printf("Unesite brojeve A i B: ");
    scanf("%d %d",&donja_granica,&gornja_granica);

    while(donja_granica<=0 ){
        if(donja_granica<=0) {
            printf("A nije prirodan broj.");
            printf("\nUnesite brojeve A i B: ");
            scanf("%d %d",&donja_granica,&gornja_granica);
       }
        else {
            printf("B nije prirodan broj.");
            printf("\nUnesite brojeve A i B: ");
            scanf("%d %d",&donja_granica,&gornja_granica);
        }
        }

    while(gornja_granica<=donja_granica){
        printf("A nije manje od B.");
        printf("\nUnesite brojeve A i B: ");
        scanf("%d %d",&donja_granica,&gornja_granica);
    }
    
    while(donja_granica<=0 || gornja_granica<=0){
        if(donja_granica<=0){
            printf("A nije prirodan broj.");
            printf("\nUnesite brojeve A i B: ");
            scanf("%d %d",&donja_granica,&gornja_granica);
        }
        else{ 
             printf("B nije prirodan broj.");
             printf("\nUnesite brojeve A i B: ");
             scanf("%d %d",&donja_granica,&gornja_granica);

        }
        }

    for(i=0;i<gornja_granica;i++){
        broj=daj_prost();
        if(broj<gornja_granica && broj>donja_granica) {
            suma=suma+broj;
        }
    }
    
    printf("Suma prostih brojeva izmedju %d i %d je %d. ",donja_granica,gornja_granica,suma);
	return 0;
    }

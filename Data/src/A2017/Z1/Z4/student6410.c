#include <stdio.h>

int main(){
    int i,j,k,Kol,red,sirina;
    do{ 
        printf("Unesite broj redova: ");
        scanf("%d", &red);
    } while(red<=0 || red>10);
    do{
        printf("Unesite broj kolona: ");
        scanf("%d", &Kol);
    }while( Kol<=0 || Kol>10);
    do {
        printf("Unesite sirinu jedne kolone: ");
        scanf("%d", &sirina);
    } while(sirina<=0 || sirina>10);
   
   for(k=0; k<red; k++){
       for(j=0; j<Kol; j++){
           if(j==0) printf("+");
           for(i=0; i<sirina; i++) printf("-");
           printf("+");
       }printf("\n");
       for(j=0; j<Kol; j++){
           if(j==0) printf("|");
           for(i=0; i<sirina; i++) printf(" ");
           printf("|");
       }printf("\n");
   }
   for(j=0; j<Kol; j++){
       if(j==0) printf("+");
       for(i=0; i<sirina;i++) printf("-");
       printf("+");
   }
  return 0;
}


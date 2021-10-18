#include <stdio.h>

int main () {
    int redovi, kolone, sirina, i,j,k;
     do {
         printf("Unesite broj redova: ");
         scanf("%d",&redovi);
     } while(redovi<=0 || redovi > 10);
     do{
         printf("Unesite broj kolona: ");
         scanf("%d",&kolone);
     }while(kolone<=0|| kolone > 10);
     do{
         printf("Unesite sirinu jedne kolone: ");
         scanf("%d",&sirina);
     }while(sirina<=0|| sirina > 10);
     for(i=0;i<redovi*2+1;i++) {
         
         for(j=0;j<kolone;j++){
             if(i%2==0){  printf("+");
             for(k=0;k<sirina;k++){
                 printf("-");
             }
             
             if(j==kolone-1) printf("+");
         } else {
             printf("|"); 
             
             for(k=0;k<sirina;k++){
                 printf(" "); 
             }
             
             if(j==kolone-1) printf("|");
         }
     }
     printf("\n");
     }
     return 0;
}
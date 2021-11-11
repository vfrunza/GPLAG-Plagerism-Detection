#include <stdio.h>


void IzbaciDuplikate (int *niz, int *velicina)
{
    
    int i,j,k;
    
   for(i = 0;i<*(velicina);i++) {
       for(j = i+1;j<*(velicina);j++) {
           
           if((niz[i])==((niz[j]))) {
               
               for(k=j;k<*velicina;k++) {
                   (niz[k])=niz[k+1];
               }
               (*velicina)--;

               j--;
           }
           
       }
   }
   
   
}





int main() {


    int a[100];
    int b[100];
  
    int i;
    int v1,v2;
    printf("Unesite broj elemenata niza a: ");
    scanf("%d", &v1);
    
    printf("Unesite elemene niza a: ");
    
    for( i = 0;i<v1;i++) {
        
        scanf("%d", &a[i]);
    }
     printf("Unesite broj elemenata niza b: ");
    scanf("%d", &v2);
    
    
       printf("Unesite elemene niza b: ");
    
    for( i = 0;i<v2;i++) {
        
        scanf("%d", &b[i]);
    }
    
    printf("Niz a prije izbacivanja izgleda: ");
    for( i = 0;i<v1;i++) {
        
        printf("%d ", a[i]);
    }
    
    
    printf("\nNiz b prije izbacivanja izgleda: ");
    for( i = 0;i<v2;i++) {
        
        printf("%d ", b[i]);
    }
    
    IzbaciDuplikate(a,&v1);
    IzbaciDuplikate(b,&v2);
    
    
      printf("\nNiz a poslije izbacivanja izgleda: ");
    for( i = 0;i<v1;i++) {
        
        printf("%d ", a[i]);
    }
    
    
    printf("\nNiz b poslije izbacivanja izgleda: ");
    for( i = 0;i<v2;i++) {
        
        printf("%d ", b[i]);
    }
    
    
    
    
    
	return 0;
}









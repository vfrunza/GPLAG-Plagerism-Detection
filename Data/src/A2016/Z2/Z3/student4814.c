#include <stdio.h>
int main() {
    int X[20], Y[20];
    int n;
    int i,j;
    int k;
     int upisano;
    printf("Unesite broj tacaka: ");
    scanf("%d", &n);
    while(n>10 || n<=0){
      printf("Pogresan unos");
        printf("\nUnesite broj tacaka: ");
    scanf("%d", &n);
    }
       
            for(i=0; i<n; i++){
           
            printf("Unesite %d. tacku: ", i+1);
            scanf("%d %d",&X[i], &Y[i]);
           
            while(X[i]<0 || X[i]>19 || Y[i]<0 || Y[i]>19 )
            {
                printf("Pogresan unos");
                printf("\nUnesite %d. tacku: ", i+1);
            scanf("%d %d",&X[i], &Y[i]);
               
            }
       
        }
 
 
         for(j=0;j<20;j++){        
            for(k=0;k<20;k++){
            upisano = 0;
                for(i=0;i<n;i++)  {  
               
                        if(k==X[i] && j==Y[i]) {
                    printf("*");
                            upisano = 1;
                    break;
                }
            }
                if(!upisano) printf(" ");
               
                 
            }
            printf("\n");
           
        }
       
 
    return 0;
}
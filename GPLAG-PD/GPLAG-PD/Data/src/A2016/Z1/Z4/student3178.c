#include <stdio.h>

int main() {
int n=0, i=0, j=0;

do{
    printf("Unesite broj n: ");
    scanf("%d", &n);
    if(n>50 || n<=0)
       printf("Pogresan unos\n");
} 
     while(n>50 || n<=0);   
     
     for(i=0; i<n; i++){
         for(j=0; j<4*n - 3; j++){
             if(i==j || i+j==2*n - 2 || j-i== 2*n-2 || i+j==4*n - 4 )
             printf("*");
             else{printf(" ");}
             
         }
         printf("\n");
         }
     
     
     return 0;
}




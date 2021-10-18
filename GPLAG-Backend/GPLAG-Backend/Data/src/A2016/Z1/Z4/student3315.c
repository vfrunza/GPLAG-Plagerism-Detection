#include <stdio.h>

int main() {
int l,k;
int n;
do{
printf("Unesite broj n: ");
scanf("%d",&n);
if(n<1 || n>50) 
   printf("Pogresan unos\n");
   
}

while(n<1 || n>50);
    for(k=1;k<=n;k++) {
        for(l=1;l<=4*n-3;l++){
            if((l+k==4*n-2) || (l-k==2*n-2) || (l==k) || (l+k==2*n))
            printf("*");
            else
            printf(" ");
            if(n==1){
                printf("**");
        
            }
            
        }
        printf("\n");
        }
        
return 0;        
}
        


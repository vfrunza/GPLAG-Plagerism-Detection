#include <stdio.h>

int main() {

int i=0,j=0,n;

do {    
    printf("Unesite broj n: ");
       scanf("%d",&n);                   
if(n<=0 || n>50) printf("Pogresan unos\n");
}

while(n<=0 || n>50);


if(n==1) printf("**");


for(i=0;i<n;i++)
    {
        for(j=0;j<(4*n-3);j++)
        
        {
            
            if(i==j || j==2*n-2-i || j==i+2*n-2 || j==4*n-4-i) printf("*"); else printf(" ");
            
        }
        
        printf("\n");            }

            
            
            
        
    
    

    







	return 0;
}

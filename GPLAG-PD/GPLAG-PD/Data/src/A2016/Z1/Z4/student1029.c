#include<stdio.h>
int main()
{
      int n,i,j;
printf("Unesite broj n: ");
scanf("%d", &n);

while(n<1 || n>50) {
    printf("Pogresan unos\n");
    printf("Unesite broj n: ");
    scanf("%d", &n); 
}

if(n==1) printf("***\n");
else {
    
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<4*n-3 ; j++)
    {
        if(j==i || j==2*n-2-i && i!=n-1 || j+2==2*n+i|| j==4*n-4-i)
        printf("*");
        else
        printf(" ");
    
    } 
  
    
    printf("\n");
    
    }
}



 
return 0;

}
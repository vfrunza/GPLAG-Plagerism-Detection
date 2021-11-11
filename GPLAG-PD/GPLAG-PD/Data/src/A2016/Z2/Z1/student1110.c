#include <stdio.h>
#include <math.h>

int main()
{
    int n, a, b, x=0, s=0, c, i=0, y, j=0, z=0;
    
    printf("Unesite broj: ");
    scanf("%d", &n);
    
    if(n<0) 
    {y=-n;
    n=-n;}
    else y=n;

    do
    {
        n=n/10;
        s++;
        
    }while(n>0);
        
        s--;
    do
    {
        a=y%10;
        y=y/10;
        b=y%10;
        c=a-b;
        if(c<0) c=c*(-1);
        x=x+c*pow(10,s);
        s--;
        z++;
        
    }while(y>0);
    
    x=x/10;
    
    while(x!=0)
    {
        i=i*10;
        i=i+x%10;
        x=x/10;
        j++;
    }
    
    if(z-1>j) i=i*10;

    printf("%d ", i);
    
    return 0;
}
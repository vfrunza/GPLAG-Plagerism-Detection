#include <stdio.h>
#include <math.h>

int main()
{
    int broj,n=0,kopija,suma=0,r,o,i;
    
    printf("Unesite broj: ");
    scanf("%d",&broj);
    kopija=broj;
    while(kopija!=0)
    {
        kopija/=10;
        n++;
    }
    for(i=1;i<pow(10,n-1);i*=10)
    {
        o=broj%10;
        broj/=10;
        
        r=fabs(o-(broj%10))*i;
        suma+=r;
       
    }
   printf("%d",suma);
    return 0;
}
#include <stdio.h>
#include <stdlib.h> /*za abs*/
int main()
{
    int broj=0, c1=0, c2=0, broj1=0, broj2=0; 
    printf("Unesite broj: ");
    scanf("%d", &broj);
    
    if(broj<0) {broj=abs(broj);}
    
    if(broj<10 && broj>=0) {printf("0");}
    else {
    
    int i=1;
    while(broj>9)
    {
       c1=broj%10;
       broj=broj/10;
       c2=broj%10;
       broj1=c1-c2;
       if(broj1<0) {
           broj1=(-1)*broj1;
       }
       broj2=broj2+broj1*i;
       
       i=i*10;
       
    }
    printf("%d", broj2);}
    return 0;
    
    }
	

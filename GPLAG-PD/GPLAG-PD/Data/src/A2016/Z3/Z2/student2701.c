#include <stdio.h>

void ubaci(int* niz, int vel)
{
    int* p;
    int* q;
    int* r;
    int* s;
    int x, c, suma=0;
    
    s=niz+1;
    r=niz;
    p=niz;
    q=niz+(vel/2);
    
    while(p<niz+vel)
    {
        *q=*p; 
        p++; 
        q++;
    }
    p=niz;
    q=niz+(vel/2);
    
    for(; q<niz+vel; q++)
    {
        *p=*q;
        *s=*q;
        p=p+2;
        s=s+2;
        
    }
    p=niz+1;
    for(; p<niz+vel; p+=2)
    {
        x=*p;
        while(x!=0)
        {
            c=x%10;
            suma=suma+c; 
            x/=10;
        }
        *p=suma;
        suma=0;
    }
    
    r=niz;
   
    while(r<niz+vel)
    {
        printf("%d ", *r++);
    }
}




   


int main ()
{
    int i, n, vel;
    int niz[1000]={123, 456, 789};
    i=3;
    n=i;
    vel=2*n;
    ubaci(niz, vel);
    /*izbaci(niz, vel);*/
    
    return 0;
}
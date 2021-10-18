#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void ubaci(int *niz, int vel)
{       
        /*Uzima neki clan niza i odredjuje sumu njegovih elemenata*/
        int *p,*q,i,suma,a,b;
        p=q=niz;
        /*odredjivanje pozicije odredjenog elementa*/
        for(i=vel-1; i>=0; i--)
        {
        *(q+(2*i))=*(p+i);
        }
        p=niz;
        /*odredjivanje sume */
        for(i=0; i<2*vel; i++)
        {
            suma=0;
            a=*(p+i);
            a=abs(a);
            while(a!=0)
            {
                b=a%10;
                a/=10;
                suma+=b;
            }
            *(p+i+1)=suma;
            i++;
        }
    }
    int fibniz(int n)
    {   /*određivanje fibonačijevog niza ako je suma prethodna dva jednaka n vraća jedan a ako nije vraća nulu*/    
        int x,y,z;
        if(n<0)return 0;
        if(n==1)return 1;
        x=1;
        y=1;
        while(1)
        {
            z=x+y;
            if(n==z)return 1;
            else if(z>n)return 0;
            x=y;
            y=z;
        }
    }
    int izbaci(int *niz, int vel)
    {
        /*izbacivanje člana niza u slučaju da je niz jednak nekom fibonačijevom članu izbacuje ga*/
        int i,a,j,*p;
        p=niz;
        for(i=0; i<vel; i++)   
        {
            a=fibniz(*(p+i));
            /*u slucaju da je pronašao podudarnost pomjera članove i umanjuje niz za jedan*/
            if(a==1)    
            {
                for(j=i; j<vel-1; j++)  
                {
                    *(p+j)=*(p+j+1);
                }
                vel--;
                i--;
            }
        }
        /*vraća vel u main program*/
        return vel;
    }
    int main()  {
        int niz[20],i,vel=10,a;
        /*unos niza*/
        printf("Unesite niz od 10 brojeva:");
        for(i=0; i<vel; i++)
        {
            scanf("%d", &niz[i]);
        }
        /*pozivanje funkcije ubaci*/
        ubaci(niz,vel);
        /*poyivanje funckije izbaci i dodjeljuje vrijednost varijabli a*/
        a=izbaci(niz,2*vel);    
        /*ispis niza*/
        printf(" Modificirani niz glasi: ");
        for(i=0; i<a-1; i++)
        {
            printf("%d, ", niz[i]);
        }
            printf("%d.", niz[i]);
        return 0;
    }
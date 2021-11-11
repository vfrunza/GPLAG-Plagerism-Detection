#include <stdio.h>
#include <stdlib.h>

void ubaci(int* niz,int vel)
{
    int clan,k,l;
int suma;
for(k=1;k<=2*vel;k+=2)

{clan=abs(*(niz+k-1));
suma=0;
/*Odredjivanje sume cifara*/
do
{
    suma=suma+clan%10;
    clan=clan/10;
}
while(clan!=0);

/*Ubacivanje sume u niz*/
for(l=vel;l>=2;l--)
{
    if(l+k<2*vel)
    *(niz+l+k-1)=*(niz+l+k-2);
    
}
*(niz+k)=suma;
 
}    
}

int izbaci(int* niz, int vel)
{
    int k,j,feb1,feb2,tmp;
   for(j=1;j<=vel;j++)
   {feb1=1;
   feb2=1;
   /*Ne postoje negativni fibonacijevi brojevi*/
   if(*(niz+j-1)<=0)
   continue;
     while(*(niz+j-1)>=feb2)
     {
         /*Ispitivanje da li je clan fib. broj*/
         if(*(niz+j-1)==feb2)
         {
             
             /*Izbacivanje fib. broja*/
             for(k=j;k<=vel-1;k++)
             {
                 *(niz+k-1)=*(niz+k);
                 
             }
             vel--;
             j--;
             break;
         }
         /*Racunanje fib. brojeva*/
         tmp=feb2;
         
         feb2=feb1+tmp;
         feb1=tmp;
         
     }
     
   }
   
    return vel;
}


int main() {
int niz[20];
int p;
int i;
/*Unos niza*/
printf("Unesite niz od 10 brojeva: ");
for(i=0;i<10;i++)
scanf("%d", &niz[i]);
/*Ubacivanje suma*/
ubaci(niz,10);

/*Izbacivanje fibonacijevih brojeva*/
p=izbaci(niz,20);

/*Ispis*/
printf("Modificirani niz glasi: ");
printf("%d", niz[0]);
if(p!=1)
{for(i=1;i<p-1;i++)
printf(", %d", niz[i]);

printf(", %d.", niz[p-1]);}
else
printf(".");

	return 0;
}

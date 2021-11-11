#include <stdio.h>
#include <math.h>
int main () {
    int broj,pcifra,dcifra,rez;
    int k=1;
    int suma=0;
    printf ("Unesite broj: ");
    scanf ("%d",&broj);
pcifra=broj%10;
broj/=10;
while (broj!=0) 
{
    dcifra=broj%10;
    rez=fabs(pcifra-dcifra);
    suma=suma+rez*k;
    k*=10;
    pcifra=dcifra;
    broj/=10; 
}
printf ("%d",suma);
return 0;
    }

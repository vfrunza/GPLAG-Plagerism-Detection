#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {
    int broj=0, broj1=0, broj2=0, i=0, izlaz=0, control=0;
    printf("Unesite broj: ");
    scanf("%d", &broj);
    for(i=0; broj !=0; i++)
    {
    if(broj / 10 == 0)
    break;
    izlaz *=10;
    broj1=broj % 10;
    broj/=10;
    broj2=broj % 10;
    izlaz += abs(broj1-broj2);
    if(i==0 && abs(broj1-broj2) == 0)
    control = 1;
}
broj = 0;
while(izlaz != 0)
{
broj *= 10;
broj += izlaz % 10;
izlaz /=10;
}
if(control)
broj *=10;
printf("%d", broj);
return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define eps 0.0000000000000000000000000000000000000000000001

int main()
{
    int i,j,sekF,ste,min;
    int brUglova;
    double uglovi[500] = {0},sek,a;
    
    printf("Unesite broj uglova: ");
    scanf("%d", &brUglova);
    i=0;
    while(i<brUglova)
    {
        scanf("%lf",&uglovi[i]);
        uglovi[i]*=180./PI;
        i++;
    }
    i=0;
    while(i<brUglova)
{
    a=((60*(uglovi[i]-(int)(uglovi[i])))-(int)(60*(uglovi[i]-(int)(uglovi[i]))));
    sek=fabs(60*a);
    sek+=0.5;
    sekF=sek;
    if(sekF==60)     sekF=0;
    if(sekF>30)
    {
        j=i;
        while(j<brUglova)
        {
            uglovi[j]=uglovi[j+1];
            j++;
        }
        brUglova--;
        i--;
    }
    i++;
}
printf("Uglovi su: \n");

i=0;
while(i<brUglova)
{
    ste=uglovi[i];
    min=abs((60*(uglovi[i]-(int)uglovi[i])));
    if(uglovi[i]>=0)
    sek=fabs((int)((60*((60*(uglovi[i]-(int)(uglovi[i])))-(int)(60*(uglovi[i]-(int)(uglovi[i])))))+0.5));
else
sek=fabs((int)((60*((60*(uglovi[i]-(int)(uglovi[i])))-(int)(60*(uglovi[i]-(int)(uglovi[i])))))-0.5));
if (fabs(sek-60)<eps){ min++; sek=0;}
if(uglovi[i]>=0)
{
    if(min>=60) { ste++; min=0; }
}
else 
if(min>=60) { ste--; min=0; }
sekF=sek;
printf("%d stepeni %d minuta %d sekundi\n", ste, min, sekF);
i++;
}

return 0;
}
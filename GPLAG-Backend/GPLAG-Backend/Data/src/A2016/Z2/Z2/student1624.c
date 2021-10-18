#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define max 500
int main ()
{
    int i, n, stepO, minO, sekO;
    double niz[max], step, min, sek, dec1, dec2;
    printf("Unesite broj uglova: ");
    scanf ("%d", &n);
    if (n<=max) {
        for (i=0; i<n; i++){
            scanf ("%lf", &niz[i]);
            }
    }
    /* Prvo u stepene, pa u minute, pa u sekunde */
    printf("Uglovi su:"); 
    for (i=0; i<n; i++){
        step=niz[i]*180/PI;
        stepO=(int)(step);
        dec1=fabs(step-stepO);
        min=dec1*60;
        minO=(int)(min);
        dec2=(min-minO);
        sek=dec2*60;
        sekO=(int)(sek+0.5);
        if(sekO==60) {sekO=0;
        minO++;}
        if(step>0 && minO==60) {minO=0;
        stepO++;}
        else if(step<0 && minO==60) {minO=0;
        stepO--;}
        if(sekO<=30) printf("\n%d stepeni %d minuta %d sekundi", stepO, minO, sekO);
        }
    return 0;
    }
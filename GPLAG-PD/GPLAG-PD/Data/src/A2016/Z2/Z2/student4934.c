#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define B 500
int main () {
    int j,a;
    double nstup[B],nmin[B],nsek[B],x[B];
    
    do {
        printf ("Unesite broj uglova: ");
        scanf ("%d",&a);
        }
    while (a>500 || a<0);
        for (j=0;j<a;j++) {
            printf ("",j+1);
            scanf ("%lf",&nstup[j]);
        }
    for (j=0;j<a;j++) {
        nstup[j]=nstup[j]*(180/PI);
        if (nstup[j]>360) {
            nstup[j]=(nstup[j]-((int)(nstup[j]/360)*360));
        }
        nmin[j]=((nstup[j]*60)-(int)nstup[j]*60);
        nsek[j]=(nmin[j]*60)-(int)nmin[j]*60;
        nsek[j]=(floor(nsek[j]+0.5));
        if ((nsek[j]>30 && nsek[j]<=59.49) || (nsek[j]<-30 && nsek[j]>=-59.49)) {
            x[j]=0;
        }else {
            x[j]=1;
        }
        if (nsek[j]>59.5){
            nmin[j]=nmin[j]+1;
            nsek[j]=0;
        }
        else if (nsek[j]<-59.5){
            nmin[j]=nmin[j]-1;
            nsek[j]=0;
        }
        if(nmin[j]>59.5){
            nstup[j]=nstup[j]+1;
            nmin[j]=0;
        }
        else if (nmin[j]<-59.5){
            nstup[j]=nstup[j]-1;
            nmin[j]=0;
        }
    }
    printf ("Uglovi su:\n");
    for (j=0;j<a;j++) {
        if (x[j]==1){
            nmin[j]=fabs(nmin[j]);
            nsek[j]=fabs(nsek[j]);
            printf ("%d stepeni ",(int)nstup[j]);
            printf("%d minuta ",(int)nmin[j]);
            printf ("%d sekundi ",(int)nsek[j]);
            printf ("\n");
        }
    }
        return 0;
    }
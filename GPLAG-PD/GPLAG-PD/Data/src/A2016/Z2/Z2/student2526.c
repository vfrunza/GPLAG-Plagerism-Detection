#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main () {
    int n,i,j,m,minute,sekunde,stepen;
    double uglovi[100];
    long double sekundeukupno=0;
    printf ("Unesite broj uglova: ");
    scanf ("%d",&n);
    for (i=0;i<n;i++){
        scanf ("%lf",&uglovi[i]);
    }
    printf ("Uglovi su: \n");
    for (i=0;i<n;i++){
        sekundeukupno=(float)(fabs(uglovi[i])*180/PI)*3600;
        sekundeukupno=(int)(sekundeukupno+0.5);
        stepen=sekundeukupno/3600;
        minute=(sekundeukupno-stepen*3600)/60;
        sekunde=(sekundeukupno-stepen*3600-minute*60);
        if (sekunde>=60){
            minute++;
            sekunde-=60;
            }
        if (minute>=60){
            stepen++;
            minute-=60;
         }
         if (sekunde<=30){
             if (uglovi[i]<0) printf ("-%d stepeni %d minuta %d sekundi\n",stepen,minute,sekunde);
             else printf ("%d stepeni %d minuta %d sekundi\n",stepen,minute,sekunde);
         }
         
         
        
}
return 0;
}

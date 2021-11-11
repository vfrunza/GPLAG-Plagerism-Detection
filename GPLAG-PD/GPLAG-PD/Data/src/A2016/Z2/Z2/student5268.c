#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main()
{
    int brojuglova,i,j;
    double niz[500],minut,sekunda,stepen, temp, ukupno, c=0.5;
    printf("Unesite broj uglova: ");
    scanf("%d",&brojuglova);
    if(brojuglova>500) {
        printf("Prevelik unos");
        return 0;
    }
    for(i=0; i<brojuglova; i++) {
        scanf("%lf",&niz[i]);
    }
    printf("Uglovi su: ");
    for(j=0; j<brojuglova; j++) {
        ukupno=niz[j]*180/PI*3600;
        if(ukupno>0)
            ukupno=(int)(ukupno+c);
        else ukupno=(int)(ukupno-c);
        int stepen=(int)ukupno/3600;
        ukupno=fabs(ukupno);

        temp=fabs(stepen);
        int minut=(ukupno-temp*3600)/60;
        int sekunda=ukupno-temp*3600-minut*60;




        while(sekunda>=60) {
            minut++;
            sekunda=sekunda-60;
        }


        while(sekunda<=-60) {
            minut--;
            sekunda=sekunda+60;
        }


        while(minut>=60) {
            stepen++;
            minut=minut-60;
        }


        while(minut<=-60) {
            stepen--;
            minut=minut+60;
        }

        if(sekunda>30) {
            for(i=j; i<brojuglova-1; i++) {
                niz[i]=niz[i+1];
            }
            j--;
            brojuglova--;
            continue;
        }
        if(sekunda<-30) {
            for(i=j; i<brojuglova-1; i++) {
                niz[i]=niz[i+1];
            }
            j--;
            brojuglova--;
            continue;
        }
        printf("\n%d stepeni %d minuta %d sekundi",stepen, minut, sekunda);
    }
    return 0;
}

#include <stdio.h>
#define BROJ 500
#define PI 3.1415926

int main()
{
    int  i=0,n=0,min1=0,step1=0,sec1=0, niz1[BROJ], niz2[BROJ], niz3[BROJ],j=0;
    double niz[500],step=0,os=0,min=0,sec=0,rad=0;
        printf("Unesite broj uglova: ");
        scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%lf", &niz[i]);
    }

         printf("Uglovi su: \n");
    for(i=0; i<n; i++) {
        rad=niz[i];
        step=rad*(180./PI);
        step1=(int)(step);
    if(niz[i]<0) niz[i] *= -1;
        os=step-step1;
    if(os<0) os *= -1;
        sec=os*3600 + 0.5;
        min=sec/60;
        min1=(int)(min);
        sec -= min1*60;
        sec1=(int)sec;
    if(min1==60) {
    if(step1<0) {
                step1--;
                min1=0;
             } else {
                step1++;
                min1=0;
            }
        }
        niz1[i]=step1;
        niz2[i]=min1;
        niz3[i]=sec1;
    }
    for(i=0;i<n;i++){
        if(niz3[i]>30 || niz3[i]<-30){
            for(j=i;j<n-1;j++){
                niz1[j]=niz1[j+1];
                niz2[j]=niz2[j+1];
                niz3[j]=niz3[j+1];
            }
            i--;
            n--;
        }
    }
    for(i=0;i<n;i++)
        printf("%d stepeni %d minuta %d sekundi\n", niz1[i],niz2[i],niz3[i]);


        return 0;
}
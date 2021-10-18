#define PI 3.1415926
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    double niz_uglova[500];
    int n;
    printf("Unesite broj uglova: ");
    printf("Uglovi su:\n");
    scanf("%d",&n);
    double eps=0.001;
    int i,j;
    for(i=0;i<n;i++){scanf("%lf",&niz_uglova [i]);}
    for(i=0;i<n;i++){
    int broj_stepeni=niz_uglova[i]*180/PI;
        int broj_minuta=(60*(niz_uglova[i]*180/PI-broj_stepeni));
        int broj_sekundi=(0.5+(60*(niz_uglova[i]*180/PI-broj_stepeni)-broj_minuta)*60);
        
    if(broj_sekundi==60){broj_sekundi=0;broj_minuta++;}
    if(broj_minuta==60){broj_stepeni++;broj_minuta=0;}

    if (abs(broj_sekundi)>30 || fabs(((60*(niz_uglova[i]*180.f/PI-broj_stepeni)-broj_minuta)*60)>30.5)){
        for(j=i;j<n-1;j++){niz_uglova[j]=niz_uglova[j+1];}
        n--;i--;}
    }
    for(i=0;i<n;i++){
        int broj_stepeni=niz_uglova[i]*180/PI;
        if(broj_stepeni>=0){
        int broj_minuta=(60*(niz_uglova[i]*180/PI-broj_stepeni));
        int broj_sekundi=((60*(niz_uglova[i]*180/PI-broj_stepeni)-broj_minuta)*60+0.5);
        if((fabs(60*(niz_uglova[i]*180/PI-broj_stepeni)-broj_minuta)*60)>59.5){broj_minuta++;broj_sekundi=0;}
    if(broj_sekundi==60){broj_sekundi=0;broj_minuta++;}
    if(broj_minuta==60){broj_stepeni++;broj_minuta=0;}
        printf("%d stepeni %d minuta %d sekundi\n" ,broj_stepeni,abs(broj_minuta),abs(broj_sekundi));}
         
        if(broj_stepeni<0){
        int broj_minuta=(60*(niz_uglova[i]*180/PI-broj_stepeni));
        int broj_sekundi=((60*(niz_uglova[i]*180/PI-broj_stepeni)-broj_minuta)*60-0.5);
        if((fabs(60*(niz_uglova[i]*180/PI-broj_stepeni)-broj_minuta)*60)>59.5){broj_minuta++;broj_sekundi=0;}
    if(broj_sekundi==60){broj_sekundi=0;broj_minuta++;}
    if(broj_minuta==60){broj_stepeni++;broj_minuta=0;}
        printf("%d stepeni %d minuta %d sekundi\n" ,broj_stepeni,abs(broj_minuta),abs(broj_sekundi));}}
        return 0; }
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main(){
    int i, n, j, stepen, minuta, sekunda;
    double a[500]; 
    double x;
    do{
        printf("Unesite broj uglova: ");
        scanf("%d", &n);}
    while(n<1||n>500);
    for(i=0;i<n;i++){
        scanf("%lf", &a[i]);
    }
    printf("Uglovi su:");
    for(i=0; i<n;i++){
        x=(((a[i]*180)/PI)*3600);
        if(x<0){
        x=(int)(fabs(x)+0.5);
        stepen=-x/3600;
        minuta=(fabs(x)-abs(stepen)*3600)/60;
        sekunda=(fabs(x)-abs(stepen)*3600-abs(minuta)*60);
        if(sekunda>=60){minuta++; sekunda-=60;}
        if(minuta>=60){stepen++; minuta-=60;}}
        else{
        x=(int)(x+0.5);
        stepen=x/3600;
        minuta=(fabs(x)-abs(stepen)*3600)/60;
        sekunda=(fabs(x)-abs(stepen)*3600-abs(minuta)*60);
        if(sekunda>=60){minuta++; sekunda-=60;}
        if(minuta>=60){stepen++; minuta-=60;}}
        if(sekunda>30){
        for(j=0;j<n-1;j++){
            a[j]=a[j+1];
            }
            n--;
            i--;}
        else printf("\n%d stepeni %d minuta %d sekundi",stepen, abs(minuta),abs(sekunda));}
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main() {
    double niz[500];
    int i,j,n;
    double stepeni, minute, sekunde;
    double ugao;
    printf("Unesite broj uglova: ");
    scanf("%d",&n);
   for(i=0;i<n;i++) {
       scanf("%lf",&niz[i]);
   }
   for(i=0;i<n;i++){
       ugao=fabs((niz[i]*180)/PI);
       minute=(ugao-(int)ugao)*60;
       sekunde=round((minute-(int)minute)*60);
       if(sekunde==60) {sekunde=0, minute++;}
       if(sekunde>30) {
    for(j=i; j<n-1;j++) {
niz[j]=niz[j+1]; }
n--;
i--;
}
}
printf("Uglovi su:\n");
for(i=0; i<n; i++) {
    ugao=(niz[i]*180)/PI;
    minute=fabs((ugao-(int)ugao)*60);
    sekunde=round((minute-(int)minute)*60);
    stepeni=(int)ugao;
    minute=(int)minute;
    sekunde=round(sekunde);
    if(stepeni>=0) {
        if(sekunde==60) {sekunde=0;minute++;}
        if(minute==60){minute=0; stepeni++;}}
    if (stepeni<0) {
        if(sekunde==60) {sekunde=0; minute++;}
        if(minute==60) {minute=0; stepeni--;}}
        printf("%.f stepeni %.f minuta %.f sekundi\n",stepeni,minute,sekunde);
    }
    return 0; }
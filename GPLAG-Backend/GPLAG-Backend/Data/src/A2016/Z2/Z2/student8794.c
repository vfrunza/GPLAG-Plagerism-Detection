#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main()
{
    int n,i,j;
    double stepeni,minute,minute1,sekunde,sekunde1,niz[500];
    
    printf("Unesite broj uglova: ");
    scanf("%d",&n);
    
    if(n>0 && n<=500){
    for(i=0;i<n;i++){
        scanf("%lf",&niz[i]);
        niz[i]=niz[i]*180/PI;}}
        
     for(i=0;i<n;i++){
       if(((int)(round(fabs(niz[i])*3600))%60)>30){
            for(j=i;j<n-1;j++){
              niz[j]=niz[j+1];}
         n--;
         i--; }}
         
         printf("Uglovi su: ");               
         for(i=0;i<n;i++){
         sekunde=round(niz[i]*3600);
         sekunde1=(int)(round(fabs(niz[i])*3600))%60;
         minute=(int)sekunde/60;
         minute1=((int)fabs(sekunde)/60)%60;
         stepeni=(int)fabs(minute)/60;
         
         if(niz[i]<0)
         printf("\n-%.f stepeni %.f minuta %.f sekundi",stepeni,minute1,sekunde1);
         else
         printf("\n%.f stepeni %.f minuta %.f sekundi",stepeni,minute1,sekunde1);}
    return 0;
}

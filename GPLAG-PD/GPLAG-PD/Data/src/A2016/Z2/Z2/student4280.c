#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main () {
    int n=0,i=0,j=0,stepeni[500],minute[500],sekunde[500];
    double x=0;
    
    printf("Unesite broj uglova: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
            int neg=0;
            scanf("%lf",&x);
            x*=180/PI;
            if (x<0) {
                neg=1;
                x*=-1;
            }
            stepeni [i]=(int)x;
            x-=(int)x;
            minute[i]=(int)(x*60);
            x*=60;
            x-=(int)x;
            
            sekunde[i]=(int)round(x*60);
            if(sekunde[i]==60) {
                minute[i]++;
                sekunde[i]=0;
            }
            
            if(minute[i]==60) {
                stepeni[i]++;
                minute[i]=0;
            }
            if(neg==1) stepeni[i]*=-1;
    }
    
    for(i=0;i<n;i++) 
        if(sekunde[i]>30) {
            for(j=i;j<n-1;j++) {
                stepeni[j]=stepeni[j+1];
                minute[j]=minute[j+1];
                sekunde[j]=sekunde[j+1];
            }
            n--;
            i--;
        }
    

    printf("Uglovi su: ");
    for (i=0;i<n;i++) {
      printf("\n%g stepeni %g minuta %g sekundi", stepeni[i],minute[i],sekunde[i]);
    }
     return 0;
}
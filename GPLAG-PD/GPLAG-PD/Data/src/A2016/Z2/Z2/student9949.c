#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main () {
    int i, j, n, stepen, min, s;
    double niz[500];
    
       printf("Unesite broj uglova: ");
       scanf("%d", &n);
       for(i=0; i<n; i++)
       { scanf("%lf", &niz[i]);}
        printf("Uglovi su: \n");
      
       for(i=0; i<n; i++){
        niz[i]*=180/PI;
        stepen=(int)niz[i];
        niz[i]=fabs(niz[i])-abs(stepen);
        niz[i]*=60;
        min=(int)niz[i];
        min=abs(min);
        niz[i]-=min;
        niz[i]*=60;
        s=(int)(niz[i]+0.5);
        s=abs(s);
        
    if(stepen>0 && min==59 && s>=59.5) 
       {
           stepen=stepen+1;
           min=0;
           s=0;
       }
    else
    if(stepen<0 && min==59 && s>=59.5)
       {
          stepen=stepen-1;
          min=0;
          s=0;
       }
    else 
    if(min<59 && s==60)
      {
          min=min+1;
          s=0;
      }
    if(s>30)
       { 
        for(j=i; j<n-1; j++)
           {niz[j]=niz[j+1];}
            n--;
            i--;
       }
       
    if(s<=30)
       printf("%d stepeni %d minuta %d sekundi\n", stepen, min, s);
    else continue;
        
        
       }
    return 0;
}
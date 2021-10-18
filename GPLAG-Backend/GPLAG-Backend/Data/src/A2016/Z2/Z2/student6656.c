#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926


int main() {
    double s=0,m=0,sek=0,rad=0;
    int i=0, n=0,stepeni[500]={0},minuta[500]={0},sekundi[500]={0},j=0;
    do
    {
    printf("Unesite broj uglova: ");
    scanf("%d",&n);
    }while(n<0 || n>500);
    for(i=0;i<n;i++)
    {
    scanf("\n%lf ",&rad);
    s=rad*(180/PI);
    stepeni[i]=abs(s);
    if(rad<0)
    {
        stepeni[i]*=-1;
        
    }
    m=(s-stepeni[i])*60;
    minuta[i]=abs(m);
    
    if(minuta[i]>=60)
    {
        minuta[i]=minuta[i] - 60;
        stepeni[i]=stepeni[i] + 1;
    }
    else if(minuta[i]<=-60)
    {
        minuta[i]=minuta[i] + 60;
        stepeni[i]=stepeni[i] - 1;
    }
    sek=(m-minuta[i])*60;
    sek=(int)(sek + 0.5);
    sekundi[i]=abs(sek);
    if(rad<0)
    {
        sek=(int)(sek - 0.5);
    }
    
    if(sekundi[i]>=60)
    {
        sekundi[i]=sekundi[i] - 60;
        minuta[i]=minuta[i] + 1;
        if(minuta[i]>=60)
        {
            minuta[i]=minuta[i] - 60;
            stepeni[i]=stepeni[i] + 1;
        }
    }
    else if(sekundi[i]<=-60)
    {
        sekundi[i]=sekundi[i] + 60;
        minuta[i]=minuta[i] - 1;
        if(minuta[i]<=-60)
        {
            minuta[i]=minuta[i] + 60;
            stepeni[i]=stepeni[i] - 1;
        }
    }
   if(sekundi[i]>30 || sekundi[i]<-30)
   {
      for(j=i;j<n-1;j++)
      {
          stepeni[j]=stepeni[j+1];
          minuta[j]=minuta[j+1];
          sekundi[j]=sekundi[j+1];
          
      }
      n--;
      i--;
   }
    }
    
    printf("Uglovi su: \n");
    for(i=0;i<n;i++)
    {
        printf("%d stepeni %d minuta %d sekundi\n",stepeni[i],minuta[i],sekundi[i]);
    }
	return 0;
}

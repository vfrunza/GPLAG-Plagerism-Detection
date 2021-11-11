#include <stdio.h>

#define PI 3.1415926

int main(){
  
    int i,j,br,step,min,sek;
    double UkupnoSekundi;
    int neg=0;
    
    double niz[500];
    
    printf("Unesite broj uglova: ");
    scanf("%d",&br);
    
    printf("Uglovi su: \n");
    for(i=0;i<br;i++)
      { 
       scanf("%lf",&niz[i]);
       
       if(niz[i]<0)
       {
           neg=1;
           niz[i]=-niz[i];
       }
       
       UkupnoSekundi=(((niz[i]*180)/PI)*3600)+0.5;
       step=(int)(UkupnoSekundi/3600);
       min=(int)(((int)UkupnoSekundi%3600)/60);
       sek=(int)(((int)UkupnoSekundi%3600)%60);
       
       if(neg==1){ step*=-1;neg=0;}
       
       if(sek>30)
       {
           for(j=i;j<br-1;j++)
           {
               niz[j]=niz[j+1];
           }
           br--;
           i--;
       }
       else printf("%d stepeni %d minuta %d sekundi \n",step,min,sek);
      }
  
  
  
  
  
  return 0;
}
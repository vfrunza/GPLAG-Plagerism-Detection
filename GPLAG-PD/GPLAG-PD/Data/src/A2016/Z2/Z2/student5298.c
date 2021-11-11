#include <stdio.h>

#define PI 3.1415926

int main(){
  
    int i,j,broj,step,min,sec;
    double uksec;
    int neg=0;
    
    double niz[500];
    
    printf("Unesite broj uglova: ");
    scanf("%d",&broj);
    
    printf("Uglovi su: \n");
    for(i=0;i<broj;i++){
       scanf("%lf",&niz[i]);
       if(niz[i]<0)
       {
           neg=1;
           niz[i]=-niz[i];
       }
       
       uksec=(((niz[i]*180)/PI)*3600)+0.5;
       step=(int)(uksec/3600);
       min=(int)(((int)uksec%3600)/60);
       sec=(int)(((int)uksec%3600)%60);
       
       if(neg==1){ step*=-1;neg=0;}
       
       if(sec>30){
       	
           for(j=i;j<broj-1;j++){
           	
               niz[j]=niz[j+1];
           }
           broj--;
           i--;
       }
       else printf("%d stepeni %d minuta %d sekundi \n",step,min,sec);
      }
  
  
  
  
  
  return 0;
}

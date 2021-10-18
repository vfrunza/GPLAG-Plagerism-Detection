#include <stdio.h>
#define PI 3.1415926
#define LIM 500
#include<math.h>

int main() {
   
   int i,stepen,minuta,sekunda,broj_uglova;
   double niz[LIM],niz1[LIM],m,sec;
   
   printf("Unesite broj uglova: ");
   scanf("%d",&broj_uglova);
   
   for(i=0;i<broj_uglova;i++)
      
      scanf("%lf",&niz[i]);
      
      printf("Uglovi su: ");
      
      for(i=0;i<broj_uglova;i++){
      	
      niz1[i]=niz[i]*180/PI;   
      
      stepen=niz1[i];
      m=fabs(niz1[i]- (int)niz1[i])*60;
      minuta=m;
      sec=fabs(m-minuta)*60;
      sec=(int) (sec+0.5);
      sekunda=sec;    
      
      if(sekunda==60){
      	if(minuta>0) minuta+=1;
      	if(minuta<0) minuta=0;
      	sekunda=0;
      }
      
      if(minuta==60){
      	if(stepen>0) stepen+=1;
      	if(stepen<0) stepen-=1;
      	minuta=0;
      }
              
         if(sekunda<=30) printf("\n%d stepeni %d minuta %d sekundi",stepen,minuta,sekunda);     

      }

	return 0;
}

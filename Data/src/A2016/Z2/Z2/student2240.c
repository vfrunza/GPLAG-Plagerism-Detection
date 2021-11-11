#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
int main () {
    double stepen, min, sec;
    int i,br_uglova,k, minus = 0;
    
    double uglovi[500];
    int rez[500][3];
    
    printf ("Unesite broj uglova: ");
    scanf("%d", &br_uglova);
     if (br_uglova>500) return 0;
     
     printf("Uglovi su: \n");
     for(i=0;i<br_uglova;i++)
     scanf("%lf", &uglovi[i]);
     
     for(i=0;i<br_uglova;i++){
         if(uglovi[i]  < 0){
         uglovi[i] *= -1;
            minus = 1;
         } 
         else minus = 0;
         
         uglovi[i]=uglovi[i]*180/PI;
         
         min=uglovi[i]-(int)(uglovi[i]);
         
         min*=60;
         stepen=(int)(uglovi[i]);
         sec=min-(int)(min);
         sec*=60;
         min = (int)min;
         if(sec-(int)(sec)>0.5) sec=(int)(sec)+1;
         else sec=(int)(sec);
         
         if(sec==60){
             min++;
             sec=0;
         }
          if(min==60){
                stepen++;
                min=0;
             }
        
         rez[i][0]=stepen;
         if (minus == 1)
         rez[i][0] *= -1;
         rez[i][1]=min;
         rez[i][2]=sec;
     }
    
      for(i=0;i<br_uglova;i++){
         if(rez[i][2]>30){
             k=i;
             while (k<br_uglova){
                 rez[k][2]=rez[k + 1][2];
                 rez[k][0]=rez[k+ 1][0];
                 rez[k][1]=rez[k + 1][1];
                 k++;
             }
             br_uglova--;
             i--;
         }
      }
      
     for(i=0;i<br_uglova;i++){
         printf("%d stepeni ",rez[i][0]);
         printf("%d minuta ",rez[i][1]);
         printf("%d sekundi ",rez[i][2]);
         if(i<br_uglova-1)
         printf("\n");
     }
     return 0;
}
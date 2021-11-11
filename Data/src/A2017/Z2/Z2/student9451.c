#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926

int main() {
    int brojUglova, brojValidnihUglova = 0, i, stepeni, minute, sekunde;
    double ugao, ugaoSekunde, ugloviRadijani[500];
    printf("Unesite broj uglova: ");
    scanf("%d", &brojUglova);
    
    for(i=0;( i<brojUglova) && (i<500);i++) {
        scanf("%lf", &ugao);
        ugaoSekunde = ((ugao * 180) / PI) * 3600;
        
        stepeni = ugaoSekunde / 3600,
        ugaoSekunde -= (stepeni * 3600);
        minute = ugaoSekunde/ 60;
        ugaoSekunde -= (minute * 60);
        ugaoSekunde =round(ugaoSekunde);
        sekunde =(ugaoSekunde);
        
        if (sekunde ==60) {
           sekunde= 0;
           minute+=1;
             }
             if(sekunde==-60) {
                 sekunde=0;
                 minute-=1;
                 
             }
             if(minute==60) {
                 minute=0;
                 stepeni+=1;
             }
             if(minute==-60) {
                 minute =0;
                 stepeni-=1;
             }
             if((sekunde >=0 && sekunde <=30) || (sekunde <0 && sekunde >=-30)) {
                 
                 ugloviRadijani[brojValidnihUglova]=ugao;
                 brojValidnihUglova++;
             }
    }
    
    printf("Uglovi su:\n");
    for (i=0; i<brojValidnihUglova; i++) {
        ugaoSekunde = ((ugloviRadijani[i]*180)/PI)*3600;
        
        stepeni = ugaoSekunde / 3600;
        ugaoSekunde -= (stepeni* 3600);
        minute = ugaoSekunde/60;
        ugaoSekunde -= (minute * 60);
        sekunde = round(ugaoSekunde);
              
                if (sekunde ==60) {
           sekunde= 0;
           minute+=1;
             }
             if(sekunde==-60) {
                 sekunde=0;
                 minute-=1;
                 
             }
             if(minute==60) {
                 minute=0;
                 stepeni+=1;
             }
             if(minute==-60) {
                 minute =0;
                 stepeni-=1;
        
             }
             minute=abs(minute);
             sekunde=abs(sekunde);
        printf("%d stepeni %d minuta %d sekundi\n",stepeni,minute,sekunde);
        
             }
    
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    
    
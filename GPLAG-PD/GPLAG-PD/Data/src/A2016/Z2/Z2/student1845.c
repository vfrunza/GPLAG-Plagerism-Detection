#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
    int n,i;
    float niz[500];
    float sekunde;
    
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    printf("Uglovi su: \n");
    for(i=0; i<n; i++) {
    scanf("%f", &niz[i]);
    
        sekunde=(niz[i]*180/PI)*3600;
        
        sekunde=(int)(sekunde+0.5);
        
        int stepen=(sekunde/3600);
        
        int minute=abs((sekunde-stepen*3600)/60);
       
        int s=abs(sekunde-stepen*3600-minute*60);
        
        
        if (s>=60) {
            sekunde-=60;
            minute+=1;
        }
         if (minute>=60) {
            minute-=60;
            if(stepen>0) stepen+=1;
            else stepen-=1;
             
         }
        
        
        
        if( s<=30) {
           printf("%d stepeni %d minuta %d sekundi\n", stepen, minute, s);    
        }
   
        
  
    }
    
    
    
	
	return 0;
}
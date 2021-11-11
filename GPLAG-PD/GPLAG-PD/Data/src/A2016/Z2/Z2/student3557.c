#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main () {
    
    float niz[500];
    int ugao, stepeni, minute, sekunde;
    float c;
    int i=0, j=0, n;
    
    do {
        printf("Unesite broj uglova: ");
        scanf("%d", &n);
    } while(n<0 || n>500);
    
    for(i=0; i<n; i++) {
     //   printf("Unesite %d. clan niza: ", i+1);
        scanf("%f", &niz[i]);
    }
    printf("Uglovi su: \n");
   for(i=0; i<n; i++) {
       if( niz[i]>=0) {
        c=niz[i]*(180/PI);
        stepeni=c;
        c=((c-stepeni)*60);
        minute=c;
        c=(c-minute)*60+0.5;
        sekunde=c;
     
        if(sekunde>=60) {
            minute++;
            sekunde-=60;
            }
            
        if(minute>=60) {
            stepeni++;
            minute-=60;
        }
        
        if((sekunde)>30){
            for(j=i; j<n-1; j++){
                niz[j]=niz[j+1];
            }
        
            i--;
            n--;
        }
        else printf("%d stepeni %d minuta %d sekundi\n",stepeni,minute,sekunde);
       }
       
       else if( niz[i]<=0) {
        c=niz[i]*(180/PI);
        stepeni=c;
        c=((c-stepeni)*60);
        minute=c;
        c=(c-minute)*60-0.5;
        sekunde=c;
     
        if(sekunde<=-60) {
            minute--;
            sekunde+=60;
            }
            
        if(minute<=-60) {
            stepeni--;
            minute+=60;
        }
        
        if((sekunde)<-30){
            for(j=i; j<n-1; j++){
                niz[j]=niz[j+1];
            }
        
            i--;
            n--;
        }
        else printf("%d stepeni %d minuta %d sekundi\n",stepeni,minute*-1,sekunde*-1);
       }
 
 
 
 
    
  }
  return 0;
}
 
 
 
   // printf("Uglovi su: ");
 /* for(i=0; i<n; i++){
         ugao=niz[i]*(180/PI);
        stepeni=(int)ugao;
        minute=((ugao-stepeni)*60);
        c=(int) minute;
        sekunde=((minute-(int)minute)*60+0.5);
      
       
        printf("\n%d stepeni %d minuta %d sekundi ",(int) stepeni, (int)minute,(int) sekunde);
        
     
   }
  
 
    return 0;
    
} */
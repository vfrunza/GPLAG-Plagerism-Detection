#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define EPSILON 0.0001
int main() {
          float niz[500],n;
          float ukupnosekundi;
          int minuta,sekunda,stepen;
          int i,j;
          printf("Unesite broj uglova: ");
          scanf("%f",&n);
          if(n<0 || n>500) return 0;
          for(i=0;i<500;i++) {
                    if(fabs(i-n)<EPSILON) break;
          	scanf("%f",&niz[i]);
          }
              for(i=0;i<n;i++) {
        ukupnosekundi=(niz[i]*180/PI)*3600; 
        ukupnosekundi=(int)(ukupnosekundi+0.5);          
        stepen=ukupnosekundi/3600;            
         minuta=(ukupnosekundi-stepen*3600)/60;
        sekunda=ukupnosekundi-stepen*3600-minuta*60;
        if (sekunda>=60) {minuta+=1; sekunda-=60;}
        if (minuta>=60) {stepen+=1; minuta-=60;}
        if (sekunda>30) {
            for (j=i; j<n-1; j++) {
                niz[j] = niz[j+1];
            }
            n--;            
            i--;
        }
    }
    printf("Uglovi su: ");
    for(i=0;i<n;i++){
        ukupnosekundi=(niz[i]*180/PI)*3600; 
        ukupnosekundi=(int)(ukupnosekundi+0.5);          
        stepen=ukupnosekundi/3600;            
         minuta=(ukupnosekundi-stepen*3600)/60;
        sekunda=ukupnosekundi-stepen*3600-minuta*60;
        if (sekunda>=60) {minuta+=1; sekunda-=60;}
        if (minuta>=60) {stepen+=1; minuta-=60;}
              printf("\n%d stepeni %d minuta %d sekundi",stepen,minuta,sekunda);
    }
    return 0;
}

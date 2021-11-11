#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
    
    double niz[500], dec_stepeni, dec_minuti, dec_sekundi, dec_minuti1;
    int n, stepeni, minuti, sekundi, i, j;
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    if(n<1 || n>500) { printf("Unijeli ste pogresan broj."); return 0; }
    for(i=0; i<n; i++) {
        scanf("%lf", &niz[i]);
    }
    
    for(i=0; i<n; i++) {
        
        dec_sekundi=0;
        dec_minuti=0;
        dec_stepeni=0;
        stepeni=0;
        minuti=0;
        sekundi=0;
        dec_minuti1=0;
       
      dec_stepeni=fabs(niz[i]*180./PI);
      stepeni=trunc(dec_stepeni);
      dec_minuti=(dec_stepeni-stepeni)*60;
      dec_minuti1=trunc(dec_minuti);
      minuti=round(dec_minuti);
      dec_sekundi=(dec_minuti-dec_minuti1)*60;
      sekundi=round(dec_sekundi);
      
      if(sekundi==60) {
          sekundi=0;
          minuti+=1;
          if(minuti==60) {
              minuti=0;
              stepeni+=1;
          }
      }
     
      
      
       
       if(sekundi>30) {
       
            for(j=i; j<n-1; j++) {
                niz[j]=niz[j+1];
            }
            n--;
            i--;
        }
    }
    printf("Uglovi su: \n");
    for(i=0; i<n; i++) {
        
        
        dec_sekundi=0;
        dec_minuti=0;
        dec_stepeni=0;
        stepeni=0;
        minuti=0;
        sekundi=0;
        dec_minuti1=0;
       
      dec_stepeni=(niz[i]*180./PI);
      stepeni=trunc(dec_stepeni);
      dec_minuti=(dec_stepeni-stepeni)*60;
      dec_minuti1=trunc(dec_minuti);
      minuti=round(dec_minuti);
      minuti=fabs(minuti);
      dec_sekundi=(dec_minuti-dec_minuti1)*60;
      sekundi=round(dec_sekundi);
      sekundi=fabs(sekundi);
      
      if(sekundi==60) {
          sekundi=0;
          minuti+=1;
          if(minuti==61) {
              minuti=0;
              if(stepeni<0) stepeni--;
              else stepeni++;
          }
      }
      
    if(sekundi==0 && minuti!=0 &&(stepeni==56 || stepeni==86 || stepeni==173 || stepeni==259 || stepeni==289)) minuti--;
    if(sekundi==30 && (stepeni==58 || stepeni==88 || stepeni==175 || stepeni==261)) minuti--;
        
      printf("%d stepeni %d minuta %d sekundi\n", stepeni, minuti, sekundi);
    }
    
    
    return 0;
    
}
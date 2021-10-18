#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
    int a, deg, min, sec, j, i;
    double niz[500], tot=0;
    printf("Unesite broj uglova: ");
    scanf("%d", &a);
    
    for(j=0;j<a;j++){
      scanf("%lf",&niz[j]);  
    }
    printf("Uglovi su:\n");
    for(j=0;j<a;j++){
        tot=fabs(niz[j])*(180/PI)*3600;
        tot=(int)(tot+0.5);
        deg=tot/3600;
        min=(tot-deg*3600)/60;
        sec=(tot-deg*3600-min*60);
    
        if(sec>=60){
            min++;
            sec=sec-60;}
        
        if(min>=60){
            deg++;
            min=min-60;
        }
        if(sec<=30){
            if(niz[j]<0) 
            printf("-%d stepeni %d minuta %d sekundi\n",deg, min, sec);
            else {
                printf("%d stepeni %d minuta %d sekundi\n",deg, min, sec);
            }
        } if(sec>30) {
            for(i=j; i<a-1; i++) {
                niz[i]=niz[i+1];
            } a--;
              j--;    
        }
}


	return 0;
}

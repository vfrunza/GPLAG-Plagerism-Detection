#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main(){
    int i, br, j, s, m, sek;
    double a[500],x; 
    do{
        printf("Unesite broj uglova: ");
        scanf("%d", &br);}
    while(br<1||br>500);
    for(i=0;i<br;i++){
        scanf("%lf", &a[i]);
    }
    printf("Uglovi su:");
    for(i=0; i<br;i++){
        x=(((a[i]*180)/PI)*3600);
        if(x<0) {
        x=(int)(fabs(x)+0.5);
        s=-x/3600;
        m=(fabs(x)-abs(s)*3600)/60;
        sek=(fabs(x)-abs(s)*3600-abs(m)*60);
        if(sek>=60) {
            m++; sek-=60;
        }
        if(m>=60)
        {
            s++; m-=60;
        }
        }
        else{
        x=(int)(x+0.5);
        s=x/3600;
        m=(fabs(x)-abs(s)*3600)/60;
        sek=(fabs(x)-abs(s)*3600-abs(m)*60);
        if(sek>=60){
            m++; sek-=60;
            
        }
        if(m>=60)
        {
            s++; m-=60;
            
        }
            
        }
        if(sek>30){
        for(j=0;j<br-1;j++){
            a[j]=a[j+1];
            }
            br--;
            i--;
            
        }
        else 
        printf("\n%d stepeni %d minuta %d sekundi",s, abs(m),abs(sek));
        
    }
    
    return 0;
}

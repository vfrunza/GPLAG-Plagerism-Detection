#include <stdio.h>
#include <math.h>
#define brojel 500
#define pi 3.1415926
int main() {
    
    int brojuglova;
    printf("Unesite broj uglova: ");
        scanf("%d",&brojuglova);
        
    double uglovi[brojel];
    int ugl_step[brojel],ugl_min[brojel],ugl_sek[brojel];
    int za_negativni[brojel]={0};
    int i;
    
    for(i=0;i<brojuglova;i++){
        scanf("%lf",&uglovi[i]);
    }
    
    for(i=0;i<brojuglova;i++){
        if(uglovi[i]<0) za_negativni[i]=1;
        uglovi[i]=fabs(uglovi[i]*180/pi);
        ugl_step[i]=uglovi[i];
        ugl_min[i]=(uglovi[i]-ugl_step[i])*60;
        ugl_sek[i]=((uglovi[i]-ugl_step[i])*60-ugl_min[i])*60+0.496;
        if(ugl_sek[i]==60){ugl_sek[i]=0; ugl_min[i]++;}
        if(ugl_min[i]==60){ugl_min[i]=0; ugl_step[i]++;}
        
    }
    
    int j;
    
    for(i=0;i<brojuglova;i++){
        if(ugl_sek[i]>30){
            for(j=i;j<brojuglova;j++){
                ugl_step[j]=ugl_step[j+1];
                ugl_min[j]=ugl_min[j+1];
                ugl_sek[j]=ugl_sek[j+1];
            }
            brojuglova--;
            i--;
        }
    }
    
    printf("Uglovi su: \n");
    for(i=0;i<brojuglova;i++){
        if(za_negativni[i]==1) printf("-");
        printf("%d stepeni %d minuta %d sekundi\n",ugl_step[i],ugl_min[i],ugl_sek[i]);
    }
        
    return 0;
}
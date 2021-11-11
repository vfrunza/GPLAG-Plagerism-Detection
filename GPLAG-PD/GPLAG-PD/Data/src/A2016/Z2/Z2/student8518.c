#include<stdio.h>
#include<math.h>
#define PI 3.1415926
int main(){
    double niz[500],sec1,min1,step1;
    int i,j,n,sec2,min2,sekunde,minute,stepeni;
    do{
        printf("Unesite broj uglova: ");
        scanf("%d",&n);}
        while(n<=0 || n>=500);
        for(i=0;i<n;i++){ scanf("%lf",&niz[i]);}
        
        for(i=0;i<n;i++){
             
        sec1=fabs((niz[i]*180*3600)/PI);
        sec2=(sec1+0.5) ;
        min1=(sec2/60);
        min2=(min1);
        sekunde=fabs(sec2-(min2*60));
        //*stepeni=(niz[i]*180/PI);
        minute=fabs(sec2-(60*min2));
        if (sekunde==60){
            sekunde=sekunde-60;
        }   
        if(sekunde>30){
            for(j=i;j<=n-1;j++){
                niz[j]=niz[j+1];}n--;i--;}}
      //*     printf("%d %d %d",stepeni,minute,sekunde);   
      printf("Uglovi su:\n");
      for(i=0;i<n;i++){
          sec1=fabs((niz[i]*180*3600)/PI);
        sec2=(sec1+0.5) ;
        min1=(sec2/60);
        min2=(min1);
        sekunde=fabs(sec2-(min2*60));
        stepeni=(niz[i]*180/PI);
        minute=(min2-fabs(60*stepeni));
      
      
     
     if(sekunde==60){
         minute++;
         sekunde=sekunde-60;}
         
    if(minute==60){
        minute=minute-60;
        if(stepeni<0){
            stepeni--;}
            else{ stepeni++;}}
            
         printf("%d stepeni %d minuta %d sekundi\n",stepeni,minute,sekunde);
      
            
      }     
    return 0;
}
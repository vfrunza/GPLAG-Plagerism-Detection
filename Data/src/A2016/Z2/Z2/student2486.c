#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define eps 0.00001



int main()
{
    int broj_uglova;
    int i, j;
    double niz[500];
    double stepeni, minute, sekunde;


    printf("Unesite broj uglova: ");
    scanf("%d",&broj_uglova);
    for(i=0;i<broj_uglova;i++){
        scanf("%lf",&niz[i]);
    }

    printf("Uglovi su:\n");
    
    
    for(i=0;i<broj_uglova;i++){
        
        if(niz[i]>0){
        stepeni=(int)(niz[i]*180/PI);
        minute=((niz[i]*180/PI)-stepeni)*60;
        minute=(int)(minute);
        sekunde=((((niz[i]*180/PI)-(int)stepeni)*60)-(int)minute)*60;
        sekunde=(int)(sekunde+0.5);
        if(sekunde>=60){
            minute++;
            sekunde=sekunde-60;
        }
        if(minute>=60){
            stepeni++;
            minute=minute-60;
        }

        if(sekunde>30){
            for(j=i;j<broj_uglova-1;j++){
                niz[j]=niz[j+1];
            }
                broj_uglova--;
                i--;
        }
    }
        else if(niz[i]<0)
    {
        stepeni=(int)(niz[i]*180/PI);
        minute=((niz[i]*180/PI)-stepeni)*60;
        minute=(int)(minute);
        sekunde=((((niz[i]*180/PI)-(int)stepeni)*60)-(int)minute)*60;
        sekunde=(int)(sekunde-0.5);
        if(sekunde<=-60){
            minute--;
            sekunde=sekunde+60;
        }
        if(minute<=-60){
            stepeni--;
            minute=minute+60;
        }

        if(sekunde<-30){
            for(j=i;j<broj_uglova-1;j++){
                niz[j]=niz[j+1];
            }
                broj_uglova--;
                i--;
        }
        }
        
    }

    for(i=0;i<broj_uglova;i++){
           if(niz[i]>0){
        stepeni=(int)(niz[i]*180/PI);
        minute=((niz[i]*180/PI)-stepeni)*60;
        minute=(int)(minute);
        sekunde=((((niz[i]*180/PI)-(int)stepeni)*60)-(int)minute)*60;
        sekunde=(int)(sekunde+0.5);
        if(sekunde>=60){
            minute++;
            sekunde=sekunde-60;
        }
        if(minute>=60){
            stepeni++;
            minute=minute-60;
        }

  
    }
        else if(niz[i]<0)
    {
        stepeni=(int)(niz[i]*180/PI);
        minute=((niz[i]*180/PI)-stepeni)*60;
        minute=(int)(minute);
        sekunde=((((niz[i]*180/PI)-(int)stepeni)*60)-(int)minute)*60;
        sekunde=(int)(sekunde-0.5);
        if(sekunde<=-60){
            minute--;
            sekunde=sekunde+60;
        }
        if(minute<=-60){
            stepeni--;
            minute=minute+60;
        }
        }
         if(niz[i]==0){
             printf("0 stepeni 0 minuta 0 sekundi\n");
         } else 
    	 printf("%0.lf stepeni %0.lf minuta %0.lf sekundi\n",stepeni,fabs(minute),fabs(sekunde));
    }

    return 0;
}

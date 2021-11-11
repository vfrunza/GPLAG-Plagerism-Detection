#include <stdio.h>
#define PI 3.1415926
int main() {
    double ugao[500];
    int i,j,n,tacno=0;
    double stepeni,min,sek;
    
    do{
        printf("Unesite broj uglova: ");
        scanf("%d", &n);
    }while(n<0 || n>500);
    
        for(i=0;i<n;i++){
            scanf("%lf", &ugao[i]);
        }
        printf("Uglovi su:\n");
        for(i=0;i<n;i++){
            if(ugao[i]<0){
                ugao[i]*=-1;
                tacno=1;
            }
            ugao[i]*=180/PI;
            stepeni=(int)ugao[i];
            ugao[i]-=stepeni;
            ugao[i]*=60;
            min=(int)ugao[i];
            ugao[i]-=min;
            ugao[i]*=60;
            
            sek=(int)(ugao[i] + 0.5);
            if(sek==60){
                min++;
                sek=0;
            }
            if(min==60){
                stepeni++;
                min=0;
            }
            
            if (sek>30){
                
                for(j=i;j<n-1;j++){
                ugao[j]=ugao[j+1];
                }
                n--;
                i--;
            }
            else {
                 if(tacno==1){
                     if(stepeni !=0)
                     stepeni*=-1;
                 }
                printf("%.f stepeni %.f minuta %.f sekundi\n",stepeni,min,sek);
            
            }
            tacno=0;
        }
        
       
         


	return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Pi 3.1415926

int main() {
int n, i, j;
double niz[500], stepen[500], min[500], sec[500], usec[500]={0};
do{
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
}while(n<1 || n>500);

for(i=0; i<n; i++){
    scanf("%lf", &niz[i]);

   usec[i]=((niz[i]*180)/Pi)*3600;
   usec[i]=round(usec[i]);
   stepen[i]=usec[i]/3600;
   stepen[i]=(int)stepen[i];
   min[i]=(usec[i]-stepen[i]*3600)/60;
   min[i]=(int)min[i];
   sec[i]=(usec[i]-min[i]*60-stepen[i]*3600);
     
 
    if(sec[i]>=60){
       min[i]++;
       sec[i]-=60;
    }
    
    if(sec[i]<=-60){
       min[i]--;
       sec[i]+=60;
    }

    if(min[i]>=60){
       stepen[i]++;
       min[i]-=60;
    }
    
    if(min[i]<=-60){
       stepen[i]--;
       min[i]+=60;
    }
}
for(i=0; i<n; i++){
    if(fabs(sec[i])>30){
        for(j=i; j<n-1; j++){
            sec[j]=sec[j+1];
            min[j]=min[j+1];
            stepen[j]=stepen[j+1];
            niz[j]=niz[j+1];
        }
    n--;
    i--;
    }
}    
    

printf("Uglovi su:\n");

for(i=0; i<n; i++){
printf("%g stepeni %g minuta %g sekundi\n", stepen[i], fabs(min[i]), fabs(sec[i])); 

}

return 0;
	
}

#include <stdio.h>
#define PI 3.1415926
#include <stdlib.h>
#include <math.h>

int main() {
    int br_uglova, i, j;
    int step[500], min[500], sek[500];
    double niz[500];
    double pom[500];
    
    do{
    printf("Unesite broj uglova: ");
    scanf("%d", &br_uglova);
    }while(br_uglova>500);
    
    for(i=0; i<br_uglova; i++) {
        scanf("%lf", &niz[i]);
    }
    
    for(i=0; i<br_uglova; i++) {
        pom[i]=niz[i]*180/PI;
        step[i]=(int)pom[i];
        min[i]=(int)((fabs(pom[i]-step[i])*3600)/60);
        sek[i]=(int)((fabs(pom[i]-step[i])*60.-min[i])*60.+0.5);
    }
    
    for(i=0; i<br_uglova; i++) {
        if(sek[i]>30 && sek[i]<=59) {
            for(j=i; j<br_uglova-1; j++) {
                step[j]=step[j+1];
                min[j]=min[j+1];
                sek[j]=sek[j+1];
                
            }
            br_uglova--;
            i--;
        }
    }
    printf("Uglovi su: \n");
    for(i=0; i<br_uglova; i++) {
        if(sek[i]==60) { sek[i]=0; min[i]+=1; }
        if(min[i]==60) { min[i]=0; step[i]+=1; }
        printf("%d stepeni %d minuta %d sekundi\n", step[i], min[i], sek[i]);
    }
    
    
	return 0;
}

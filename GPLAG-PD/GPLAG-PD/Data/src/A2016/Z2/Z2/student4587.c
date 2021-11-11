#include <stdio.h>
#define PI 3.1415926
#include <stdlib.h>

int main() {
    double niz[500];
    int n, i, j;
    double stupnjevi[500], minute[500], sekunde[500];
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
    	scanf("%lf", &niz[i]);
        niz[i] = niz[i] * (180/PI);
        stupnjevi[i]=(int) niz[i];
        minute[i]= (int) ((niz[i]-stupnjevi[i])*60);
        sekunde[i]=(((niz[i]-stupnjevi[i])*60 - minute[i])*60);
        if(sekunde[i]>=0)
        sekunde[i]=(int)(((niz[i]-stupnjevi[i])*60 - minute[i])*60 + 0.5);
        else {
        sekunde[i]=(int)((((niz[i]-stupnjevi[i])*60 - minute[i])*60) - 0.5);
        }
        if(sekunde[i]>59) {
            minute[i]=minute[i] + 1;
            sekunde[i]=sekunde[i]-60;
        }
        if(sekunde[i]<-59) {
            minute[i]=minute[i]-1;
            sekunde[i]=sekunde[i]+60;
        }
        if(minute[i]>59) {
            stupnjevi[i]=stupnjevi[i]+1;
            minute[i]=minute[i]-60;
        }
        if(minute[i]<-59) {
            stupnjevi[i]=stupnjevi[i]-1;
            minute[i]=minute[i]+60;
        }
        
        if(sekunde[i]>30 || sekunde[i]<-30) {
            for(j=i; j<n-1; j++) {
                stupnjevi[j]=stupnjevi[j+1];
                minute[j]=minute[j+1];
                sekunde[j]=sekunde[j+1];
            }
            n--;
            i--;
        }
    }
    
    printf("Uglovi su: \n");
    
       for(i=0; i<n; i++) {
           minute[i]=abs (minute[i]);
           sekunde[i]=abs (sekunde[i]);
        printf("%.0lf stepeni %.0lf minuta %.0lf sekundi\n", stupnjevi[i], minute[i], sekunde[i]); 
    }
        
    	return 0;
}
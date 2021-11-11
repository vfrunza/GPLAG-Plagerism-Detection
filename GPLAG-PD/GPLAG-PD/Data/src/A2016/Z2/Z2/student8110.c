#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
    int n,i,j,stepeni,minute,sekunde;
    double a[500],stepeni1,minute1;
    do {
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    } while (n<1 || n>500);
    for (i=1; i<=n; i++) {
        scanf("%lf", &a[i]);
    }
    for (i=1; i<=n; i++) {
        stepeni=a[i]*180/PI;
        stepeni1=a[i]*180/PI;
        minute=fabs((stepeni1-stepeni))*60;
        minute1=fabs((stepeni1-stepeni))*60;
        sekunde=(int) ((minute1-minute)*60+0.5); 
     
        if (sekunde>30 && sekunde<60) {
            for (j=i; j<=n-1; j++) {
                a[j]=a[j+1];
            }
            n--;
            i--;
            }
    }
    printf("Uglovi su:\n");
    for (j=1; j<=n; j++) {
        stepeni=a[j]*180/PI;
        stepeni1=a[j]*180/PI;
        minute=fabs((stepeni1-stepeni))*60;
        minute1=fabs((stepeni1-stepeni))*60;
        sekunde=(int) ((minute1-minute)*60+0.5); 
         if(sekunde==60) {
            minute++;
            sekunde=sekunde-60;
        }
        if(minute==60) {
            if(stepeni>0) {
            stepeni++;
            }
            else {
                stepeni--;
            }
            minute=minute-60;
        }
        printf("%d stepeni", stepeni);
        printf(" %d minuta", minute);
        printf(" %d sekundi\n", sekunde);
    }
    return 0;
}
    

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
int main () {
    int n,i;
    float
    printf("Unesite broj uglova: ");
    do scanf("%d",n); while (n>500 || n<1);
    int radijani[n];
    printf("Uglovi su: ");
    for(i=0;i<n;i++) {
        scanf("%d",&radijani[i]);
    }
    for(i=0;i<n;i++) {
        if((radijani[i]*(180/PI))%3600>30) {
            
        }
    }
    return 0;
}
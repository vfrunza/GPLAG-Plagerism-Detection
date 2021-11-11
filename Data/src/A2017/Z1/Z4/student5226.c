#include <stdio.h>
int main() {
    int a,b,c,i,j;
    do {
        printf("Unesite broj redova: ");
        scanf("%d",&a);
    } while (a<=0 || a>10);
    do {
        printf("Unesite broj kolona: ");
        scanf("%d",&b);
    } while (b<=0 || b>10);
    do {
        printf("Unesite sirinu jedne kolone: ");
        scanf("%d",&c);
    } while (c<=0 || c>10);
    for(i=0;i<2*a+1;i++) {
        if(i%2==0) {
        for(j=0;j<(c+1)*b+1;j++) {
            if(j%(c+1)==0) {
                printf("+");
            }
            else { 
                printf("-");
            }
        }
    } 
    if(i%2==1) {
        for(j=0;j<(c+1)*b+1;j++) {
            if(j%(c+1)==0) {
                printf("|");
            }
            else { 
                printf(" ");
            }
    }    
}
    printf("\n");
}
return 0;
}

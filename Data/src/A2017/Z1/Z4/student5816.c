#include "stdio.h"
int main(void)
{
    int r=0,ko=0,sk=0;
    
    do {
        printf("Unesite broj redova: ");
        scanf("%d",&r);
    } while (r<=0|| r>10);
    do {
        printf("Unesite broj kolona: ");
        scanf("%d",&ko);
    } while (ko<=0 || r>10);
    do {
        printf("Unesite sirinu jedne kolone: ");
        scanf("%d",&sk);
    } while(sk<=0|| sk>10);
    int i,j,k;
    for (i=0; i<r*2+1; i++) {
        for(j=1; j<=ko; j++) {
            if (i%2==0) printf("+");
            else printf("|");

            for(k=1; k<=sk; k++) {
                if (i%2==0) printf("-");
                else printf(" ");
            }
        }
        if (i%2==0) printf("+\n");
        else printf("|\n");
    }
    return 0;
}
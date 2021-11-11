#include <stdio.h>

int main()
{

    int i,j,br,bk,sk,k,z,m,n,e;

    do {
        printf("Unesite broj redova: ");
        scanf("%d",&br);
    } while(br<=0 || br>10);

    do {
        printf("Unesite broj kolona: ");
        scanf("%d", &bk);
    } while((bk<=0 || bk>10));

    do {
        printf("Unesite sirinu jedne kolone: ");
        scanf("%d", &sk);
    } while ((sk<=0 || sk>10));

    for(i=0; i<bk; i++) {
        if(i==0) {
            printf("+");
        }
        for(j=0; j<sk; j++) {
            printf("-");
        }
        printf("+");

    }
    
    for(e=0; e<br; e++) {
        for(k=0; k<bk; k++) {
            if(k==0) {
                printf("\n|");
            }

            for(z=0; z<sk; z++) {
                printf(" ");
            }
            printf("|");
        }
        for(m=0; m<bk; m++) {
            if(m==0) {
                printf("\n+");
            }
            for(n=0; n<sk; n++) {
                printf("-");
            }
            printf("+");

        }
    }

    return 0;
}

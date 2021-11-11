#include <stdio.h>

int main()
{
    int i,j, n, m, s,k;
    int a;
    do {
        printf("Unesite broj redova: ");
        scanf("%d", &n);
    } while(n<=0 || n>10);

    do {
        printf("Unesite broj kolona: ");
        scanf("%d", &m);
    } while(m<=0 || m>10);

    do {
        printf("Unesite sirinu jedne kolone: ");
        scanf("%d", &s);
    } while(s<=0 || s>10);
    
    a=m*(s+1)+1;

    for(i=0; i<=n; i++) {
        for(j=0; j<m; j++) {

            printf("+");

            for(k=0; k<s; k++) {
                printf("-");
            }

        }
        printf("+\n");
        if(i!=n) {
            for(k=0; k<=a; k++) {
                if(k%(s+1)==0)
                    printf("|");

                else
                    printf(" ");
            }
            printf("\n");
        } else
            printf("\n");
    }




    return 0;
}


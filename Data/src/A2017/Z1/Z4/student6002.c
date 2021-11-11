#include <stdio.h>

int main()
{
    int i,a,b,c,br,brk=1;

    printf("Unesite broj redova: ");
    scanf("%d", &a);
    if (a<=0 || a> 10) {
        do {
            printf("Unesite broj redova: ");
            scanf("%d", &a);
        } while(a<=0 || a>10);
    }
    printf("Unesite broj kolona: ");
    scanf("%d", &b);
    if (b<=0 || b>10) {
        do {
            printf("Unesite broj kolona: ");
            scanf("%d", &b);
        } while(b<=0 || b>10);
    }
    printf("Unesite sirinu jedne kolone: ");
    scanf("%d", &c);
    if (c<=0 || c>10) {
        do {
            printf("Unesite sirinu jedne kolone: ");
            scanf("%d", &c);
        } while(c<=0 || c>10);
    }
    do {
        br=0;
        do {
            printf ("+");
            for(i=1; i<=c; i++) {
                printf ("-");
                br++;
            }
        } while(br<b*c);
        printf("+\n");
        br=0;
        do {
            printf("|");
            for (i=1; i <=c; i++) {
                printf(" ");
                br++;
            }
        } while(br<b*c);
        printf("|\n");
        brk+=2;
    } while(brk<= a*2);
    br=0;
    do {
        printf("+");
        for (i=1; i <=c; i++) {
            printf("-");
            br++;
        }
    } while(br<b*c);
    printf("+");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
    int red, kolona, sirina;
    do{
        printf("Unesite broj redova: ");
        scanf("%d", &red);
    }while(red<1 || red>10);
    do{
        printf("Unesite broj kolona: ");
        scanf("%d", &kolona);
    }while(kolona<1 || kolona>10);
    do{
        printf("Unesite sirinu jedne kolone: ");
        scanf("%d", &sirina);
    }while(sirina<1 || sirina>10);
    int i, j, k, t, z;
    for(k=1;k<=red;k++){
        for(i=1;i<=kolona;i++){
            printf("+");
            for(j=1;j<=sirina;j++){
                printf("-");
            }
            if(i==kolona) printf("+");
        }
        printf("\n");
        for(t=1;t<=kolona;t++){
            printf("|");
            for(z=1;z<=sirina;z++){
                printf(" ");
            }
            if(t==kolona) printf("|");
        }
        printf("\n");
    }
    for(i=1;i<=kolona;i++){
        printf("+");
        for(j=1;j<=sirina;j++){
            printf("-");
        }
        if(i==kolona) printf("+");
    }
    return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k, n, nizx[10], nizy[10];
    
    do{
        printf("Unesite broj tacaka: ");
        scanf("%d", &n);
        if(n<=0 || n>10) printf("Pogresan unos\n");
    } while(n<=0 || n>10);
    
    for(i=0; i<n; i++){
        printf("Unesite %d. tacku: ", i+1);
        scanf("%d%d", &nizx[i], &nizy[i]);
        if(nizx[i]<0 || nizx[i]>19 || nizy[i]<0 || nizy[i]>19){
            printf("Pogresan unos\n");
            i--;
        }
    }
    
    for(i=0; i<20; i++){
        for(j=0; j<20; j++){
            for(k=0; k<n; k++){
                if(nizx[k] == j && nizy[k] == i){
                    printf("*");
                    break;
                }
            }
            if(n==k) printf(" ");
        }
        printf("\n");
    }

    return 0;
}

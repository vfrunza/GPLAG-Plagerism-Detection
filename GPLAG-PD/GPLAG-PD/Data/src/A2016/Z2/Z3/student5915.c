#include <stdio.h>
#include <stdlib.h>

int main() {
	
int i, j, k, n;
int x[10], y[10];
do {
    printf("Unesite broj tacaka: ");
    scanf("%d", &n);
    if(n >= 1 && n <=10){
        for(i = 1; i <= n; i++){
            printf("Unesite %d. tacku: ", i);
            scanf("%d %d", &x[i - 1], &y[i - 1]);
            if(x[i - 1] < 0 || x[i - 1] > 19 || y[i - 1] < 0 || y[i - 1] > 19){
                printf("Pogresan unos\n");
                i--;
            }
        }
    }
    else
    printf("Pogresan unos\n");
}while (n < 1 || n > 10);

for(k = 0; k <= 19; k++){
    for(j = 0; j <= 19; j++){
       int l = 0;
        for(i = 0; i < n; i++){
        if(y[i] == k && x[i] == j){
        l = 1;
        printf("*");
        break;
        }
        }
        if(l == 0)
        printf(" ");
    }
    printf("\n");
}
return 0;
}
#include <stdio.h>

int main() {
    int n, i, j, t, x[20], y[20], mat[20][20]={{0}};
    do {
        printf("Unesite broj tacaka: ");
        scanf("%d",&n);
        if(n<=0 || n>10) {
            printf("Pogresan unos\n");
        }
    } while (n<=0 || n>10);
    
    for(t=0;t<n;t++) {
        printf("Unesite %d. tacku: ",t+1);
        scanf("%d %d",&x[t],&y[t]);
        if((x[t]<0 || x[t]>19) || (y[t]<0 || y[t]>19)) {
            printf("Pogresan unos\n");
            t--;
        }
    }
    for(t=0;t<n;t++) {
        for(i=0;i<20;i++) {
            for(j=0;j<20;j++) {
                if(i==y[t] && j==x[t]) {
                    mat[i][j]=1;
                }
            }
        }
    }
    for(i=0;i<20;i++) {
        for(j=0;j<20;j++) {
            if(mat[i][j]==1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
        
    
    
    

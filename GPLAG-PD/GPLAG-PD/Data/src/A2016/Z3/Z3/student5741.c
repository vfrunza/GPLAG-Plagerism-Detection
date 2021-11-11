#include <stdio.h>

int main(){
    int m,n,i,j,a[200][200],br=0,k,l;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&m,&n);
        if(m>200 || m<=0 || n>200 || n<=0){
            printf("Brojevi nisu u trazenom opsegu.\n");
        }
    }
    while(m>200 || m<=0 || n>200 || n<=0);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=i;j<m-1;j++){
            for(k=0;k<n;k++){
                if(a[i][k]==a[j+1][k]){
                    br++;
                }
            }
            if(br==n){
                for(l=j;l<m-1;l++){
                    for(k=0;k<n;k++){
                        a[l+1][k]=a[l+2][k];
                    }
                }
                j--;
                m--;
            }
            br=0;
        }
    }
    
    for(i=0;i<n;i++){
        for(j=i;j<n-1;j++){
            for(k=0;k<m;k++){
                if(a[k][i]==a[k][j+1]){
                    br++;
                }
            }
            if(br==m){
                for(l=j;l<n-1;l++){
                    for(k=0;k<m;k++){
                        a[k][l+1]=a[k][l+2];
                    }
                }
                j--;
                n--;
            }
            br=0;
        }
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
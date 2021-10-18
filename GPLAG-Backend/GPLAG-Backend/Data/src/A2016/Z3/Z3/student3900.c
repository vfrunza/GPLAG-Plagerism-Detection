#include <stdio.h>

int main(){
    
    int t=1,l,p,o,i,j,k,m,n,mat[200][200];
    
    do{
        
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &m, &n);
        if(m<=0 || m>200 || n<=0 || n>200){

        printf("Brojevi nisu u trazenom opsegu.\n");
        }
        
    }while(m<=0 || m>200 || n<=0 || n>200);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    for(i=0;i<m-1;i++){
        for(k=0;k<m-i-1;k++){
            for(j=0;j<n;j++){
               if (mat[i][j]!=mat[i+k+1][j]) break;    
            }
            if(j==n){
                for(l=0;l<m-k-i-1;l++){
                    for(j=0;j<n;j++){
                        mat[i+k+l+1][j]=mat[i+k+l+2][j];
                    }
                }m--;
                 k--;
            }
        }
    }
    
    t=1;
    for(j=0;j<n-1;j++){
        for(k=0;k<n-j-1;k++){
            for(i=0;i<m;i++){
                if(mat[i][j]!=mat[i][j+k+1]) break;
            }
        if(i==m){
            for(o=0;o<m;o++){
                for(p=0;p<n-k-j-1;p++){
                    mat[o][j+k+p+1]=mat[o][j+k+p+2];
                }
            }n--;
            k--;
        }
        }
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%5d", mat[i][j]);
            
        }
        printf("\n");
    }
    return 0;
}
#include<stdio.h>

int main(){
    int mat[200][200],i,j,k,m,n;
    int izbaci,t,l;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&m,&n);
        if(m<=0 || m>200) printf("Brojevi nisu u trazenom opsegu.\n");
        else if(n<=0 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
    } while(m<=0 || m>200 || n<=0 || n>200);
    
    printf ("Unesite elemente matrice: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    }
    
    for(i=0;i<m;i++){
        for(k=i+1;k<m;k++){
            izbaci=1;
            for(j=0;j<n;j++){
                if(mat[k][j]!=mat[i][j]) izbaci=0;
            }
            if(izbaci==1){
                for(l=k;l<m-1;l++)
                    for(t=0;t<n;t++)
                      mat[l][t]=mat[l+1][t];
                      m--;
                      k--;
            }
        }
    }
    
    for(i=0;i<n;i++){
        for(k=i+1;k<n;k++){
            izbaci=1;
            for(j=0;j<m;j++){
                if(mat[j][k]!=mat[j][i]) izbaci=0;
            }
            if(izbaci==1){
                for(t=0;t<m;t++)
                    for(l=k;l<n-1;l++)
                        mat[t][l]=mat[t][l+1];
                        n--;
                        k--;
            }
        }
    }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%5d",mat[i][j]);
        printf("\n");
    }
    return 0;
    
}
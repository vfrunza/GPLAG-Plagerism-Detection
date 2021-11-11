#include<stdio.h>
int main(){
    int mat[201][201],m,n,k=0,i,j,tr=0,h;
    printf("Unesite brojeve M i N: ");
    scanf("%d%d",&m,&n);
    if(m<=0 || n<=0 || m>200 || n>200){
    do{
        printf("Brojevi nisu u trazenom opsegu.\n");
        printf("Unesite brojeve M i N: ");
        scanf("%d%d",&m,&n);
    }while(m<=0 || n<=0 || m>200 || n>200);
    }
    printf("Unesite elemente matrice: ");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
    while(k<m){
    for(i=k+1; i<m; i++){
        for(j=0; j<n ;j++){
            if(mat[k][j]!=mat[i][j]){tr=0;break;} 
            else {tr=1;}
        }
    if(tr==1){ 
    if(i==m-1)m--; 
        else {
            int a;
            for(h = i; h < m - 1; h++) {
                for(a = 0; a < n; a++) {
                    mat[h][a] = mat[h+1][a];
                }
            }
            i--;
            m--;
        }
    }
    }
    k++;
    }
    
    
    k=0;
    while(k<n){
    for(i=k+1; i<n; i++){
        for(j=0; j<m ;j++){
            if(mat[j][k]!=mat[j][i]){tr=0;break;} 
            else {tr=1;}
        }
    if(tr==1){ 
    if(i==n-1)n--; 
        else {
            int a;
            for(h = i; h < n - 1; h++) {
                for(a = 0; a < m; a++) {
                    mat[a][h] = mat[a][h+1];
                }
            }
            i--;
            n--;
        }
    }
    }
    k++;
    }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi: ");
    printf("\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(mat[i][j]>9 || mat[i][j]<0)
            printf("   %d",mat[i][j]);
            else  printf("    %d",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
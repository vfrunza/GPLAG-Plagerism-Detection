#include <stdio.h>

    
int main(){
    char mat[20][20],n,i,j,k;
    unos:
    printf("Unesite broj tacaka: ");
    scanf("%d",&n); 
    if(n<1 || n>10) { printf("Pogresan unos\n"); goto unos; }
    int x[10],y[10];
    for(i=0;i<n;i++){
        unos1:
        printf("Unesite %d. tacku: ",i+1);
        scanf("%d %d",&x[i],&y[i]);
        if(x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19) { printf("Pogresan unos\n"); goto unos1; }
        

    }
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            mat[i][j]=' ';
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<20;i++){
            for(j=0;j<20;j++){
                if(x[k]==j && y[k]==i) mat[i][j]='*';
            }
        }
    
}

for(i=0;i<20;i++){
    for(j=0;j<20;j++){
        printf("%c",mat[i][j]);
    }
    printf("\n");
}
return 0;
}
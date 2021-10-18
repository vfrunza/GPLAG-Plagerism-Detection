#include <stdio.h>


int main(){
    int mat[200][200],a,b,c,d,e,i,j,k,f;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &a,&b );
        if(a<=0 || a>200 || b<=0 || b>200) printf("Brojevi nisu u trazenom opsegu.\n");
    }
    while(a<=0 || a>200 || b<=0 || b>200);
    
    printf("Unesite elemente matrice: ");
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    for(i=0;i<a-1;i++){
        for(j=i+1;j<a;j++){
            c=0;
            if(mat[i][0]==mat[j][0]){
                c=1;
                for(d=1;d<b;d++){
                    if(mat[i][d]!=mat[j][d]) c=0;
                }
            }
            if(c==1){
                for(k=j;k<a-1;k++){
                    for(e=0;e<b;e++){
                        mat[k][e]=mat[k+1][e];
                    }
                }
                a--;
                j--;
            }
        }
    }
    
    
    
    
    for(i=0;i<b-1;i++){
        for(j=(i+1);j<b;j++){
            c=0;
            if(mat[0][i]==mat[0][j]){
                c=1;
                for(d=1;d<a;d++){
                    if(mat[d][i]!=mat[d][j]) c=0;
                }
                
                
            
            if(c==1){
                for(k=j;k<b-1;k++){
                    for(f=0;f<a;f++){
                        mat[f][k]=mat[f][k+1];
                    }
                }
                b--;
                j--;
            }
        }
        
    }
}

    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
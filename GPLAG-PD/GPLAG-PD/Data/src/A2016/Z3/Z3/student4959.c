#include <stdio.h>
#include <math.h>
int main()
{ int m,n,i,j,mat[200][200],check,a,b,c,x,y;
    
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&m,&n);
        if(m>200 || m<1 || n>200 || n<1) printf("Brojevi nisu u trazenom opsegu.\n");
    }
    while(m>200 || m<1 || n>200 || n<1);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    x=m;
    for(i=0;i<x;i++){
        for(j=i+1;j<x;j++){
            check=1;
            for(a=0;a<n;a++){
                if(mat[i][a]!=mat[j][a])
                { check=0;
                break;
                    
                }
            }
            if(check){
                for(b=j;b<x-1;b++){
                    for(c=0;c<n;c++){
                        mat[b][c]=mat[b+1][c];
                    }}
                    j--;
                    x--;
                }
            }
            
        }
         y=n;
    for(j=0;j<y;j++){
        for(i=j+1;i<y;i++){
            check=1;
            for(a=0;a<x;a++){
                if(mat[a][i]!=mat[a][j])
                { check=0;
                break;
                    
                }
            }
            if(check){
                for(b=i;b<y-1;b++){
                    for(c=0;c<x;c++){
                        mat[c][b]=mat[c][b+1];
                    }}
                    i--;
                    y--;
                }
            }
            
        }
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
#include<stdio.h>
int main(){
    int m,n,i,j,matrica[200][200],temp=1,k,l,d;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&m,&n);
        if(m<=0 || m>200 || n<=0 || n>200)
            printf("Brojevi nisu u trazenom opsegu.\n");
    }while(m<=0 || m>200 || n<=0 || n>200);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&matrica[i][j]);
        }
    }
    /*izbacivanje redova koji se ponavljaju*/
    for(i=0;i<m-1;i++){
            d=i+1;;
            while(d<m){
                temp=1;
                for(j=0;j<n;j++)
                    if(matrica[i][j]!=matrica[d][j])
                        temp=0;
                if(temp)
                    break;
                d++;
            }
            if(temp){
                for(k=d;k<m-1;k++)
                    for(l=0;l<n;l++)
                        matrica[k][l]=matrica[k+1][l];
                    m--;
                    i--;
                }
            }
    /*izbacivanje kolona koje se ponavljaju*/
    for(i=0;i<m;i++){
        for(j=0;j<n-1;j++){
            d=j+1;
            while(d<n){
                temp=1;
                    for(i=0;i<m;i++)
                        if(matrica[i][j]!=matrica[i][d])
                            temp=0;
                    if(temp){
                        break;
                    }
                    d++;
            }
            if(temp){
                for(k=0;k<m;k++)
                    for(l=d;l<n-1;l++)
                        matrica[k][l]=matrica[k][l+1];
                    n--;
                    j--;
                }
        }
    }
    
            
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%5d",matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}
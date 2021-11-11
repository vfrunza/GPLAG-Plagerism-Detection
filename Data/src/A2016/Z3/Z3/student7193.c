#include <stdio.h>

int main()
{
    int i,j,k,l,p,r,q,h,pret,pret1,matrica[200][200],m,n;
    do
    {
        printf("Unesite brojeve M i N: ");
        scanf("%d%d",&m,&n);
        if( m<=0 || m>200 || n<=0 || n>200)
        {
            printf("Brojevi nisu u trazenom opsegu.\n");
        }
    }while (m<=0 || m>200 || n<=0 || n>200);  
    
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&matrica[i][j]);
        }
    }
        for(i=0;i<m;i++)
        {
            for(p=i+1;p<m;p++) {
                pret=1;
            
            
               if(matrica[i][0]==matrica[p][0]){
                   for(j=1;j<n;j++){
                       if(matrica[i][j]!=matrica[p][j]){
                           pret=0;break;
                       }
                   }
               }
               else pret=0;
               if(pret==1)
                    {
                        for(k=p;k<m;k++)
                        for(l=0;l<n;l++)
                        matrica[k][l]=matrica[k+1][l];
                        m--;
                        p--;
                    } 
                }
            
        }
        for(j=0;j<n;j++)
        {
            for(r=j+1;r<n;r++)
            {
                pret1=1;
                
                    
                    if(matrica[0][j]==matrica[0][r])
                    {
                        for(i=1;i<m;i++){
                        if(matrica[i][j]!=matrica[i][r]){
                             pret1=0; break;
                        }
                        }
                    }
                    else pret1=0;
                if(pret1==1)
                    {
                        for(q=r;q<n;q++)
                        for(h=0;h<m;h++)
                        matrica[h][q]=matrica[h][q+1];
                        n--;
                        r--;
                    }
                
            }
        }
     
        printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            printf("%5d",matrica[i][j]);
            printf("\n");
        }
        
    return 0;
}
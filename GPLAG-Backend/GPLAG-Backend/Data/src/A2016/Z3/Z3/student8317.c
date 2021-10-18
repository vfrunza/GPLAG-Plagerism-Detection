#include <stdio.h>

int main() {
    int m,n,i,j;
    int isti,l,brojac;
    int mat[200][200];
    
    /*Unos matrice i elemenata*/
    printf("Unesite brojeve M i N: ");
    do
    {
        scanf("%d %d",&m,&n);
        while(n<=0 || n>200 || m<=0 || m>200)
        {
            printf("Brojevi nisu u trazenom opsegu.\n");
            printf("Unesite brojeve M i N: ");
            scanf("%d %d",&m,&n);
        }
    } while(n<=0 || n>200 || m<=0 || m>200);
    
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    
    
    /*poredjenje clanova reda*/
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            isti=1;
            for(brojac=0;brojac<n;brojac++)
            {
                if(mat[i][brojac]!=mat[j][brojac])
                {
                    isti=0;
                }
            } /*kraj za poredjenje*/
            
            
            if(isti==1)
            {
                for(brojac=j;brojac<n-1;brojac++)
                {
                    for(l=0;l<m;l++)
                    {
                        mat[brojac][l]=mat[brojac+1][l];
                    }
                }
                
                m--;
                j--;
            }
        }
    }
    
    /*poredjenje kolona*/
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            isti=1;
            for(brojac=0;brojac<m;brojac++)
            {
                if(mat[brojac][i]!=mat[brojac][j])
                {
                    isti=0;
                }
            } /*kraj petlje za poredjenje clanova kolona*/
            
            
            if(isti==1)
            {
                for(brojac=j;brojac<n-1;brojac++)
                {
                    for(l=0;l<m;l++)
                    {
                        mat[l][brojac]=mat[l][brojac+1];
                    }
                }
                n--;
                j--;
            }
        }
    }
    
    
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");  /*ispis novonastale matrice*/
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;

}

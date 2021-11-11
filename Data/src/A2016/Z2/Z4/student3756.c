
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 0.000000000000000000000001
int main()
{
    double niz[100][100];
    int m,n,i=0,j,a=0;
    do{
        if(i>0)
        printf("Pogresan unos!\n");
        printf("Unesite M i N: ");
        scanf("%d %d",&m,&n);
        i++;
    }while(m<=0 || m>100 || n<=0 || n>100);
    printf("Unesite elemente matrice: ");
    i=0;
    while(i<m)
    {
        j=0;
        while(j<n)
        {
            scanf("%lf",&niz[i][j]);
            j++;
        }
        i++;
    }
    for(i=0;i<m-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(fabs(niz[i][j]-niz[i+1][j+1])>g)
            {
                a++;
                break;
            }
        }
        if(a==1)
        {
            printf("Matrica nije ni cirkularna ni Teplicova");
        }
    }
    if(a==0)
    {
        for(i=0;i<m-1;i++)
        {
            if(m==1)
            {
                break;
            }
            for(j=0;j<n;j++)
            {
                if(fabs(niz[i][n-1]-niz[i+1][0])>g)
                {
                    a++;
                    printf("Matrica je Teplicova ");
                    break;
                }
            }
            if(a==1)
            {
                break;
            }
        }
        if(a==0)
        {
            printf("Matrica je cirkularna ");
        }
    }
    return 0;
}


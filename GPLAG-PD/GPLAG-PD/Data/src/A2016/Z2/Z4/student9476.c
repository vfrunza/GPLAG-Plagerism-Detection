#include <stdio.h>

int main() {
    int i,j,m,n;
    int tep=1, cirk=1;
    int a=0;
    double mat[100][100];
    do
    {
        printf("Unesite M i N: ");
        scanf("%d %d", &m, &n);
        if(m<=0 || m>100 || n<=0 || n>100)
        printf("Pogresan unos!\n");
    }
    while(m<=0 || m>100 || n<=0 || n>100);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                {
                    scanf("%lf", &mat[i][j]);
                }
        }
    if(m==1 && n==1) {printf("Matrica je cirkularna");return 0;}
    if(m==2 && n==2)
    {
        if(mat[0][0]!=mat[1][1]) printf("Matrica nije ni cirkularna ni Teplicova");
        else
        {
            if(mat[0][1]!=mat[1][0]) printf("Matrica je Teplicova");
            else printf("Matrica je cirkularna");
        }
        return 0;
    }
    for(i=0;i<m-1;i++)
     {
            for(j=0;j<n-1;j++)
             {
                 if(mat[i][j]!=mat[i+1][j+1]) cirk=0;
             }
     }
     
    if(cirk==1)
    {
        for(i=0;i<m-1;i++)
        {
            for(j=0;j<n;j++)
            {
                if(j==n-1)
                {
                    if(mat[i][j]!=mat[i+1][0]) {a++;};
                    
                }
            }
            
        }
        if(a==0) printf("Matrica je cirkularna");
        else printf("Matrica je Teplicova");
    }
    else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}

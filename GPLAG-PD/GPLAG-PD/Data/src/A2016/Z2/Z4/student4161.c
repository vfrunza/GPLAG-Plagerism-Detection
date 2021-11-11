#include <stdio.h>

int main() {
    int m, n;
    double matrica[100][100];
    int i, j;
     int cirkularna=1;
     int teplicova=1;
    
    while(1)
    {
        printf("Unesite M i N: ");
        scanf("%d %d", &m, &n);
        if(m<=0 || m>100 || n<=0 || n>100) printf("Pogresan unos!\n");
        else break;
    }    
    printf("Unesite elemente matrice: ");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%lf", &matrica[i][j]);
        }
    }
   
    for(i=0; i<m-1; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(matrica[i][j]!=matrica[i+1][j+1]) {teplicova=0; break;}
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i<m-1 && j<n-1)
            {
            if(matrica[i][j]!=matrica[i+1][j+1]) {cirkularna=0; break;}
            }
            else if(i<m-1 && j==n-1)
            {
                if(matrica[i][j]!=matrica[i+1][0]){cirkularna=0; break;}
            }
        }
    }
    if(teplicova==1 && cirkularna==1) printf("Matrica je cirkularna");
    else if(teplicova==1) printf("Matrica je Teplicova");
    else if(cirkularna==1) printf("Matrica je cirkularna");
    else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}

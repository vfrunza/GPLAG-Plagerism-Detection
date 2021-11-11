#include <stdio.h>
int main(){
    int matrica[100][100];
    int i,j,k, visina, sirina, provjera=1, provjera2=1;
    do{
    printf("Unesite M i N: ");
    scanf("%d %d",&visina, &sirina);
    if(visina<=0 || sirina<=0 || visina>100 || sirina>100) printf("Pogresan unos!\n");
    }while(visina<=0 || sirina<=0 || sirina>100 || visina>100);
    
    printf("Unesite elemente matrice: ");
    for(i=0; i<visina; i++)
    {
        for(j=0; j<sirina; j++)
        {
            scanf("%d", &matrica[i][j]);
        }
    }
    
    for(k=-(visina-1); k<sirina+1; k++)
    {
        for(i=0; i<(visina-1); i++)
        {
            for(j=0; j<(sirina-1); j++)
            {
                if(i==(j+k) && matrica[i][j]!=matrica[i+1][j+1]) provjera=0;
            }
        }
    }
    for(i=0; i<visina; i++)
    {
        for(j=0; j<sirina; j++)
        {
            if(j==0 && i>0 && matrica[i-1][sirina-1]!=matrica[i][0]) provjera2=0;
        }
    }
    if(provjera==1 && provjera2==1) printf("Matrica je cirkularna");
    else if(provjera==1 && provjera2==0)  printf("Matrica je Teplicova");
    else printf("Matrica nije ni cirkularna ni Teplicova");
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
#include <stdio.h>
#define sirina 20

int main()
{
    int n[sirina][sirina]={2};
    int a,i,c,d,j;
    do {
        printf("Unesite broj tacaka: ");
        scanf("%d",&a);
        if(a<=0  || a>10) printf("Pogresan unos\n");

    } while(a<=0 || a>10);

    for(i=0; i<a; i++) {
        printf("Unesite %d. tacku: ",i+1);
        scanf("%d %d",&c,&d);
        if((c<0 || c>19) || (d<0 || d>19)) {
            printf("Pogresan unos\n");
            i--;
        }else n[d][c]=3;

    }
    for(i=0; i<sirina; i++) {
        for(j=0; j<sirina; j++) {
            if(n[i][j]==3)  printf("*");
                else printf(" ");


                }
        printf("\n");
    }


    return 0;
}

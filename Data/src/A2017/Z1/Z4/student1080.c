#include <stdio.h>

int main()
{
    int i,j,k,l,m; 
    int red,sirina,kolone;
    

do {
    printf("Unesite broj redova: ");
    scanf("%d", &red);
}
while ((red<=0)||(red>10));

do {
    printf("Unesite broj kolona: ");
    scanf("%d", &kolone);
}
while ((kolone<=0)||(kolone>10));

do {    
    printf("Unesite sirinu jedne kolone: ");
    scanf("%d", &sirina);
}
while ((sirina<=0)||(sirina>10));


for(m=1;m<=red;m++) {


for(i=1; i<=kolone; i++)
    {
        printf("+");
        for(j=1; j<=sirina; j++)
        {
            printf("-");
        }
        if (i==kolone) {
            printf("+");
        }
    }
 
printf("\n"); 


for(k=1; k<=kolone; k++) {
        printf("|");
        for(l=1; l<=sirina; l++)
        {
            printf(" ");
        }
        if (k==kolone) {
            printf("|");
        }
    }
    printf("\n");

}

for(i=1; i<=kolone; i++)
            {
            printf("+");
        for(j=1; j<=sirina; j++)
        {
            printf("-");
        }
        if (i==kolone) {
            printf("+");
        }
            }

    return 0;
}

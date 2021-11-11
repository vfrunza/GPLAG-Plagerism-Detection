#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int n)
{
    int i;
    for (i=0; i<n; i++) {
        niz[i]=(round(niz[i]*10))/10;
    }
}

int sumaf(float broj)
{
    int suma=0;
    int pom=0;
    broj*=10;
    pom=(int)broj;
    while (pom!=0) {
        suma += pom%10;
        pom/=10;
    }
    return suma;
}


void preslozi( float niz[], int n, int k)
{
    int i,j,br=0;
    float temp;
    zaokruzi1(niz,n);
    for (i=0; i<n; i++) {
        if (sumaf(fabs(niz[i]))>=k) {
            for(j=i; j>br; j--) {
                temp= niz[j];
                niz[j]=niz[j-1];
                niz[j-1]=temp;
            }
            br++;
        }
    }
}

int main()
{
    int i;
    float niz[] = { 13.1 , 15.749999 , 15.75 , 9.222 , 78.1};
    zaokruzi1(niz, 5);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
//for (i=0; i<n; i++) printf("%d ", sumaf(niz[i]));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int suma(int n)
{
    int c,suma;
    suma=0;
    while (n!=0)
    {
        c=abs(n%10);
        suma+=c;
        n=n/10;

    }
    return suma;
}
int ubaci(int *niz, int vel)
{
    int i,j;
    for(i=0; i<vel; i++)
    {
        for(j=vel-1; j>i; j--)
        niz[j+1]=niz[j];

        niz[i+1]=suma(niz[i]);
        vel++;
        i++;
    }
 return vel;
}
int fibonaci(int n)
{
    int a,b;
    a=1;
    b=1;
    while(a<n && b<n)
    {
        a=a+b;
        b=b+a;
    }
    if (a==n || b==n) return 1;
    else return 0;
}
int izbaci(int* niz,int vel)
{
    int i,j;
    for(i=0; i<vel; i++)
    {
        if (fibonaci(niz[i])==1){
        for(j=i; j<vel-1; j++)
        {
            niz[j]=niz[j+1];
        }
        vel--;
        i--;
        }
    }
    return vel;

}

int main ()
{
    int niz[100],vel,i;
    vel=10;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<vel; i++)
    {
        scanf("%d", &niz[i]);
    }
    vel=ubaci(niz,vel);
    vel=izbaci(niz,vel);
    printf("Modificirani niz glasi: ");
    for(i=0; i<vel; i++)
    {
        if(i==vel-1) {
            printf("%d.", niz[i]);
        } else
        printf("%d, ", niz[i]);
    }
    return 0;
}

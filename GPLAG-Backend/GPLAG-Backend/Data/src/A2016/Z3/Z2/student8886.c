#include <stdio.h>
#include <stdlib.h>

/*Racunanje sume cifara i-tog clana niza*/
int suma(int n) {
    int c, sum=0;
    while (n!=0) {
        c=abs(n%10);
        sum+=c;
        n=n/10;
    }
    return sum;
}

/*Ubacivanje sume cifara i-tog clana niza u niz nakon tog clana*/ 
void ubaci(int *niz, int vel) {
    int i, j;
    for (i=0; i<vel; i++) {
        for (j=vel-1; j>i; j--) 
            niz [j+1]=niz[j];
            niz [i+1]=suma(niz[i]);
            vel++;
            i++;
        
    }
}

/*Provjeravanje da li se i-ti clan niza pojavljuje u Fibonacijevom nizu*/
int fibonaci(int n)
{
    int x,y;
    x=1;
    y=1;
    while (x<n && y<n) {
        x=x+y;
        y=x+y;
    }
    if (x==n || y==n) return 1;
    else return 0;
}

/*Izbacivanje onih clanova iz niza koji se pojavljuju u Fibonacijevom nizu*/
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
int main () {
    
    int niz[1000], i, vel=10;
    printf("Unesite niz od 10 brojeva: ");
    for (i=0; i<vel; i++) {
        scanf ("%d", &niz[i]);
    }
    ubaci(niz, vel);
    vel=vel*2;
    vel=izbaci(niz, vel);
    
/*Ispis modificiranog niza*/
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
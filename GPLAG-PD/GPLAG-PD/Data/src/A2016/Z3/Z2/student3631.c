#include <stdio.h>
#include <stdlib.h>

int suma(int n)
{
    int s=0;
    while (n>0)
    {
        s=s+n%10;
        n=n/10;
    }return s;
}


void ubaci(int niz[], int velicina) {
    int z;
    int *s,*t;
   int  i=2*velicina;
    /*ubacujem prazno mjesto izmedju clanova*/
    for (i=velicina-1;i>=0;i--)
    {
        t=niz + i*2;
        s=niz + i;
        *t=*s;
    }
    /*ubacujem sumu cifara na novonastala prazna mjesta*/
    for (i=0;i<velicina*2;i=i+2)
    {
        t=niz + i;
        s=t + 1;
        z=abs(*t);
        *s=suma(z);
    }
}



int izbaci (int *niz, int velicina) {
    int i,j,fibonacijev,fib1,fib0;
    for (i=0;i<velicina;i++){
        /*provjeravanje da li je broj fibonacijev*/
        fibonacijev=1;
        fib1=1;
        fib0=1;
        while(fibonacijev<niz[i])
        {
            fibonacijev=fib1+fib0;
            fib0=fib1;
            fib1=fibonacijev;
        }
        /*izbacivanje fibonacijevih brojeva*/
        if (fibonacijev==niz[i]){
            for (j=i;j<velicina-1;j++){
                niz[j]=niz[j+1];
            }
            velicina--;
            i--;
        }
        
    }

   return velicina;
}

int main() {
int niz[20],i,velicina=10,izbacivanje;

/*unos niza*/
printf ("Unesite niz od 10 brojeva: ");
for (i=0; i<10; i++)
{
	scanf ("%d", &niz[i]);
}	

/* pozivanje funkcija za modifikaciju niza*/
ubaci (niz,velicina);
velicina=velicina*2;
izbacivanje=izbaci(niz,velicina);

/*ispisivanje modificiranog niza*/
printf ("Modificirani niz glasi: ");
for (i=0;i<izbacivanje- 1;i++)
printf ("%d, ", niz[i]);
printf ("%d.", niz[i]);
return 0;
}

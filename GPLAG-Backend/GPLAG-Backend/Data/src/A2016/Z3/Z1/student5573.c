#include <stdio.h>
int daj_prost()
{
    /*deklarisanje statične varijable*/
    static int d=1;
    int j,k=0,c=0; 
    /*odredjivanje prostog broja*/
        for(j=1;j<=d;j++)
        {
            if(d%j==0)
            {
                k++;
            }
        }
        c=d;
        d++;
        /*vracanje prostog broja odnosno ponovno pozivanje funkcije*/
      if(k==2)
        {
            return c;
        }  
        else
        {
            daj_prost();
        }
}

int main() {
    int i,a,b,suma=0,c;
    /*unos brojeva*/
    printf("Unesite brojeve A i B: ");
    scanf("%d %d",&a,&b);
    /*osiguramo da su nam brojevi u određenim intervalima*/
    while(a<1 || a==b || a>b)           
    {
        if(a<1)
        { 
            printf("A nije prirodan broj. \n");
            printf("Unesite brojeve A i B: ");
        }                   
        if(a==b || a>b)
        {
            printf("A nije manje od B. \n");
            printf("Unesite brojeve A i B: ");
        }
        scanf("%d %d",&a,&b);
    }
    /*pozivanje funkcije i racunanje sume prstih brojeva izmedju A i B*/
    for(i=1;i<b;i++)
    {
            c=daj_prost();
            if(c!=0 && c>a && c<b)
            {
                suma=suma+c; 
            }
    }
    printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}

#include <stdio.h>

int SaberiCifre(int x){ /* sabiranje vrijednosti cifara poslanog broja uzimajuci u obzir da broj moze biti negativan */
    int n=0;
    if (x<0) x*=-1;
    while(x>0)
    {
        n+= x%10;
        x/= 10;
    }
    return n;
}

	
void ubaci(int *niz, int vel){ /*vrsi ubacivanje sume cifara pocetnog niza na odgovarajuca mjesta sa odgovarajucim indeksima*/
	int i, t;
	int nizp[20]={0};/* pomocni niz kojim sprjecavamo preklapanje vrijednosti pocetnog niza */
	for (i=0; i<vel; i++)
	{
	    nizp[i]=niz[i];
	}
	for (i=0; i<vel; i++)
	{  
	    niz[2*i]=nizp[i];
	}
	for (i=0; i<vel; i++)
	{
	    t=SaberiCifre(nizp[i]);
	    niz[2*i+1]=t;
	}
} 
int izbaci(int *niz, int vel){ 
    int a,b;
    int n;
    int i,j,k,t;
    for(i=0; i<vel; i++)
    {
        a=0;
        b=1;
        while(niz[i]>=b)
        { 
            
            if(niz[i]==b){ 
                for(j=i;j<vel-1;j++){
                    niz[j]=niz[j+1];
                }
                i--;
                vel--; /* smanjenje duzine niza */
                break;
            }
            n=a+b;
            a=b;
            b=n;
        }
    }
    return vel;
}
int main() {
    int niz[20]={0};
    int i, t=20;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++){
        scanf("%d", &niz[i]);
    }
    ubaci(&niz,10);/* pozivanje funkcije za unos sume cifara brojeva pocetnog niza */
    t=izbaci(&niz,20);/* poziv funkcije za pronalazak i izbacivanje fibonaccijevih brojeva iz niza*/
    printf("Modificirani niz glasi: ");
    for(i=0; i<t; i++){
        if(i<t-1){
            printf("%d, ", niz[i] );
        }
        if(i==t-1){
            printf("%d.",niz[i]);
        }
    }
    return 0;
}
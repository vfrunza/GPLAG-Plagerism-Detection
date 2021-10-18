#include <stdio.h>
#include <math.h>

void ubaci(int niz[],int vel)
{   
    int i,suma=0,j,k,n;
    for(i=0;i<2*vel;i=i+2){ 
        for(k=vel-1+i/2;k>=i;k--)
        niz[k+1]=niz[k];   /*pomjeranje clanova niza*/
        n=fabs(niz[i]);
            while(n>0){   /*racunanje sume cifara*/
            j=n%10;
            suma=suma+j;
            n=n/10;
            }
        niz[i+1]=suma; /*ubacivanje clanova niza*/
        suma=0;
    }
}

int izbaci(int niz[],int vel)
{
    int i,fibonaci=0,j,suma=0,prvi_clan,drugi_clan,a;
    for(i=0;i<vel;i++){
        suma=0;
        prvi_clan=1;
        drugi_clan=1;
        a=niz[i];
        while(a>suma){
            suma=prvi_clan+drugi_clan;
            prvi_clan=drugi_clan;
            drugi_clan=suma;
            if(a==suma || a==1){fibonaci=1; break;} /*provjera da li je broj fibonacijev*/
        }
            if(fibonaci==1){                        /*izbacivanje broja iz niza ako je fibonacijev*/
                for(j=i;j<vel-1;j++){
                    niz[j]=niz[j+1];
                }
                vel--;
                i--;
                }
    fibonaci=0;       
    }
    return vel;
}


int main() {
    
    int i,niz[20],novavel;
    printf("Unesite niz od 10 brojeva: ");
        for(i=0;i<10;i++){
        scanf("%d",&niz[i]);
        }
    ubaci(niz,10);
    printf("Modificirani niz glasi: ");
    novavel=izbaci(niz,20);
    for(i=0;i<novavel;i++){
        if (i==novavel-1) printf("%d.",niz[i]);
        else printf("%d, ",niz[i]);
    }
	
	return 0;
}

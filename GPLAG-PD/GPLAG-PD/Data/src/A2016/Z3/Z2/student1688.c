#include <stdio.h>
#include <math.h>
/* Funkcija ubaci koja prima niz cijelih brojeva te nakon svakog clana niza ubacuje u niz poitivan broj koji predstavlja sumu cifara prethodnog clana */
void ubaci(int niz[],int vel){
    int i=0,p,suma,j,vel1=vel;
    /* Znamo da ce niz biti duplo veci, zato nam i ide do vel+vel */
    while(i<vel+vel){
        suma=0;
        /* Uzmemo apsolutnu vrijednost niza i nadjemo sumu cifara prethodnog clana  */
        p=fabs(niz[i]);
        while(p!=0){
            suma+=p%10;
            p/=10;
        }
        /* Pomjerimo sve elemente niza za jedan da bi mogli smjestiti sumu */
        for(j=vel1;j>i+1;j--){
            niz[j]=niz[j-1];
        }
        niz[++i]=suma;
        vel1++;
        i++;

    }
    
}
/* Funkcija izbaci prima niz cijelih brojeva i iz njega izbacuje sve clanove niza koji su Fibonaccijevi brojevi */
int izbaci(int niz[],int vel){
    int i,j,jest,a,b,k,fibo;
    for(i=0;i<vel;i++){
        /* Ispitivali smo samo pozitivne brojeve */
        if(niz[i]>0){
            /* Inicijalizujemo prva dva clana fibonacijevog niza*/
            a=1;
            b=1;
            if(niz[i]==1 || niz[i]==2)
            jest=1;
            else {
                for(k=2;k<niz[i]+1;k++){
                    fibo=a+b;
                    b=a;
                    a=fibo;
                    /*Ako je element niza jednak fibonacijevom znaci da se nalazi i prekinemo ili ako je fibonacijev element veci od elementa niza znaci da se ne nalazi */
                    if(fibo==niz[i]){
                        jest=1;
                        break;
                    }
                    if(fibo>niz[i]){
                        jest=0;
                        break;
                    }
                }
            }
            /* Ako se broj nalazi u Fibonacijevom nizu izbacujemo ga */
            if(jest){
                for(j=i;j<vel-1;j++)
                niz[j]=niz[j+1];
                vel--;
                i--;
            }
        }
    }
    return vel;
}

int main(){
    int niz [4000];
    int pom,i,vel=10;
    /* Unosimo niz od 10 elemenata */
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<vel;i++)
    scanf("%d",&niz[i]);
    /* Pozivamo prvo funkciju ubaci,pa izbaci */
    ubaci(niz,10);
    vel+=vel;
    pom=izbaci(niz,vel);
    /* Ispisujemo modificirani niz */
    printf("Modificirani niz glasi: ");
    for(i=0;i<pom-1;i++)
    printf("%d, ",niz[i]);
    printf("%d.",niz[i]);
    return 0;
}
#include <stdio.h>
#define BROJ_EL 100
/* Dati zadatak cu uraditi cdeklarisanjem dva niza od 10 elemenata gdje ce prvi biti za pomocne elemente, drugi za pomocne sume,i taj drugi ce biti jednak samom nasem pocetnom nizu.*/
 void ubaci (int niz[],int vel)
{  int pomocnielementi[10],i, pomocnisume[10],suma=0;
    for(i=0;i<vel;i++) pomocnielementi[i]=niz[i];
    for(i=0;i<vel;i++){
        suma=0;
        int broj=niz[i];
        /*Potrebno je rastaviti cifre svih elemenata niza pa ih onda sabrati to sam uradila preko varijable broj, i elementi niza postaju broj nakon toga se izracuna i suma tih cifara.*/
        if(broj<0) broj=broj*(-1);
        while(broj!=0) {
         int cifra=broj%10;
         suma=suma+cifra;
         broj/=10;
       }
        pomocnisume[i]=suma;
}
/*Nakon sto sam izracunala sumu cifara svakog elementa niza suma je postala taj niz, sada je potrebno u novi niz zalijepiti niz elemenata i suma u dvostruku velicinu niza.*/
    int k=0;
    for(i=0;i<vel*2;i++) {
        niz[i]=pomocnielementi[k];
        niz[i+1]=pomocnisume[k];
        i++; k++;
    }
}
 
 /*Za funkciju izbaci potrebno je napraviti i funkciju fib(Fibonacijev niz) nakon toga u funkciji izbaci, pozivamo funkciju fib, ako je njena vrijednost jednaka 1, 
 tada izbacujemo elemente iz niza tako da na mjesto onog clana koji izbacimo prepisemo sljedeci clan.*/
   int fib(int n){
       
   int p=1,d=1,treci=0;
   if(p==n) return 1;
   while(treci<=n){
       treci=p+d;
       if(treci==n) return 1;
       p=d;
       d=treci;
   }
   return 0;
}
      
    int izbaci(int* niz,int vel)
{   int i,j;   
    for(i=0;i<vel;i++){
        if(fib(niz[i])==1){
         for(j=i;j<vel-1;j++)
            niz[j]=niz[j+1];
        i--;
        vel--;
        }
    }    
return vel;
        
}

    
int main() {
    /*Klasicno unosimo niz od 10 elemenata te pozivamo funkciju ubaci, pa izbaci.*/
    int niz[BROJ_EL];
    int i,novavelicina;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++){
    scanf("%d",&niz[i]);
    }

    ubaci(niz,10); 
    novavelicina=izbaci(niz,20);
    printf("Modificirani niz glasi:");
    for(i=0;i<novavelicina;i++){
        if(i==(novavelicina-1)) 
        printf(" %d.",niz[i]);
        else printf(" %d,",niz[i]);
    }
 return 0;
}

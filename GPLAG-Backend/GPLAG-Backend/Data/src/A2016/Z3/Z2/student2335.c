#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*Funkcija ubaci prima promijenjivu tipa int koja pokazuje na niz i velicinu tog niza. Prvo treba napraviti
 mjesta za nove clanove niza, kojih ima isto onoliko koliko i elemenata niza. ocekuje se da se nakon 
 svakog elementa niza doda novi element koji predstavlja sumu cifara prethodnika, tako da ce se svaki elemant
 pomjeriti tako da nakon njega ima mjesto za novi clan. prva for petlja je sluzi da se napravi mjesta za nove
 clanove niza, dok druga petlja racuna te clanove i ubacuje ih na njihova mjesta*/

void ubaci(int *niz,int vel){
    int i,a=(2*vel)-2,suma=0,x;
    for(i=vel-1;i>=0;i--){
        niz[a]=niz[i];
        a-=2;
    }
    for(i=0;i<vel*2;i+=2){
        suma=0;
        x=abs(niz[i]);
        do{
            suma+=x%10;
            x/=10;
        }while(x>0);
        niz[i+1]=suma;
    }
}
/*Funkcija izbaci treba iz niza izbaciti sve brojeve koji su Fibonacijevi brojevi. Najprije je potrebno
provjeriti da li uopce ima takvih brojeva. To se postize prvom, vanjskom, petljom. Dakle, prolazi se kroz
sve clanove niza, ali na pocetku petlje dodjeljujemo vrijednost 1 prvom i drugom elementu niza, te
takodjer istu vrijednost i varijabli fib(da joj se ne dodijeli nikakva vrijednost na pocetku, automatski
bi joj se dodijelila neka proizvoljna vrijednost iz memorije, te se while pezlja vjerovatno nikada ne bi
ni izvrsila). Dalje, kako je u Fibonacijevom nizu svaki element suma prethodna dva(osim prvog i drugog clana,
oni su jednaki broju 1), while petlja prolazi kroz Fibonacijev niz sve dok je clan tog niza manji od clana
naseg zadanog niza. Ako je nakon zavrsetka petlje ispostavi da clan naseg niza pripada Fibonacijevom nizu,
odnosno da mu je jednak, taj clan se izbacuje iz niza pomocu druge for petlje. Funkcija na kraju vraca 
velicinu niza, jer mi ne znamo koliko elemenata ce biti izbaceno iz niza nakon pokretanja funkcije, tj. 
ne znamo da li ce se izbaciti ijedan clan.*/
int izbaci(int *niz,int vel){
    int i,j,fib,a,b;
    for(i=0;i<vel;i++){
        fib=1;
        a=1;
        b=1;
        while(fib<niz[i]){
            fib=a+b;
            a=b;
            b=fib;
        }
        if(fib==niz[i]){
            for(j=i;j<vel-1;j++)
            niz[j]=niz[j+1];
            vel--;
            i--;
        }
    }
    return vel;
}

int main() {
    int niz[20],i,nvel;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++)
    scanf("%d",&niz[i]);
    ubaci(niz,10);
    nvel=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    printf("%d",niz[0]);
    for(i=1;i<nvel;i++)
        printf(", %d",niz[i]);
        printf(".");
   	return 0;
}

#include <stdio.h>
#include <stdlib.h>

/*Funkcija "ubaci" prima niz elemenata i nakon svakog elementa ubacuje sumu cifara istog.*/

void ubaci (int *niz, int vel) {
    int i, j, copy[10], copy2[20]={0}, sum_num, temp;
    for(i=0; i<vel; i++){
        copy[i]=niz[i];
        copy2[i]=copy[i];
    }
    j=2;
    for(i=1; i<vel; i++){
        copy2[j]=copy[i];
        j+=2;
    }
    for(i=0; i<vel*2; i+=2){
        sum_num=0;
        temp=copy2[i];
        while(abs(temp)!=0){
            sum_num+=temp%10;
            temp/=10;
        }
        copy2[i+1]=abs(sum_num);
    }
    for(i=0; i<vel*2; i++){
        *(niz+i)=copy2[i];
    }
}

/*Funkcija "izbaci" prima niz elemenata i izbacuje iz njega sve elemente koji su Fibonaccijev broj*/

int izbaci (int *niz, int vel) {
    int i, j, n1, n2, check=0;
    for(i=0; i<vel;){
        n1=1; n2=1;     /*n1 i n2 su prva dva clana Fibonaccijevog niza koji se sabiraju da bi stvorili sljedece clanove niza*/
        do{
            if(check==1) i--;
            check=0;
            if(i<0) i++;
            if(niz[i]==n1 || niz[i]==n2){
                for(j=i; j<vel-1; j++){
                    niz[j]=niz[j+1];
                }
                i--;
                vel--;
            }
            n1=n1+n2;
            n2=n1+n2;
            if(i<0){
                i++;
                check=1;        /*Varijabla "check" provjerava vrijednost varijable "i" da se u uslovu "while" ne bi pristupilo zabranjenoj memoriji, a ukoliko je manja od nule, povecava za jedan, a nakon uslova smanjuje za 1*/
            }
        }while(n1<=niz[i]);
        i++;
        if(i==vel && check==1) i--;
    }
    return vel;
}

/*Funkcija "main" trazi od korisnika unos 10 brojeva, nakon cega pomocu funkcija "ubaci" i "izbaci" modificira uneseni niz elemenata i ispisuje isti na ekran*/

int main() {
    int niz[20]={0}, i, vel=10;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++){
        scanf("%d", &niz[i]);
    }
    ubaci(niz, vel);
    vel=izbaci(niz, 20);
    printf("Modificirani niz glasi: ");
    for(i=0; i<vel; i++){
        if(i!=vel-1)
            printf("%d, ", niz[i]);
        else printf("%d.", niz[i]);
    }
    return 0;
}
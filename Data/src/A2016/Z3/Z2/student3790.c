#include <stdio.h>
#include <stdlib.h>


void ubaci(int *niz,int velicina){
    int i;
    int j;
    int cifra;
    int suma;
    //premjestanje elemenata niza na svako drugo mjesto
    for(i=velicina-1;i>0;i--){
        niz[2*i]=niz[i];
    }
    
    //trazenje zbira cifara predhonog elementa
    for(i=0;i<velicina;i++){
        suma=0;
        for(j=abs(niz[2*i]);j>0;j/=10){
            cifra=j%10;
            suma+=cifra;
        }
        niz[2*i+1]=suma;
    }
}

int izbaci(int *niz,int velicina){
   int a,b;
   int i,k;
   int temp;
   // prolaz kroz petlju za svaki element
   for(i=0;i<velicina;i++){
        a=1;
        b=1;
        //provjerava da li je element niza jednak Fib broju
        while(niz[i]>=b){
            if(niz[i]==b){
                k=i;
                //izbacivanje tog elementa
                for(k=i;k<velicina-1;k++){
                     niz[k]=niz[k+1];
                 }
                 velicina--;
                 i--;
                 break;
            }
            //trazenje narednog Fib broja
            temp=b;
            b=a+b;
            a=temp;
        }
   }
   return velicina;
} 

int main(){
    int i;
    int *p;
    int niz[20];
    
    // unos niza
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++){
        scanf("%d",&niz[i]);
    }
    
    // koristenje funkcija
    int vel;
    vel=10;
    p=&niz[0];
    ubaci(p,vel);
    vel=2*vel;
    vel=izbaci(p,vel); 
    
    // ispis
    printf("Modificirani niz glasi: ");
    for(i=0;i<vel-1;i++){
        printf("%d, ",niz[i]);    
    }
    if(vel>0){
        printf("%d.",niz[vel-1]);
    }
    return 0;
}



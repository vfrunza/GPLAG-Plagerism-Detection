#include <stdio.h>
int zbir_cifara(int n){
    int p,suma=0;
    if(n<0) n*=-1;
    while(n!=0){
        p=n%10;
        suma+=p;
        n=n/10;
    }
    return suma;
}

void ubaci(int niz[], int vel){
    int niz1[1000],i,brojac=0;
    
    for(i=0;i<vel;i++){
        niz1[brojac]=niz[i];
        brojac++;
        niz1[brojac]=zbir_cifara(niz[i]);
        brojac++;
    }
    for(i=0; i<vel*2; i++)
    niz[i]=niz1[i];
}
//Funkcija koja provjerava da li se clan unesenog niza javlja u Fibonaccijevom nizu
int fibonaci(int broj){
    int fibonaci_niz[100], i;
    for(i=0; i<100; i++){
        if(i==0 || i==1) fibonaci_niz[i]=1;
        else fibonaci_niz[i]=fibonaci_niz[i-1]+fibonaci_niz[i-2];
    }
    for(i=0; i<100; i++){
        if(broj==fibonaci_niz[i])
        return 1;
    }
    return 0;
}

int izbaci (int niz[], int vel){
    int i,j;
    for(i=0; i<vel; i++){
        if(fibonaci(niz[i])==1 && niz[i]>0){
            for(j=i; j<vel-1; j++){
                niz[j]=niz[j+1];
            }
            vel--;
            i--;
        }
    }
    return vel;
        
}
int main() {
    int niz[100], i, vel;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++){
        scanf("%d", &niz[i]);
    }
    ubaci(niz, 10);
    vel=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    for(i=0; i<vel; i++){
         if(i==vel-1) printf("%d.",niz[i]);
         else printf("%d, ",niz[i]);
    }
    
	return 0;
}

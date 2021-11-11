#include <stdio.h>
#include <stdlib.h>

int suma(int z1){
    int suma1=0;
    while(z1>0){
        suma1=suma1+z1%10;
        z1=z1/10;
    }
    return suma1;
}
void ubaci(int niz[],int duzina){
    int *p,*q,z1,i;
    //petljom prolazimo kroz clanove niza
    for(i=duzina-1;i>=0;i--){
        q=niz+i;
        p=niz+i*2;
        *p=(*q);
        }
        //pri sljedecem prolazu kroz petlju udvostrucimo nas niz
        for(i=0;i<2*duzina;i=i+2){
            p=niz+i;
            q=p+1;
            z1=abs(*p);
            *q=suma(z1);
        }
        
}
int main(){
    int niz[30],i,duzina=10;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<duzina;i++){
        scanf("%d",&niz[i]);
    }
    ubaci(niz,duzina);
    printf("%d",niz[i]);
    return 0;
}

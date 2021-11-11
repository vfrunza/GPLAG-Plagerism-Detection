#include <stdio.h>
#include <stdlib.h>

/* Funkcija za ubacivanje elementa u niz  */
void ubaci(int niz[],int velicina_niza) {
    int element_niza,m=1;
    int i,j,broj;
    int dr_velicina=2*velicina_niza;
    int drugi_niz[20];
    int suma=0;
    for(i=0;i<dr_velicina;i++){
        if(i%2==0){
            drugi_niz[i]=niz[i/2];
            }
            else {
                element_niza=niz[i-m];
                while(element_niza!=0){
                    broj=element_niza%10;
                    suma+=abs(broj);
                    element_niza=element_niza/10;
                }
                drugi_niz[i]=suma;
                suma=0;
                m=m+1;
            }
        }
        for(j=0;j<dr_velicina;j++){
            niz[j]=drugi_niz[j];
        }
        
    }

/* Funkcija za izbacivanje elemenata iz niza */

int izbaci(int*p,int velicina_niza) {
    int fibonacci,i,k,m;
    for(i=0;i<velicina_niza;i++) {
        fibonacci=0;
        int broj;
        int prvi_broj=1;
        int drugi_broj=1;
        for(m=1;m<=*(p+i);m++) {
            if(*(p+i)==prvi_broj){
                fibonacci=1;
                break;
            }
            if(m==prvi_broj) {
                broj=prvi_broj;
                prvi_broj=prvi_broj+drugi_broj;
                drugi_broj=broj;
            }
            
        }
        
        if(fibonacci){
            k=i;
            while(k<velicina_niza-1){
                *(p+k)=*(p+k+1);
                k++;
            }
            velicina_niza--;
            i--;
        }
        
        
    }
    return velicina_niza;
}


/* Unosenje pocetnog niza i ispisivanje krajnjeg-modificiranog niza */

int main() {
int niz[20];
int i,g;
printf("Unesite niz od 10 brojeva: ");
for(i=0;i<10;i++){
    scanf("%d",&niz[i]);
}

    ubaci(niz,10);
    int niznakraju;
    niznakraju=izbaci(niz,20);
    if(niznakraju==0){
        printf("Prazan niz");
        return 0;
    }
    printf("Modificirani niz glasi: ");
    for(g=0;g<niznakraju;g++) {
        if(g<niznakraju-1 && g>=0){
            printf("%d, ",niz[g]);
        }
        else{
            printf("%d.",niz[g]);
        }
    }
    return 0;
}



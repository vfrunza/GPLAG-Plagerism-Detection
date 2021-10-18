#include <stdio.h>
#include <math.h>
#define BROJ_EL 100

void zaokruzi1(float niz[], int velicina)
{
    int i;
    for(i=0; i<velicina; i++) {
        niz[i]=round(niz[i]*10)/10.;
    }
}

void preslozi(float niz[], int velicina, int k)
{
    int i, j, broj, suma=0, brojac=0, pom, duzina=0, mjesto=0;
    float temp;

    zaokruzi1(niz,velicina);

    for(i=0; i<velicina; i++) {
        if(niz[i]>=0) {
            broj=niz[i]*10;
            pom=niz[i]*10;
        } else {
            broj=(-1)*niz[i]*10;
            pom=(-1)*niz[i]*10;
        }
        
        /*Provjeravamo kolika je duzina broja kada se pomnozi sa 10 zbog racunanja sume koja je razlicito ogranicena kod svakog broja*/
        while(pom>0) {
            pom=pom/10;
            duzina++;
        }

        while(brojac<duzina) {
            suma+=broj%10;
            broj=broj/10;
            brojac++;
        }
        
        /*Preslazemo niz*/
        if(suma>=k) {
            temp=niz[i];
            for(j=i; j>mjesto; j--) {
                niz[j]=niz[j-1];
            }
            niz[mjesto]=temp;
            mjesto++;
        }

        suma=0;
        brojac=0;
        duzina=0;
    }
}

int main()
{
    int i, k, velicina;
    float niz[BROJ_EL];

    printf("Unesite duzinu niza: ");
    scanf("%d", &velicina);

    printf("Unesite niz: ");
    for(i=0; i<velicina; i++) {
        scanf("%f", &niz[i]);
    }

    printf("Unesite broj k: ");
    scanf("%d", &k);

    zaokruzi1(niz,velicina);
    printf("Nakon transformacije: ");
    for(i=0; i<velicina; i++) {
        printf("%g ", niz[i]);
    }

    preslozi(niz,velicina,k);

    printf("Nakon transformacije: ");
    for(i=0; i<velicina; i++) {
        printf("%g ", niz[i]);
    }

    return 0;
}

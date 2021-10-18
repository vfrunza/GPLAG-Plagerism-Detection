#include <stdio.h>
#include <math.h>

int velicina;
//Funkcija zaokružuje elemente datog niza na 1 decimalu
void zaokruzi1 (float niz[], int velicina)
{
    int p;
    for (p=0; p<velicina; p++) {
        niz[p]=(niz[p] * 10);
        niz[p]=(round)(niz[p]);
        niz[p]=niz[p]/ 10;
    }
}

int suma_cifara (float broj)
{


    int suma=0;
    int cifra=1;
    broj = fabs(broj*10);

    while (broj!=0) {
        cifra = ((int) (broj)) % 10;
        suma = suma + cifra;
        broj = broj/10;
    }

    return suma;
}


void preslozi (float niz[], int velicina, int k)
{
    int i=0, j=0, m=0,  br=1;
    float broj1=0, broj2=0;
    zaokruzi1(niz,velicina); //pozivamo fuknciju zaokruzi
    for (i=0; i<velicina; i++) {
        broj1=niz[i];
        if (suma_cifara(broj1)>=k) continue; //ako je suma nekog elemnta veća od datog broja k on treba da ostane na tom mjestu

        else { //ako je suma manja od k, trazimo sljedeci broj cija je suma veca od k, tako da im mozemo zamijeniti mjesta, ali pri tome ocuvati redosljed
            for (j=i+1; j<velicina; j++) {
                broj2=niz[j];
                if (br<2) {
                    if (suma_cifara(broj2)>=k) {
                        for (m=j; m>i; m--)
                            niz[m]=niz[m-1];  //svaki sljedeci broj niza, iduci od kraja pa prema broju, pomjeramo za jedno mjesto udesno
                        niz[i]=broj2;  // i na mjesto elementa koji je imao manju sumu od k, stavljamo element koji ima vecu
                        br++;
                    }

                }

            }

        }
        br=1;
    }

}
int main()
{
    float niz [100];
    int n=0,  velicina=0, k=0;

    printf ("Unesite velicinu niza\n");
    scanf ("%d", &velicina);
    printf ("Neka je dat niz\n");

    //Unosimo niz

    for (n=0; n<velicina; n++)
        scanf ("%f", &niz[n]);

    zaokruzi1(niz, velicina);  //Poziv funkcije zaokruzi brojeve

    printf ("Unesite k\n");
    scanf ("%d", &k);

    preslozi(niz, velicina, k);  //Poziv funkcije preslozi

    printf("Niz glasi: ");    //Printenje konacnog niza
    for (n=0; n<velicina; n++)
        printf("%.1f ", niz[n]);

    return 0;
}

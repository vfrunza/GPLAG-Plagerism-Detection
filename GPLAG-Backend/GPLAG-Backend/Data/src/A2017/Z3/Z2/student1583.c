#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz1, int vel_niz1)
{

    int i;

    for(i=0; i<vel_niz1; i++) {
        niz1[i]=niz1[i]*10;
        niz1[i]=roundf (niz1[i]);           /*...Zaokruzujemo na jednu decimalu sve clanove niza...*/
        niz1[i]=niz1[i]/10;
    }

}



void preslozi(float* niz1, int vel_niz1, int k)
{

    zaokruzi1(niz1, vel_niz1);



    int i=0,j,l;
    int cifra,suma=0;
    int temp;
    double temp2;



    for(j=0; j<vel_niz1; j++) {             /*...Prolazimo kroz niz...*/


        suma=0;
        temp=fabs(niz1[i]*10);

        while (temp>0) {
            cifra=temp%10;
            suma+=cifra;                    /*...Nalazimo sumu cifara svakog clana...*/
            temp=temp/10;
        }


        if(suma<k) {

            temp2=niz1[i];

            for(l=i; l<vel_niz1-1; l++) {       /*...Preslazemo niz...*/
                niz1[l]=niz1[l+1];
            }

            niz1[vel_niz1-1]=temp2;
            i--;                                /*...Provjeravamo da li i susjedni clan zadovoljava uslov...*/
        }

        i++;                                    /*...Prelazimo na naredni clan niza...*/

    }


}

int main()
{

    return 0;

}  

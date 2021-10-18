#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void zaokruzi1 (float *niz, int vel)
{
    int i;
    for(i=0; i<vel; i++) {
        niz[i]*=10;
        niz[i]=round(niz[i]);
        niz[i]/=10;
    }
}

void preslozi (float *niz, int vel, int k)
{
    int i, a, b, c, d, e, f, g, h, j, Velicina=vel, vel1=vel;
    float red[10000]= {0}, NoviNiz[10000]= {0};

    zaokruzi1(niz, vel);

    /* U pomocni niz "red" stavljamo uneseni niz */
    for(i=0; i<vel; i++)
        red[i]=niz[i];

    /* Rastavljamo broj na cifre i ako su manje od k stavljamo ih u niz, a ako su vece ili jednake u red */
    for(i=0; i<vel; i++) {

        a=(int)(abs)((niz[i]*10))%10;
        b=((int)(abs)((niz[i]*10))%100-a)/10;
        c=((int)(abs)((niz[i]*10))%1000-(a+b*10))/100;
        d=((int)(abs)((niz[i]*10))%10000-(a+b*10+c*100))/1000;
        e=((int)(abs)((niz[i]*10))%100000-(a+b*10+c*100+d*1000))/10000;
        f=((int)(abs)((niz[i]*10))%1000000-(a+b*10+c*100+d*1000+e*10000))/100000;
        g=((int)(abs)((niz[i]*10))%10000000-(a+b*10+c*100+d*1000+e*10000+f*100000))/1000000;
        h=((int)(abs)((niz[i]*10))%100000000-(a+b*10+c*100+d*1000+e*10000+f*100000+g*1000000))/10000000;

        if(a+b+c+d+e+f+g+h<k) {
            for(j=i; j<vel-1; j++)
                niz[j]=niz[j+1];

            vel--;
            i--;
        }
    }

    for(i=0; i<vel1; i++) {
        a=(int)(abs)((red[i]*10))%10;
        b=((int)(abs)((red[i]*10))%100-a)/10;
        c=((int)(abs)((red[i]*10))%1000-(a+b*10))/100;
        d=((int)(abs)((red[i]*10))%10000-(a+b*10+c*100))/1000;
        e=((int)(abs)((red[i]*10))%100000-(a+b*10+c*100+d*1000))/10000;
        f=((int)(abs)((red[i]*10))%1000000-(a+b*10+c*100+d*1000+e*10000))/100000;
        g=((int)(abs)((niz[i]*10))%10000000-(a+b*10+c*100+d*1000+e*10000+f*100000))/1000000;
        h=((int)(abs)((niz[i]*10))%100000000-(a+b*10+c*100+d*1000+e*10000+f*100000+g*1000000))/10000000;

        if(a+b+c+d+e+f+g+h>=k) {
            for(j=i; j<vel1-1; j++)
                red[j]=red[j+1];

            vel1--;
            i--;
        }
    }
    /* U NoviNiz stavljamo oba niza pri cemu je niz prvi, a red drugi po redu */
    for(i=0; i<vel; i++)
        NoviNiz[i]=niz[i];
    for(i=vel; i<Velicina; i++)
        NoviNiz[i]=red[i-vel];


    for(i=0; i<Velicina; i++)
        niz[i]=NoviNiz[i];
}

int main()
{
    return 0;
}
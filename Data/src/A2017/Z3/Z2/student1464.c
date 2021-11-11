#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int n)
{
    int i=0;
    int decimala=0;
    float rezultat=0;
    for( ; i<n; i++) {
        rezultat=(int)(niz[i]);
        decimala=(int)(niz[i]*100);
        decimala=decimala%100;
        if(decimala>0 && decimala%10>=5) decimala+=10;
        if(decimala<0 && decimala%10<=-5) decimala-=10;
        rezultat+=(float)(decimala/10)/10;
        niz[i]=rezultat;
    }
}

void preslozi(float niz[], int n, int k)
{
    float a[50];
    float b[50];
    int na=0, nb=0;
    int i, suma=0, temp;
    zaokruzi1(niz,n);
    for(i=0; i<n; i++) {
        temp=niz[i]*10;
        suma=0;
        for( ; temp!=0; temp/=10) suma+=temp%10;
        if(suma<0)suma*=-1;
        if(suma>=k) {
            a[na++]=niz[i];
        } else {
            b[nb++]=niz[i];
        }
    }
    for(i=0; i<n; i++) {
        if(i<na) {
            niz[i]=a[i];
        } else {
            niz[i]=b[i-na];
        }
    }
}
int main() {
      return 0;
        
}

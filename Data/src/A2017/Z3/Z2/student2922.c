#include <stdio.h>
#include <math.h>

void zaokruzi1 (float niz[], int n) {
int i=0; 
for(i=0; i<n; i++)
niz[i]=round(niz[i]*10.)/10.;
}

void preslozi(float niz[], int n, int k) {
    float A[100]={0}, B[100]={0};
    int a=0, b=0, x=0, i=0, suma=0;
    zaokruzi1(niz,n);
    for(i=0; i<n; i++){
        x=fabs(niz[i]*10);
        while(x!=0){
            suma+=x%10;
            x/=10;
        }
        if(suma>=k) {
            A[a]=niz[i];
            a++;
        }
        else {
        B[b]=niz[i];
        b++;}
        suma=0;
    }
    for(i=0; i<a; i++)
    niz[i]=A[i];
    for(i=a; i<a+b; i++)
        niz[i]=B[i-a];
}
int main() {
    return 0;
}
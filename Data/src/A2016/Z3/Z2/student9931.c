#include <stdio.h>
 
int fibonacci(int br) {
    int i=0, niz[100], w=0;
    do { if(i==0||i==1){
    niz[i]=1;}
    else niz[i] = niz [i-1] + niz[i-2];
    if (br==niz[i]){
    w=1;
    break;}
    }while (niz[i++]<br);
    return w;
}
void ubaci(int* p, int velicina) {
    int g, n, *q, *d, i=0;
    q=p;
    while (q<p+2*velicina-1){
    n=1;d=q+velicina-i-1;
    while (d>=q){
    *(d+1)=*d;d--;}
    if (*q<0) g=-*q;
    else g=*q;
    while (g>=10){
    g=g/10;
    n=n*10;}
    if (*q<0)g=-*q;
    else g=*q;
    *(q+1)=0;
    while(n>=1){
    *(q+1)=*(q+1)+g/n;
    g=g-(g/n)*n;
    n=n/10;}
    i++;q=q+2;}
}
int izbaci(int* p, int velicina) {
    int *q, *d;
    q=p;
    while (q<p+velicina){
    if (fibonacci(*q)){
    d=q;
    while (d<(p+velicina-1)){
    *d=*(d+1);d++;}
    q--;velicina--;}
    q++;}
    return velicina;
}
int main() {
    int niz[100], i, j;
    printf ("Unesite niz od 10 brojeva: ");
    for (i=0; i<10; i++){
    scanf ("%d", &niz[i]);
    }
    ubaci(niz, i);
    i=i*2; i=izbaci(niz, i);
    printf ("Modificirani niz glasi: ");
    for (j=0; j<i; j++){
    printf ("%d", niz[j]);
    if (j!=i-1) { printf (", ");}
    if (j==i-1) printf (".");
    }
    return 0;
}
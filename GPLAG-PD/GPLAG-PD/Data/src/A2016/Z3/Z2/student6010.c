#include <stdio.h>
#include <math.h>
void ubaci(int *niz, int vel) {
 int i, j;
 int n, suma;
 for(i=0; i<vel; i++) {
  for(j=vel-1; j>i; j--) {
   niz[j+1]=niz[j];
  } n=niz[i];
  if(n<0) n*=-1;
  suma=0;
  while(n!=0) {
   suma+=n%10;
   n/=10;
  } niz[i+1]=suma;
   i++;
   vel++;
   }
}
 
 int izbaci(int *niz, int vel) {
  int i, brojFib=0;
  int a, b, fibonaccijev;
   for(i=0; i<vel-brojFib; i++) 
   {
    niz[i]=niz[i+brojFib];
    a=1;
    b=1;
    while(niz[i]>a && niz[i]>b) {
     a=a+b;
     b=a+b;
    } 
     if(niz[i]==a || niz[i]==b) fibonaccijev=1;
    else fibonaccijev=0;
    if(fibonaccijev==1) {
    brojFib++;
    i--;
    }
   }
   return vel-brojFib;
 }
 
int main() {
 int novaVel=0, niz[20]={0}, i;
 printf("Unesite niz od 10 brojeva: ");
 for(i=0; i<10; i++)
 {scanf("%d", &niz[i]);
 } 
     ubaci(niz,10);
    novaVel=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    for(i=0; i<novaVel; i++) {
     if(i<novaVel-1) printf("%d, ", niz[i]);
     else printf("%d.", niz[i]);
    }
     return 0;
  }

#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[], int vel)
{
  int i;
  for(i=0; i<vel; i++) {
    niz[i]=round(niz[i]*10)/10;
  }
}
int suma_cifara(float broj)
{
  int suma=0;
  int cifra;
  int br=broj;
  suma+=(fabs(broj-(int)broj)*10+0.5);
  while(br!=0) {
    cifra=br%10;
    if(cifra<0) cifra*=-1;
    suma=suma+cifra;
    br=br/10;
  }
  return suma;
}
void preslozi(float niz[], int vel, int k)
{
  int i;
  int j=0;
  int m=0;
  float niz_pom1[100000];
  float niz_pom2[100000];
  zaokruzi1(niz, vel);
  for(i=0; i<vel; i++) {
    if(suma_cifara((niz[i]))>=k) {
      niz_pom1[j]=niz[i];
      j++;
    } else {
      niz_pom2[m]=niz[i];
      m++;
    }
  }
  for(i=0; i<j; i++)
    *(niz+i)=niz_pom1[i];
  for(i=0; i<m; i++)
    *(niz+i+j)=niz_pom2[i];
}
int main()
{
  int i;
  float niz[] = { 3.2, -4.301, -123.1999, 0, 0.9 };
  float niz1[100000]={0.11,0.22,-0.44,-111111.1501,0};
  preslozi(niz1,99999,4);
  preslozi(niz, 5, 8);
  printf("Niz glasi: ");
  for (i=0; i<5; i++)
    printf("%g ", niz[i]);

  return 0;
}

#include <stdio.h>
#include <math.h>
#define vel1 10
#define vel2 20

void ubaci(int *niz, int vel )
{

  int m=2*vel;
  int i,nizpom[20];

  /*Kopiranje vrijednosti clanova niza iz starog u novi*/
  for(i=vel-1; i>=0; i--) {
    *(nizpom+2*i)=*(niz+i);
  }

  /*Racunanje sume cifara broja i smjestanje sume u clanove novog niza*/
  for(i=0; i<m; i=i+2) {
    int suma=0;
    int tmp,zadnja;
    tmp=*(nizpom+i);

    while(*(nizpom+i)!=0) {
      if(*(nizpom+i)<0)
        *(nizpom+i)=-*(nizpom+i);
      zadnja=*(nizpom+i)%10;
      suma+=zadnja;
      *(nizpom+i)/=10;
    }
    *(nizpom+i)=tmp;
    *(nizpom+i+1)=suma;
  }

  /*Kopiranje clanova niza iz pomocnog u novi*/
  for(i=0; i<m; i++) {
    *(niz+i)=*(nizpom+i);
  }
}

int izbaci(int *niz, int m)
{
  int i,j,x,z,y;
  /*Petlja koja provjerava da li clan novog niza zadovoljava uslov da pripada Fibonacijevom nizu*/
  for(i=0; i<m; i++) {
    x=0,y=1,z=1;
    while(z<*(niz+i)) {
      z=x+y;
      x=y;
      y=z;
    }
    /*Petlja koja izbacuje clanove Fibonacijevog niza*/
    if(*(niz+i)==z) {
      for(j=i; j<m-1; j++) {
        *(niz+j)=*(niz+j+1);
      }
      m--;
      i--;
    } else
      continue;
  }
  return m;
}


int main()
{

  int  niz[20],n,i;
  printf("Unesite niz od 10 brojeva: ");
  for(i=0; i<10; i++)
    scanf("%d", &niz[i]);
  ubaci(niz,vel1);
  n=izbaci(niz,vel2);
  printf("Modificirani niz glasi: ");
  for(i=0; i<n; i++) {
    if(i<n-1)
      printf("%d, ", niz[i]);
    else if(i==n-1)
      printf("%d.", niz[i]);
  }
  return 0;
}
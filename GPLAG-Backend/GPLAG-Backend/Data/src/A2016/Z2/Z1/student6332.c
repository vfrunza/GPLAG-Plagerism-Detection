#include <stdio.h>
#include <math.h>


int main() {
   int x, a, b, c,r=0, z=0;
   printf ("Unesite broj: ");
   scanf ("%d", &x);
   
  if(x<0)
     x*=-1;
  
  while (x/10!=0) {
     a=x%10;
     x/=10;
     b=x%10;
     c=a-b;
     if(c<0)
     c*=-1;
     r=r*10+c;
     if(r==0 && c==0)
     r=1;
  }
  while (r>0) {
     z=z*10 + r%10;
     r/=10;
  }
  printf ("%d", z);
  return 0;
}
   
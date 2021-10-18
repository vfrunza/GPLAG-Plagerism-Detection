#include <stdio.h>


int daj_prost()
{
  static int a=1;
  int i, x;
  a++;
 
 for(i=2; i<a; i++)
 {
   if(a%i==0)
    {
      i=1;
      a++;
    }
 }
 x=a;
 return x;
}

 int main ()
 {
  int A, B, i, y, suma=0;
 
  do
  {
     printf("Unesite brojeve A i B: ");
     scanf("%d %d", &A, &B);
     if(A<=0)
       {
         printf("A nije prirodan broj.\n");
         continue;
       }
    if(A>=B)
       {
         printf("A nije manje od B.\n");
         continue;
       }
    if(B<=0)
       {
         printf("B nije prirodan broj.\n");
         continue;
       }
  }while(A>=B || A<=0 || B<=0);
 
 y=A+1;
 for(i=daj_prost(); i<B; i=daj_prost())
  {
    if(y<=i)
     {
      suma=suma+i;
      
     }
  }
 printf("Suma prostih brojeva izmedju %d i %d je %d.\n", A, B, suma);
 
 return 0;
 }

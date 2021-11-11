#include <stdio.h>

int daj_prost ()
{
    static int  brj=1;
    n1:brj++;
    int i;
        for (i=2;i<brj;++i)
        {
            
            if (brj%i==0)
            {
                 /*nije prost*/
                break;
            }
            
            
        }
        if ( i==brj )
        {
           return i;
        }
        else if (i!=brj)
        {
            goto n1;
        }
    }


int main ()
{
   long int a,b,i;
   int niz[5000];
   int suma=0;
   n1:printf ("Unesite brojeve A i B: ");
   scanf ("%li",&a);
   scanf ("%li",&b);
   
   /*pogresan unos*/
    if (a<1)
   {
       printf ("A nije prirodan broj.\n");
       goto n1;
   }
   else if (b<=a)
   {
      printf ("A nije manje od B.\n"); 
      goto n1;
   }
   
  
  for (i=0;i<5000;i++)
  {
      niz[i]=daj_prost();
  }
  
  for (i=0;i<5000;i++)
  {
      if (niz[i]>a && niz[i]<b)
      {
          suma=suma+niz[i];
      }
  }
  
  printf ("Suma prostih brojeva izmedju %i i %i je %i.",a,b,suma);
  
  return 0;
}
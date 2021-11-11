#include <stdio.h>
int daj_prost()
{
    static int a=1;
    int i,prost;
    while(1==1)
    {
        a++;
        prost=1;
        for(i=2;i<a;i++)
        {
            if(a%i==0)
            {
                prost=0;
                break;
            }
        }
    if(prost==1) break;
    }
        return a;
    }
int main() {
    int a,b,i;
    int s=0;
    while(1==1)
    {
     printf("Unesite brojeve A i B: ");
     scanf("%d %d", &a, &b);
     if(a<=0)
     printf("A nije prirodan broj.\n");
     else if (a>=b) 
     printf("A nije manje od B.\n");
     else break;
    } 
    for(i=daj_prost();i<b;)
      {
          if(i>a)
          s+=i;
          i=daj_prost();
      }
      printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, s);
	return 0;
}

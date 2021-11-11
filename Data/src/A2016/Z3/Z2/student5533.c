#include <stdio.h>
void ubaci(int*niz, int vel)
{
	int niz1[30], i,j=0,suma=0,broj;
	for (i=0; i<vel; i++)
	{
		niz1[j]=niz[i];
		j++;
		broj=niz[i];
		suma=0;
		while (broj!=0)
		{
			suma+=broj%10;
			broj/=10;
		}
		if (suma<0)
		   suma*=-1;
		niz1[j]=suma;
		j++;
		
	}
	for (i=0;i<2*vel; i++)
	{
		niz[i]=niz1[i];
	}
}
int izbaci (int *niz, int vel)
{
  int fib[300], i, j, k;
  fib[0]=1;
  fib[1]=1;
  for (i=2; i<300; i++)
  {
  	fib[i]=fib[i-1]+fib[i-2];
  }
  for (i=0; i<vel; i++)
  
     for (j=0; j<300; j++ )
     
        if (fib[j]==niz[i])
        {
        	for (k=i; k<vel-1; k++)
        		niz[k]=niz[k+1];
        vel--;
        i--;
        break;
        }
        //printf("%d", vel);
  return vel;
}

int main() {
	int i,niz[30],vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<vel; i++)
	   scanf ("%d", &niz[i]);
	ubaci(niz,vel);
	vel=vel*2;
	vel=izbaci(niz,vel);
	printf("Modificirani niz glasi: ");
	for (i=0; i<vel; i++)
	{
		if (i<=vel-2)
		   printf ("%d, ", niz[i]);
		else
		   printf ("%d.", niz[i]);
	}
	return 0;
}

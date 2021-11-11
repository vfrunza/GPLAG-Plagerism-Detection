#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ubaci(int*niz,int n)
{ /*funkcija za prosirivanje niza*/
  int i,x,n1,suma=0;
  int*p=niz,*q=niz;
  n1=n-1;
  for(i=n1;i>0;i--)
  {*(p+(2*i))=*(p+i);}
  p=niz;
  for (i=1;i<2*n;i+=2)
  {x=*q;suma=0;
   while (x!=0)
  	{ suma=suma+x%10;
  		x=x/10; 
  	}
   *(p+i)=(abs)(suma);
   q=q+2;
  }
}


int fibonaci (int x) {
	/*da li je broj clan fibonacijevog niza*/
	int fiboNew=0,fiboNminus1=0,fiboNminus2=1;
	if (x==fiboNminus2) {return 1;}
	else 
	{	while (fiboNew<x)
		{	fiboNew=fiboNminus2+fiboNminus1;
			if (x==fiboNew) {return 1;}
			fiboNminus1=fiboNminus2;
			fiboNminus2=fiboNew;
		}
		return 0;
	}
}


int izbaci (int* niz, int n)
{ int*p=niz,i,j,*q;
	for(i=0;i<n;i++)
	{	q=p;
		if (fibonaci(*p)==1)
		{/*izbacivanje clana iz niza*/
		 for(j=i;j<n-1;j++)
		 {	*q=*(q+1);
		 		*q++;
		 }
		*p--;
		n--;
		i--;
		}
	*p++;
	}
	return n;
}


int main(){
	int niz[20],i,velicina=0,novav=0;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++)
		{scanf("%d",&niz[i]);velicina++;}
	int*p=niz[0];
	
	ubaci(niz,velicina);
	velicina=velicina*2;
	novav=izbaci(niz,velicina);
	printf("Modificirani niz glasi: ");
	for(i=0;i<novav;i++)
		{	if (i==novav-1) printf("%d.",niz[i]);
			else printf("%d, ",niz[i]);}
return 0;	
}
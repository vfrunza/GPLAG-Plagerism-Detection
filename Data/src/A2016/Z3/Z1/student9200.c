#include <stdio.h>

int prost(int x)
{
	int i;
	int brojac=0;
	for(i=2;i<=x/2;i++)
	{
		if(x%i==0) brojac++;
	}
	if(brojac==0) return 1;
	else return 0;
}

int daj_prost()
{
  static int k=2;
  for(;;)
  {
  	if(prost(k)) return k++;
  	++k;
  }
 
}

int main()
{
	int A,B;
	int i;
	int suma=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A<1)
		{
			printf("A nije prirodan broj.\n");
			continue;
		}
	   if (A>=B)
		{
			printf("A nije manje od B.\n");
			continue;
		}
		else break;
		
		
	}while(1);
	
	i=daj_prost();
	
	while(i<B)
	{
	     if(i>A && i<B) suma+=i;
	     
	     i=daj_prost();
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}

#include <stdio.h>
static int A=0,B=0;
static int n=0;
int daj_prost()
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			break;
		}
		else if(i==n)
		{
			return n;
		}
	}
}
int main() {
	int i,suma=0,prost=0;
	ponovi:
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A<0)
	{
		printf("A nije prirodan broj.\n");
		goto ponovi;
	}
	if(A==0)
	{
		printf("A nije prirodan broj.\n");
		goto ponovi;
	}
	if(A>B)
	{
		printf("A nije manje od B.\n");
		goto ponovi;
	}
	if(A==B)
	{
		printf("A nije manje od B.\n");
		goto ponovi;
	}
	for(i=A+1;i<=B;i++)
	{
		n=i;
		prost=daj_prost();
		suma=suma+prost;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}

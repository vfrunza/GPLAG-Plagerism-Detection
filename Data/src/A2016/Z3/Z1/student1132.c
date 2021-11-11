#include <stdio.h>
#include <math.h>

int daj_prost()
{
	static int curr = 1;
	int i,j,korijen,prost;
	for(i=curr+1;;i++)
	{
		 korijen = sqrt(i)+1;
		 prost = 1;
		for(j=2;j<korijen;j++)
		{
			if(i%j==0)
			{
				prost = 0;
				break;
			}
		}
		if(prost)
		{
			curr = i;
			break;
		}
	}
	return curr;
}



int main()
{

int i=10,j,A,B,suma = 0,prime;
/*UNOS*/
do
{
	printf("Unesite brojeve A i B: ");
	scanf("%d%d",&A,&B);
	
	if(A<1) printf("A nije prirodan broj.\n");
	else if(!(A<B)) printf("A nije manje od B.\n");
	
} while(A<1 || B<1 || !(A<B));

/*RACUNANJE SUME*/
do
{
prime = daj_prost();
if(prime>A && prime<B) suma+=prime;
}while(prime<B);

printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);

	return 0;
}

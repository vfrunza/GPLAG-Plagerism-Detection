#include <stdio.h>
int daj_prost ()
{
	int prost;
	int j;
	static int i=2;
	int br;
	do
	{
		br=0;
		for(j=1;j<=i;j++)
		{
			if(i%j==0)
			br++;
		}
		prost=i;
		i++;
		if(br==2)
		return prost;
	}
	while(br!=2);
}
int main() 
{
	float A1,B1;
	int A,B;
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%f %f",&A1,&B1);
		A=(int)(A1);
		B=(int)(B1);
		if(A<=0 || (A1-A)!=0)
		printf("A nije prirodan broj.\n");
		else if(A>=B)
		printf("A nije manje od B.\n");
		else if(B<=0 || (B1-B)!=0)
		printf("B nije prirodan broj.\n");
	}
	while(A<=0 || A>=B || (A1-A)!=0 || B<=0 || (B1-B)!=0);
	int suma=0;
	int i=daj_prost();
	while(i<B)
	{
		if(i>A)
		suma+=i;
		i=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	return 0;
}

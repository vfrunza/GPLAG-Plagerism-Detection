#include <stdio.h>
#include <math.h>
int daj_prost()
{
	static int prost = 2;
	static int poziv = 1;
	int i, daLiJeProst = 1;
	if(poziv++==1) return 2;
	for(;;)
	{
		prost++;
		daLiJeProst=1;
		if(prost%2==0) daLiJeProst = 0;
		int k = sqrt(prost);
		for(i=2;i<=k;i++)
			if(prost%i==0) daLiJeProst = 0;
		if(daLiJeProst) return prost;
	}
}

int main() {
	int i=0, a,b;
	for(;;)
	{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	if(a<=0)
		printf("A nije prirodan broj.\n");
	else if(a>=b)
		printf("A nije manje od B.\n");
	else if(b<=0)
		printf("B nije prirodan broj.\n");
	else break;
	}
	int suma=0;
	for(;;)
	{
		int x = daj_prost();
		if( x>a && x<b) suma+=x;
		if(x>b) break;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	return 0;
}

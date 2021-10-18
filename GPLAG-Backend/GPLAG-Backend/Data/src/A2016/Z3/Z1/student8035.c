#include <stdio.h>
#include <math.h>

int jeProst(int n)
{
	int i;
	if( n == 2 || n == 3) return 1;
	
	for( i = 2; i <= sqrt(n); ++i)
	{
		if(n %i == 0) return 0;
	}
	
	return 1;
}
int daj_prost()
{
	static int prost = 2;
	while(1)
	{
		if(jeProst(prost)) return prost++;
		++prost;
	}
}
int main() {
	int a, b, zbir = 0, i;
	while(1)
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		
		if(a <= 0 ) printf("A nije prirodan broj.\n");
		else if(a >= b) printf("A nije manje od B. \n");
		else if(b <= 0) printf("B nije prirodan broj. \n");
		else break;
	}
	
	for(i = daj_prost(); i < b; i = daj_prost())
	{
		if(i > a && i < b) zbir += i;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, zbir);
	return 0;
}

#include <stdio.h>

int daj_prost()
{	static int k=1;
	int j;
	k++;
	for(; ; k++)
	{
	for(j=2; j<k; j++)
	{
		if(k%j==0)
		{	
			break;
		}
	}
	
	if(k!=j)
	continue; 
	else 
	break; 
	}
	return k; 
}

int main() {
	int x, a, b, suma=0;

	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	if(a>=b)
	printf("A nije manje od B.\n");
	else if(a<1)
	printf("A nije prirodan broj.\n");
	}
	while(a>=b || a<1); 

	do{
		x=daj_prost();
		if(x>a && x < b)
			suma+=x;
	} while(x<b);
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}

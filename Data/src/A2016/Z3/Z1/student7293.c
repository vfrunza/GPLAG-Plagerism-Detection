#include <stdio.h>

int daj_prost ()
{
	static int x=1;
	int i,br=0;

	while (br==0)
{	
	x++;
	br=1;
	for (i=2; i<x; i++) //ispituje da li je broj prost
	{
		if (x%i==0)
		{
			br=0;
			break;
		}
	}
		if (br!=0)
	return x;
}
}

int main() 
{
	int a,b,p,suma=0,i;
	
	do //omogucava unos brojeva A i B u odredjenom opsegu
	{
	printf("Unesite brojeve A i B: ");
	scanf ("%d %d", &a, &b);

	if (a<=0)
	{
		printf ("A nije prirodan broj.\n");
	}
	if (a>=b)
	{
		printf ("A nije manje od B.\n");
	}
	} while (a<=0 || a>=b);
	

	p=daj_prost();
	
	while (p<b) //racuna sumu prostih brojeva
	{
		if (p>a && p<b)
		suma+=p;
		p=daj_prost();
	}
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	
	return 0;
}

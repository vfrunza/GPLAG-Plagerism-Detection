#include <stdio.h>

int daj_prost ()

{
	static int prost=1;
	int temp=0;int pom;
	
	while (temp==0)
	{
		prost++;
		pom=0;
		int i;
		for (i=2; i<prost; i++)
		{
			if (prost%i==0) pom=1;
		}
		if (pom==1) continue;
		temp=1;
	}
return prost;

}


int main() {
	int a=0;
	int b=0;
	while (a<=0 || b<=0 || a>=b)
	{
		printf ("\nUnesite brojeve A i B: ");
		scanf ("%d", &a);
		scanf ("%d", &b);
		if (a<=0) printf ("A nije prirodan broj. ");
		else if (a>=b) printf ("A nije manje od B. ");
		else if (b<=0) printf ("B nije prirodan broj. ");
	
		
	}
	
	int pom=daj_prost ();
	while (pom<=a)
	{
		pom=daj_prost ();
		
	}
	int suma=pom;
	while (pom<b)
	{
		pom=daj_prost();
		suma+=pom;
	}
	suma-=pom;
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);

	return 0;
}

#include <stdio.h>
#define Unos 100

int main() {
	int a, niz[Unos], i, t;
	int p=0, c, d=0;
	printf("Uneste velicinu niza");
	scanf ("%d", &a);
	for (i=0; i<Unos; i++)
	{
	
		while(p!=(a+1))
		{
	    ponovo:
		scanf("%d", &niz[i]);
		if(niz[i]<0)
		    {
		     niz[i]=niz[a-1];
		     a--;
		     i--;
		     goto ponovo;
		    }
		p++;
		}
	}
	
	return 0;
}

#include <stdio.h>

int main() { 
	int n=-1,red=0,kolona=0;
	int sirina;

	
	while (n<=0 || n>50)
	
	{
		
		printf ("Unesite broj n: ");
		scanf ("%d", &n);
		if (n==1)
		{
			printf ("**");
		}
			if (n>0 && n<=50)
			
		{
				sirina=4*(n-1)+1;
			break;
			
		}
		else
		{
			printf ("Pogresan unos\n");
		}
		
	}


	
	for (red=0;red<n;red++)
	{
		for (kolona=0;kolona<sirina;kolona++)
		{
			if (red==kolona || red+kolona==2*(n-1) || kolona-red==2*(n-1) || red+kolona==4*(n-1))
			{
				printf ("*");
			} else {
				printf (" ");
			}
		}
		printf ("\n");
	}return 0;
}

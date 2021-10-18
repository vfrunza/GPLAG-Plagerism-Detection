#include <stdio.h>

int main() {
	int i,j,a,uslov,n;
	do {
		uslov = 1;
		printf ("\nUnesite broj n: ");
		scanf ("%d", &n);
		a = 2 * (n - 1);
		if ((n<1) || (n>50) || (n!=(int)n))
		{
			uslov = 0;
			printf ("Pogresan unos");
		} 
		else {
			if (a==0) a = 1;
			for (i=0; i<n; i++)
			{
				for (j=0; j < ( 2 * a + 1) ; j++)
				{
					if (((j%a)==i) || ((i + (j%a))==a))
					{ printf ("*"); 
					}
					else { printf (" ");
				}
				}
				printf ("\n", j);
		}
		
              }
        }
              while (uslov == 0);
return 0;
}
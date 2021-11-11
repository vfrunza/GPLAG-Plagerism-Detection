#include <stdio.h>

int main()
{
	int i, j, r, k, sk, o;
	int pom=0;
	int pom2=0;	
	do{
		printf ("Unesite broj redova: ");
		scanf ("%d", &r);
		
	}while (r<=0 || r>10);
	do{
		printf ("Unesite broj kolona: ");
		scanf ("%d", &k);
	
	}while (k<=0  || k>10);
	do{
			printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &sk);
}while(sk<=0 || sk>10);
	
		
	
	
	
		for (i=0; i<((r+1)+r); i++)
		{
			pom=0;
			pom2=0;
		
			if (i%2==0)
			{
				for (j=0; j<=((k*sk)+k); j++)
				{
					if (j==pom)
					{
						printf ("+");
						pom=pom+(sk+1);
				}
				else
				printf ("-");
			}
		}
		else
		{
			for (o=0; o<=((k*sk)+k); o++)
			{
				if (o==pom2)
				{
					printf ("|");
					pom2=pom2+(sk+1);
				}
				else {
					printf (" ");
				}
				}
			}
			printf ("\n");
		}


	return 0;

}

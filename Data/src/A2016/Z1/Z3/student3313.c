#include <stdio.h>

int main() 
{
	char bo;
	int c=0,b=0,s=0,v=0,p=0,u;
	float pr;
	printf ("Unesite vozila: ");
	do
	{
		scanf ("%c",&bo);
		if (bo=='c' || bo=='C')
			c++;
		else if (bo=='b' || bo=='B')
			b++;
		else if (bo=='s' || bo=='S')
			s++;
		else if (bo=='v' || bo=='V')
			v++;
		else if (bo=='p' || bo=='P')
			p++;
		else if (bo=='k' || bo=='K')
			break;
		else if (bo=='\n')
			continue;
		else
			printf ("Neispravan unos\n");
			
		
	}while (bo!='k');
	
	u=c+b+s+v+p;
	
	printf ("Ukupno evidentirano %i vozila.",u);
	
	if (u==0)
	{
		printf ("\nNajpopularnija boja je crna (0.00%%).");
	}
	
	else if (c>=b&&c>=s&&c>=v&&c>=p)
	{
		pr=(100*c)/(1.0*u);
		printf ("\nNajpopularnija boja je crna (%.2f%%).",pr);
	}
	else if (b>=c&&b>=s&&b>=v&&b>=p)
	{
		if (b>c)
		{
		pr=(100*b)/(1.0*u);
		printf ("\nNajpopularnija boja je bijela (%.2f%%).",pr);
		}
		else
		{
			pr=(100*c)/(1.0*u);
			printf ("\nNajpopularnija boja je crna (%.2f%%).",pr);
		}
	}
	else if (s>=c&&s>=b&&s>=v&&s>=p)
	{
		if (s>c && s>b)
		{
			pr=(100*s)/(1.0*u);
			printf ("\nNajpopularnija boja je siva (%.2f%%).",pr);
		}
		else if (s==b)
		{
			pr=(100*b)/(1.0*u);
			printf ("\nNajpopularnija boja je bijela (%.2f%%).",pr);
		}
		else if (s==c)
		{
			pr=(100*c)/(1.0*u);
			printf ("\nNajpopularnija boja je crna (%.2f%%).",pr);
		}
	}
	else if (v>=c&&v>=b&&v>=s&&v>=p)
	{
		if (v>c&&v>b&&v>s)
		{
			pr=(100*v)/(1.0*u);
			printf ("\nNajpopularnija boja je crvena (%.2f%%).",pr);
		}
		else if (v==c)
		{
			pr=(100*c)/(1.0*u);
			printf ("\nNajpopularnija boja je crna (%.2f%%).",pr);
		}
		else if (v==b)
		{
			pr=(100*b)/(1.0*u);
			printf ("\nNajpopularnija boja je bijela (%.2f%%).",pr);
		}
		else if (v==s)
		{
			pr=(100*s)/(1.0*u);
			printf ("\nNajpopularnija boja je siva (%.2f%%).",pr);
		}
		else
		{
			pr=(100*v)/(1.0*u);
			printf ("\nNajpopularnija boja je crvena (%.2f%%).",pr);
		}
	}
	else if (p>=c&&p>=b&&p>=s&&p>=v)
	{
		if (p>c&&p>b&&p>s&&p>v)
		{
			pr=(100*p)/(1.0*u);
			printf ("\nNajpopularnija boja je plava (%.2f%%).",pr);
		}
		else if (p==c)
		{
			pr=(100*c)/(1.0*u);
			printf ("\nNajpopularnija boja je crna (%.2f%%).",pr);
		}
		else if (p==b)
		{
			pr=(100*b)/(1.0*u);
			printf ("\nNajpopularnija boja je bijela (%.2f%%).",pr);
		}
		else if (p==s)
		{
			pr=(100*s)/(1.0*u);
			printf ("\nNajpopularnija boja je siva (%.2f%%).",pr);
		}
		else if (p==v)
		{
			pr=(100*v)/(1.0*u);
			printf ("\nNajpopularnija boja je crvena (%.2f%%).",pr);
		}
	}
	
	return 0;
}

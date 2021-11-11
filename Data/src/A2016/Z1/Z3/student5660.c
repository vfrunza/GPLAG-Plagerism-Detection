#include <stdio.h>

int main() 
{
	char slovo;
	int c = 0, b = 0, s = 0, v = 0, p = 0, ukupno = 0;
	printf ("Unesite vozila: ");
	do
	{
		scanf("%c", &slovo);
		if (slovo == 'c' || slovo == 'C')
		{
			c++; ukupno++;
		}
		else if (slovo == 'b' || slovo == 'B')
		{
			b++; ukupno++;
		}
		else if(slovo == 's' || slovo == 'S')
		{
			s++; ukupno++;
		}
		else if(slovo == 'v' || slovo == 'V')
		{
			v++; ukupno++;
		}
		else if(slovo == 'p' || slovo == 'P')
		{
			p++; ukupno++;
		}
		else if (slovo == 'k' || slovo == 'K')
		{
			break;
		}
		else 
		{
			printf("Neispravan unos\n");
		}
	}while(slovo != 'k' && slovo != 'K');
	printf ("Ukupno evidentirano %d vozila.\n", ukupno);

	if (ukupno == 0)
		printf ("Najpopularnija boja je crna (0.00%%).");
	else if(c > b && c > s && c > v && c > p)
		printf ("Najpopularnija boja je crna (%.2f%%).", (float)c/ukupno*100);
	else if (b > c && b > s && b > v && b > p)
		printf ("Najpopularnija boja je bijela (%.2f%%).", (float)b/ukupno*100);
	else if (s > c && s > b && s > v && s > p)
		printf ("Najpopularnija boja je siva (%.2f%%).", (float)s/ukupno*100);
	else if (v > c && v > b && v > s && c > p)
		printf ("Najpopularnija boja je crvena (%.2f%%).", (float)v/ukupno*100);
	else if (p > s && p > c && p > b && p > v)
		printf ("Najpopularnija boja je plava (%.2f%%).", (float)p/ukupno*100);
	
	else if (c == b && c > s && c > v && c > p)
		printf ("Najpopularnija boja je crna (%.2f%%).", (float)c/ukupno*100);
	else if (c == s && c > v && c > p)
		printf ("Najpopularnija boja je crna (%.2f%%).", (float)c/ukupno*100);
	else if (c == v && c > p)
		printf ("Najpopularnija boja je crna (%.2f%%).", (float)c/ukupno*100);
	else if (c == p)
		printf ("Najpopularnija boja je crna (%.2f%%).", (float)c/ukupno*100);
	
	else if (b == s && b > v && b > p)
		printf ("Najpopularnija boja je bijela (%.2f%%).", (float)b/ukupno*100);
	else if (b == v && b > p)
		printf ("Najpopularnija boja je bijela (%.2f%%).", (float)b/ukupno*100);
	else if (b == p)
		printf ("Najpopularnija boja je bijela (%.2f%%).", (float)b/ukupno*100);
		
	else if (s == v && s > p)
		printf ("Najpopularnija boja je siva (%.2f%%).", (float)s/ukupno*100);
	else if (s == p)
		printf ("Najpopularnija boja je siva (%.2f%%).", (float)s/ukupno*100);
	else if (v > p)
		printf ("Najpopularnija boja je crvena (%.2f%%).", (float)v/ukupno*100);
	else
		printf ("Najpopularnija boja je crvena (%.2f%%).", (float)p/ukupno*100);
	
	return 0;
}

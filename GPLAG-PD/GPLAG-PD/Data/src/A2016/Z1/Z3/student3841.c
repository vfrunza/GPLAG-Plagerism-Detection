#include <stdio.h>

int main() 
{
	char color;
	int b = 0, w = 0, g = 0, r = 0, a = 0, i = 0;
	double p = 0, idk = 0;
	
	printf("Unesite vozila: ");
	
	do
	{
		scanf("%c", &color);
		if (color == 'C' || color == 'c')
		{
			b++;
			idk++;
		}
		
		if(color == 'B' || color == 'b')
		{
			w++;
			idk++;
		}
		
		if(color == 'S' || color == 's')
		{
			g++;
			idk++;
		}
		
		if(color == 'V' || color == 'v')
		{
			r++;
			idk++;
		}
		
		if(color == 'P' || color == 'p')
		{
			a++;
			idk++;
		}
		
		if(color == 'K' || color == 'k')
			break;
			
		i = b + w + g + r + a;
		
		if(color != 'C' && color != 'c' && color != 'B' && color != 'b' && color != 'S' && color != 's'
		&& color != 'V' && color != 'v' && color != 'P' && color != 'p')
			printf("Neispravan unos\n");
	}
	
	while(idk <= 1000000000000);
	printf("Ukupno evidentirano %d vozila.\n", i);
	
	if (b >= w && b >= g && b >= r && b >= a)
	{
		p = (b / idk) * 100;
		
		if(b == 0)
			printf("Najpopularnija boja je crna (0.00%%).");
			
		else
			printf("Najpopularnija boja je crna (%.2f%%).", p);
			
	}
	
	else if (w >= b && w >= g && w >= r && w >= a)
	{
		p = (w / idk) * 100;
		
		if(w == 0)
			printf("Najpopularnija boja je bijela (0.00%%).");
			
		else
			printf("Najpopularnija boja je bijela (%.2f%%).", p);
	}
	
	else if (g >= b && g >= w && g >= r && g >= a)
	{
		p = (g / idk) * 100;
		
		if(g == 0)
			printf("Najpopularnija boja je siva (0.00%%).");
			
		else
			printf("Najpopularnija boja je siva (%.2f%%).", p);
	}
	
	else if (g == r && g == a)
	{
		p = (g / idk) * 100;
		printf("Najpopularnija boja je siva (%.2f%%).", p);
	}
	
	else if(r >= b && r >= w && r >= g && r >= a)
	{
		p = (r / idk) * 100;
		
		if(r == 0)
			printf("Najpopularnija boja je crvena (0.00%%).");
			
		else
		printf("Najpopularnija boja je crvena (%.2f%%).", p);
	}
	
	else if(a >= b && a >= w && a >= g && a >= r)
	{
		p = (a / idk) * 100;
		
		if(a == 0)
			printf("Najpopularnija boja je plava (0.00%%).");
			
		else
		printf("Najpopularnija boja je plava (%.2f%%).", p);
	}
	
	
	
	
	return 0;
}

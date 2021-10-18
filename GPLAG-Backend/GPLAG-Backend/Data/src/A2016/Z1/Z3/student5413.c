#include <stdio.h>

int main() 
{
	int i = 0, c = 0, b = 0, s = 0, v = 0, p = 0, max;
	char x;
	float pr;
	printf("Unesite vozila: ");
	while(1 == 1)
	{
		scanf("%c", &x);
		if(x == 'c' || x == 'C')
		  c++;
		else if(x == 'b' || x == 'B')
		  b++;
		else if(x == 's' || x == 'S')
		  s++;
		else if(x == 'v' || x == 'V')
		  v++;
		else if(x == 'p' || x == 'P')
		  p++;
		else if(x == 'k' || x == 'K')
		  break;
		else
		{
			printf("Neispravan unos\n");
		    continue;	
		}
		i++;
	}
	
	printf("Ukupno evidentirano %d vozila.\n", i);
	if(i == 0)
	{
		printf("Najpopularnija boja je crna (0.00%).");
		return 0;
	}
	max = 0;
	
	if(max < c)
	  max = c;
	if(max < b)
	  max = b;
	if(max < s)
	  max = s;
	if(max < v)
	  max = v;
	if(max < p)
	  max = p;
	
	pr = (float)max / i * 100;
	  
	if(max == c)
	  printf("Najpopularnija boja je crna (%.2f%%).", pr);
	else if(max == b)
	  printf("Najpopularnija boja je bijela (%.2f%%).", pr);
    else if(max == s)
      printf("Najpopularnija boja je siva (%.2f%%).", pr);
	else if(max == v)
	  printf("Najpopularnija boja je crvena (%.2f%%).", pr);
	else if(max == p)
	  printf("Najpopularnija boja je plava (%.2f%%).", pr);
	  
	  return 0;
}

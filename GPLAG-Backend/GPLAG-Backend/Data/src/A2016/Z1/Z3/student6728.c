#include <stdio.h>

int main() {
	char slovo;
	int c1=0,b1=0,s1=0,v1=0,p1=0,ukupno,najveci;
	float prosjek;
	
	printf("Unesite vozila: ");
	
	while(1)
	{
		
		scanf("%c", &slovo);
		
		if(slovo == 'C' || slovo == 'c')
		
		c1++;
		
		else if(slovo == 'B' || slovo == 'b')
		
		b1++;
		
		else if(slovo == 'S' || slovo == 's')
		
		s1++;
		
		else if(slovo == 'V' || slovo == 'v')
		
		v1++;
		
		else if(slovo == 'P' || slovo == 'p')
		
		p1++;
		
		else if(slovo == 'K' || slovo == 'k' )
		
		break;
		
		else if (slovo != 'c' && slovo != 'C' && slovo != 'b' && slovo != 'B' && slovo != 's' && slovo != 'S' && slovo != 'V' && slovo != 'v' && slovo !='p' && slovo != 'P' && slovo != '\n') 
	
		printf("Neispravan unos\n");

	
		
		
	}
	ukupno = c1 + b1 + s1 + v1 + p1;
	
	printf("Ukupno evidentirano %d vozila.", ukupno);
	
	if (c1 > b1 && c1 > s1 && c1 > v1 && c1 > p1)
	{
		najveci = c1;
	
			if(najveci == 0)
		{
			prosjek = 0;
			
			printf("\nNajpopularnija boja je crna (%.2f%).", prosjek);
			
			return 0;
			
		}
		prosjek = (float)(najveci*100) / ukupno;
	
		printf("\nNajpopularnija boja je crna (%.2f%).", prosjek);
	
		return 0;
	
	}
	
	else if(b1 > c1 && b1 > s1 && b1 > v1 && b1 > p1)
	{
	
		najveci = b1;
		
			if(najveci == 0)
		{
			prosjek = 0;
			
			printf("\nNajpopularnija boja je bijela (%.2f%).", prosjek);
			
			return 0;
			
		}
	
		prosjek = (float)(najveci*100) / ukupno;
	
		printf("\nNajpopularnija boja je bijela (%.2f%).", prosjek);
	
		return 0;
	}
	
	else if(s1 > c1 && s1 > b1 && s1 > v1 && s1 > p1)
	{
		
		najveci = s1;
		
		if(najveci == 0)
		{
			prosjek = 0;
			
			printf("\nNajpopularnija boja je siva (%.2f%).", prosjek);
			
			return 0;
			
		}
	
		prosjek = (float)(najveci*100) / ukupno;
	
		printf("\nNajpopularnija boja je siva (%.2f%).", prosjek);
	
		return 0;
	}
	
	else if (v1 > c1 && v1 > b1 && v1 > s1 && v1 > p1)
	{
		
		najveci = v1;
		
			if(najveci == 0)
		{
			prosjek = 0;
			
			printf("\nNajpopularnija boja je crvena(%.2f%).", prosjek);
			
			return 0;
		}
	
		prosjek = (float)(najveci*100) / ukupno;
		
		printf("\nNajpopularnija boja je crvena (%.2f%).", prosjek);
	
		return 0;
	}
	
	else if (p1 > c1 && p1 > b1 && p1 > s1 && p1 > v1)
	{
		najveci = p1;
		
			if(najveci == 0)
		{
			prosjek = 0;
			
			printf("\nNajpopularnija boja je plava (%.2f%).", prosjek);
			
			return 0;
			
		}
		
		prosjek = (float)(najveci*100) / ukupno;
		
		printf("\nNajpopularnija boja je plava (%.2f%).", prosjek);
	
		return 0;
	}
	
	else if (c1!= 0 && c1 == b1 || c1 == s1 || c1 == v1 || c1 == p1)
	{
		
		najveci = c1;
			
			if(najveci == 0)
		{
			prosjek = 0;
			
			printf("\nNajpopularnija boja je crna (%.2f%).", prosjek);
			
			return 0;
			
		}
	
		prosjek = (float)(najveci*100) / ukupno;
		
		printf("\nNajpopularnija boja je crna (%.2f%).", prosjek);
	
		return 0;
	}
	
	else if (b1 != 0 &&  b1 == s1 || b1 == v1 || b1 == p1)
	{
	
		najveci = b1;
		
			if(najveci == 0)
		{
			prosjek = 0;
			
			printf("\nNajpopularnija boja je bijela (%.2f%).", prosjek);
			
			return 0;
			
		}
	
		prosjek = (float)(najveci*100) / ukupno;
			
		printf("\nNajpopularnija boja je bijela (%.2f%).", prosjek);
	
		return 0;
	}
	
	else if (s1 != 0 && s1 == v1 || s1 == p1)
	{
		
		najveci = s1;
		
			if(najveci == 0)
		{
			prosjek = 0;
			
			printf("\nNajpopularnija boja je siva (%.2f%).", prosjek);
			
			return 0;
			
		}
	
		prosjek = (float)(najveci*100) / ukupno;
		
		printf("\nNajpopularnija boja je siva (%.2f%).", prosjek);
	
		return 0;
	}
	
	else if (v1 != 0 && v1 == p1)
	{
	
		najveci = v1;
		
			if(najveci == 0)
		{
			prosjek = 0;
			
			printf("\nNajpopularnija boja je crvena (%.2f%).", prosjek);
			
			return 0;
			
		}
	
		prosjek = (float)(najveci*100) / ukupno;
		
		printf("\nNajpopularnija boja je crvena (%.2f%).", prosjek);
	
		return 0;
	}
	
	else
	{
		najveci = p1;
		
			if(najveci == 0)
		{
			prosjek = 0;
			
			printf("\nNajpopularnija boja je plava (%.2f%).", prosjek);
			
			return 0;
			
		}
		
		prosjek = (float)(najveci*100) / ukupno;
		
		printf("\nNajpopularnija boja je plava (%.2f%).", prosjek);
	
		return 0;
	}
	return 0;
}

	
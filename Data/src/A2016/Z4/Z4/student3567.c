#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

float konvertor(char *string, char *kraj)
{
	float broj = 0, zarez = 0;
	int minus = 0, bio_zarez = 0, na = 1;
	while(string != kraj)
	{
		if(*string == '.')
		{
			bio_zarez = 1;
			string++;
			continue;
		}
		else if(*string == '-')
		{
			minus = 1;
			string++;
			continue;
		}
		if(!bio_zarez)
		{
			broj *= 10;
			broj += *string - '0';
		}
		else
		{
			zarez *= 10;
			zarez += *string -'0';
			na *= 10;
		}
		string++;
	}
	if(zarez > epsilon)
		broj += pow(zarez, -na);
	if(minus)
		broj *= -1;
	return broj;
}
char *obuhvat(char *tacke, float x1, float y1, float x2, float y2)
{
	char *setac = tacke;
	char *medja1, *medja2, *pomocni;
	float x, y;
	int zarezi = 0;
	while(*setac != '\0')
	{
		if((*setac != '.' && *setac != ',' && *setac != '-' && *setac != '(' && *setac != ')') && (*setac < '0' || *setac > '9'))
			return 0;
		else if(*setac == '.' && (*(setac-1) < '0' || *(setac-1) > '9'))
			return 0;
		if(*setac == ',')
			zarezi++;
		if(*setac == '(')
			medja1 = setac;
		else if(*setac == ')')
		{
			if(zarezi != 1)
				return 0;
			zarezi = 0;
			medja2 = setac;
			pomocni = medja1;
			while(*pomocni != ',') pomocni++;
			x = konvertor(medja1+1, pomocni);
			y = konvertor(pomocni+1, medja2);
			pomocni = medja1;
			if(x < x1 || y < y1 || x > x2 || y > y2)
			{
				if(*(medja2+1) != '\0')
					medja2++;
				medja2++;
				pomocni = medja1;
				while(*medja2 != '\0')
					*medja1++ = *medja2++;
				setac = pomocni-1;
				*medja1 = '\0';
			}
			else
			{
				if(*(medja2+1) != '\0')
					setac = medja2+1;
				else setac = medja2;
			}
		}
		setac++;
	}
	setac = tacke;
	while(*(setac+1) != '\0') setac++;
	if(*setac != ')')
        *setac = '\0';
	return tacke;
}

int main()
{
	char s[] = "(1,7),(2,5),(1,6),(3,3)";
	obuhvat(s, 3, 3, 1, 7);
	printf("'%s' ", s);
	return 0;
}

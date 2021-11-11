#include <stdio.h>
#define EPSILON 0.0001
#include <math.h>

int digit (int a)
{
	if (a >= '0' && a <= '9')
		return 1;
	return 0;
}

int format(char *string)
{
	char* s = string;
	int brojac = 0, brojac1 = 0, brojac2 = 0;
	while (*s != '\0')
	{	
		brojac = 0;
		brojac1 = 0;
		brojac2 = 0;
		if (*s == '(')		/* mora započeti sa otvorenom zagradom */
			s++;
		else return 0;
		if (*s == '-')		/* provjerava da li ispred ima minus i ide dalje, jedan minus je okej */
			s++;
		while (*s == '-')	/* provjerava da li ima još minusa i broji ih, ako ima bar još jedan - format je neispravan! */
		{
			s++;
			brojac++;
		}
		if (brojac > 0)
			return 0;
		if(!digit(*s))		/* nakon minusa ili zagrade prvo što mora doći je neki broj, u suprotnom format je neispravan*/
			return 0;		/* broj mora biti ispred tačke! */
		while(*s != ',')	/* sve dok pokazivač ne dođe do zareza, tj dok ne pređe na drugu koordinatu */
			{	
				if (*s != '.' && !digit(*s))	/* ako je *s različit od broja ili tačke format je neispravan */
					return 0;
				while(*s == '.')		/* brojanje tačaka; samo jedna je dopustiva */
				{
					brojac1++;
					s++;
				}
				while (digit(*s))	/* brojanje cifara, bar jedna mora biti*/
				{
					brojac2++;
					s++;
				}
			} 
		if (brojac2 < 1 || brojac1 > 1) 	/* ako imamo manje od jednog broja ili više od jedne tačke, format je neispravan */
			return 0;
		s++;
		brojac = 0;			/* resetiranje brojača jer sad prelazimo na iduću koordinatu, tj onu iza zareza */
		brojac1 = 0;
		brojac2 = 0;
		if (*s == '-')			/* isto kao u prethodnom slučaju za minuse */
			s++;
		while (*s == '-')
		{
			s++;
			brojac++;
		}
		if (brojac > 0)
			return 0;
		if(!digit(*s))
			return 0;
		while(*s != ')') 
		{
			if (*s != '.' && !digit(*s))
					return 0;
			while (*s == '.')
			{
				brojac1++;
				s++;
			}
			while (digit(*s))
			{
				brojac2++;
				s++;
			}
		}	
		if(brojac2 < 1 || brojac1 > 1)
			return 0;
		s++;
		if (*s == ',')				/* ako nam je pokazivač na zarezu pomjeramo ga dalje */
		{
			s++;
			if (*s == '\0')			/* ako nam je sada pokazivač na '\0' format je neispravan jer nakon zareza mora biti sljedeći uređen par! */
				return 0;
		}

	} 
	return 1;
}

int pripada (float x, float y, float x1, float y1, float x2, float y2)	/* funkcija koja provjerava da li koordinate pripadaju pravougaoniku */
{
	if ((x > x1 || fabsf(x1 - x) < EPSILON) && (x < x2 || fabsf(x2 - x) < EPSILON) && 
	( y > y1 || fabsf(y1- y) < EPSILON) && (y < y2 || fabsf(y2 - y) < EPSILON))
		return 1;
	return 0;
}

char* obuhvat (char* s, float x1, float y1, float x2, float y2)
{
	char* prva_zag = s, *iduca_zag = s, *p = s, *cifra = s;
	char* pomocni = s, *ret = s;
	int predznak, brojac = 0;
	float x, y, k;
	if (*s == '\0')
		return s;
	if (!format(s))			/* provjera da li zadovoljava format kojim koordinate moraju biti napisane */
		return 0;
	while(*p != '\0')
	{
		x = 0;
		y = 0;
		iduca_zag = prva_zag;			/* iduća zagrada je jednaka prvoj */
		iduca_zag++;					/* iduću zagradu pomjeramo za jedno mjesto da bi se iduća petlja mogla izvršiti */
		p = prva_zag;					/* stavljamo pokazivač kojim ćemo prolaziti kroz uređeni par na prvu zagradu */
		while(*iduca_zag != '(' && *iduca_zag != '\0')	/* sve dok je iduća zagrada različita od '(' pomjeramo je */
			iduca_zag++;								/* iduca_zag nam se sad nalazi na '(' idućeg uređenog para i biti će nam 
							potrebna u slučaju izbacivanja uređenog para ili prelaska na idući u slučaju ispravnosti */	
		p++;
		if(*p == '-')		/* u slučaju minusa; dobivenu koordinatu množimo sa predznakom */
		{
			predznak = -1;
			p++;
		}
		else predznak = 1;
		cifra = p;
		brojac = 0;
		k = 1;							
		while(*p != '.' && *p != ',')		/* brojimo koliko cifara brojačem */
		{
			p++;
			brojac++;
		}
		k = pow (10, brojac - 1);		
		while (cifra != p)
		{
			x += (*cifra - '0') * k;
			k = k / 10;
			cifra++;
		}
		if (*p == '.')		/* ako imamo tačku moramo dodati i brojeve iza nje */
		{
			cifra++;
			k = 10;
			while(*cifra != ',')
			{
				x += (*cifra - '0') / k;
				k *= 10;
				cifra++;
			}
		}
		p = cifra;
		x *= predznak;		/* dobili smo x koordinatu, sad nastavljamo sa istim postupkom za y */
		p++;
		if (*p == '-')
		{
			predznak = -1;
			p++;
		}
		else predznak = 1;
		k = 1;
		brojac = 0;
		cifra = p;
		while(*p != '.' && *p != ')')
		{
			p++;
			brojac++;
		}
		k = pow (10, brojac - 1);
		while(cifra != p)
		{
			y += (*cifra - '0') * k;
			k = k / 10;
			cifra++;
		}
		if (*p == '.')
		{
			k = 10;
			cifra++;
			while(*cifra != ')')
			{
				y += (*cifra - '0') / k;
				k *= 10;
				cifra++;
			}
		}
		y *= predznak;			
		if(!pripada(x, y, x1, y1, x2, y2))			/* ako ne pripada pravougaoniku izbacujemo uređen par */
		{
			pomocni = prva_zag;
			while(*iduca_zag != '\0')
				*prva_zag++ = *iduca_zag++;
			while(*prva_zag != '\0')
				*prva_zag++ = '\0';
			prva_zag = pomocni;
			s = pomocni;
		}
		else {									/* u suprotnom prelazimo na idući */
			prva_zag = iduca_zag;
		p = iduca_zag;
		}
	}
	while(*s != '\0')
		s++;
	s--;
	if(*s == ',')				
		*s = '\0';
	return ret;
}

int main() 
{

	char s[] = "(1.2,5.5)";
	char* rez = obuhvat(s, 1.2, 5.499, 1.4, 5.501);
	printf("%s", rez);
	int a = pripada(1.2, 5.5, 1.2, 5.499, 1.4, 5.501);
	printf ("\nmain : %d", a);
	
	
	if (pripada(1.2, 5.5, 1.2, 5.499, 1.4, 5.501)) printf ("jeste");
	else printf ("nije");
	return 0;
}

#include <stdio.h>

int broj_kordinata(char* s)
{
	int kordinate = 1;
	while(*s != '\0')
	{
		if((*s >= '0' && *s <= '9') || *s == '(' || *s == ')' || *s == '-' || *s == '.' || *s == ',')
		{
			if(*s == ')' && *(s+1) != '\0')
			{
				if(*(s+1) == ',' && *(s+2) == '(')
				{
					kordinate++;
				}
			}
		}
		s++;
	}
	

	return kordinate;
}

int provjera_tacaka(char *s)
{
	while(*s != '\0')
	{
		if(*s == '.')
		{
			if(*(s-1) < '0' || *(s-1) > '9')
			{
				return 0;
			}
		}
		s++;
	}
	return 1;
}

int provjera_zareza(char *s)
{
	while(*s != '\0')
	{
		if(*s == ',')
		{
			if(*(s-1) == ',' || *(s+1) == ',' || *(s-1) == '(' || *(s+1) == ')' || *(s-1) == '-')
			{
				return 0;
			}
		}
		s++;
	}
	
	
	return 1;
}

int provjera_minusa(char *s)
{
	while(*s != '\0')
	{
		if(*s == '-')
		{
			if(*(s+1) <= '0' || *(s+1) >= '9')
			{
				return 0;
			}
		}
		s++;
	}
	return 1;
}

int provjeri_format(char* s)
{
	int zagrade1 = 0, zagrade2 = 0,zarezi = 0, logika=0, razmaci=0;

	while(*s != '\0')
	{
		if((*s >= '0' && *s <= '9') || *s == '(' || *s == ')' || *s == '-' || *s == '.' || *s == ',') /* provjerava dozvoljene znakove */
		{
			if(*s == '(') /* broji koliko ima kojih znakova */
			{
				zagrade1++;
			}
			else if(*s == ')')
			{
				zagrade2++;
			}
			else if(*s == ',')
			{
				zarezi++;
			}
			
			if(*s == ')' && *(s+1) != '\0')    /* broji ),( znakove */
			{
				if(*(s+1) == ',' && *(s+2) == '(')
				{
					razmaci++;
				}
			}
		}
		else
		{
			return 0;
		}
		s++;
	}

	if(zagrade1 == zagrade2 && zarezi == zagrade1*2 - 1 && razmaci == zagrade1-1)
	{
		logika = 1;
	}
	else
	{
		logika = 0;
	}
	
	return logika;
}

char* pocetak_rijeci(int br, char* s)
{
	int brojac=0, logika=1;
	
	while(*s != '\0')
	{
		if(*s == ',' && *(s+1) == '(' && *(s-1) == ')')
		{
			logika = 1;
		}
		else if(logika == 1)
		{
			logika = 0;
			brojac++;
			if(brojac == br)
			{
				return s;
			}
		}
		s++;
	}
	return s;
}

char* kraj_rijeci(char* s)
{
	while(*s != ')')
	{
		s++;
	}
	return s;
}

int broj_znakova(char* s)
{
	int brojac = 0;
	while(*s != ')')
	{
		brojac++;
		s++;
	}
	return ++brojac;
}

char* kraj_stringa(char* s)
{
	while(*s != '\0')
	{
		s++;
	}
	return s;
}

double daj_broj(int n,int br, char* poc) /* n - redni broj kordinate, br - 1(x), 2(y), poc - string */
{
	double broj = 0;
	int dec_stepen = 1;
	int znak = 1, tacka = 0;
	
	poc = pocetak_rijeci(n, poc);
	poc++;
	
	if(br == 2)
	{
		while(*poc != ',')
		{
			poc++;
		}
		poc++;
	}

	if(*poc == '-')
	{
		znak = -1;
	}
	
	while(*poc != ',' && *poc != ')')
	{
		if(*poc == '.')
		{
			tacka = 1;
		}
		
		if(tacka == 1) /* pretvara sting u float poslije dec tacke */
		{
			if(*poc >= '0' && *poc <= '9')
			{
				broj *= dec_stepen*10;
				broj += (*poc - '0');
				
				dec_stepen *= 10;
				broj /= dec_stepen;
			}
		}
		else
		{
			if(*poc >= '0' && *poc <= '9') /* pretvara sting u float prije dec tacke */
			{
				broj *= 10;
				broj += (*poc - '0');
			}
		}
		poc++;
	}
	return broj * znak;
}

char* obuhvat(char* pom, double x1, double y1, double x2, double y2)
{
	int brojkordinata = broj_kordinata(pom);
	int i, br_znakova;
	double x_niz, y_niz;
	char *pocetak, *kraj;
	
	if(provjeri_format(pom) == 0 || provjera_tacaka(pom) == 0 || provjera_zareza(pom) == 0 || provjera_minusa(pom) == 0)
	{
		return NULL;
	}
	
	for(i = brojkordinata; i != 0; i--)
	{
		x_niz = daj_broj(i, 1, pom);
		y_niz = daj_broj(i, 2, pom);
		
		if(x_niz >= x1 && x_niz <= x2 && y_niz >= y1 && y_niz <= y2)
		{
			continue;
		}
		else
		{
			pocetak = pocetak_rijeci(i, pom);
			
			if(*(kraj_rijeci(pocetak)+1) == '\0')
			{
				if( i != 1 ) pocetak--;
				*pocetak = '\0';
			}
			else
			{
				kraj = kraj_stringa(pocetak);
				br_znakova = broj_znakova(pocetak);
			
				while(pocetak <= kraj-br_znakova)
				{
					*pocetak = *(pocetak + br_znakova+1);
					pocetak++;
				}
			}
		}
	}
	return pom;
}

int main() 
{

	return 0;
}

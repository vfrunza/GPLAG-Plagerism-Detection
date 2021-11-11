#include <stdio.h>

char* kraj_stringa(char *s)
{
	while(*s != '\0') s++;
	return s;
}

int broj_rijeci(char *s)
{
	int brojac=0;
	int logika_znak=1;
	
	while(*s != '\0')
	{
		if(!((*s >= 'A' && *s <='Z') || (*s >= 'a' && *s <='z')))
		{
			logika_znak = 1;	
		}
		else if(logika_znak == 1)
		{
			logika_znak = 0;
			brojac++;
		}
		s++;	
	}
	return brojac;
}

char* pocetak_rijeci(int br_rijeci, char* s)
{
	int brojac=0;
	int logika_znak=1;
	
	while(*s != '\0')
	{
		if(!((*s >= 'A' && *s <='Z') || (*s >= 'a' && *s <='z')))
		{
			logika_znak = 1;	
		}
		else if(logika_znak == 1)
		{
			logika_znak = 0;
			brojac++;
			if(brojac == br_rijeci)
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
	while((*s >= 'A' && *s <='Z') || (*s >= 'a' && *s <='z')) s++;
	return --s;
}

int broj_slova(char *s)
{
	int brojac=0;
	while((*s >= 'A' && *s <='Z') || (*s >= 'a' && *s <='z'))
	{ 
		brojac++;
		s++;
	}
	return brojac;
}

int poredi(char *prva, char *druga)
{
	char* kraj_prve = kraj_rijeci(prva);
	int isto=0;
	
	if(broj_slova(prva) == broj_slova(druga))
	{
		while(prva <= kraj_prve)
		{
			if(*prva == *druga || *prva + 32 == *druga || *prva == *druga + 32)
			{
				isto=1;
				prva++;
				druga++;
			}
			else
			{
				return 0;
			}
		}
	}
	return isto;
}

char *nadji_najcescu(char* s)
{
	int brojac=0, max = 0, i, j;
	char* pok = s;
	char *prva, *druga;
	int br =  broj_rijeci(s);

	for(i=1; i<= br; i++)
	{
		prva = pocetak_rijeci(i, s);
		brojac = 0;
		for(j=1; j <= br; j++)
		{
			druga = pocetak_rijeci(j, s);
			if((poredi(prva, druga) == 1))
			{
				brojac++;
			}
		}
		if(brojac > max)
		{
			pok = prva;
			max = brojac;
		}
	}
	return pok;
}

char* izbaci_najcescu(char* s)
{
	char* najcesca = nadji_najcescu(s);
	char* rijeci;
	int j, br, duzinarijeci;
	char* krajstringa, *p;
	
	krajstringa = kraj_stringa(s);
	br = broj_rijeci(s);
	
	for(j=1; j <= br; j++)
	{
		rijeci = pocetak_rijeci(j, s);
		if(rijeci == najcesca)
		{
			continue;
		}
		else if(poredi(najcesca, rijeci))
		{
			duzinarijeci = broj_slova(rijeci);
			p = rijeci;
			while(p <= krajstringa-duzinarijeci)
			{
				*p = *(p + duzinarijeci);
				p++;
			}
			j--; 
		}
	}
	
	p = najcesca;
	duzinarijeci = broj_slova(najcesca);
	
	while(p <= krajstringa-duzinarijeci)
	{
		*p = *(p + duzinarijeci);
		p++;
	}
	return s;
}
int main() 
{
	
	return 0;
}

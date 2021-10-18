#include <stdio.h>

char veliko(char c)
{
	if(c >= 'a' && c <= 'z')
		return c-('a'-'A');
	return c;
}
int provjeri(char *s)
{
	char matrica[20][20];
	int brojac = 0;
	char *upisivac=matrica[0];
	while(*s != '\0' && *s != '<') s++;
	if(*s == '\0') return 1;
	while(*s != '\0')
	{
		while(*s != '\0' && *s != '<') s++;
		if(*s == '\0') break;
		s++;
		upisivac = matrica[brojac];
		if(*s == '/')
		{
			s++;
			if(!(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z' || *s >= '0' && *s <= '9') || *s == '/') return 0;
			if(brojac-1 < 0) return 0;
			upisivac = matrica[brojac-1];
			while(*upisivac != '\0' && *s != '\0' && veliko(*upisivac) == veliko(*s))
			{
				upisivac++;
				s++;
			}
			if(*upisivac != '\0') return 0;
			brojac--;
			while(*s != '\0' && *s != '>')
			{
				if(*s == '<') return 0;
				s++;
			}
		}
		else
		{
			if(!(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z' || *s >= '0' && *s <= '9') || *s == '/') return 0;
			while(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z' || *s >= '0' && *s <= '9')
			{
				*upisivac = *s;
				upisivac++;
				s++;
			}
			*upisivac = '\0';
			brojac++;
		}
		
		if(*s == '\0') return 0;
		s++;
	}
	if(brojac != 0) return 0;
	return 1;
}
int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}

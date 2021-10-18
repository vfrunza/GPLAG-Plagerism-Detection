#include <stdio.h>

void sortiraj(char* karakteri, int* brojaci, int velBrojaca)
{
	int i,j;
	for (i = 0; i < velBrojaca; i++)
	{
		for (j = i;  j < velBrojaca; j++)
		{
			if (brojaci[i] < brojaci[j])
			{
				int temp = brojaci[i];
				brojaci[i] = brojaci[j];
				brojaci[j] = temp;
				char tmp = karakteri[i];
				karakteri[i] = karakteri[j];
				karakteri[j] = tmp;
			}
			else if (brojaci[i] == brojaci[j])
			{
				if (karakteri[i] > karakteri[j])
				{
					char tmp = karakteri[i];
					karakteri[i] = karakteri[j];
					karakteri[j] = tmp;
				}
			}
		}
	}
}

char* kodiraj (char* s1, char* s2)
{
	char pom[200];
	pom[0] = '\0';
	int brojaci[200] = {0}, i1 = 0, ip = 0, velp = 0;
	while (s1[i1] != '\0')
	{
		ip = 0; 
		int flag = 1;
		while(pom[ip] != '\0')
		{
			if (s1[i1] == pom[ip])
			{
				brojaci[ip]++;
				flag = 0;
			}
			ip++;
			if (!flag) break;
		}
		    if (flag)
		    {
		    	pom[velp] = s1[i1];
		    	brojaci[velp]++;
		    	velp++;
		    	pom[velp] = '\0';
		    }
		    i1++;
		}
		
	sortiraj (pom,brojaci,velp);
	i1 = 0;
	while (pom[i1] != '\0')
	{
		s2[i1] = pom[i1];
		i1++;
	}
	velp = i1;
	for (ip = 32; ip <= 126; ip++)
	{
		int j;
			for (j = 0; j < i1; j++)
			{
				if (s2[j] == ip)
				{
					j = -1;
					break;
				}
			}
			if (j != -1)
			{
				s2[velp] = ip;
				velp++;
			}
		}
		s2[velp] = '\0';
		
		i1 = 0;
		while (s1[i1] != '\0')
		{
			ip = 0;
			while (s1[i1] != s2[ip])
			{
				ip++;
			}
			s1[i1] = 126 - ip;
			i1++;
		}
		return s1;
	}
	
	char* dekodiraj (char*s1, char* s2)
	{
		int i1 = 0, ip = 0;
		while (s1[i1] != '\0')
		{
			ip = 126 - s1[i1];
			s1[i1] = s2[ip];
			i1++;
		}
		return s1;
	}
	
	int main ()
	{
			char tekst[] = "Ovo je neki testni tekst";
char sifrarnik[100] = "";
int i;
kodiraj(tekst, sifrarnik);
printf("%s", tekst);
for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
dekodiraj(tekst, sifrarnik);
printf("%s", tekst);

		return 0;
	}

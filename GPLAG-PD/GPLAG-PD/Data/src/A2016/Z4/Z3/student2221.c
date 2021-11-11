#include <stdio.h>

int jednakiSu(char* s1, char* s2)
{
	int i = 0, t = 1;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		t = 0;
		if (!t) return t;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		t = 0;
		if (!t) return t;
		i++;
	}
	return t;
}

void zamijeni(char* s, char* zamjena, int i)
{
	int ind = i-1;
	while (ind >= 0 && s[ind] != ' ')
	{
		ind--;
	}
	ind++;
	char m[1000];
	int j = 0, k = 0;
	
	while (s[j] != '\0')
	{
		if (j < i && j >= ind)
		{
			int h = 0;
			
			while (zamjena[h] != '\0')
			{
				m[k] = zamjena[h];
				h++;
				k++;
			}
			while (s[j] != ' ' && s[j] != '\0')
			j++;
			continue;
		}
		
		m[k] = s[j];
		k++;
		j++;
	}
	m[k] = '\0';
	j = 0;
	while(m[j] != '\0')
	{
		s[j] = m[j];
		j++;
	}
	s[j] = '\0';
}

char* zamjena_rijeci(char* tekst, char** rijeci, char**zamjene, int broj_rijeci)
{
	int i1 = 0;
	while (tekst[i1] != '\0')
	{
		char temp[50];
		int i2 = 0; 
		while (tekst[i1] != '\0' && tekst[i1] != ' ')
		{
			temp[i2] = tekst[i1];
			i2++;
			i1++;
		}
		temp[i2] = '\0';
		for (i2 = 0; i2 < broj_rijeci; i2++)
		{
			if (jednakiSu(temp,rijeci[i2]) && !jednakiSu(zamjene[i2], rijeci[i2]))
			{
				zamijeni(tekst,zamjene[i2],i1);
				i1 = 0;
				break;
			}
		}
		if(tekst[i1] == '\0') break;
		i1++;
	}
	return tekst;
}

int main()
{
char* rijeci[3] = { "proba", "Ovo", "je" };
char* zamjene[3] = { "", "", "" };
char tekst[100] = "Ovo je proba";
printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 3));

	return 0;
}

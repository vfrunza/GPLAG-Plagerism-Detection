#include <stdio.h>

int da_li_je_slovo (char  s)
{
	if ((s>='A' && s<='Z') || (s>='a' && s<='z'))
	{
		return 1;
	}
	return 0;
}

int broj_rijeci (char s[])
{
	int n=0, ne_slovo=1;
	
	while (*s != '\0')
	{
		if (!da_li_je_slovo(*s))
		{
			ne_slovo=1;
		}
		else if (ne_slovo==1)
		{
			ne_slovo=0;
			n++;
		}
		s++;
	}
	return n;
}

int provjeri_duzine (char s[], int niz[], int n)
{
	int temp=broj_rijeci(s), duzinarijeci=0, ne_slovo=1,m=0,br=0;
	if (temp!=n)
	{
		return 0;
	}
	
	while (!da_li_je_slovo(*s))
	{
		s++;
	}
	
	while (*s!='\0')
	{
		if (!da_li_je_slovo(*s))
		{
			ne_slovo=1;
			if (duzinarijeci!=niz[m]) return 0;
			if ( m == n-1)
			{
				return 1;
			}
		}
		else if (ne_slovo==1)
		{
			ne_slovo=0;
			duzinarijeci=0;
			if (br!=0) m++;
			br=1;
		}
		if (da_li_je_slovo(*s))duzinarijeci++;
		s++;
	}
	return 1;
}

int main ()
{
	return 0;
}
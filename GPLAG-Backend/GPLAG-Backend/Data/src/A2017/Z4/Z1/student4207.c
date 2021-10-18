#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int broj_cifara (int br)
{
	int n=0,predznak,br_abs=abs(br);
	if (br<0) predznak=-1;
	else predznak=1;
	while (br_abs!=0)
	{
		br_abs/=10;
		n++;
	}
	if (predznak==-1) n++;
	return n;
}

int obrni (int n)
{
	int reverse=0;
	while (n!=0)
	{
	  reverse=reverse*10;
	  reverse=reverse+n%10;
	  n=n/10;
	}
	return reverse;
}

char * ubaci_broj (char * tekst, int broj)
{
	char * ret = tekst;
	int mjesta=broj_cifara(broj)+1,cifra;
	int test=1;
	char cifra_str='\0';
	char * temp1='\0';
	char * temp2='\0';
	char * pocetakslova='\0';
	int broj_temp=abs(broj),i;
	broj_temp=obrni(broj_temp);
	int predznak;
	if (broj>0) predznak=1;
	else predznak=-1;


	while (*tekst == ' ')
	{
		tekst++;
	}

	while (*tekst != '\0')
	{
		if (*tekst==' ' && tekst!=ret && *(tekst-1)>='9')
		{

			temp1=tekst;
			temp2=tekst;

			while (*temp1!='\0')
			{
				temp1++;
			}

			temp1=temp1+mjesta;

			while (*(tekst)==' ')
            {
                tekst++;
                temp2++;
            }


			while (temp1!=tekst)
			{
				*temp1=*(temp1-mjesta);
				temp1--;
			}


			broj_temp=abs(broj);
			broj_temp=obrni(broj_temp);
			test=1;
			for (i=0; i<mjesta-1; i++)
			{
				cifra=broj_temp%10;
				broj_temp/=10;
				cifra_str=cifra+'0';
				if (predznak==-1 && test)
				{
					*temp2='-';
					test=0;
					temp2++;
				}
				*temp2=cifra_str;
				temp2++;
				if (predznak==-1 && i==mjesta-3) break;
			}
		}
		tekst++;
	}
	return ret;
}

int main ()
{
	char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
	printf("\"%s\"", ubaci_broj(s, 320));

	return 0;
}
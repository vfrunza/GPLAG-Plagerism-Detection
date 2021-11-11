#include <stdio.h>

char* pocetak_rijeci(int broj_rijeci, char* s)
{
	int brojac=0;
	int logika_znak=1;
	
	while(*s != '\0')
	{
		if(*s == ' ')
		{
			logika_znak = 1;
		}
		else if(logika_znak == 1)
		{
			logika_znak = 0;
			brojac++;
			if(brojac == broj_rijeci)
			{
				return s;
			}
		}
		s++;
	}
	return s;
}

char* kraj_stringa(char *s)
{
	while(*s != '\0') 
	{
		s++;
	}
	return s;
}

char* kraj_rijeci(char* s)
{
	while(*s != ' ' && *s != '\0')
	{
		s++;
	}
	return s--;
}

int broj_rijeci_u_tekstu(char* s)
{
	int brojac=0;
	int logika_znak=1;
	
	while(*s != '\0')
	{
		if(*s == ' ')
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

int broj_slova(char *s)
{
	int brojac=0;
	while(*s != ' ' && *s != '\0')
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
		while(prva < kraj_prve)
		{
			if(*prva == *druga)
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

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	int br_rijeci = broj_rijeci_u_tekstu(tekst);
	int i, j, razlika;
	char* rijeci_u_tekstu, *rijec_zamjena, *nova_rijec, *krajstringa, *mjenjanje;
	
	for(i=br_rijeci; i != 0; i--)
	{
		rijeci_u_tekstu = pocetak_rijeci(i, tekst);
		mjenjanje = rijeci_u_tekstu;
		
		for(j=0 ; j< broj_rijeci; j++)
		{
			rijec_zamjena = *(rijeci+j);
			
			if(poredi(rijeci_u_tekstu, rijec_zamjena))
			{
				nova_rijec = *(zamjene+j);
				razlika = broj_slova(nova_rijec) - broj_slova(rijeci_u_tekstu);
				 
				if(razlika > 0)
				{
					krajstringa = kraj_stringa(tekst);
					while(rijeci_u_tekstu < krajstringa)
					{
						*(krajstringa + razlika) = *krajstringa;
						krajstringa--;
					}
				}
				else if(razlika < 0)
				{
				 	razlika *= -1;
				  	krajstringa = kraj_stringa(tekst);
				 
				 	while(rijeci_u_tekstu <= krajstringa - razlika - broj_slova(nova_rijec))
					{
				 		*(rijeci_u_tekstu + broj_slova(nova_rijec)) = *(rijeci_u_tekstu + broj_slova(nova_rijec) + razlika);
				 		rijeci_u_tekstu++;
					}
				}
				while(*nova_rijec != '\0')
				{
					*mjenjanje = *nova_rijec;
					nova_rijec++;
					mjenjanje++;
				}
				break;
			}
		}
	}
	return tekst;
}

int main() 
{

	return 0;
}

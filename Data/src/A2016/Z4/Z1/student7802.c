#include <stdio.h>

char * izbaci_najcescu(char * s)
{
	char * p;
	char * q;
	char * n;
	char * pokazivac_na_njcescu_rijec = s;
	char rijec_koju_treba_izbaciti[100];
	char * izbacujemo;
	char * rijec;
	int brojac = 0;
	int brojacrijeci = 0, i = 0, k = 0;
	int max = 0;
	int brojac_kolko_se_slova_izbacilo = 0;
	p = s;
	while ( * s != '\0')
	{

		q = s;
		n = s;
		while ( * s != '\0')
		{

			/*Preskaćemo sve što nije slovo*/
			while (!(( * s >= 'A' && * s <= 'Z') || ( * s >= 'a' && * s <= 'z')))
			{
				s++;
				if ( * s == '\0') break;
			}
			q = s;

			/*postavljamo pokazivać na početak riječi*/
			n = q;
			brojacrijeci = 0;
			while ( * s != '\0')
			{
				/*vraća pokazivač na riječ koju provjeravamo koliko je puta ima u tekstu*/
				q = n;

				/*u prvom prolazu nema koristi ali preskaće razmake kroz svaki prolazak*/
				while (!(( * s >= 'A' && * s <= 'Z') || ( * s >= 'a' && * s <= 'z')))
				{
					s++;
					if ( * s == '\0') break;
				}
				if ( * s == '\0') break;

				/*prolazimo kroz sting tražeći riječ koja počine istim slovom kao i riječ koju gledamo koliko se puta nalazi u tekstu*/
				while ( * s != * q)
				{
					s++;
					q = n;
					if ( * s == '\0')
						break;
				}
				if ( * s == '\0') break;

				/*prvo slovo rijči isto*/
				while ( * s == * q || * s == * q - 32 || * s == * q + 32)
				{
					s++;
					q++;
					if ( * s == '\0') break;
					/*ako se završi riječ koju tražimo prekidamo ovu petlju jer riječ nije ista*/
					if (!(( * q >= 'A' && * q <= 'Z') || ( * q >= 'a' && * q <= 'z'))) break;
				}
				/*ako su i pokazivači i s i q stigli do kraja riječi onda znači da je riječ ista povećavamo brojać riječi*/
				if (!(( * s >= 'A' && * s <= 'Z') || ( * s >= 'a' && * s <= 'z')) && !(( * q >= 'A' && * q <= 'Z') || ( * q >= 'a' && * q <= 'z'))) brojacrijeci++;
			}
			/*prebacimo  pokazivač q na sljedeću riječ*/
			while ((( * q >= 'A' && * q <= 'Z') || ( * q >= 'a' && * q <= 'z'))) q++;
			s = q;
			/*ako je brojač veći od maxa to je naša riječ koju trebamo izbaciti i postavljamo pokazivač pokazivac_na_naj... na n koji pokazuje na početak te riječi gore u petlji*/
			if (brojacrijeci > max)
			{
				max = brojacrijeci;
				pokazivac_na_njcescu_rijec = n;

			}
		}
	}



	if (!(( * pokazivac_na_njcescu_rijec >= 'A' && * pokazivac_na_njcescu_rijec <= 'Z') || ( * pokazivac_na_njcescu_rijec >= 'a' && * pokazivac_na_njcescu_rijec <= 'z')));

	else
	{

		/*u niz char-ova upisujem svoju riječ koju trebam izbaciti*/
		while (( * pokazivac_na_njcescu_rijec >= 'A' && * pokazivac_na_njcescu_rijec <= 'Z') || ( * pokazivac_na_njcescu_rijec >= 'a' && * pokazivac_na_njcescu_rijec <= 'z'))
		{
			rijec_koju_treba_izbaciti[i] = * pokazivac_na_njcescu_rijec;
			i++;
			pokazivac_na_njcescu_rijec++;
		}
		rijec_koju_treba_izbaciti[i] = '\0';


		/*stavimo pokazivač na prvo slovo ovog kojeg trebamo izabaciti*/


		izbacujemo = rijec_koju_treba_izbaciti;

		/*prebrojimo kolko slova ima rijec*/

		while ( * izbacujemo != '\0')
		{
			brojac++;
			izbacujemo++;

		}
		izbacujemo = rijec_koju_treba_izbaciti;
		s = p;
		q = p;
		//printf("%s",izbacujemo);

		while (s != '\0')
		{

			i = 0;
			while (( * izbacujemo == * s || * s == ( * izbacujemo - 32) || * s == * izbacujemo + 32))
			{

				/*ne gleda prvu riječ da ne bi dobili mem grešku*/
				if (k != 0)
				{
					/*gleda samo prije početka riječi*/
					if (i == 0)
					{
						if (( * (s - 1) >= 'A' && * (s - 1) <= 'Z') || ( * (s - 1) >= 'a' && * (s - 1) <= 'z'))
						{
							break;
						}
					}
				}
				s++;
				izbacujemo++;
				i++;
				if ( * s == '\0') break;
				if ( * izbacujemo == '\0')
					break;
			}

			rijec = q;


			/*ako dođemo do kraja riječi znači da su riječi iste, izbacimo riječ i skratimo string za dužinu riječi*/
			if (!(( * s >= 'A' && * s <= 'Z') || ( * s >= 'a' && * s <= 'z')) && !(( * izbacujemo >= 'A' && * izbacujemo <= 'Z') || ( * izbacujemo >= 'a' && * izbacujemo <= 'z')))
			{

				while ( * s != '\0')
				{
					* (rijec) = * s;
					rijec++;
					s++;

				} * (s - brojac) = '\0';
			}


			s = q;
			izbacujemo = rijec_koju_treba_izbaciti;
			if ( * s == '\0') break;
			q++;
			s++;
			k++;
		}

	}
	return p;
}


void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i = 0;
	while (i < velicina - 1 && znak != '\n')
	{
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

int main()
{
	char tekst[100];

	unesi(tekst, 100);

	izbaci_najcescu(tekst);

	printf("\n%s", tekst);


	return 0;
}

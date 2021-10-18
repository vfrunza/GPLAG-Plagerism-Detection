#include <stdio.h>

void unesi (char niz[], int velicina)
{
	int i = 0;
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	while (i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

int provjeri (char* string)
{
	char pomocni [1000];
	char *kraj, *pokazivac_pomocnog;
	char* pamti = string, *pamti_pok_pomocnog = pomocni;

	pokazivac_pomocnog = pomocni;

	while (*string != '\0') {
		if(*string == '<') {
			while (*string != '>' && *string != ' ') {
				*pokazivac_pomocnog = *string;
				pokazivac_pomocnog++;
				string++;
			}
			*pokazivac_pomocnog = '>';
			pokazivac_pomocnog++;
		}
		string++;
	}

	*pokazivac_pomocnog = '\0';

	string = pamti;
	pokazivac_pomocnog = pomocni;

	while (*pokazivac_pomocnog != '\0') {

		if(*pokazivac_pomocnog == '\0') break;
		if(*pokazivac_pomocnog == '<') {

			kraj = pokazivac_pomocnog;
			kraj += 1;

			while (*kraj != '<') kraj++;

			kraj++;

			if (*kraj == '/') {
				if(*(1 + pokazivac_pomocnog) != *(1 + kraj))
					return 0;

				else if( *(1 + pokazivac_pomocnog) == *(1 + kraj)) {
					kraj++;
					pokazivac_pomocnog++;

					while ( (*pokazivac_pomocnog != '>' && *pokazivac_pomocnog != ' ') && (*kraj!= '>' && *kraj != ' ')) {
						if(*kraj != *pokazivac_pomocnog) return 0;

						pokazivac_pomocnog++;
						kraj++;
					}
					pokazivac_pomocnog--;
					while(*pokazivac_pomocnog!= '\0' && *pokazivac_pomocnog != '>') pokazivac_pomocnog--;

					pokazivac_pomocnog++;
					kraj++;


					if(*kraj == '\0') {
						pokazivac_pomocnog = pamti_pok_pomocnog;

						while(pokazivac_pomocnog != kraj) {
							*pokazivac_pomocnog = '\0';
							pokazivac_pomocnog++;
						}
					}

					while(*kraj != '\0') {
						*pokazivac_pomocnog = *kraj;
						kraj++;
						pokazivac_pomocnog++;
					}

					*pokazivac_pomocnog = '\0';
				}

				pokazivac_pomocnog = pamti_pok_pomocnog;
			}

			else if (*(++pokazivac_pomocnog) != *kraj) {
				pokazivac_pomocnog = --kraj;
			}
		}

	}

	return 1;
}

int main()
{
	char kod [1000];
	unesi (kod, 1000);

	printf("%d", provjeri(kod));

	return 0;
}

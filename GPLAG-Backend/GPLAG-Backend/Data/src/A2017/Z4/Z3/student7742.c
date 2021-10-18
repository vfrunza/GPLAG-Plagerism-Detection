#include <stdio.h>

void kopiraj_niz(char *s1, char *s2)
{
	char *pok1, *pok2;
	pok1 = s1;
	pok2 = s2;

	while(*pok1 != '\0') {
		*pok2 = *pok1;
		pok2++;
		pok1++;
	}
	*pok2='\0';
}

int prvi_veci_od_drugog(char *s1, char *s2)
{
	char *pok1, *pok2;
	pok1 = s1;
	pok2 = s2;
	int br1=0, br2=0;
	while(*pok1 != '\0') {
		br1++;
		pok1++;
	}
	while (*pok2 != '\0') {
		br2++;
		pok2++;
	}
	if(br1 > br2) return 1;

	return 0;
}

int ima_li_ga(char *string, char znak)
{
	char* pok;
	pok = string;
	while(*pok != '\0') {
		if(*pok == znak || *pok + 32 == znak || *pok - 32 == znak ) return 1;
		pok++;
	}
	return 0;
}

void najduzi_bp(char* s1, char *s2)
{
	char podniz[10000];
	char* pok;
	char* poc;
	*s2 = '\0';

	char *cuvar;
	cuvar=s1;

	char* pocetaks2;
	pocetaks2 = s2;



	pok = podniz;
	poc = podniz;
	while(*cuvar != '\0') {
		s1 = cuvar;
		while(*s1 != '\0') {
			poc = pok;
			*pok = '\0';


			while(((*s1 < 'a' || *s1 > 'z') && (*s1 < 'A' || *s1 > 'Z')) && *s1 != '\0') {

				s1++;
			}




			while(((*s1 >='a' && *s1 <= 'z') || (*s1 >= 'A' && *s1 <='Z')) && *s1 != '\0') {

				if(ima_li_ga(poc, *s1)) {
					if(prvi_veci_od_drugog(poc, pocetaks2)) kopiraj_niz(poc, pocetaks2);
					pok = poc;
					*pok = '\0';

					s1++;

				} else {

					*pok = *s1;
					pok++;
					s1++;
					*pok = '\0';
				}
			}



			if(prvi_veci_od_drugog(poc, pocetaks2)) {
				kopiraj_niz(poc, pocetaks2);
				pok = poc;
				*pok = '\0';
				s1++;

			}
		}
		cuvar++;
	}

}



int main()
{
//samo se prvi znak "uzima"
	char niz[10];
	najduzi_bp ("abcde etankera cdefg", niz);
	printf ("Niz: '%s'", niz);
	return 0;

}

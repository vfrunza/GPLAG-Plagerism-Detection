#include <stdio.h>

void unesi(char niz[], int velicina)
{

	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n')
	{
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

char* izbaci_najcescu (char *s)
{
	
	int neslovo = 1,neslovo2=1,brojac=0,max=brojac;
	char *pocetak=s;
	char *poc_max,*poc_max_rijeci=NULL, *kraj_max=NULL;
	int razlicite=0;
	/*trazim prvu rijec u stringu*/
	while (*s != '\0')
	{
		if (!(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z'))
			neslovo = 1;
		else if (neslovo == 1)
		{

			neslovo = 0;
			char *p = s, *k = s;
			poc_max=p;
			while (*k != '\0' && (*k >= 'A' && *k <= 'Z' || *k >= 'a' && *k <= 'z'))
				k++;
			char *druga = k;
			neslovo2=1;
			brojac=0;
			/*trazim drugu rijec u stringu*/
			while (*druga != '\0')
			{
				if (!(*druga >= 'A' && *druga <= 'Z' || *druga >= 'a' && *druga <= 'z'))
					neslovo2 = 1;
				else if (neslovo2 == 1)
				{

					neslovo2 = 0;
					char *p2 = druga, *k2 = druga;
					while (*k2 != 0 && (*k2 >= 'A' && *k2 <= 'Z' || *k2 >= 'a' && *k2 <= 'z'))
						k2++;
						
					char *prov_max=poc_max;
					razlicite=0;
					/*provjera jesu li jednake rijeci*/
					while (((*prov_max >= 'A' && *prov_max <= 'Z') || (*prov_max >= 'a' && *prov_max <= 'z')) && ((*p2 >= 'A' && *p2 <= 'Z') || (*p2 >= 'a' && *p2 <= 'z')))
					{
						if(*prov_max!=*p2 && *prov_max!=*p2+32 && *prov_max!=*p2-32)
						{
							razlicite=1;
							break;
						}
						prov_max++;
						p2++;
					}
					if(!(p2==k2)||!(prov_max==k))
						razlicite=1;
					if (razlicite==0)
					{
						brojac++;
					}
					if(brojac>max)
					{
						max=brojac;
						poc_max_rijeci=poc_max;
						kraj_max = k;
					}
				}
				druga++;
			}
		}
		s++;
	}
	/*ako se sve rijeci(ili jedna rijec) ponavljaju samo 
	jednom tj. sve isti broj puta izbacujem prvu po redu*/
	if(!poc_max_rijeci)
	{
		char *poc=pocetak;
		char *kraj=pocetak;
		while(*kraj!='\0' && ((*kraj >= 'A' && *kraj <= 'Z') || (*kraj >= 'a' && *kraj <= 'z')))
			kraj++;
		/*ako se u stringu nalazi samo jedna rijec*/
		if(*kraj=='\0')
			*poc=*kraj;
		/*ako se u stringu nalazi vise rijeci*/
		else
		{
			while(*poc!='\0')
			{

				if(*kraj!='\0')
				{
					*poc++=*kraj++;
				}
				else
				{
					*poc++=*kraj++;
					break;
				}

			}
		}
	}
	/*ako nema ponavljanja rijeci zavrsi funkciju
	jer smo vec gore prethodno izbacili prve rijeci
	u tom slucaju*/
	if(!poc_max_rijeci)
		return pocetak;
	if(!kraj_max)
		return pocetak;
	char *izbacivanje=kraj_max, *hodanje_kroz_max;
	while(*izbacivanje!='\0' )
	{
		hodanje_kroz_max=poc_max_rijeci;
		while(*hodanje_kroz_max!=*izbacivanje && *hodanje_kroz_max!=*izbacivanje+32 && *hodanje_kroz_max!=*izbacivanje-32 && *izbacivanje!='\0')
			izbacivanje++;
		/*ako nadjeno slovo koje nije pocetak rijeci 
		nastavi provjeravati string*/
		if(((*(izbacivanje-1)>='A' && *(izbacivanje-1)<='Z' )||(*(izbacivanje-1)>='a' && *(izbacivanje-1)<='z' ))&&(*izbacivanje!='\0'))
		{
			izbacivanje++;
			continue;
		}
		char *poc_izbaci=izbacivanje;
		while (hodanje_kroz_max !=kraj_max &&((*izbacivanje>='A' && *izbacivanje<='Z' )||(*izbacivanje>='a' && *izbacivanje<='z' )))
		{
			if(*hodanje_kroz_max==*izbacivanje || *hodanje_kroz_max==*izbacivanje+32 || *hodanje_kroz_max==*izbacivanje-32)
			{
				hodanje_kroz_max++;
				izbacivanje++;
			}
			else if(*hodanje_kroz_max!=*izbacivanje)
				break;
		}
		if(hodanje_kroz_max==kraj_max && !((*izbacivanje>='A' && *izbacivanje<='Z' )||(*izbacivanje>='a' && *izbacivanje<='z' )))
			/*onda su jednake rijeci*/
		{
			izbacivanje=poc_izbaci;
			char *poc_izbaci2=poc_izbaci;
			while(*poc_izbaci!='\0')
			{

				char *poc=poc_izbaci2;
				char *kraj=poc;
				while(*kraj!='\0' && ((*kraj >= 'A' && *kraj <= 'Z') || (*kraj >= 'a' && *kraj <= 'z')))
					kraj++;
				while(*poc!='\0')
				{

					if(*kraj!='\0')
					{
						*poc++=*kraj++;
					}
					else
					{
						*poc++=*kraj++;
						break;
					}
				}
				poc_izbaci++;
			}
		}
	}
	/*izbacujem maksimalnu rijec sa pocetka
	s kojom sam poredio sve vrijeme*/
	while(*poc_max_rijeci!='\0' )
		*poc_max_rijeci++=*kraj_max++;
	return pocetak;
}
int main()
{
	char niz[100];
	printf("Unesi neki tekst: ");
	unesi(niz,100);
	izbaci_najcescu(niz);
	printf("%s",niz);
	return 0;
}

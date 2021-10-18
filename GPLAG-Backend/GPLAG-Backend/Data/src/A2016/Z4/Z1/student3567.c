#include <stdio.h>

int iste_rijeci(char *pok1, char* pok2)
{
	char slovo1, slovo2;
	while((*pok1 >= 'A' && *pok1 <= 'Z' || *pok1 >= 'a' && *pok1 <= 'z') || (*pok2 >= 'A' && *pok2 <= 'Z' || *pok2 >= 'a' && *pok2 <= 'z'))
	{
		if(*pok1 >= 'A' && *pok1 <= 'Z' && *pok2 >= 'a' && *pok2 <= 'z')
		{
			slovo1 = *pok1;
			slovo2 = *pok2 - 32;
		}
		else if(*pok1 >= 'a' && *pok1 <= 'z' && *pok2 >= 'A' && *pok2 <= 'Z')
		{
			slovo1 = *pok1 - 32;
			slovo2 = *pok2;
		}
		else
		{
			slovo1 = *pok1;
			slovo2 = *pok2;
		}
		if(slovo1 != slovo2)
			return 0;
		pok1++;
		pok2++;
	}
	return 1;
}
int nadji_max_indeks(int *niz, int duzina)
{
	int max = 0, i;
	for(i = 0; i < duzina; i++)
		if(niz[i] > niz[max])
			max = i;
	return max;
}
char* izbaci_najcescu(char* s) {
	char rijeci[50][50];
	int histogram[50] = {0};
	int i, broj_rijeci = 0, kontrola;
	char *pocetak = s, *setac1, *setac2;
	//vadimo rijeci i spremamo u niz stringova
	while(*s != '\0')
	{
		if(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')
		{
			kontrola = 0;
			for(i = 0; i < broj_rijeci; i++)	//provjeravamo da li smo na tu rijec vec naisli i izvadili	
				if((kontrola = iste_rijeci(s, rijeci[i])))
				{
					histogram[i]++;				//ako jesmo povecamo njen brojac za 1
					while(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z') s++; //ako smo prije vec nasli tu rijec predjemo preko nje
					s--;
					break;
				}
			if(!kontrola)						//ako nismo vadimo tu rijec i onda povecamo njen brojac za 1
			{
				i = 0;
				while(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')
					rijeci[broj_rijeci][i++] = *s++;
				histogram[broj_rijeci]++;
				rijeci[broj_rijeci][i] = '\0';
				broj_rijeci++;
				s--;
			}
		}
		s++;
	}
	i = nadji_max_indeks(histogram, broj_rijeci); //nadjemo indeks rijeci koja se najvise puta ponavlja, dakle rijeci[i] ce biti rijec koja nam se najvise puta ponavlja
	s = pocetak;								  //potrebno je jos da izbacimo svako ponavljanje te rijeci
	while(*s != '\0')
	{
		if(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')	//ako je ono na sto naidjemo slovo
		{
			if(iste_rijeci(s, rijeci[i]))	//ako je ista rijec na koju smo naisli sa onom koja se najvise puta ponavlja
			{
				setac1 = s;					//pokazivac na pocetak rijeci
				setac2 = s;					//pokazivac na kraj rijeci
				while(*setac2 >= 'A' && *setac2 <= 'Z' || *setac2 >= 'a' && *setac2 <= 'z') setac2++;	//tjeramo pokazivac na kraj rijeci do kraja rijeci
				while(*setac2 != '\0')	
					*setac1++ = *setac2++;	//izbacujemo rijec tako sto ono sto je u pokazivacu na kraj rijeci pisemo u pokazivac na pocetku rijeci
				*setac1 = '\0';
				s--;
			}
			else
			{
				while(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z') s++;
				s--;
			}
		}
		s++;
	}
	return pocetak;
}
int main() {
	printf("Zadaća 4, Zadatak 1");
	return 0;
}

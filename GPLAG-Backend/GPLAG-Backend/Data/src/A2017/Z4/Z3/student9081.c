#include <stdio.h>
void najduzi_bp (char *s1, char *s2)
{
	char* pocetak;
	char* kraj;
	char* pom1;
	char* pom2;
	char* temp;
	char* temp2;
	char* cuvaj=s2;
	int brojac=0;
	int max=0;
	int cs=32;
	while (*s1!='\0') {
		/*Pomocna varijabla cs,koja nam pomaze jer program ne pravi razliku izmedju malih i velikih slova*/
		/*Ako je slovo veliko moramo ga uporediti i sa malim slovom i obrnuto*/
		if (*s1>='A' && *s1<='Z')
			cs=32;
		else if (*s1>='a' && *s1<='z')
			cs=-32;
		temp=s1;
		temp++;
		/*Pomocnom varijablom temp prolazimo do kraja stringa ili do kraja prve rijeci (a rijeci je definisana kao neprekinuti niz slova) */
		while (((*temp!=*s1 && *temp!=*s1+cs) || *temp==' ') && *temp!='\0' && ((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) && ((*temp>='A' && *temp<='Z') || (*temp>='a' && *temp<='z')))
			temp++;
		/*Ako ono na sto pokazuje temp nije slovo i ako nije jednako onom na sto pokazuje s1,to znaci da se ono na sto pokazuje s1 nijednom nije pojavilo u podstringu*/
		if (((*temp<'a' || *temp>'z') && (*temp<'A' || *temp>'Z')) || *temp=='\0' || *temp==*s1 || *temp==*s1+cs ) {
			/*Postavljamo pokazivac pocetak na s1,jer sada znamo da je ono na sta pokazuje s1 pocetak podstringa koji mozda odgovara uslovu zadatka*/
			pocetak=s1;
			/*Pokazivac kraj postavljamo na ono na sta pokazuje pokazivac temp*/
			kraj=temp;
			/*Medjutim u datom podstringu ima jos karaktera koji se eventualno mogu ponavljati,pa pomocnim brojacima pom1 i pom2 prolazimo kroz taj podstring*/
			pom1=s1;
			pom1++;
			pom2=pom1;
			pom2++;
			/*Ako se jos neki karakter ponavlja vise puta,vratimo pokazivac kraj unazad,tj.smanjujemo podstring dok ne pronadjemo podstring u kojem se nijedan karatker ne ponavlja vise od jednom*/
			while (pom1<kraj) {
				if (*pom1>='A' && *pom1<='Z')
					cs=-32;
				else if (*pom1>='a' && *pom1<='z')
					cs=32;
				while (((*pom1!=*pom2 && *pom1!=*pom2+cs) || ((*pom2<'a' || *pom2>'z') && (*pom2<'A' || *pom2>'Z'))) && *pom2!='\0' && pom2<kraj)
					pom2++;
				kraj=pom2;
				pom1++;
				pom2=pom1;
				pom2++;
			}
			/*Kada pronadjemo podstring koristimo temp2 da bismo dosli do kraja podstringa i izracunali njegovu velicinu*/
			temp2=pocetak;
			while (temp2<kraj) {
				brojac++;
				temp2++;
			}
			/*Jedino ako je velicina tog podstringa veca od prethodno upisanog,dati podstring se upisuje u drugi string*/
			if (brojac>max) {
				max=brojac;
				while (pocetak<kraj) {
					*s2=*pocetak;
					s2++;
					pocetak++;
				}
				*s2='\0';
			}
		}
		/*Koristimo pokazivac cuvaj,da vratimo s2 na pocetak drugog stringa,jer cemo mozda pronaci veci podstring*/
		brojac=0;
		s2=cuvaj;
		s1++;
	}
}
int main()
{
	return 0;
}

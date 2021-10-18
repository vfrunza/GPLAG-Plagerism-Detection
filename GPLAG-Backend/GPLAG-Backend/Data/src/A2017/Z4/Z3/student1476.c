#include <stdio.h>
int duzina_stringa (char*s){
	int d=0;
	while(*s!='\0') {
		d++;
		s++;
	}
	return d;
}

void najduzi_bp(char *s1, char *s2) {
	char *pocetak;
	char *kraj;
	char *pom1;
	char *pom2;
	char *temp;
	char *temp2;
	char *sacuvaj=s2;
	int brojac=0;
	int cs=32;
	int max=0;
	while(*s1!='\0'){
		/*pomocna varijabla cs koja nam pomaze jer program ne pravi razliku izmedju velikih i malih slova*/
		if(*s1>='A' && *s1<='Z') cs=32;
		else if(*s1>='a' && *s1<='z') cs=-32;
		temp=s1;
		temp++;
		/*Pomocnom varijablom temp prolazimo do kraja stringa ili do kraja rijeci(rijec - neprekinuti niz slova)*/
		while( ((*temp!=*s1 && *temp!=*s1+cs) || *temp==' ') && (*temp!='\0') && ((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))){
			temp++;
		}
		/*ako ono na sta pokazuje temp nije slovo i ako nije jednako onom na sto pokazuje s1, to znaci da se ono na sto pokazuje s1 nijednom nije pojavilo u podstringu*/
		if(((*temp<'a' || *temp<'z') && (*temp<'A' && *temp>'Z')) || (*temp=='\0') || (*temp=*s1) || (*temp==*s1+cs)) {
			/*Postavljamo pokazivac pocetak na s1, jer sada znamo da je ono na sta pokazuje s1 pocetak podstringa koji mozda odgovara uslovu zadatka*/
			pocetak = s1;
			kraj=temp;
			/*u datom podstringu ima jos karaktera koji se eventualno mogu ponavljati, pa pomocnim brojacima pom1 i pom2 prolazimo kroz..*/
			pom1=s1;
			pom1++;
			pom2=pom1;
			pom2++;
			/*Ako se jos neki karakter ponavlja vie puta, vratimo pokazivac kraj unazad, tj. smanjujemo podstring dok ne pronadjemo podstring u kojem..*/
			while(pom1<kraj) {
				if(*pom1>='A' && *pom1<='Z') cs=-32;
				else if(*pom1>='a' && *pom1<='z') cs=32;
				while(((*pom1!=*pom2 && *pom1!=*pom2+cs) || ((*pom2<'a' || *pom2>'z') && (*pom2<'A' || *pom2>'Z'))) && *pom2!='\0' && pom2<kraj){
					pom2++;
				}
				kraj=pom2;
				pom1++;
				pom2=pom1;
				pom2++;
			}
			/*Kada pronadjemo podstring koristimo temp2 da bismo dosli do kraja podstringa i izracunali njegovu velicinu*/
			temp2=pocetak;
			while(temp2<kraj){
				brojac++;
				temp2++;
			}
			/*Jedino ako je velicina tog podstr veca od prethodno upisanog, dati podstring se upisuje u drugi string*/
			if(brojac>max){
				max=brojac;
				while(pocetak<kraj) {
					*s2=*pocetak;
					s2++;
					pocetak++;
				}
				*s2='\0';
			}
		}
		/*koristimo pokazivac sacuvaj da vratimo s2 na pocetak drugog stringa, jer cemo mozda pronaci veci podstr*/
		brojac=0;
		s2=sacuvaj;
		s1++;
	}
}



int main() {
	char primjer[] = "Ovo je neki primjer teksta";
	char prazni[1000] = "";
	najduzi_bp(primjer, prazni);
	printf("%s", primjer);
	return 0;
}
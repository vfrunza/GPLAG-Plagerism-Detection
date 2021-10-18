#include <stdio.h>
#include <ctype.h>	//zbog funkcije tolower cija upotreba u linijama 13 i 14 omogucava da zanemarim razliku izmedju velikih i malih slova

void najduzi_bp(char *p1, char *p2)
{
	int broj=0; //broj slova trenutnog podstringa
	while(*p1!='\0') {
		if((*p1>='a' && *p1<='z') || (*p1>='A' && *p1<='Z')) {
			char *pom=p1;
			char *poc=p1;//poc cuva pocetak stringa
			int histogram[200]= {0};
			while((*pom>='a' && *pom<='z') || (*pom>='A' && *pom<='Z')) {
				if(histogram[(int)tolower(*pom)]==1) break; //prije nego sto stavim slovo u histogram provjeravam da li se to slovo vec nalazi u histogramu
				else histogram[(int)tolower(*pom)]++;	//ako slovo nije u histogramu trenutno, smijem ga staviti
				pom++;
			}
			if((pom-p1)>broj) { //oduzimanjem ova dva pokazivaca dobijam duzinu podstringa i ako je ta duzina veca od prethodne ubacujem podstring u poslati prazni string
				broj=pom-p1;
				char *novi=p2;
				while(poc<pom && *poc!='\0') { //prvi dio uslova omedjuje podstring koji treba prepisat
					*novi++=*poc++;
				}
				*novi='\0';	//rucno postavljam kraj prosljedenog drugog stringa na '\0'
			}

		}
		p1++;
	}
}




int main()
{
	char string[]="ovo je neki primjer";
	char prazni[100]= {'a'};
	najduzi_bp(string, prazni);
	printf("%s", prazni);
	return 0;
}

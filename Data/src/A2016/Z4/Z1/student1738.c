#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak = getchar();
	int i;
	if (znak == '\n') znak=getchar();
	 i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int izbroj_mi(char *s,char *rijec){
	int br = 0, case_sensative;
	char *p,*poc,*q, malo_slovo1,malo_slovo2;
	poc = s;
	while(*s != '\0') {
		if ((*s >= 'a' && *s <= 'z') || (	*s >= 'A' && *s <= 'Z' ) ){
			p = rijec;
			q = s;
			case_sensative = 1; 
				while(*p != '\0'){
						malo_slovo1 = *p;
						malo_slovo2 = *s;
						if(malo_slovo1 >= 'A' && malo_slovo1 <= 'Z')malo_slovo1 += 32;
						if(malo_slovo2 >= 'A' && malo_slovo2 <= 'Z')malo_slovo2 += 32;
						if(	malo_slovo1 != malo_slovo2)case_sensative = 0;
							s++; p++;
						if(!case_sensative)break;
				}
				if(case_sensative){
					if(	poc == q ||  
					!((*(q - 1) >= 'a' && *(q - 1) <= 'z') || (	*(q - 1) >= 'A' && *(q - 1) <= 'Z' ) )
					&&  *s == ' ' || !( (*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z' ) ) )br++;
				}
				s--;
		}
		if(*s == '\0') return br;
		s++;
	}
	return br;
}


char *izbaci_rijec(char *s,char *rijec){
			int br = 0, case_sensative;
	char *p,*poc,*q,*pocetak, malo_slovo1,malo_slovo2;
	poc = s;
	while(*s != '\0') {
		if ((*s >= 'a' && *s <= 'z') || (	*s >= 'A' && *s <= 'Z' ) ){
			p = rijec;
			q = s;
			pocetak = s;
			case_sensative = 1; 
				while(*p != '\0'){
						malo_slovo1 = *s;
						malo_slovo2 = *p;
						if(malo_slovo1 >= 'A' && malo_slovo1 <= 'Z')malo_slovo1 += 32;
						if(malo_slovo2 >= 'A' && malo_slovo2 <= 'Z')malo_slovo2 += 32;
						if(	malo_slovo1 != malo_slovo2)case_sensative = 0;
						s++; p++;
						if(!case_sensative)break;
				}
				if(case_sensative){
					if(	poc == q ||  
					!((*(q - 1) >= 'a' && *(q - 1) <= 'z') || (	*(q - 1) >= 'A' && *(q - 1) <= 'Z' ) )
					&&  *s == ' ' || !((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z' ) ) ){
						p = pocetak;
						while(*s != '\0')*pocetak++ = *s++;
						*pocetak = '\0';
						s = p;
						s--;
					}
				}
		}
		s++;
	}
	return poc;
}

char *izbaci_najcescu(char *s){
	char *vrati = s, *p, *q, niz1[100] = "", niz2[100] = "";
	int trenutni_broj_ponavljanja, duzina = 0;
	while(*s != '\0'){
		if ((*s >= 'a' && *s <= 'z') || (	*s >= 'A' && *s <= 'Z' ) ){
			p = niz1;
			while((*s >= 'a' && *s <= 'z') || (	*s >= 'A' && *s <= 'Z' ) )*p++ = *s++;		*p = '\0';
			/*saljemo u fju da izbrojimo koliko se puta ponavlja niz1*/
			trenutni_broj_ponavljanja = izbroj_mi(vrati, niz1);
			if(trenutni_broj_ponavljanja > duzina){
				/*u niz2 cemo sacuvati rijec koja se najvise ponavlja*/
				/*uzeli smo cinjenicu da u nasem jeziku ne postoji rijec veca od 20 slova*/
				duzina = trenutni_broj_ponavljanja;
				p = niz1;
				q = niz2;
				while(*p != '\0'){
					*q = *p;
					p++; q++;
				}
				*q = '\0'; /*moramo rucno dodati,jer ne kopira petlja */
			}
			s--;
		}
		s++;
	}
	/*sad cemo samo pozvati funkciju koja ce izbaciti rijec koja se ponavlja */
	vrati = izbaci_rijec(vrati,niz2);
	return vrati;
}

int main()
{
printf("Hello world");
	return 0;
}

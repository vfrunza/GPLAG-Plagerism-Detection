#include <stdio.h>


int ekvivalentno(char a, char b)
{

	if(a >= 'A' && a<= 'Z')
		a += 'a' - 'A';
	if(b >= 'A' && b<= 'Z')
		b += 'a' - 'A';

	if( a == b)
		return 1;
	return 0;
}

/* Prvo nadjemo broj rijeci, i onda postavimo for petlju od 0 do broja rijeci, posle vidimo koji brojac
je najveci*/
char *izbaci_najcescu(char *s)
{
	int duzina[100]= {0}, brojac[100]= {0}, i, j, br_rijeci=1, max, najcesca, duzina2, rijec=0;
	char *pocetak;
	char *kraj;
	char *reset=s;
// Preskacemo sve do pocetka prve rijeci
	while((*s<'A' || (*s>'Z' && *s<'a') || *s>'z') && *s!='\0')
		s++;
//Trazimo broj rijeci
	while(*s!='\0') {
		if((*s<'A' || (*s>'Z' && *s<'a') || *s>'z') && ((*(s+1)>='A' && *(s+1)<='Z') || (*(s+1)>='a' && *(s+1)<='z')))
			br_rijeci++;
		s++;
	}

	s=reset;

//Preskacemo razmake na pocetku
	while((*s<'A' || *s>'z') && *s!='\0')
		s++;
	pocetak=s;
	for(j=0; j<br_rijeci; j++) {
		while(*s!='\0' && (*s<'A' || *s>'z')) {
			s++;
		}
		pocetak=s;
		while(*s!='\0' && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))  {
			duzina[j]++;
			s++;
		}
		kraj=s-1;
		while(*s!='\0') {
			if(ekvivalentno(*s, *pocetak)) {
				for(i=0; i<duzina[j]; i++) {
					if(!(ekvivalentno(*(pocetak + i), *s)) || *(s+1)=='\0')
						break;
					s++;
				}
				if(i==duzina[j]) {
					brojac[j]++;
				}


			}
			s++;
		}
		s=kraj;
		s++;
	}

	max=brojac[0];
	najcesca=0;
	duzina2=duzina[0];
	for(i=1; i<br_rijeci; i++) {
		if(brojac[i]>max) {
			max=brojac[i];
			najcesca=i;
			duzina2=duzina[i];
		}
	}
	s=reset;
	while((*s<'A' || (*s>'Z' && *s<'a') || *s>'z') && *s!='\0')
		s++;
//izbacivanje rijeci
	while(*s!='\0') {
		if((*s<'A' || *s>'z') && (*(s+1)>='A' && *(s+1)<='z')) {
			rijec++;
			s++;
		}
		pocetak=s;
		if(rijec==najcesca) {
			pocetak=s;
			s++;
			while(*s!='\0') {
				if(!(ekvivalentno(*s, *(pocetak))) && *s!='\0') {
					s++;
					continue;
				}
				for(i=0; i<duzina2; i++) {
					if(!(ekvivalentno(*s, *(pocetak + i))) || *s=='\0')
						break;
					s++;
				}
//Postavljamo uslov kako ne bismo izbacili deo rijeci u kojoj je sadrzana nasa rijec, vec se izbacuje samo cijela rijec
				if(i==duzina2 && (*s<'A' || (*s>'Z' && *s<'a') || *s>'z') && (*(s-duzina2-1)<'A' || (*(s-duzina2-1)>'Z' && *(s-duzina2-1)<'a') || *(s-duzina2-1)>'z')) {
					s=s-duzina2;

					while(*(s+duzina2-1)!='\0') {
						*s=*(s+duzina2);
						s++;
					}
					*s='\0';
					s=pocetak;
				}
				s++;
			}
			s=pocetak;
			while(*(s+duzina2-1)!='\0') {
				*s=*(s+duzina2);
				s++;
			}
			*s='\0';
			s=reset;
			return s;
		}
		s++;
	}
	*s='\0';
	s=reset;
	return s;
}

int main()
{

	return 0;
}

#include <stdio.h>
#include <math.h>

struct Datum {
	int dan;
	int mjesec;
	int godina;

};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int dva_prezimena(char* s){
	
	int dva_prez=0;
	
	while(*s!=' '){
		if(*s=='-') dva_prez=1;
		s--;
	}
	
	return dva_prez;
	
}

int prestupna(int godina)
{
	if( (godina%4==0 && godina%100!=0) || godina%400==0)
		return 1;
	return 0;
}



int funkcija(struct Datum d1)
{

	int br_dana=0;

	int i=0;

	int dan1,mj1,god1;


	int dani_u_mj[15]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

	dan1=d1.dan;
	mj1=d1.mjesec;
	god1=d1.godina;


	for(i=1; i<god1; i++) {
		br_dana+=(365+prestupna(i));
	}

	if(prestupna(god1)) dani_u_mj[2]++;

	for(i=1; i<mj1; i++) {
		br_dana+=dani_u_mj[i];
	}

	br_dana=dan1+br_dana;

	return br_dana;  /*Broja dana proteklih od 1.1.1 pa sve do datum d1*/

}


int isto_prezime(char* s1, char* s2)
{

	
	char* p=s1;
	char* q=s2;

	while( *s1!=' ' || *s2!=' ') {

		if(*s1!=*s2 && !dva_prezimena(p) &&!dva_prezimena(q)) {
			return 0;			/*Poredimo prezime direktora i kandidata*/
		}
		
		else if (*s1!=*s2 && dva_prezimena(p) && !dva_prezimena(q)) {
			
			s2=q;
			s1=p;
			while(*s1!='-') s1--;
			s1--;
			
			while(*s1!=' ' && *s2!=' '){
				if(*s1!=*s2) return 0;
				s1--;
				s2--;
			}
		}
		
		else if (*s1!=*s2 && !dva_prezimena(p) && dva_prezimena(q)) {
			
			s1=p;
			s2=q;
			while(*s2!='-') s2--;
			s2--;
			
			while(*s1!=' ' && *s2!=' '){
				if(*s1!=*s2) return 0;
				s1--;
				s2--;
			}
		}
		
		else if (*s1!=*s2 && dva_prezimena(p) && dva_prezimena(q)) {
			
			s1=p;
			s2=q;
			while(*s2!='-') s2--;
			s2--;
			
			while(*s1!='-' && *s2!=' '){
				if(*s1!=*s2){
					s2=q;
					s1=p;
					while(*s1!='-') s1--;
					s1--;
					while(*s1!=' ' && *s2!='-'){
						if(*s1!=*s2){
							s1=p;
							s2=q;
							while(*s1!='-') s1--;
							s1--;
							while(*s2!='-') s2--;
							s2--;
							
							while(*s1!=' ' && *s2!=' '){
								if(*s1!=*s2) return 0;
								s1--;
								s2--;
							}
							
						}
					}
					s1--;
					s2--;
				}
				
				
		s1--;
		s2--;
	}
		}
		s1--;
		s2--;
}
	return 1;

}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{

	int i,j;
	int broj_dana_1=fabs(broj_dana);

	for(i=0; i<vel; i++) {
		char* p=direktor.ime_prezime;
		while(*p!='\0') p++;
		p--;

		char* q=kandidati[i].ime_prezime;
		while(*q!='\0') q++;
		q--;

		int rodjak = isto_prezime(p,q);  /* Da li direktor i kandidat imaju isto prezime? */


		int a = funkcija(kandidati[i].datum_rodjenja);
		int b = funkcija(direktor.datum_rodjenja);
		int razlika=b-a; 	/*Za koliko je dana kandidat stariji od direktora*/

		if(razlika>broj_dana_1 && !rodjak) { /*Ne smijemo izbaciti rodjake :)*/
			for(j=i; j<vel-1; j++)
				kandidati[j]=kandidati[j+1];
			vel--;
			i--;
		}
	}

	return vel;
}

int main()
{
	
	char s[50]="Pero Peric";
	char* p=s;
	while(*p) p++;
	p--;
	printf("%d", dva_prezimena(p));
	
	

	return 0;
}
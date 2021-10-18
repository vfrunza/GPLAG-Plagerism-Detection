#include <stdio.h>
#include <string.h>
struct Datum {
	int dan, mjesec, godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
/*Funckija koja provjerava da li je godina prestupna, vraca 1 ako jest, 0 ako nije*/
int prestupna(int god)
{
	if(god%400==0) return 1;
	if(god%4==0 && god%100!=0) return 1;
	else return 0;
}
/*Funkcija koja racuna koliko dana je prozivio neko do 2018. godine*/
/*Bitne su razlike među prozivljenim danima, tako da je sasvim OK proracunati broj dana zivota do recimo 2018. godine*/
int broj_dana_zivota(struct Uposlenik d)
{
	int n=0;
	int br=0,proteklo=0;
	int dani_u_mjesecu[12]= {31,28,31,30,31,30,31,31,30,31,30,31}; /*Niz u kojem su uneseni brojevi dana u mjesecu kada godina nije prestupna*/
	/*Petlja koja prolazi kroz sve godine zivota do 2018. godine, i broji koliko je neko prozivio prestupnih godina*/
	for(n=d.datum_rodjenja.godina+1; n<2018; n++)
		if(prestupna(n)) br++; /*Brojac se uvecava ako je godina prestupna, time dodajemo toliko dana zivota na ukupne dane*/
	proteklo=365*(2017-d.datum_rodjenja.godina)+br; /*Broj dana zivota (za sada), nisu uracunati prozivljeni dani u godini rodjenja*/
	/*Dodajemo i dane prozivljene u godini rodjenja*/
	for(n=d.datum_rodjenja.mjesec+1; n<=12; n++) proteklo+=dani_u_mjesecu[n-1];
	proteklo+=(dani_u_mjesecu[d.datum_rodjenja.mjesec-1]-d.datum_rodjenja.dan);
	if(prestupna(d.datum_rodjenja.godina)==1 && d.datum_rodjenja.mjesec<3) proteklo++; /*Ako je godina rodjenja prestupna, a datum rodjenja je stariji od 29. februara, dodaje se jos jedan dan*/
	return proteklo;
}
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int m=0,z=0,l=0,v=0,T=1,i=0,tacno=1,j=0,razmaci=0,t=0,k=0,br_dir=1,br_kand=1;
	char prezime_kandidata[50]= {'b','\0'},prezime_kandidata1[50]= {'b','\0'},prezime_kandidata2[50]= {'b','\0'},prezime_direktora[50]= {'a','\0'},prezime_direktora1[50]= {'a','\0'},prezime_direktora2[50]= {'a','\0'};
	char prezime[50]= {'a','\0'};
	char znak[10]="-";
	char *a=prezime;
	char *c=a;
	char *b=a;
	/*Trazimo prezime direktora*/
	if(strstr(direktor.ime_prezime,znak)!=NULL) { /*Ako u ime_prezime direktora postoji znak "-", direktor ima dva prezimena*/
		for(i=0; i<50; i++)
			/*Pomjeramo kursor do prezimena tako sto stati kada dođemo do razmaka, i pomjeriti ga za jos jedno mjesto*/
			if(direktor.ime_prezime[i]==' ') {
				i++;
				break;
			}
		/* Zapisujemo prezime, sve dok petljom ne dodjemo do NULL karaktera-kraj stringa*/
		while(direktor.ime_prezime[i]!='\0') {
			prezime[j]=direktor.ime_prezime[i];
			i++;
			j++;
		}
		prezime[j]='\0';
		j=0;
	} else {
		/* Slucaj kada direktor nema dva prezimena, onda moguce da ima dva imena pa to ispitujemo*/
		/*Brojimo broj razmaka, time cemo znati da li ima dva imena*/
		for(i=0; i<50; i++) {
			if(direktor.ime_prezime[i]==' ') razmaci++;
			if(direktor.ime_prezime[i]=='\0') break;
		}
		/*Ako smo izbrojali 2 razmaka, znaci da direktor ima dva imena,ali jedno prezime*/
		if(razmaci==2) {
			/*Petljom "preskacemo" ime i sve razmake, te dolazimo do prezimena*/
			for(i=0; i<50; i++) {
				if(direktor.ime_prezime[i]==' ' && tacno==1) tacno=0;
				if(direktor.ime_prezime[i]==' ' && tacno==0) {
					i++;
					k=i;
					/*Biljezimo prezime dok petljom ne dodjemo do NULL karaktera*/
					while(direktor.ime_prezime[k]!='\0') {
						prezime[t]=direktor.ime_prezime[k];
						t++;
						k++;
					}
					prezime[t]='\0';
					t=0;
					i=k;
				}
				if(direktor.ime_prezime[i]=='\0') break;
			}
			/*Slucaj kada direktor ima jedno ime i jedno prezime*/
		} else if(razmaci==1) {
			/*Petljom "preskacemo" ime i razmak, te dolazimo do prezimena*/
			for(i=0; i<50; i++) {
				if(direktor.ime_prezime[i]==' ') {
					i++;
					k=i;
					t=0;
					/*Biljezimo prezime dok ne dodjemo do NULL karaktera*/
					while(direktor.ime_prezime[k]!='\0') {
						prezime[t]=direktor.ime_prezime[k];
						t++;
						k++;
					}
					prezime[t]='\0';
					i=k;
					t=0;
				}
				if(direktor.ime_prezime[i]=='\0') break;
			}
		}
	}
	j=0;
	razmaci=0;
	while(prezime[j]!='\0') j++;
	k=0;
	/* Prezime "unosimo" u pokazivac*/
	while(k<(j+1)) {
		a=&prezime[k];
		a++;
		k++;
	}
	while(*c!='\0') {
		prezime_direktora[m]=*c;
		m++;
		c++;
	}
	prezime_direktora[m]='\0';
	for(l=0; l<m; l++) c--;
	m=0;
	i=0;
	j=0;
	/*Ukoliko direktor ima dva prezimena, koristimo dva stringa*/
	if(strstr(prezime_direktora,znak)!=NULL) {
		br_dir=2;
		while(prezime_direktora[i]!='-') {
			prezime_direktora1[i]=prezime_direktora[i];
			i++;
		}
		prezime_direktora1[i]='\0';
		i++;
		j=0;
		while(prezime_direktora[i]!='\0') {
			prezime_direktora2[j]=prezime_direktora[i];
			i++;
			j++;
		}
		prezime_direktora2[j]='\0';
		i=0;
		j=0;
	}
	/*Prolazimo kroz petlju gdje cemo poredit prezimena kandidata i direktora te izbacivati kandidate*/
	for(z=0; z<vel; z++) {
		tacno=1;
		/*Kao za direktora, sada trazimo prezime za kandidata*/
		if(strstr(kandidati[z].ime_prezime,znak)!=NULL) {
			for(i=0; i<50; i++)
				if(kandidati[z].ime_prezime[i]==' ') {
					i++;
					break;
				}
			j=0;
			while(kandidati[z].ime_prezime[i]!='\0') {
				prezime[j]=kandidati[z].ime_prezime[i];
				i++;
				j++;
			}
			prezime[j]='\0';
			j=0;
		} else {
			for(i=0; i<50; i++) {
				if(kandidati[z].ime_prezime[i]==' ') razmaci++;
				if(kandidati[z].ime_prezime[i]=='\0') break;
			}
			if(razmaci==2) {
				for(i=0; i<50; i++) {
					if(kandidati[z].ime_prezime[i]==' ' && tacno==1) tacno=0;
					if(kandidati[z].ime_prezime[i]==' ' && tacno==0) {
						i++;
						k=i;
						while(kandidati[z].ime_prezime[k]!='\0') {
							prezime[t]=kandidati[z].ime_prezime[k];
							t++;
							k++;
						}
						prezime[t]='\0';
						t=0;
						i=k;
					}
					if(kandidati[z].ime_prezime[i]=='\0') break;
				}
			} else if(razmaci==1) {
				for(i=0; i<50; i++) {
					if(kandidati[z].ime_prezime[i]==' ') {
						i++;
						k=i;
						t=0;
						while(kandidati[z].ime_prezime[k]!='\0') {
							prezime[t]=kandidati[z].ime_prezime[k];
							t++;
							k++;
						}
						prezime[t]='\0';
						i=k;
						t=0;
					}
					if(kandidati[z].ime_prezime[i]=='\0') break;
				}
			}
		}
		j=0;
		razmaci=0;
		while(prezime[j]!='\0') j++;
		k=0;
		while(k<(j+1)) {
			a=&prezime[k];
			a++;
			k++;
		}
		while(*b!='\0') {
			prezime_kandidata[m]=*b;
			m++;
			b++;
		}
		prezime_kandidata[m]='\0';
		for(l=0; l<m; l++) b--;
		m=0;
		T=1;
		v=0;
		i=0;
		j=0;
		br_kand=1;
		/*Kao za direktora, ukoliko kandidat ima dva prezimena, razdvajamo ih u dva stringa*/
		if(strstr(prezime_kandidata,znak)!=NULL) {
			br_kand=2;
			while(prezime_kandidata[i]!='-') {
				prezime_kandidata1[i]=prezime_kandidata[i];
				i++;
			}
			prezime_kandidata1[i]='\0';
			i++;
			j=0;
			while(prezime_kandidata[i]!='\0') {
				prezime_kandidata2[j]=prezime_kandidata[i];
				i++;
				j++;
			}
			prezime_kandidata2[j]='\0';
			i=0;
			j=0;
		}
		tacno=0;
		/*br_dir - broj prezimena direktora ; br_kand - broj prezimena kandidata, koje smo prethodno brojali*/
		/*Uporedjujemo karaktere odgovarajucih prezimena, ako se poklapaju vracamo tacno=1, u suprotnom tacno=0*/
		if(br_dir==1 && br_kand==1) {
			while(prezime_direktora[v]!='\0' && prezime_kandidata[v]!='0') {
				if(prezime_direktora[v]!=prezime_kandidata[v]) { /*Ukoliko se neki karakteri ne podudaraju odmah znamo da se ni prezimena ne podudaraju*/
					T=0;
					break;
				}
				v++;
			}
			if(prezime_direktora[v]!='\0' || prezime_kandidata[v]!='\0') T=0; /*Ukoliko su se svi karakteri poklapali, da bi se i prezimena poklapala, moraju se oba zavrist u petlju, tj. da smo dosli petljom do NULL karaktera u oba prezimena*/
			v=0;
			if(T) tacno=1;
			else tacno=0;
		} else if(br_dir==2 && br_kand==1) {
			while(prezime_direktora1[v]!='\0' && prezime_kandidata[v]!='\0') {
				if(prezime_direktora1[v]!=prezime_kandidata[v]) {
					T=0;
					break;
				}
				v++;
			}
			if(prezime_direktora1[v]!='\0' || prezime_kandidata[v]!='\0') T=0;
			v=0;
			if(T) tacno=1;
			T=1;
			while(prezime_direktora2[v]!='\0' && prezime_kandidata[v]!='\0') {
				if(prezime_direktora2[v]!=prezime_kandidata[v]) {
					T=0;
					break;
				}
				v++;
			}
			if(prezime_direktora2[v]!='\0' || prezime_kandidata[v]!='\0') T=0;
			v=0;
			if(T) tacno=1;

		} else if(br_dir==1 && br_kand==2) {
			while(prezime_direktora[v]!='\0' && prezime_kandidata1[v]!='\0') {
				if(prezime_direktora[v]!=prezime_kandidata1[v]) {
					T=0;
					break;
				}
				v++;
			}
			if(prezime_direktora[v]!='\0' || prezime_kandidata1[v]!='\0') T=0;
			v=0;
			if(T) tacno=1;
			T=1;
			while(prezime_direktora[v]!='\0' && prezime_kandidata2[v]!='\0') {
				if(prezime_direktora[v]!=prezime_kandidata2[v]) {
					T=0;
					break;
				}
				v++;
			}
			if(prezime_direktora[v]!='\0' || prezime_kandidata2[v]!='\0') T=0;
			v=0;
			if(T) tacno=1;
		} else if(br_dir==2 && br_kand==2) {
			while(prezime_direktora1[v]!='\0' && prezime_kandidata1[v]!='\0') {
				if(prezime_direktora1[v]!=prezime_kandidata1[v]) {
					T=0;
					break;
				}
				v++;
			}
			if(prezime_direktora1[v]!='\0' || prezime_kandidata1[v]!='\0') T=0;
			v=0;
			if(T) tacno=1;
			T=1;
			while(prezime_direktora2[v]!='\0' && prezime_kandidata1[v]!='\0') {
				if(prezime_direktora2[v]!=prezime_kandidata1[v]) {
					T=0;
					break;
				}
				v++;
			}
			if(prezime_direktora2[v]!='\0' || prezime_kandidata1[v]!='\0') T=0;
			v=0;
			if(T) tacno=1;
			T=1;
			while(prezime_direktora1[v]!='\0' && prezime_kandidata2[v]!='\0') {
				if(prezime_direktora1[v]!=prezime_kandidata2[v]) {
					T=0;
					break;
				}
				v++;
			}
			if(prezime_direktora1[v]!='\0' || prezime_kandidata2[v]!='\0') T=0;
			v=0;
			if(T) tacno=1;
			T=1;
			while(prezime_direktora2[v]!='\0' && prezime_kandidata2[v]!='\0') {
				if(prezime_direktora2[v]!=prezime_kandidata2[v]) {
					T=0;
					break;
				}
				v++;
			}
			if(prezime_direktora2[v]!='\0' || prezime_kandidata2[v]!='\0') T=0;
			v=0;
			if(T) tacno=1;
		}
		/*Ako se prezimena podudaraju, kandidata ne izbacujemo, koristimo naredbu continue, tako da ne prolazi ostatak koda u kojem se izbacuje dogovarajuci kandidat*/
		if(tacno) {
			continue;
		} else {
			if(broj_dana==0) return vel;
			/*Uporedjujemo dane zivota direktora i kandidata*/
			else if((broj_dana_zivota(kandidati[z])-broj_dana_zivota(direktor))>broj_dana) {
				/*Izbacivanje kandidata iz niza/liste*/
				for(v=z; v<vel-1; v++)
					kandidati[v]=kandidati[v+1];
				z--; /*Vracamo brojac da bi ispitali slucaj kandidata koji je dosao na mjesto izbacenog*/
				vel--; /*Smanjujemo velicinu liste*/
			}
		}
	}
	return vel;
}
int main()
{
	/* AT11: Varijante sa dva prezimena (samo direktor) */
	struct Uposlenik direktor = {"Mujo Mujic-Peric", {3, 3, 1992} };
	struct Uposlenik kandidati[7] = {
		{ "Meho Mehic", { 31, 1, 1990 } },
		{ "Pero Peric", { 1, 2, 1990 } },
		{ "Sara Sarac", { 2, 2, 1990 } },
		{ "Fata Mujic", { 1, 2, 1986 } },
		{ "Jozo Jozic", { 1, 10, 1990 } },
		{ "Mijo Mijic", { 4, 3, 1989 } },
		{ "Suljo Suljic", { 31, 12, 1991 } },
	};

	int novi_br = suzi_listu(kandidati, 9, direktor, 3);
	int i;
	printf("Nakon suzenja liste:\n");
	for (i=0; i<novi_br; i++)
		printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}
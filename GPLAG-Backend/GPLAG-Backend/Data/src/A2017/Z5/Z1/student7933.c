#include <stdio.h>

typedef struct Datum { 
	int dan, mjesec, godina;
} Datum;

typedef struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
} Uposlenik;

//Provjeri jel' godina prestupna
int Prestupna(int godina){
	//Djeljiva sa 4
	if (godina % 4 == 0)
		//i sa 100
        if (godina % 100 == 0)
        	//onda mora i 400
            if (godina % 400 == 0)
                return 1;
            else //Ako ne, nije prestupna
                return 0;
        else //Samo djeljiva s 4, ne sa 100
            return 1;
    
    return 0;
}

//Razlika medju datumima
int DateDifference(Datum d1, Datum d2){
	int dana_u_mjesecu[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int dUm = 0, dani1, dani2, godina = 0;
	int i = 0;
	
	//Prebroj koliko dana ima u d1
	for(i = 0; i < d1.mjesec-1; i++)
		dUm += dana_u_mjesecu[i];
	
	for(i = 1; i < d1.godina; i++)
		godina += 365 + Prestupna(i);
	
	dani1 = godina + dUm + d1.dan;
	if(d1.mjesec > 2)
		dani1 += Prestupna(d1.godina);
		
	
	//Prebroj koliko dana ima u d2
	dUm = godina = 0;
	for(i = 0; i < d2.mjesec-1; i++)
		dUm += dana_u_mjesecu[i];
	
	for(i = 1; i < d2.godina; i++)
		godina += 365 + Prestupna(i);
	
	dani2 = godina + dUm + d2.dan;
	if(d2.mjesec > 2)
		dani2 += Prestupna(d2.godina);
	

	
	//dani1 i dani2 predstavlja broj dana koji je prosao od 0 do datuma rodjenja osobe
	//dani1 je u ovom slucaju direktor
	//ako je dUm pozitivan, stariji kandidat od direktora, direktor rodjen kasnije
	dUm = dani1 - dani2;
	
	return dUm;
}

//Kopirano iz zadatka 4 tutorijal 12
int strCmp(char *s1, char *s2){
	char *s,*p;
	s = s1;
	p = s2;
	
	while(*s != '\0' && *p != '\0' && *s == *p){
		s++;
		p++;
	}
	
	if(*s != '\0' || *p != '\0') return 0;
	
	return 1;
}

//Provjeri prezimena da bi saznali jel' osoba u rodu s Direktorom
int Rod(char *ime_prezime1, char *prezime_dir1, char *prezime_dir2){
	char *s1 = ime_prezime1;
	char *p1, *p2, *pd1, *pd2;
	
	//Prezimena
	p1 = s1;
	//Pretpostavimo da nema drugo prezime
	p2 = NULL;
	pd1 = prezime_dir1;
	//Ako direktro nema drugo prezime, prezime_dir2 ce biti prosljedjeno kao null karakter
	pd2 = prezime_dir2;
	
	//Nadji prezimena osobe
	while(*s1 != '\0') {
		//Prvo prezime
		if((*s1 >= 'a' && *s1 <= 'z') || (*s1 >= 'A' && *s1 <= 'Z'))
			p1 = s1;
		
		//Prodji kroz ime ili prezime
		while((*s1 >= 'a' && *s1 <= 'z') || (*s1 >= 'A' && *s1 <= 'Z')){
			s1++;
		}
		
		if(*s1 == '\0') break;
		
		//Ako ima crtica, p11 je vec prvo prezime, a nakon '-' je drugo prezime
		if(*s1 == '-') {
			p2 = s1+1;
			*s1 = '\0';
			break;
		}
		
		s1++;
	}
	
	//Uporedi prvo direktorovo sa prvim osobe, ako 
	//se ne poklapa vidi ima li uposlenik drugo prezime pa ga uporedi
	//sa direktorovim, pa ako se bar jedno poklapa, return 1
	if(strCmp(pd1, p1) || (p2 != NULL && strCmp(pd1, p2))) {
		if(p2)
			*(p2-1) = '-'; //Vrati karakter nakon poredjenja
		return 1;
	}
	
	
	//Ako postoji, uporedi drugo direktorovo sa prvim osobe, ako 
	//se ne poklapa vidi ima li uposlenik drugo prezime pa ga uporedi
	//sa direktorovim drugim, pa ako se bar jedno poklapa, return 1
	if(pd2 != NULL && (strCmp(pd2, p1) || (p2 != NULL && strCmp(pd2, p2)))) {
		if(p2)
			*(p2-1) = '-'; //Vrati karakter nakon poredjenja
		return 1;
	}
	
	//Ne poklapa se nijedno prezime, ret 0
	return 0;
}

int suzi_listu(Uposlenik* kandidati, int vel, Uposlenik direktor, int broj_dana){
	//Nadji direktorovo prezime
	char *p1, *p2, *s1;
	s1 = p1 = direktor.ime_prezime;
	p2 = NULL; //Pretpostavimo direktor nema drugo prezime
	
	//Nadji prezimena direktora
	while(*s1 != '\0') {
		//Prvo prezime
		if((*s1 >= 'a' && *s1 <= 'z') || (*s1 >= 'A' && *s1 <= 'Z'))
			p1 = s1;
		
		//Prodji kroz ime ili prezime
		while((*s1 >= 'a' && *s1 <= 'z') || (*s1 >= 'A' && *s1 <= 'Z'))
			s1++;
		
		
		//Ako ima crtica, p11 je vec prvo prezime, a nakon '-' je drugo prezime
		if(*s1 == '-') {
			p2 = s1+1;
			*s1 = '\0';
			break;
		}
		
		s1++;
	}
	
	//Sada su p1 i p2 prezimena direktora
	int i, j, razlikaDana;
	
	//Prodji kroz kandidate
	for(i = 0; i < vel; i++){
		razlikaDana = DateDifference(direktor.datum_rodjenja, kandidati[i].datum_rodjenja);
		
		if( (broj_dana > 0 && razlikaDana > broj_dana) || (broj_dana < 0 && razlikaDana > broj_dana) ){
			//Uslov za izbacivanje kandidata po kriteriji godina ispunjen
			if(!Rod(kandidati[i].ime_prezime, p1, p2)){
				for(j = i; j < vel-1; j++){
					kandidati[j] = kandidati[j+1];
				}
				vel--;
				i--;
			}
			
		}
	}
	
	//Ako je direktor imao drugo prezime, vrati znak '-'
	if(p2){
		*(p2-1) = '-';
	}
	
	
	return vel;
}

int main() {
	struct Uposlenik direktor = {"Mujo Mujic", {1, 1, 1892} };
	struct Uposlenik kandidati[7] = {
	    { "Meho Mehic", { 31, 1, 1990 } },
	    { "Pero Peric", { 1, 2, 1990 } },
	    { "Sara Sarac", { 2, 10, 1990 } },
	    { "Fata Mujicic", { 10, 1, 1992 } },
	    { "Jozo Jozic", { 1, 10, 1990 } },
	    { "Mijo Mijic", { 4, 3, 1989 } },
	    { "Suljo Suljc", { 15, 1, 1992 } },
	};
	int novi_br = suzi_listu(kandidati, 7, direktor, -15);
	printf("Novi broj: %d\n", novi_br);
	direktor.datum_rodjenja.godina = 1992;
	novi_br = suzi_listu(kandidati, 7, direktor, -15);
	printf("Novi broj: %d\n", novi_br);
	    
		
	return 0;
}

#include <stdio.h>

struct Datum{
	int dan,mjesec,godina;
};

struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna(int godina){
	if((godina%4==0 && godina%100!=0)  || godina%400==0) return 1;
	return 0;
}

int poklapanje(char *p1, char *p2){		/*Pomocna funkcija za poredjenje prezimena*/
	if(*p1=='\0' || *p2=='\0') return 0;
	while(*p1!='\0' || *p2!='\0'){
		if(*p1!=*p2) return 0;
		p1++;
		p2++;
	}
	if(*p1=='\0' && *p2=='\0') return 1;
	return 0;
}

int isto_prezime(char *p1, char *p2){	/*Funkcija za provjeru poklapanja prezimena*/
	char prezimed1[30]={'0'}, prezimed2[30]={'0'}, prezimeu1[30]={'0'}, prezimeu2[30]={'0'};	/*Popunjavam niz sa nulama da se ne bi desilo havarijsko stanje pri poredjenju*/
	while(*p1!='\0') p1++;
	while(*p2!='\0') p2++;
	p1--;
	p2--;
	int i=0;
	while(*p1!=' '){
		if(*p1=='-') break;
		prezimed1[i]=*p1;
		p1--;
		i++;
	}
	prezimed1[i]='\0';
	i=0;
	if(*p1=='-'){
		p1--;
		i=0;
		while(*p1!=' '){
			if(*p1==' ') break;
			prezimed2[i]=*p1;
			i++;
			p1--;
		}
	}
	prezimed2[i]='\0';
	i=0;
	while(*p2!=' '){
		if(*p2=='-') break;
		prezimeu1[i]=*p2;
		p2--;
		i++;
	}
	prezimeu1[i]='\0';
	i=0;
	if(*p2=='-'){
		p2--;
		i=0;
		while(*p2!=' '){
			prezimeu2[i]=*p2;
			p2--;
			i++;
		}
	}
	prezimeu2[i]='\0';
	if(poklapanje(prezimed1,prezimeu1) || poklapanje(prezimed1,prezimeu2) || poklapanje(prezimed2,prezimeu1) || poklapanje(prezimed2,prezimeu2)) return 1;
	return 0;
}

int broj_dana_uposlenika(struct Uposlenik u){	/*Funkcija koja racuna broj dana svakog uposlenika od 0.0.0 (referentni datum) */
	int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(prestupna(u.datum_rodjenja.godina)) broj_dana[1]++;
	int suma=0,i;
	suma+=u.datum_rodjenja.dan;
	for(i=u.datum_rodjenja.mjesec-2;i>=0;i--){
		suma+=broj_dana[i];
	}
	for(i=0;i<u.datum_rodjenja.godina;i++){
		if(prestupna(i)) suma+=366;
		else suma+=365;
	};
	return suma;
}

void izbaci_radnika(struct Uposlenik *kandidati, int vel, int indeks){
	int i;
	struct Uposlenik temp;
	for(i=indeks;i<vel-1;i++){
		temp=kandidati[i+1];
		kandidati[i+1]=kandidati[i];
		kandidati[i]=temp;
	}
}


int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	int i,j,br_d=broj_dana_uposlenika(direktor);
	struct Uposlenik temp;
	for(i=0;i<vel;i++){
		if(broj_dana<0){
			if((broj_dana_uposlenika(kandidati[i])-br_d) < broj_dana){	/*treba ga izbaciti*/
				if(isto_prezime(direktor.ime_prezime,kandidati[i].ime_prezime)) continue;
				else{ 
					for(j=i;j<vel-1;j++){
						temp=kandidati[j+1];
						kandidati[j+1]=kandidati[j];
						kandidati[j]=temp;
					}
					vel--;
					i--;
					continue;
				}
				
			}
		}
		if(broj_dana>=0){
			if((br_d-broj_dana_uposlenika(kandidati[i])) > broj_dana){	/*Treba ga izbaciti*/
				if(isto_prezime(direktor.ime_prezime,kandidati[i].ime_prezime)) continue;
				else{
					for(j=i;j<vel-1;j++){
						temp=kandidati[j+1];
						kandidati[j+1]=kandidati[j];
						kandidati[j]=temp;
					}
					vel--;
					i--;
					continue;
				}
				
			}
		}
	}
	return vel;
}

int main() {
	struct Uposlenik u1, u2;
	int i;
	printf("Unesite ime uposlenika 1: ");
	for(i=0;i<50;i++){
		char x=getchar();
		if(x=='\n'){ 
			u1.ime_prezime[i]='\0';
			break;
		}
		u1.ime_prezime[i]=x;
	}
	printf("Unesite ime uposlenika 2: ");
	for(i=0;i<50;i++){
		char x=getchar();
		if(x=='\n'){ 
			u2.ime_prezime[i]='\0';
			break;
		}
		u2.ime_prezime[i]=x;
	}
	u1.datum_rodjenja.dan=29;
	u1.datum_rodjenja.mjesec=10;
	u1.datum_rodjenja.godina=1997;
	u2.datum_rodjenja.dan=27;
	u2.datum_rodjenja.mjesec=6;
	u2.datum_rodjenja.godina=1998;
	printf("Broj dana izmedju Edvina i Almine je: %d",broj_dana_uposlenika(u1)-broj_dana_uposlenika(u2));
	printf("\nBroj dana izmedju Almine i Edvina je: %d",broj_dana_uposlenika(u2));
	return 0;
}

#include <stdio.h>
#define epsilon 0.0001

struct Student{ //zadana struktura
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int uporedi(char* s1, char* s2){ //funkcija iz predavanja koja leksikografski poredi dva stringa
	while(*s1!='\0' && *s2!='\0'){
		if(*s1<*s2) return 1; //ako prvi string treba biti ispred drugog vrati 1
		if(*s1>*s2) return 2; //ako drugi string treba biti ispred prvog vrati 2
		s1++; s2++;
	}
		if(*s1!='\0') return 2; //ako prvi string nije dosao na kraj, tj. ima jos slova, drugi je ispred njega i vrati 2
		if(*s2!='\0') return 1;//ako drugi string nije dosao na kraj, tj. ima jos slova, prvi je ispred njega i vrati 1
	return 0; //ako su dva ista stringa vrati 0
}

float prosjek(int niz[], int vel){ //funkcija racuna prosjek svakog studenta pojedinacno i to u zavisnosti od broja ocjena
	int i=0, suma=0;
	
	if(vel==0) return 5; // u zadatku je receno ako je velicina 0, da je prosjek 5, tj. pao
	
	for(i=0;i<vel;i++) 
		if(niz[i]==5) return 5; //ako ima ijednu 5, prosjek je 5, tj. pao
			for(i=0;i<vel;i++){
				suma+=niz[i]; //racunamo sumu
			}

	float prosjek=(float)suma/vel; //float da bi dobili decimalan broj
	return prosjek;
}



int dalijeveci(struct Student pr, struct Student dr){ // funkcija priam dva studenta, vraca 1 ako prvi treba biti ispred drugog, u suprotnom 0
	if(prosjek(pr.ocjene, pr.br_ocjena)>prosjek(dr.ocjene, dr.br_ocjena)) return 1; //ako je prosjek prvog veci, onda treba vratiti 1, tj. da on bude prije drugog
	if(prosjek(pr.ocjene, pr.br_ocjena)<prosjek(dr.ocjene, dr.br_ocjena)) return 0; //ako je prosjek prvog manji, onda ovaj student ne treba biti prije drugog
//ovdje se podrazumijeva da im je prosjek jednak je funkcija nije nista vratila, pa dalje poredimo prezimena
	if(uporedi(pr.prezime, dr.prezime)==1) return 1;
	if(uporedi(pr.prezime, dr.prezime)==2) return 0;
//podrazumijeva se da su im imena ista ako nije do sada nista vratila, pa isto kao i za prezimena, poredimo imena	
	if(uporedi(pr.ime, dr.ime)==1) return 1;
	if(uporedi(pr.ime, dr.ime)==2) return 0;
	else return 1; //ako su im jednaki prosjeci, prezimena i imena, svejedno je sta ce funkcija vratiti
}


int genijalci(struct Student niz[], int vel, double prosjekk){ //glavna funkcija koja primi niz struktura, velicinu niza i zadani prosjek
	int i, j, indexmin=0, indexprvi, indexdrugi, indextreci;
	double min=10;
	
for(i=0;i<vel;i++){
	if(prosjekk-prosjek(niz[i].ocjene, niz[i].br_ocjena)>epsilon){//ako je nas prosjek manji od zadanog moramo izbaciti
		for(j=i;j<vel-1;j++){ //izbacivanje kao i kod obicnih nizova
			niz[j]=niz[j+1];
		}
	vel--;
	i--;
	}
}
//iznad se vel niza smanjivala, sada nam je vel onolliko koliko je ostalo struktura u nizu nakon izbacivanja onih ispod prosjeka
for(i=0;i<vel;i++){//prolazak kroz preostali niz i nalazenje minimuma i pamtimo mu index
	if(min-prosjek(niz[i].ocjene, niz[i].br_ocjena)>epsilon){
		min=prosjek(niz[i].ocjene, niz[i].br_ocjena);
			indexmin=i;
	}
}
	
int maxprvi=5;

switch(vel){
		
case 0:
	break;
case 1: //ako je vel 1, printamo samo tog jednog studenta
	maxprvi=5; indexprvi=indexmin; //indexmin smo morali naci prije da bi bili sigurni da pokazuje na najmanji i trazimo sve vece od njega
		
	for(i=0;i<vel;i++){
		int temp_prosjek=prosjek(niz[i].ocjene, niz[i].br_ocjena);
		
		if(dalijeveci(niz[i],niz[indexprvi])){ //poziv funkcije koja trazi studenta koji ima najveci prosjek, ako ima isti onda poredi imena i prezimena
			indexprvi=i; //pamtimo index
			maxprvi=temp_prosjek;
		}
	}

printf("\n%s %s\n", niz[indexprvi].prezime, niz[indexprvi].ime); //printamo najboljeg studenta
	break;
		
case 2: //ako je vel 2, printamo ta dva studenta
	indexprvi=indexmin;
		
	for(i=0;i<vel;i++){
		if(dalijeveci(niz[i],niz[indexprvi])==1) indexprvi=i; //pamtimo indexprvog tj. najveceg studenta da bi u iducoj petlji mogli ga preskociti
	}
		
printf("%s %s\n", niz[indexprvi].prezime, niz[indexprvi].ime);
	
indexdrugi=indexmin;
		
for(i=0;i<vel;i++){
	if(dalijeveci(niz[i],niz[indexdrugi])==1 && i!=indexprvi){ //preskacemo onog najboljeg
			indexdrugi=i;
	}
}

printf("%s %s\n", niz[indexdrugi].prezime, niz[indexdrugi].ime);
	break;
		
default: 
	
	indexprvi=indexmin; //nadjemo najveceg
		
for(i=0;i<vel;i++){
	if(dalijeveci(niz[i],niz[indexprvi])==1)
		indexprvi=i; 
}
		
printf("%s %s\n", niz[indexprvi].prezime, niz[indexprvi].ime);

indexdrugi=indexmin;

for(i=0;i<vel;i++){
	if(dalijeveci(niz[i],niz[indexdrugi])==1 && i!=indexprvi){
		indexdrugi=i;
	}
}
	
printf("%s %s\n", niz[indexdrugi].prezime, niz[indexdrugi].ime);

indextreci=indexmin;

for(i=0;i<vel;i++){
	if(dalijeveci(niz[i],niz[indextreci])==1 && i!=indexprvi && i!=indexdrugi)//preskacemo one koje smo ispisali
		indextreci=i;
}

printf("%s %s\n", niz[indextreci].prezime, niz[indextreci].ime);
}
	return vel;
}


int main() {

struct Student studenti[5]={
	
	{"Mujo", "Mujic", {7,7,7,7,8},5},
	{"Meho", "Mujic", {7,7,7,7,8},5},
	{"Beba", "Bebic", {10,10,10,10,5},5},
	{"Mujo", "Mujic", {7,7,7,7,8},5},
	{"Fata", "Fatic", {7,7,7,7,8},5},
};

genijalci(studenti,5,6.5);

	return 0;
}

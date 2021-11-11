#include <stdio.h>
#include <string.h>
#define KAPACITET 200
#define MAX 1000
#define MIN 0

struct Vrijeme{
	int sati,minute,sekunde;
};

struct Cas{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};
void UnosStringa(char* s, int vel){
	int i=0;
	char z=getchar();
	if(z=='\n') z=getchar();
	while(i<vel-1 && z!='\n'){
		s[i]=z;
		i++;
		z=getchar();
	}
	s[i]='\0';
}

int ucitaj_datoteku(struct Cas raspored[]){
	int UcitajDat;
	FILE* datoteka=fopen("raspored.dat","rb");
	if(datoteka==NULL) return 0;
    UcitajDat=fread(raspored,sizeof(raspored),KAPACITET,datoteka);
	fclose(datoteka);
	return UcitajDat;
}
int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	int ZapisiDat;
	FILE* datoteka=fopen("raspored.dat","wb");
	if(datoteka==NULL) return 0;
	ZapisiDat=fwrite(raspored,sizeof(raspored),broj_casova,datoteka);
	if(ferror(datoteka)){
		printf("Greska prilikom pisanja datoteke.\n");
	}
	fclose(datoteka);
	return 1;
}
/* pomocna */
void Inicijaliziraj(struct Cas* s){
	(*s).pocetak.sati=0;
	(*s).pocetak.minute=0;
	(*s).pocetak.sekunde=0;
	(*s).kraj.sati=0;
	(*s).kraj.minute=0;
	(*s).kraj.sekunde=0;
	(*s).dan_u_sedmici=1;
}
/* custom funkcija za kopiranje */
void CopyFunk(char* s1, const char* s2){
	int x=0;
	for(;;){
		s1[x]=s2[x];
		if(s2[x] == '\0') break;
		x++;
	}
}

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas){
	int i;
	for(i=0;i<broj_casova;i++){
		if(cas.dan_u_sedmici != raspored[i].dan_u_sedmici) return 0;
		if(cas.pocetak.sati == raspored[i].kraj.sati){
			if(raspored[i].pocetak.sati == cas.kraj.sati){
				if(cas.pocetak.minute < raspored[i].kraj.minute && raspored[i].pocetak.minute < cas.kraj.minute){
					return 1;
				}
			}
			else if(raspored[i].pocetak.sati < cas.kraj.sati && cas.pocetak.minute < raspored[i].kraj.minute){
				return 1;
			}
		}
		else if(raspored[i].pocetak.sati == cas.kraj.sati){
			if(cas.pocetak.sati < raspored[i].kraj.sati && raspored[i].pocetak.minute < cas.kraj.minute){
				return 1;
			}
		}
		else if(cas.pocetak.sati < raspored[i].kraj.sati && raspored[i].pocetak.sati < cas.kraj.sati){
			return 1;
		}
	}
	return 0;
}
int dodaj_cas(struct Cas raspored[],int broj_casova, const char* predmet, int trajanje){
	struct Cas s;
	int i;
	int tmp=1;
	Inicijaliziraj(&s);
	if(trajanje > 10) return 0;
	broj_casova++;
	CopyFunk(s.predmet,predmet);
	for(i=0;i<broj_casova;i++){
		/*sat ne smije biti >19 i dan ne smije biti >6*/
		if(s.kraj.sati > 19 && tmp > 6) return 0;
		/*cas pocinje u 9 i zavrsava za + trajanje*/
		s.pocetak.sati=9;
		s.kraj.sati= 9 + trajanje;
		s.dan_u_sedmici=tmp;
		/*ako nema mjesta u rasporedu vraca 0, u protivnom dodajemo cas*/
		if(!preklapanje(raspored,broj_casova,s)) break;
		else{
		     for(;;){
		        s.pocetak.sati++;
			    s.kraj.sati++;
			    /*provjeravamo opet jel isteklo vrijeme*/
			    if(s.kraj.sati > 19 && tmp > 6) return 0;
			    /*ako postoji preklapanje u rasporedu prekidamo*/
			    if(!preklapanje(raspored,broj_casova,s)) break;
		    }
		}
		/*ako je proslo 19h prelazimo na sljedeci dan*/
		if(s.kraj.sati > 19){
			 tmp++;
			 i=0; /*brojac postavljamo na nulu!!*/
		}
	}
	/*sada pamtimo trenutni dan*/
	s.dan_u_sedmici=tmp;
	/*i dodajemo cas na kraj*/
	raspored[broj_casova-1]=s;
	return 1;
}
void ispis_rasporeda(struct Cas raspored[], int broj_casova){}
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	int i, br=0,test=0;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			if(test==0){
				printf("\n");
				printf("Uneseni su casovi:");
			}
			test=1; br++;
			printf("\n%d) %s (%02d:%02d-%02d:%02d)",br,raspored[i].predmet,raspored[i].pocetak.sati,raspored[i].pocetak.minute,raspored[i].kraj.sati,raspored[i].kraj.minute);
		}
	}
}
void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena){
	int i,tmp=0;
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			tmp++;
			if(tmp==redni_broj){
				/*mijenjam predmet sa pomocnom funk za kopiranje*/
				CopyFunk(raspored[i].predmet,promjena.predmet);
				/*ostalo jednostavno samo dodjeljujemo*/
				raspored[i].dan_u_sedmici=promjena.dan_u_sedmici;
				raspored[i].pocetak=promjena.pocetak;
				raspored[i].kraj=promjena.kraj;
			}
		}
	}
}
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
	int i,j,tmp=0;
	/*brisanje uz ocuvanje redoslijeda*/
	for(i=0;i<broj_casova;i++){
		if(raspored[i].dan_u_sedmici==dan){
			tmp++;
			if(tmp==redni_broj){
				for(j=i;j<broj_casova-1;j++){
					/*koristit cu ovu funkciju za predmete jer treba paziti na tip dodjeljivanja*/
					CopyFunk(raspored[i].predmet,raspored[j+1].predmet);
					raspored[i].dan_u_sedmici=raspored[j+1].dan_u_sedmici;
					raspored[i].pocetak=raspored[j+1].pocetak;
					raspored[i].kraj=raspored[j+1].kraj;
				}
				broj_casova--;
				i--;
			}
		}
	}
}
int main() {
	struct Cas raspored[KAPACITET];
	int broj_casova=0,izbor=1,tmp;
	char string[MAX];
	ucitaj_datoteku(raspored);
	do{
			printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		    scanf("%d", &izbor);
		switch(izbor){
		    case 2: printf("Unesite naziv predmeta: ");
		            UnosStringa(string,MAX);
		            string[9]='\0';
		            printf("Unesite broj casova: ");
		            scanf("%d",&tmp);
		            /*provjeramo ima li dovoljno mjesta u rasporedu
		            if(dodaj_cas(raspored,broj_casova,string,tmp)==0){
		            	printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",tmp);
		            }*/
		            break;
		    case 0: break;
	     }
	 }while(izbor!=0);
	zapisi_datoteku(raspored,broj_casova);
	return 0;
}

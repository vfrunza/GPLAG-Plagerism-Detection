
            ------------------------------> STRUKTURE <---------------------------------
            
napomena: zadatak sa zavrsnog-struktura-ispit5


fja koja provjerava je li se isto nesto javilo ranije-npr neki studenti

int bio_ranije(struct Student student,int velicina,struct Student niz[3]){
 
 int i;
 for(i=0;i<velicina;i++){
  if(strcmp(student.ime,niz[i].ime)==0 && strcmp(student.prezime,niz[i].prezime)==0){
   return 1;
  }
 }
 return 0;
}




primjer unosa strukture odmah na pocetku, za strukture: 

struct Student{
    char ime[20];
    char prezime[20];
};
struct Ocjena{
    struct Student s;
    char predmet[100];
    int ocjena;
};

  struct Ocjena niz[] = {
	{ { "Meho", "Mehic"}, A, 6},
	{ { "Sara", "Sarac"}, A, 9},
	{ { "Meho", "Mehic"}, "IM1", 10},
	{ { "Iva", "Ivic"}, "TP", 8},
	{ { "Pero", "Peric"}, "TP", 7},
	{ { "Sara", "Sarac"}, "IM1", 8},
};

koristenje struktura sa geometrijiskim likovima

struct Tacka {
float x, y;
};

float udaljenost(struct Tacka t1, struct Tacka t2) {
return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
}

struct Kruznica {
struct Tacka centar;
float poluprecnik;
};

struct Kvadrat {
struct Tacka dolje_lijevo;
float stranica;
};

int unutar_kruznice(struct Kruznica k, struct Tacka t) {
if (udaljenost(t, k.centar) < k.poluprecnik) return 1;
return 0;
}

int na_kruznici(struct Kruznica k, struct Tacka t) {
if (udaljenost(t, k.centar) - k.poluprecnik < EPSILON) return 1;
return 0;
}

int kruznice_preklapanje(struct Kruznica k1, struct Kruznica k2) {
if (udaljenost(k1.centar, k2.centar) < k1.poluprecnik + k2.poluprecnik)
return 1;
return 0;
}



struct Tacka unos_tacke()
{
 struct Tacka t;
 printf ("Unesite koordinate tacke (x, y): ");
 scanf ("%f %f", &t.x, &t.y);
 return t;
}


struct Kruznica unos_kruznice()
{
 struct Kruznica k;
 printf ("Unesite centar kruznice: \n");
k.centar = unos_tacke();
 printf ("Unesite poluprecnik kruznice: ");
 scanf("%f", &k.poluprecnik);
 return k;
}


/* Tačka se nalazi unutar kružnice ako je udaljenost tačke od centra
kruznice manja od poluprečnika kružnice */
d = udaljenost(t, k.centar);
 if (d < k.poluprecnik)
 printf("Tacka je unutar kruznice. \n");
 else if (d == k.poluprecnik)
 printf("Tacka je na kruznici. \n");
 else
 printf("Tacka je izvan kruznice. \n");
 
 
 
 
 ZA PRAVOUGAONIK-USLOV DA SE TACKA NALAZI U PRAVOUGAONIKU (UZ OVU DEF STRUKTURA):
 
 struct Kruznica k;
 struct Tacka t;
 struct Pravougaonik p;
 float d;
 
 if(t.x<p.koordinata2.x && t.x>p.koordinata1.x && t.y<p.koordinata1.y && t.y>p.koordinata4.y)
 printf("Tacka je unutar pravougaonika.\n");
 else if ((t.x==p.koordinata1.x && (t.y<=p.koordinata1.y && t.y>=p.koordinata4.y)) || (t.x==p.koordina
ta2.x && (t.y<=p.koordinata2.y &&t.y>=p.koordinata3.y)) || (t.y==p.koordinata1.y && (t.x<=p.koordinata3.x
&& t.x>=p.koordinata1.x)) || (t.y==p.koordinata3.y &&(t.x<=p.koordinata4.x && t.x>=p.koordinata1.x)))
 printf("Tacka je na pravougaoniku.\n");
 else printf("Tacka je izvan pravouganika.\n");


/*Ucitavanje podataka iz datoteke u niz
struktura*/
 while (fscanf(ulaz, "%i %i %i\n", &osoba[i].indeks, &osoba[i].predmet,&osoba[i].ocjena) != EOF && i < velicina)
i++;
i--;


 /*Ucitavanje datoteke u niz*/
 DATOTEKA JE OBLIKA:  1 INZENJERSKA MATEMATIKA I
 
 int j = 0;
 struct Predmet imena[vel];
 do{
 fscanf(ulaz, "%i ", &imena[j].redni_broj);
 fgets (imena[j].ime, 50, ulaz);
imena[j].ime[strlen (imena[j].ime)-1] = '\0';
j++;
 } while (j < vel );
j--;




/*Funkcija za unos novih studenata na kraj datoteke*/
int dodaj ()
{
FILE* dodavanje;
 struct Osoba novi;
dodavanje = fopen("ispit.txt", "a");
 if ( dodavanje == NULL )
 return -1;
 printf("Unesite prezime:\n");
unos(novi.prezime, lname);
 printf("Unesite ime:\n");
unos(novi.ime, name);
 printf("Unesite broj bodova na prvom parcijalnom:");
 do
 {
 if ((scanf("%i", &novi.broj_bodova_1))!= 1 || novi.broj_bodova_1 < 0 || novi.broj_bodova_1 > 20)
 printf("Unesite ponovo!\n");
Ocisti();
 } while (novi.broj_bodova_1 < 1 || novi.broj_bodova_1 > 20);
 printf("Unesite broj bodova na drugom parcijalnom:");
 do
 {
 if (( scanf("%i", &novi.broj_bodova_2)!= 1 || novi.broj_bodova_2 < 0 || novi.broj_bodova_2 > 20))
 printf("Unesite ponovo!\n");
Ocisti();
 } while (novi.broj_bodova_2 < 1 || novi.broj_bodova_2 > 20);
 fprintf(dodavanje, "%-15s %-15s %-2i %-
2i\n", novi.prezime, novi.ime, novi.broj_bodova_1, novi.broj_bodova_2);
 fclose (dodavanje);
 return 0;
}



poredjenje dva datuma

int datum_prije(struct Datum d1, struct Datum d2) {
 if (d1.godina < d2.godina) return 1;
 if (d1.godina == d2.godina && d1.mjesec < d2.mjesec) return 1;
 if (d1.godina == d2.godina && d1.mjesec == d2.mjesec && d1.dan < d2.dan)
return 1;
 return 0;
}


studenti rodjeni prije nekog zadatog datuma, a indeks im je paran broj

void stariji_od(struct Student* studenti, int vel, struct Datum d) {
 int i;
 for (i=0; i<vel; i++) {
 if (datum_prije(studenti[i].datum_rodjenja, d) &&
 studenti[i].broj_indeksa % 2 == 0)
 printf("%s %s\n", studenti[i].ime, studenti[i].prezime);
 }
 }
 
 






          -------------------------------> DATOTEKE <----------------------------------
          
otvaranje datoteke sa navedenim imenom:

char ime_datoteke[1000];
printf("Unesite ime datoteke: ");
unesi(ime_datoteke, 1000);
FILE* ulaz = fopen(ime_datoteke, "r");


uspjesnost otvaranja datoteka-provjera:

 int main() {
 FILE* ulaz = fopen("prva.txt", "r");
 if (ulaz == NULL) {
 printf("Otvaranje datoteke prva.txt nije uspjelo");
 return 1;
 }
 FILE* izlaz = fopen("druga.txt", "w");
 if (izlaz == NULL) {
 fclose(ulaz);
 printf("Otvaranje datoteke druga.txt nije uspjelo");
 return 2;
 }
 
rad na nivou karaktera sa datotekom:

char znak;
do{
	znak=fgetc(ulaz);
}while(znak!=EOF);
        
            
prebrojavanje samoglasnika u tekstualnoj datoteci

do {
 c = fgetc(ulaz);
 if (c == ’a’ || c == ’e’ || c == ’i’ || c == ’o’ || c == ’u’ ||
 c == ’A’ || c == ’E’ || c == ’I’ || c == ’O’ || c == ’U’)
 samoglasnika++;
 } while (c != EOF);


upisivanje jednog karaktera u datoteku:

do {
c = fgetc(ulaz);
if (c != EOF) fputc(c, izlaz);
} while (c != EOF);


ocitavanje citavog stringa iz datoteke:

// br-koliko zelimo da se ucita znakova pri cemu vraca br-1 znak jer imamo i /0
char* fgets(char* string, int br, FILE* datoteka);
//Prvi parametar ove funkcije je pokazivač tipa char koji pokazuje na neku lokaciju
//gdje možemo upisati sadržaj očitan iz datoteke


upis stringa u datoteku

void fputs(char* string, FILE* datoteka);
//Prvi parametar je string (adresa niza tipa char) koji treba zapisati, a drugi pokazivač
//na datoteku u koju zapisujemo.


rad sa stringom kad ga uzimamo iz ulaza i saljemo na izlaz
char s[100];
while(fgets(s, 100, ulaz))
 fputs(s, izlaz);
 





FORMATIRANE DATOTEKE(IMAMO I SLOVA I BROJEVE U DATOTECI)

fja fscanf-fja iscitavanja iz datoteke-CITA SE RED PO RED, CITA SE ONAKO KAKO PO REDU IDE U DATOTECI

while(fscanf(ulaz, "%d %d %s\n", &sirina, &duzina, ime) == 3)
printf("Ucitano je: %d,%d,%s\n", sirina, duzina, ime);



ako imamo neko ime da je sa razmakom to fscanf ne cita dobro, pa moramo znak po znak npr. NEW YORK

while(fscanf(ulaz, "%d,", &br_stanovnika) == 1) {
 i=-1;
 do {
 if (i<19) i++;
 ime[i] = fgetc(ulaz);
 } while(ime[i] != ’,’ && ime[i] != EOF);
 ime[i] = ’\0’;
 if (fscanf(ulaz, "%f\n", &temperatura) == 0) break;
 printf("Prosjecna temperatura u %s (%d) je %g\n", ime, br_stanovnika,
temperatura);
 }
 

fja fprintf-fja za upisivanje podataka u datoteku

fprintf(izlaz, "%d %s\n", sirina*duzina, ime); // moramo ekspilicitno ucitat znak \n zato ga pisemo


iz datoteke se iscitava niz realnih brojeva:
float niz[100];
i=0;
while (i<100 && fscanf(ulaz, "%f", &niz[i]) == 1)
i++;


iscitavanje podataka u strukturu: npr:

struct Mjerenje {
char grad[21];
int dan, mjesec;
float temperatura;
};

// za promjenjive u strukturi, nizovnog tipa, ne moramo korisiti znam ampersanda

while (i<1000 && fscanf(ulaz, "%20s %d %d %f\n", mjerenja[i].grad, &
mjerenja[i]].dan, &mjerenja[i].mjesec, &mjerenja[i].temperatura) == 4);




ucitavanje u strukturu ako to radimo preko fje UCITAJ: npr:

#define KAPACITET 1000
struct Osoba {
char ime[20], prezime[20], brtel[15];
};
struct Osoba imenik[KAPACITET];


int ucitaj(struct Osoba* imenik) {
 int i = 0;
 FILE* dat = fopen("baza.txt", "r");
 if (dat == NULL) {
 printf("Greska pri otvaranju datoteke za citanje.\n");
 return 0;
 }
 while (i < KAPACITET && fscanf(dat, "%20s%20s%15s\n",
 imenik[i].ime, imenik[i].prezime, imenik[i].brtel) == 3)
 i++;
 fclose(dat);
 return i;
 }


fja ZAPISI

void zapisi(struct Osoba* imenik, int broj_osoba) {
 int i;
 FILE* dat = fopen("baza.txt", "w");
 if (dat == NULL) {
 printf("Greska pri otvaranju datoteke za pisanje.\n");
 exit(1);
 }
 for (i=0; i<broj_osoba; i++) {
 fprintf(dat, "%-20s%-20s%-15s\n", imenik[i].ime, imenik[i].prezime,imenik[i].brtel);
 if (ferror(dat)) {
 	printf("Greska prilikom pisanja datoteke.\n");
 	break; }
 	}
 fclose(dat);
}



BINARNE DATOTEKE:

fje za rad sa binarnim datotekama: (MOZEMO DA KORISTIMO FGETC KOD BINARNIH ALI NE MOZES FSCANF I FPRINTF)

ZA CITANJE:

size_t fread(void* ptr, size_t vel, size_t broj, FILE *dat);
// prvi parametar-gdje iscitavamo, drugi parametar-koliko memorije uzima taj tip, treci-kapacitet(br_karaktera),
// cetvrti parametar-datoteka iz koje citamo

int ucitano = fread(ime, 1, 99, dat);

primjer sa strukturom:
int ucitano = fread(imenik, sizeof(struct Osoba), KAPACITET, dat);

ZA PISANJE:

size_t fwrite(void* ptr, size_t vel, size_t broj, FILE *dat);

int zapisano = fwrite(imenik, sizeof(struct Osoba), broj_osoba, dat);

 




 

#include <stdio.h>
#include <stdlib.h>

struct Prodavnica {
	char naziv[100];
	int ID;
};

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};
int ucitaj_prodavnice(struct Prodavnica *niz, int kap)
{
	FILE *ulaz=fopen("prodavnice.txt", "r");
	if(ulaz==NULL) {
		ulaz=fopen("prodavnice.txt", "w");
		if(ulaz!=NULL) {
			fclose(ulaz);
			return 0;
		}
		printf("Greska u modu za citanje i pisanje!");
		exit(1); 
	}

	int	a=0;
//	printf("Tu sam");
	while(!feof(ulaz) && a<kap) {
		int i=-1;
		int c;
		int prviwhitespace=1;
		do {
			if(i<99) i++;
			c=fgetc(ulaz);
			if(prviwhitespace) {
				if(c==' ' || c=='\n' || c=='\t') {
					prviwhitespace=1;
					i--;
				} else {
					prviwhitespace=0;
					niz[a].naziv[i]=c;
				}
			} else niz[a].naziv[i]=c;
			//		printf("ovde uzimam karaktere\n %d", i);
		} while(niz[a].naziv[i]!=EOF && niz[a].naziv[i]!=',');
		//	printf("\n%d\n", niz[a].naziv[i]);
		niz[a].naziv[i]='\0';
		//valjda se treba pomjeriti jedno mjesto da uzme ID

		int provjera=fscanf(ulaz,"%d,",&niz[a].ID);
		if(provjera>1) {
			printf("GRESKA");
			fclose(ulaz);
			return a;
		}

		//	else printf("\nuzeo sam broj %d\n", niz[a].ID);
		a++;
	}
	fclose(ulaz);

	return a;


}

int ucitaj_artikle(struct Artikal *niz, int kap)   //ovo se cinilo previse jednostavnim da bi bilo dobro, provjeri ti neke slucajvee
{
	int a=0;
	FILE *ulaz=fopen("artikli.bin", "rb");
	if(ulaz==NULL) {
		//mozda ne postoji pa je otvorim za citanje i zatvorim
		ulaz=fopen("artikli.bin", "wb");
		if(ulaz==NULL) {
			printf("Greska prilikom otvaranja datoteke!");
			exit(1);
		}
		fclose(ulaz);
		return 0;
	}

	a=fread(niz, sizeof(struct Artikal), kap, ulaz);
	if(ferror(ulaz)) printf("Doslo je do greske prilikom citanja datoteke!");
	fclose(ulaz);
	return a;
}

double prosjecna_cijena_u_prodavnici(struct Prodavnica p, struct Artikal *artikli, int broj_artikala) //ili float
{
	double suma=0;
	int brojac=0;
	double prosek=0;
	int i;
	for(i=0; i<broj_artikala; i++) {
		if(artikli[i].prodavnica==p.ID) {
			suma=suma+artikli[i].cijena;
			brojac++;
		}
	}

	if(suma==0) return 0;
	prosek=suma/brojac;
	return prosek;
}

void izbaci_prodavnicu(struct Prodavnica *p, int indexnje, int brojnjih)
{
	int i;
	for(i=indexnje+1; i<brojnjih; i++) {
		p[i-1]=p[i];
	}
//	brojnjih--;
//	return brojnjih;
}

int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	int i;
	double sumasvih=0;
	double prosjek=0;
	double prosjekpojedinacno;
	for(i=0; i<np; i++) {
		sumasvih=sumasvih+prosjecna_cijena_u_prodavnici(p[i], a, na);
	}
	if(sumasvih==0) return np;  //zavisno da li vraca broj obrisanih ili broj preostalih, skontaj to da li da vrati 0, mislim da ce ovo radiiti cak i kad aje broj prodavnica 0 jer si gore stavila da je suma nula pa nece nikada uci u ovu petlju i onda ce samo vratiti 0 ali provjeri
	prosjek=sumasvih/np;

	for(i=0; i<np; i++) {
		prosjekpojedinacno=prosjecna_cijena_u_prodavnici(p[i], a, na);
		if(prosjekpojedinacno>prosjek) { //izbaci;
			izbaci_prodavnicu(p, i, np);
			np--;
			i--;
		}

	}

	return np;
}

int koliko_ima_znakova(char *string)   //za ovo vjerovatno postoji funkcija vec //pazi ako nie null terminiran ovo ode u inf loop
{
	char *novi=string;
	int broj=0;
	while(*novi!='\0') {
		broj++;
		novi++;
	}
	return broj;
}


int sacuvaj(struct Prodavnica* p, int n, const char* ime_datotetke)   //eh sada jel treba onda da sacuva i ove odprije podatke ili ne, procitaj malo bolje postavku pa razmisli
{
	FILE *ulaz=fopen(ime_datotetke, "ab") ;
	// u slucaju da treba da ona sacuva i ove prosle ti prvo napravi u read mode da ti cita ove prosle pa onda upisi to u niz struktura pa tek onda da ti pise ta oba niza u novi, ali tu ces se opet susresti s istim onim problemom kada nisi znala kako da napravis proizvoljne duzine char i ne znam sta ces onda, eventualno ovo otvori u rezimu ab+
	if(ulaz==NULL) {
		printf("Greska pri citanju datoteke");
		return 0;
	}
	int i;
	int brojnjih=0;
//	void *nekipointer=p;
	
	for(i=0; i<n; i++) {
		int velicina=sizeof(int)+koliko_ima_znakova((*p).naziv)+1;
		brojnjih=fwrite(p, velicina, 1, ulaz);
		p++;
		//eh sad pitanje je jesul oni uopce nul terminirani ti sto ih ti dobijes, ako niosu onda trazi do prvog zareza a ne do kraja stringa
//		printf("\nSacuvano je bajta : %d , a inace struktura ima maksimalno %d, %d ima znakova", velicina, sizeof(struct Prodavnica), koliko_ima_znakova(p[i].naziv));
	}
	if(ferror(ulaz)) {
		printf("Bila je greska u pisanju datoteke!");
		fclose(ulaz);
		return 0;
	}
	return brojnjih;
	fclose(ulaz);
}

int main()
{
//	struct Prodavnica p[10];
//	int broj=ucitaj_prodavnice(p,2);
//	printf("%d", broj);
//
	return 0;
}

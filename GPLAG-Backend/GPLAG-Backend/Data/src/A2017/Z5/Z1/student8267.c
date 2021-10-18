#include <stdio.h>
struct Datum { int dan, mjesec, godina };
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
	};
int dana(struct Uposlenik o){
	int x;
	
	return x;
}
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i,prestupna=0;
	if(broj_dana==0) return vel;
	for(i=0;i<vel;i++){
		if(kandidati[i].godina%4==0&&kandidati[i].godina%100!=0) prestupna=1;
		if(kandidati[i].godina>=direktor.godina&&kandidati[i].mjesec>=direktor.mjesec){
			if(prestupna==1){
				if(kandidati[i].mjesec==1) prestupna=0;
				if(kandidati[i].mjesec==2&&kandidati[i].dan<=28) prestupna=0; 
			}
			if(kandidati[i].dan==)
		}
		
	}
}
int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
/*#include <stdio.h>
#include <string.h>

struct Grad {
	char naziv[20];
	int br_stanovnika;
};
struct Drzava {
	char naziv[20];
	struct Grad gradovi[100];
	int br_gradova;
};

int izbaci_duple(struct Grad* gradovi, int velg, struct Drzava* drzave, int veld) 
{
	int izbaci=0;
	int broj;
	int i,j,k,l;
	for(i=0;i<velg;i++)
	{
		izbaci=0;
		broj=0;
		for(j=0;j<veld;j++)
		{
			for(l=0;l<drzave[j].br_gradova;l++)
			{
				if(strcmp(gradovi[i].naziv,drzave[j].gradovi[l].naziv)==0) broj++;
			}
		}
		if(broj>=2) izbaci=1;
		if(izbaci)
		{
			for(k=i;k<velg-1;k++)
			{
				gradovi[k]=gradovi[k+1];
			}
			i--;
			velg--;
		}
	}
	return velg;
}

int main() {

struct Grad gradovi[10] = {
	{"Sarajevo", 500000},
	{"Beograd", 1500000},
	{"Zagreb", 1000000},
	{"Ljubljana", 300000},
	{"Skopje", 400000},
	{"Banja Luka", 150000},
	{"Slavonski Brod", 50000}
};

struct Drzava drzave[10] = {
	{"BiH", {{"Sarajevo", 500000}, {"Banja Luka", 150000}}, 2},
	{"Hrvatska", {{"Beograd", 1000000}, {"Slavonski Brod", 50000}}, 2},
	{"Neka", {{"Beograd", 300000}, {"Sarajevo", 150000}}, 2},
};

int vel = izbaci_duple(gradovi,7,drzave,3);
int i;
for (i=0; i<vel; i++)
	printf("%s\n", gradovi[i].naziv);
	return 0;
}*/
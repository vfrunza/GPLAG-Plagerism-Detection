#include <stdio.h>
#define eps 0.00001
// Funkcija koja sluzi za mjerenje duzine stringa.

int duz(char *s){
	int a=0;
	while(*s++!=0)
		a++;
	return a;
}
// Funkcija koja poredi 2 stringa po leksikografski. U slucaju ako su poredjeni stringovi jednaki, vraca nulu.
// Ukoliko je prvi veci od drugog stringa, vraca 1, u suprotnom vraca 2.
int poredi(char *s, char *p){
	while(*s!=0){
		if(*s<*p)
			return 1;
		else if(*s>*p)
			return 2;
		s++;
		p++;
	}
	if(duz(s)!=duz(p))
		return 1;
	return 0;
}
// Funckija racpr je skracenica od "racunam prosjek". Prima pokazivac na niz i velicinu datog niza. I naravno, vraca prosjek.
double racpr(int niz[], int vel){
	int i;
	double prosjek=0;
	for(i=0;i<vel;i++)
	{
		if(niz[i]==5)
		{
			prosjek=5.0;
			break;
		}
		prosjek+=niz[i];
	}
	if(prosjek-5.0<eps)
		return prosjek;
	prosjek/=vel;
	return prosjek;
}
// Struktura Student...
struct Student {
char ime[20], prezime[20];
int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student studenti[],int vel, double prosjek ){
	double pr=0;
	// pr je varijabla u kojoj se smjesta prosjek nekog studenta.
	// max1i, max2i i max3i su varijable koje oznacavaju index najveca 3 prosjeka kod studenata. Stavljene su na pocetnoj vrijednosti -1, jer nema indexa -1. 
	int i,j,max1i=-1,max2i=-1,max3i=-1;
	// max1, max2, max3 su realne varijable koje oznacavaju 3 najveca prosjeka kod datih studenata.
	double max1=0,max2=0,max3=0;
	// Ovdje se vrsi "eliminacija" studenata ciji prosjek je manji od datog.
	for(i=0;i<vel;i++){
		pr=racpr(studenti[i].ocjene,studenti[i].br_ocjena);
		if(pr<prosjek||studenti[i].br_ocjena==0)
		{
			for(j=i;j<vel-1;j++){
				studenti[j]=studenti[j+1];
			}
			i--;
			vel--;
		}
		pr=0;
	}
	// Ovdje se vrsi odredjivanje studenta sa najvecim prosjekom. 
	// Ukoliko se nalazi vise studenata sa istim prosjekom, uzima se onaj koji je po leksikografskom poretku manji. Prvo se gleda prezime. 
	// U slucaju da imaju isti prosjek i prezime, onda se gledaju njihova imena. 
	for(i=0;i<vel;i++)
	{
		pr=racpr(studenti[i].ocjene,studenti[i].br_ocjena);
		if(max1<pr)
		{
			max1=pr;
			max1i=i;
		}
		else if(max1-pr<eps&&i!=max1i){
			if(poredi(studenti[i].prezime,studenti[max1i].prezime)==1)
			{
				max1i=i;
			}
			else if(poredi(studenti[i].prezime,studenti[max1i].prezime)==0&&poredi(studenti[i].ime,studenti[max1i].ime)==1)
			{
				if(poredi(studenti[i].ime,studenti[max1i].ime)==1)
				{
					max1i=i;
				}
			}
		}
	}
	// Kako za prvog, tako i za drugog i treceg najboljeg studenta u datom nizu. 
	for(i=0;i<vel;i++)
	{
		pr=racpr(studenti[i].ocjene,studenti[i].br_ocjena);
		if(max1i==i)
			continue;
		if(max2i==-1)
			{
				max2=pr;
				max2i=i;
			}
		if(max2<pr&&max1>pr){
			max2=pr;
			max2i=i;
		}
		if(max1-pr<eps||max2-pr<eps)
		{
			if(poredi(studenti[i].prezime,studenti[max2i].prezime)==1)
			{ 
				max2=pr;
				max2i=i;
			}
			else if(poredi(studenti[i].prezime,studenti[max2i].prezime)==0)
			{
				if(poredi(studenti[i].ime,studenti[max2i].ime)==1)
				{
					max2=pr;
					max2i=i;
				}
			}	
		}
	}
	for(i=0;i<vel;i++)
	{
		pr=racpr(studenti[i].ocjene,studenti[i].br_ocjena);
		if(max2i==i||max1i==i)
			continue;
		if(max3i==-1)
		{
			max3=pr;
			max3i=i;
		}
		if(max3<pr&&max2>pr){
			max3=pr;
			max3i=i;
		}
		if(max3-pr<eps&&i!=max2i&&i!=max1i)
		{
			if(poredi(studenti[i].prezime,studenti[max3i].prezime)==1)
			{
				max3=pr;
				max3i=i;
			}
			else if(poredi(studenti[i].prezime,studenti[max3i].prezime)==0)
			{
				if(poredi(studenti[i].ime,studenti[max3i].ime)==1)
				{
					max3i=i;
				}
			}
		}
	}
	// Ovdje se vrsi provjera da li ima studenata koji zadovoljavaju dati uslov.
	// Pocetna vrijednost je -1, ukoliko se promijenila, znaci da postoji student koji zadovoljava uslov, u protivnom ne.
	if(max1i!=-1)
		printf("%s %s\n",studenti[max1i].prezime,studenti[max1i].ime);
	if(max2i!=-1)
		printf("%s %s\n",studenti[max2i].prezime,studenti[max2i].ime);
	if(max3i!=-1)
		printf("%s %s\n",studenti[max3i].prezime,studenti[max3i].ime);
	return vel;
}	
int main() {
	// Kraci program za provjeru tacnosti zadatka.
	struct Student studenti[6] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 6, 6.5);
return 0;
}
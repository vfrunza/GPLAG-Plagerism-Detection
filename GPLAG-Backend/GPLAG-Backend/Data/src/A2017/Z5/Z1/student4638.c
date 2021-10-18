#include <stdio.h>

void unesi(char niz[], int velicina)
{
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
struct Datum {
	int dan, mjesec, godina;
};
struct Datum unesi_datum()
{
	struct Datum d;
	printf("Datum: ");
	scanf("%d, %d, %d", &d.dan, &d.mjesec, &d.godina);
	return d;
}
int prestupna(int godina)
{
	if(godina%4==0 && godina%100!=0 || godina%400==0)
		return 1;
	return 0;
}
int broj_dana(struct Datum d)
{
	int ukupno=0, i;
	int bdum[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for(i=1; i<d.godina; i++) {
		ukupno+=365+prestupna(i);
	}
	if(prestupna(d.godina)) bdum[2]++;
	for(i=1; i<d.mjesec; i++) {
		ukupno+=bdum[i];
		ukupno+=d.dan;
	}
	return ukupno;
}

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

struct Uposlenik unesi_uposlenika()
{
	int i=0;
	char ime_prezime[50];
	struct Uposlenik kandidati[100];
	printf("Unesite ime, prezime i datum rodjena kandidata: ");
	kandidati[i].ime_prezime=unesi(ime_prezime, 50);
	kandidati[i].datum_rodjenja=unesi_datum();
	i++;
	return kandidati[i];
}
//int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana)  /*glavna f-ija*/
//{

//}

int main()
{
	int i, vel=0;
	struct Uposlenik kandidati[100];
	struct Uposlenik direktor;
	
	printf("Unesite podatke od direktoru: ");
	direktor=unesi_uposlenika();
	
	printf("Unesite podatke o kandidatima: ");
	for(i=0; i<100; i++){
		kandidati[i]=unesi_uposlenika();
		i++;
	}
	vel=i;
	//printf("Nakon suzenja liste: ");
	//suzi_listu(kandidati, vel, direktor, )
	return 0;
}

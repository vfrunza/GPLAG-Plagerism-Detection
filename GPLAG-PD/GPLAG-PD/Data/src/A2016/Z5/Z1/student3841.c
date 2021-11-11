#include <stdio.h>
#include <string.h>

struct Student
{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/*POMOCNA FUNKCIJA ZA RACUNANJE PROSJEKA OCJENA JEDNOG STUDENTA*/
double prosjek_ocjena(int ocjene[], int br_ocjena)
{
	double prosjek1 = 0, suma = 0;
	int i = 0;
	
	if(br_ocjena == 0)
		return 5.0;
		
	for(i = 0; i < br_ocjena; i++)
	{
		if(ocjene[i] == 5)
		{
			prosjek1 = 5.0;
			return prosjek1;
		}
			
		suma += ocjene[i];
	}	
	
	prosjek1 = suma / br_ocjena;
	
	return prosjek1;
}
/*FUNKCIJA ZA POREDJENJE DVA STUDENTA PO KRITERIJU*/
int kriterij(struct Student prvi, struct Student drugi)
{
	double p1, p2;
	
	p1 = prosjek_ocjena(prvi.ocjene, prvi.br_ocjena); /*prosjek ocjena prvog studenta*/
	p2 = prosjek_ocjena(drugi.ocjene, drugi.br_ocjena); /*prosjek ocjena drugog studenta*/
	
	if(p1 > p2) /*ako je prosjek prvog veci od prosjeka drugog prvi je bolji*/
		return 1;
		
	if(p1 < p2) /*ako je prosjek drugog veci od prosjeka prvog onda je bolji drugi student*/
		return 0;
		
	if(strcmp(prvi.prezime, drugi.prezime) < 0) /*prvi bolji tj abecedno prije drugog po prezimenu (isti prosjek)*/
		return 1;
		
	else if(strcmp(prvi.prezime, drugi.prezime) > 0) /*drugi je prije abecedno*/
		return 0;
		
	if(strcmp(prvi.ime, drugi.ime) < 0) /*ako su prezimena ista gleda se cije je ime abecedno prije*/
		return 1;
		
	else 
		return 0;
}

int genijalci(struct Student studenti[], int velicina, double prosjek)
{
	double pr;
	int i = 0, j = 0, i1 = 0, i2 = -1, i3 = -1;
	
	for(i = 0; i < velicina; i++)
	{
		pr = prosjek_ocjena(studenti[i].ocjene, studenti[i].br_ocjena);
		
		if(pr < prosjek)
		{
			for(j = i; j < velicina - 1; j++) /*izbacuje studente ciji je prosjek manji od parametra funkcije*/
				studenti[j] = studenti[j + 1];
				
			velicina--;
			i--;
		}
	}
	
	if(velicina == 0)  /*ako su izbaceni svi studenti nema sta ispisivati tj prekid funkcije*/
		return 0;
		
	/*trazi se prvi student*/
	for(i = 0; i < velicina; i++)
		if(kriterij(studenti[i], studenti[i1]))
			i1 = i;
	
	/*postavljanje indeksa drugog studenta na neku vrijednost koja nije i1*/
	for(i = 0; i < velicina; i++)
		if(i != i1)
			i2 = i;
	
	/*ako postoji drugi najbolji*/
	if(i2 != -1)
	{
		/*trazenje drugog najboljeg*/
		for(i = 0; i < velicina; i++)
			if(kriterij(studenti[i], studenti[i2]) && i != i1)
				i2 = i;
		
		/*postavljanje indeksa treceg na neku vrijednost koja nije ni i1 ni i2*/
		for(i = 0; i < velicina; i++)
			if(i != i2 && i != i1)
				i3 = i;
		
		/*ukoliko postoji treci student*/
		if(i3 != -1)
			for(i = 0; i < velicina; i++) /*trazenje treceg studenta*/
				if(kriterij(studenti[i], studenti[i3]) && i != i2 && i != i1)
					i3 = i;
	}
	
	printf("%s %s\n", studenti[i1].prezime, studenti[i1].ime);  /*ispisivanje prvog studenta*/
	
	if(i2 != -1)
		printf("%s %s\n", studenti[i2].prezime, studenti[i2].ime); /*ispisivanje drugog ukoliko on postoji*/
		
	if(i3 != -1)
		printf("%s %s\n", studenti[i3].prezime, studenti[i3].ime); /*ispisivanje treceg ukoliko postoji*/
		
	return velicina;
}

int main() 
{
	/*printf("Zadaća 5, Zadatak 1");*/
	
	struct Student studenti[6] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};

	printf("%d ", kriterij(studenti[0], studenti[5]));
	return 0;
}

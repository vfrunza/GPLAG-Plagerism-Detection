#include <stdio.h>
#include <math.h>


struct Datum
{
	int dan, mjesec, godina;
};

struct Uposlenik
{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int PretvoriUDane(struct Datum dat)
{   
	int i;
	int dani=dat.dan;
	int mjes=0;
	int god=0;
	int Mjeseci[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if((dat.godina%4==0 && dat.godina%100!=0) || dat.godina%400==0) Mjeseci[1]++;


	for(i=0;i<dat.mjesec-1;i++)
		mjes+=Mjeseci[i];
	
	for(i=1800;i<dat.godina;i++)
		if((i%4==0 && i%100!=0) || i%400==0)
			god+=366;
		else god+=365;
		
	return god+mjes+dani;	
}


int Razlika(struct Uposlenik kandidat,struct Uposlenik direktor)
{
	int x,y;
	
	x=PretvoriUDane(kandidat.datum_rodjenja);
	y=PretvoriUDane(direktor.datum_rodjenja);
	
	return y-x;
}


int JesuFamilija(struct Uposlenik kandidat,struct Uposlenik direktor)
{   
	
	
	char *kand=kandidat.ime_prezime;
	char *dir=direktor.ime_prezime;
	
	while(*kand!='\0')
		kand++;
	while(*dir!='\0')
		dir++;
		
	
	kand--;dir--;

	while(*kand!=' ' &&  *dir!=' '){
		
		if(*kand!=*dir) return 0;
		kand--;
		dir--;
		if(*kand==' ' || *dir==' ') break;
	}
	
	
		
	return 1;
}


int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	
	int i,j;
	int razlika;

	for(i=0;i<vel;i++)
	{
		
	   razlika=Razlika(kandidati[i],direktor);
		
		if(razlika>broj_dana && !(JesuFamilija(kandidati[i],direktor)))
			{
				for(j=i;j<vel-1;j++)
				{
					kandidati[j]=kandidati[j+1];
				}
				i--;
				vel--;
			}
		
	}
	
	
	return vel;
}

int main() {
/* AT10: Nova godina */
struct Uposlenik direktor = {"Mujo Mujic", {3, 1, 1982} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 12, 1981 } },
    { "Pero Peric", { 1, 2, 1980 } },
    { "Sara Sarac", { 2, 2, 1980 } },
    { "Fata Mujicic", { 1, 2, 1976 } },
    { "Jozo Jozic", { 1, 1, 1982 } },
    { "Mijo Mijic", { 4, 3, 1979 } },
    { "Suljo Suljic", { 30, 12, 1981 } },
};

/* Meho Mehic je za 3 dana stariji, a Suljo Suljic za 4 dana */

int novi_br = suzi_listu(kandidati, 7, direktor, 3);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}

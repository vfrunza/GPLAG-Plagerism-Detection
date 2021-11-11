#include <stdio.h>
#include <string.h>
#define EPSILON 0.0001
struct Student
{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};
/*prosjek svakog studenta pojedinacno
u zavisnosti od broja ocjena*/
float prosjek(int niz[],int vel)
{
	int i=0,suma=0;
	float prosjek;
	if(vel==0)
		return 5;
	for(i=0;i<vel;i++)
	{
		/*ako ima ijednu 5 pao je*/
		if(niz[i]==5)
			return 5;
		suma+=niz[i];
	}
	prosjek=(float)suma/vel;
	return prosjek;
	
}
/*vraca 1 ako prvi treba bit
ispred drugog odnosno 0 ako ne*/
int dalijeveci(struct Student pr,struct Student dr)
{
	if(prosjek(pr.ocjene,pr.br_ocjena)>prosjek(dr.ocjene,dr.br_ocjena))
		return 1;
	else if(prosjek(pr.ocjene,pr.br_ocjena)<prosjek(dr.ocjene,dr.br_ocjena))
		return 0;
	/*prosjek im je jednak ako se 
	funkcija nije prekinula do sada
	pa gledamo prezimena*/
	if(strcmp(pr.prezime,dr.prezime)>0)
		return 0;
	else if(strcmp(pr.prezime,dr.prezime)<0)
		return 1;
	if(strcmp(pr.ime,dr.ime)>0)
		return 0;
	else if(strcmp(pr.ime,dr.ime)<0)
		return 1;
	/*ako su jednaki prosjeci 
	svejedno sta se vraca*/
	else return 1;
}
int ind(struct Student niz[],int vel,double prosjekk)
{
	int i;
	int indexmin=0;
	double min=10;
	float temp;
	for(i=0;i<vel;i++)
	{
		temp=prosjek(niz[i].ocjene,niz[i].br_ocjena);
		if(min-temp>EPSILON)
		{
			min=temp;
			indexmin=i;
		}
	}
	return indexmin;
}
int izb(struct Student niz[],int vel,double prosjekk)
{
	int i,j;
	for(i=0;i<vel;i++)
	{
		/*ako je nas prosjek manji od 
		zadanog moramo ga izbaciti*/
		if(prosjekk-prosjek(niz[i].ocjene,niz[i].br_ocjena) > EPSILON)
		{
			for(j=i;j<vel-1;j++)
			{
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}

void ispis(struct Student niz[],int vel,double prosjekk,int indexmin)
{
	int i,indexprvi,indexdrugi=0,indextreci,vr;
	if(vel>0)
	{
		/*indexmin prije smo nasli vec ranije*/
		indexprvi=indexmin;
		for(i=0;i<vel;i++)
		{
			vr=dalijeveci(niz[i],niz[indexprvi]);
			if(vr==1)
			/*patmimo najveceg studenta 
			da bi ga mogli preskocit slj. put*/
			indexprvi=i;
		}
		if(i>0)
		/*printamo naj studenta*/
		printf("\n%s %s\n",niz[indexprvi].prezime,niz[indexprvi].ime);
	}
	if(vel>1)
	{
		indexdrugi=indexmin;
		for(i=0;i<vel;i++)
		{
			if(i==indexprvi)
				continue;
			vr=dalijeveci(niz[i],niz[indexdrugi]);
			if(vr==1)
				indexdrugi=i;
		}
	printf("%s %s\n",niz[indexdrugi].prezime,niz[indexdrugi].ime);
	}
	if(vel>2)
	{
		indextreci=indexmin;
		for(i=0;i<vel;i++)
		{
			if(i==indexprvi || i==indexdrugi)
				continue;
			vr=dalijeveci(niz[i],niz[indextreci]);
			if(vr==1)
			indextreci=i;
		}
		if(i>0)
		printf("%s %s\n",niz[indextreci].prezime,niz[indextreci].ime);
	}
}
int genijalci(struct Student niz[],int vel,double prosjekk)
{
	int indexmin=0;
	vel=izb(niz,vel,prosjekk);
	indexmin=ind(niz,vel,prosjekk);
	ispis(niz,vel,prosjekk,indexmin);
	return vel;
}
int main() {
	struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 10, 10, 10, 10, 5}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 5, 6.5);

	return 0;
}

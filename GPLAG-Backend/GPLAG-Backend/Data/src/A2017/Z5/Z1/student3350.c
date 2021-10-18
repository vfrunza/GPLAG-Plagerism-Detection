#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void unesi_ime(char niz[],int vel)
{
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while (i<vel-1&znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
int broj_rijeci(char *p)
{
	int razmak=1,br=0;
	while (*p!='\0') {
		if(*p==' ') razmak=1;
		else if(razmak==1) 
		{
			razmak=0;
			br++;
		}
		p++;
	}	
	return br;
}
struct Datum {
	int dan;
	int mjesec;
	int godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
struct Uposlenik unesi()
{
	struct Uposlenik u;
	printf("Unesite ime i prezime: ");
	unesi_ime(u.ime_prezime,50);
	printf("Unesite datum rodjenja: ");
	scanf("%d%d%d",&u.datum_rodjenja.dan,&u.datum_rodjenja.mjesec,&u.datum_rodjenja.godina);
	return u;
}
int suzi_listu(struct Uposlenik* kandidati,int vel,struct Uposlenik direktor,int broj_dana)
{
	struct Uposlenik *pocetak=kandidati;
	struct Uposlenik *kraj=kandidati+vel;
	struct Uposlenik *pom=kandidati;
	char *s=direktor.ime_prezime,*q;
	int godine_direktora=2018-direktor.datum_rodjenja.godina,brojac=0,br=0;
	int i=0,b=0,t=0,b_uposlenik,b_direktor,j=0,y=0,size,var=0,k,x;
	char niz[30],niz1[30];
	int dani_d=0,dani_k=0,velicina;
	int mjeseci_prestupna[12]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int mjeseci_neprestupna[11]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int niz_godina[100],niz_godina_kandidati[100],suma_dana=0,suma_dana_kandidati=0,duzina,duzina_kandidati;
	int broj_slova_direktor=0,broj_slova_kandidat=0;
	b_direktor=broj_rijeci(direktor.ime_prezime);
			while(direktor.datum_rodjenja.godina+1+i!=2018)
			{
				niz_godina[i]=direktor.datum_rodjenja.godina+1+i;
				i++;
			}
			duzina=i;
			i=0;
		for(k=0;k<duzina;k++)
		{
			if(niz_godina[k]%4==0) suma_dana+=366;
			else suma_dana+=365;
		}
		if(direktor.datum_rodjenja.godina%4==0)
		{
			if(direktor.datum_rodjenja.mjesec==12)	suma_dana+=0;
			else
			{
			for(j=direktor.datum_rodjenja.mjesec+1;j<13;j++)
				suma_dana+=mjeseci_prestupna[j];
			}
			suma_dana+=mjeseci_prestupna[direktor.datum_rodjenja.mjesec]-direktor.datum_rodjenja.dan;
		}
		else
		{
			if(direktor.datum_rodjenja.mjesec==12)	suma_dana+=0;
			else
			{
			for(j=direktor.datum_rodjenja.mjesec+1;j<13;j++)
				suma_dana+=mjeseci_neprestupna[j];
			}	
			suma_dana+=mjeseci_neprestupna[direktor.datum_rodjenja.mjesec]-direktor.datum_rodjenja.dan;
		}
	if(b_direktor==3)
	{
		while (*s!='\0') {
			if(*s==' ') b++;
			if(b==2) 
			{
				s++;
				niz[i]=*s;
				i++;
				t=1;
				broj_slova_direktor++;
			}
			if(t==1) niz[i]='\0';
		 	else 	s++;
		}
	}
	if(b_direktor==2)
	{
		while (*s!='\0') {
			if(*s==' ') b++;
			if(b==1)
			{
				s++;
				niz[i]=*s;
				i++;
				t=1;
				broj_slova_direktor;
			}
			if(t) niz[i]='\0';
			else s++;
		}
	}
	b=0;
	t=0;
	 k=0;
	printf("Broj dana direktora: %d",suma_dana);
	printf("\nPrezime direktora: ");
	for(k=0;k<i;k++)
		printf("%c",niz[k]);
			 i=0;
	while (y!=vel) {
			while(kandidati->datum_rodjenja.godina+1+i!=2018)
			{
				niz_godina_kandidati[i]=kandidati->datum_rodjenja.godina+1+i;
				i++;
			}
			duzina_kandidati=i;
		for(k=0;k<duzina_kandidati;k++)
		{
			if(niz_godina_kandidati[k]%4==0) suma_dana_kandidati+=366;
			else suma_dana_kandidati+=365;
		}
		if(kandidati->datum_rodjenja.godina%4==0)
		{
			if(kandidati->datum_rodjenja.mjesec==12)	suma_dana+=0;
			else
			{
			for(j=kandidati->datum_rodjenja.mjesec+1;j<13;j++)
				suma_dana_kandidati+=mjeseci_prestupna[j];
			}	
			suma_dana_kandidati+=mjeseci_prestupna[kandidati->datum_rodjenja.mjesec]-kandidati->datum_rodjenja.dan;
		}
		else(kandidati->datum_rodjenja.godina%4!=0);
		{
			if(kandidati->datum_rodjenja.mjesec==12) suma_dana+=0;
			else
			{
			for(j=kandidati->datum_rodjenja.mjesec+1;j<13;j++)
				suma_dana_kandidati+=mjeseci_neprestupna[j];
			}
			suma_dana_kandidati+=mjeseci_neprestupna[kandidati->datum_rodjenja.mjesec]-kandidati->datum_rodjenja.dan;
		}
		printf("\nNiz godina: ");
				for(x=0;x<duzina_kandidati;x++)
					printf("%d ",niz_godina_kandidati[x]);
		j=0;
		printf("\nBroj dana kandidata: %d",suma_dana_kandidati);
		suma_dana_kandidati=0;
		i=0;
	q=kandidati->ime_prezime;
	b_uposlenik=broj_rijeci(kandidati->ime_prezime);
	if(b_uposlenik==3)
	{
		while (*q!='\0') {
			if(*q==' ') b++;
			if(b==2) 
			{
				q++;
				niz1[j]=*q;
				j++;
				t=1;
				broj_slova_kandidat++;
			}
			if(t==1) niz1[j]='\0';
		 	else 	q++;
		}
	}
	t=0;
	if(b_uposlenik==2)
	{
		while (*q!='\0') {
			if(*q==' ') b++;
			if(b==1)
			{
				q++;
				niz1[j]=*q;
				j++;
				t=1;
				broj_slova_kandidat++;
			}
			if(t==1) niz1[j]='\0';
		 	else 	q++;
		}
		niz1[j]='\0';
	}
	t=0;
	pom=kandidati;
	kraj=kandidati+vel;
	pocetak=kandidati+1;

		if(broj_slova_kandidat==broj_slova_direktor)
		{
			for(i=0;i<broj_slova_direktor;i++)
			{
				if(niz[i]!=niz1[i])
				t=1;
			}
		}
		if(t==1)
		{
			while (pom!=kraj) {
				kandidati=pocetak;
				kandidati++;
				pocetak++;
				pom++;
			}
			vel--;
		}
	int l;
	s=niz;
	q=niz1;
	pom=kandidati;
	kraj=kandidati+vel;
	printf("\nPrezime radnika: ");
	for(i=0;i<j;i++)
		printf("%c",niz1[i]);
		b_uposlenik=0;
		t=0;
		b=0;
		j=0;
		kandidati++;
		y++;
	}
	printf("\nVelicina: %d",vel);
	return vel;
}
int main() {
	int i,god,p,x;
	struct Uposlenik kandidati[2];
	struct Uposlenik direktor;
	for(i=0;i<2;i++)
		kandidati[i]=unesi(kandidati[i]);
	direktor=unesi(direktor);
	printf("Unesite x: ");
	scanf("%d",&x);
	p=suzi_listu(kandidati,2,direktor,x);
	printf("\nP = %d",p);
	return 0;
}

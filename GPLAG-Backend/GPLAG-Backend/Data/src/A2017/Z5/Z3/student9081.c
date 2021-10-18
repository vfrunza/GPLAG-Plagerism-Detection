#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};
double obim(struct Oblik o)
{
	int i;
	double ob=0;
	for (i=0; i<o.br_stranica; i++)
		ob+=o.stranice[i];
	return ob;

}
struct Oblik daj_najveci()
{
	FILE *dat;
	struct Oblik niz[500];
	struct Oblik max;
	unsigned short broj_oblika;
	unsigned char temp;
	float temp2;
	int i,j;
	dat=fopen("oblici.dat","rb");
	if (dat==NULL)
		exit(1);
	/*Ucitamo broj oblika,koji zauzima 2 bajta, da koristimo unsigned short,i tako znamo broj slogova*/
	fread(&broj_oblika,sizeof(unsigned short),1,dat);
	for (i=0; i<broj_oblika; i++) {
		/*Ucitamo string*/
		fread(niz[i].naziv,sizeof(char),20,dat);
		/*Broj stranica je u strukturi tipa int,ali ovdje zauzima 1 bajt, pa koristimo pomocnu varijablu tipa unsigned char*/
		fread(&temp,sizeof(unsigned char),1,dat);
		niz[i].br_stranica=temp;
		/*Slicno koristimo pomocnu varijablu tipa float*/
		for (j=0; j<temp; j++) {
			fread(&temp2,sizeof(float),1,dat);
			niz[i].stranice[j]=temp2;
		}
	}
	fclose(dat);
	max=niz[0];
	/*Uz pomoc pomocne funkcije,izbacujemo one koji imaju najveci obim*/
	for(i=0; i<broj_oblika; i++) {
		for (j=i+1; j<broj_oblika; j++) {
			if (obim(niz[j])>obim(max))
				max=niz[j];
		}
	}
	return max;
}
void dodaj_oblik (struct Oblik o)
{
	FILE *dat;
	struct Oblik niz[500];
	int i,j;
	unsigned char temp;
	unsigned short broj_oblika;
	float temp2;
	/*Ucitamo sadrzaj datoteke da bismo znali broj oblika*/
	dat=fopen("oblici.dat","rb");
	if (dat==NULL)
		exit(1);
	fread(&broj_oblika,sizeof(unsigned short),1,dat);
	for (i=0; i<broj_oblika; i++) {
		fread(niz[i].naziv,sizeof(char),20,dat);
		fread(&temp,sizeof(unsigned char),1,dat);
		niz[i].br_stranica=temp;
		for (j=0; j<temp; j++) {
			fread(&temp2,sizeof(float),1,dat);
			niz[i].stranice[j]=temp2;
		}
	}
	fclose(dat);
	/*Povecamo broj oblika za jedan,na posljednje mjesto u nizu ucitamo novu strukturu*/
	niz[broj_oblika]=o;
	broj_oblika++;
	dat=fopen("oblici.dat","wb");
	/*Ucitamo sve clanove strukture tj.niza iz pocetka,brisuci stari sadrzaj*/
	if (dat==NULL)
		exit(1);
	fwrite(&broj_oblika,sizeof(unsigned short),1,dat);
	for (i=0; i<broj_oblika; i++) {
		fwrite(niz[i].naziv,sizeof(char),20,dat);
		temp=niz[i].br_stranica;
		fwrite(&temp,sizeof(unsigned char),1,dat);
		for (j=0; j<temp; j++) {
			temp2=niz[i].stranice[j];
			fwrite(&temp2,sizeof(float),1,dat);
		}
	}
	fclose(dat);
}
void izbaci_duple ()
{
	FILE *dat;
	struct Oblik niz[500];
	unsigned short broj_oblika;
	unsigned char temp;
	float temp2;
	int i,j,k;
	dat=fopen("oblici.dat","rb");
	if (dat==NULL)
		exit(1);
	/*Slicno, ucitamo sve podatke u niz strukture Oblik*/
	fread(&broj_oblika,sizeof(unsigned short),1,dat);
	for (i=0; i<broj_oblika; i++) {
		fread (niz[i].naziv,sizeof(char),20,dat);
		fread(&temp,sizeof(unsigned char),1,dat);
		niz[i].br_stranica=temp;
		for (j=0; j<temp; j++) {
			fread(&temp2,sizeof(float),1,dat);
			niz[i].stranice[j]=temp2;
		}
	}
	fclose(dat);
	/*Iz tog niza izbacujemo sve one koje ne odgovaraju uslovu zadatka*/
	for (i=0; i<broj_oblika; i++) {
		for (j=i+1; j<broj_oblika; j++) {
			if (strcmp(niz[i].naziv,niz[j].naziv)==0) {
				for (k=j; k<broj_oblika-1; k++)
					niz[k]=niz[k+1];
				broj_oblika--;
				j--;
			}
		}
	}
	/*Ucitamo datoteku iz pocetka*/
	dat=fopen("oblici.dat","wb");
	if (dat==NULL)
		exit(1);
	fwrite(&broj_oblika,sizeof(unsigned short),1,dat);
	for (i=0; i<broj_oblika; i++) {
		fwrite(niz[i].naziv,sizeof(char),20,dat);
		temp=niz[i].br_stranica;
		fwrite(&temp,sizeof(unsigned char),1,dat);
		for (j=0; j<temp; j++) {
			temp2=niz[i].stranice[j];
			fwrite(&temp2,sizeof(float),1,dat);
		}
	}
	fclose(dat);

}
int main()
{
	return 0;
}
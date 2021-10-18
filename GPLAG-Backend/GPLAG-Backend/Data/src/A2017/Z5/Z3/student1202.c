#include <stdio.h>
#include <string.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};
double obim(struct Oblik o)
{
	double t = 0;
	while (o.br_stranica-- > 0) t += o.stranice[o.br_stranica];
	return t;
}
int ucitaj(struct Oblik *o, FILE *f)
{
	int i = 0;
	float a = 0;
	unsigned char c = 0;
	o->br_stranica = 0;
	if (fread(o->naziv, 1, 20, f) == 20 && fread(&c, 1, 1, f) == 1) {
		o->br_stranica = (int) c;
		while (i < c && fread(&a, 4, 1, f) == 1)
			o->stranice[i++] = (double) a;
		return 1;
	}
	return 0;
}
int dodaj_oblik(struct Oblik o)
{
	FILE *f = fopen("oblici.dat", "rb+");
	struct Oblik tmp;
	float a;
	unsigned short n = 0;
	unsigned char c = 0;
	int i = 0;
	if (!f) f = fopen("oblici.dat", "wb+");
	if (!f) return 1;
	//Ako fajl ne sadrzi prva 2 bajta za broj oblika, dodajemo ih
	if (fread(&n, 2, 1, f) != 1) n=1;
	else n++;
	fseek(f, 0, SEEK_SET);
	fwrite(&n, 2, 1, f);
	while (i++ < n-1 && ucitaj(&tmp, f));
	if (!f) return 1;
	c = (unsigned char) o.br_stranica;
	if (fwrite(o.naziv, 1, 20, f) == 20 && fwrite(&c, 1, 1, f) == 1) {
		i = 0;
		while (i < c) {
			a = (float) o.stranice[i];
			fwrite(&a, 4, 1, f);
			i++;
		}
	} else {
		fclose(f);
		return 1;
	}
	fclose(f);
	return 0;
}
int izbaci_duple()
{
	struct Oblik ref, oblik, tmp;
	long pocetak = 0, kraj, eof, i = 0, pocetak_ref = 0;
	char c;
	unsigned short n;
	FILE *f = fopen("oblici.dat", "rb+");
	if (!f) return 1;
	fread(&n, 2, 1, f);
	while (i++ < n && ucitaj(&tmp, f));
	eof = ftell(f);
	fseek(f, 2, SEEK_SET);
	i = 0;
	pocetak_ref = ftell(f);
	//Referentni oblik
	while (pocetak_ref < eof && ucitaj(&ref, f)) {
		pocetak_ref = pocetak = ftell(f);
		//Prolazi kroz sve preostale oblike
		while (pocetak < eof && ucitaj(&oblik, f)) {
			kraj = ftell(f);
			if (!strcmp(oblik.naziv, ref.naziv)) { //Isti naziv, potrebno izbaciti
				n--;
				while (ftell(f) < eof && fread(&c, 1, 1, f) == 1) {
					fseek(f, pocetak - kraj - 1, SEEK_CUR);
					fwrite(&c, 1, 1, f);
					fseek(f, kraj - pocetak, SEEK_CUR);
				} //Prepisuje sve podatke ostatka fajla ulijevo
				eof -= kraj - pocetak;
				fseek(f, pocetak, SEEK_SET);
			} else pocetak = kraj;
		}
		fseek(f, pocetak_ref, SEEK_SET);
	}
	fseek(f, 0, SEEK_SET);
	fwrite(&n, 2, 1, f);
	fclose(f);
	return 0;
}
struct Oblik daj_najveci()
{
	struct Oblik ret, lok;
	double najveci = 0;
	unsigned short n = 0, i = 0;
	FILE *f = fopen("oblici.dat", "rb");
	if (!f) return ret;
	if (fread(&n, 2, 1, f) != 1) return ret;
	while (i++ < n && ucitaj(&lok, f))
		if (obim(lok) > najveci) najveci = obim(ret = lok);
	fclose(f);
	return ret;
}
int main()
{
	return 0;
}
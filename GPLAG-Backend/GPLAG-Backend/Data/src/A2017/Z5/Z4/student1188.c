#include <stdio.h>

struct Prodavnica{
	char naziv[100];
	int ID;
};
struct Artikal{
	char naziv[100];
	double cijena;
	int prodavnica;	
};

int ucitaj_artikle(struct Artikal *niz, int kap){
	int ucitani=0;
	FILE *dat=fopen("artikli.bin", "rb");
	if(!dat){
		printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	ucitani=fread(niz, sizeof(struct Artikal), kap, dat);
	fclose(dat);
	return ucitani;
}
int ucitaj_prodavnice(struct Prodavnica *niz, int kap){
	int ucitane=0, i, j;
	FILE *dat=fopen("prodavnice.txt", "r");
	if(!dat){
		printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	for(j=0; j<kap; j++){
		int tmp;
		i=-1;							 /* pojednost. uslov do-while petlje */
		do{
			if(i<99) i++; 			/* i ne smije izaći van dekl vel stringa */
			niz[j].naziv[i]=fgetc(dat);		 /* ako je ime duze od 99 charova*/
		}while(niz[j].naziv[i]!=',' && niz[j].naziv[i]!=EOF);
		niz[j].naziv[i]='\0';   					   /* terminiramo string */
		
		tmp=fscanf(dat, "%d\n", &niz[j].ID);
		if(tmp == 0) break;
		else if(tmp == 1) ucitane++;
	}
	
	fclose(dat);
	return ucitane;
}
int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na){
	double suma[100]={0}, prosjek=0, br_artikala[100]={0};
	int i, j;
	for(i=0; i<na; i++){
		j=a[i].prodavnica-1; /* ID prodavnice-1 da bi suma počela od indeksa 0*/
		suma[j]+=a[i].cijena;
		br_artikala[j]++;
	}
	for(j=0; j<np; j++)	prosjek+=suma[j];
	if(np!=0) prosjek/=na;
	
	for(j=0; j<np; j++)
		if(br_artikala[j] != 0) suma[j]/=br_artikala[j];
	
	for(i=0; i<np; i++){
		j=p[i].ID-1;
		if(suma[j]>prosjek){
			int k;
			for(k=i+1; k<np; k++){
				p[k-1]=p[k];
			}
			np--;
			i--;
		}
	}
	
	return np;
}
int sacuvaj(struct Prodavnica *p, int n, const char *ime_datoteke){
	FILE* dat=fopen(ime_datoteke, "wb");
	if(dat==NULL) return 0;
	
	fwrite(p, sizeof(struct Prodavnica), n, dat);
	if(ferror(dat))	return 0;
	fclose(dat);
	return 1;
}
int main() {
	struct Prodavnica p[]={
		{"Konzum", 2},
		{"Amko", 1},
		{"Bingo", 3},
	};
	struct Artikal n[]={
		{"Brasno", 5.2, 1},
		{"Ulje", 2, 1},
		{"Secer", 1.5, 1},
		{"Brasno", 5.2, 2},
		{"Ulje", 2.1, 2},
		{"Secer", 2.2, 2},
		{"Brasno", 5.2, 3},
		{"Ulje", 1.1, 3},
		{"Secer", 1.2, 3},
		{"Grah", 5, 3}
	};
	int novavel=izbaci_skupe(p, 3, n, 10), i;
	for(i=0; i<novavel; i++)
		printf("'%s', id: %d\n", p[i].naziv, p[i].ID);
	return 0;
}

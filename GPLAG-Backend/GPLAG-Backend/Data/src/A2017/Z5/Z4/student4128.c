#include <stdio.h>
#include <string.h>

struct Prodavnica {
	char naziv[100];
	int ID;				
};

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;		
};

int ucitaj_artikle (struct Artikal *niz, int kap){
	FILE*dat = fopen("artikli.bin","rb");
	int ucitanih;
	if(dat==NULL){
		printf("Greska prilikom otvaranja datoteke!");
		return -1;
	}
	ucitanih = fread(niz,sizeof(struct Artikal),kap,dat);
	fclose(dat);
	return ucitanih;
}

int ucitaj_prodavnice (struct Prodavnica *niz, int kap){
	FILE*dat = fopen("prodavnice.txt","r");
	char znak;
	char naziv[100];
	int broj_ucitanih=0,i;
	if(dat==NULL){
		printf("Greska prilikom otvaranja datoteke!");
		return -1;
	}
	while((znak=fgetc(dat))!=EOF&&broj_ucitanih<kap){
		i=0;
		naziv[i++]=znak;
		while((znak=fgetc(dat))!=','){
			if(i==99)continue;
			naziv[i++]=znak;
		}
		naziv[i]='\0';
		strcpy(niz[broj_ucitanih].naziv,naziv);
		fscanf(dat,"%d\n",&niz[broj_ucitanih].ID);
		broj_ucitanih++;
	}
	fclose(dat);
	return broj_ucitanih;
}


int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na){
	double suma=0,prosjek_svih_artikala,prosjek_prodavnice;
	int i,j, broj_artikala=0;
	for ( i = 0; i < na; i++) {
		suma+=a[i].cijena;
	}
	prosjek_svih_artikala = suma/na;
	

	
	for ( i = 0; i < np; i++) {
		broj_artikala=0;
		suma=0;
		for (j = 0; j < na; j++) {
			if(a[j].prodavnica==p[i].ID){
				suma+=a[j].cijena;
				broj_artikala++;
			}
		}
		if(suma==0)continue;
		prosjek_prodavnice = suma/broj_artikala;
		if(prosjek_prodavnice>prosjek_svih_artikala){
			for (j = i; j < np-1; j++) {
				p[j]=p[j+1];
			}
			i--;
			np--;
		}
	}
	return np;
}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke){
	FILE*dat = fopen(ime_datoteke,"wb");
	if(dat==NULL){
		printf("Greska prilikom otvaranja datoteke!");
		return 0;
	}
	
	fwrite(p,sizeof(struct Prodavnica),n,dat);
	
	fclose(dat);
	
	return 1;
}
int main() {
	
	struct Artikal artikli[300];
	struct Prodavnica prodavnice[10];
	int i,broj_ucitanih,uspjesno_sacuvana;
	int ucitanih = ucitaj_artikle(artikli,10);
	printf("%d",ucitanih);
	for ( i = 0; i < ucitanih; i++) {
		printf("Naziv: %s, cijena:%f, ID:%d\n",artikli[i].naziv,artikli[i].cijena, artikli[i].prodavnica);
	}
	

	
	 broj_ucitanih=ucitaj_prodavnice(prodavnice,10);
	printf("Broj ucitanih %d\n",broj_ucitanih);
	for(i=0;i<broj_ucitanih;i++){
		printf("Naziv:%s,",prodavnice[i].naziv);
		printf("ID:%d\n",prodavnice[i].ID);
	}
	
	broj_ucitanih = izbaci_skupe(prodavnice,broj_ucitanih,artikli,ucitanih);
	printf("\nNAKON IZBACIVANJA:\n");
		printf("Broj ucitanih %d\n",broj_ucitanih);
	for(i=0;i<broj_ucitanih;i++){
		printf("Naziv:%s,",prodavnice[i].naziv);
		printf("ID:%d\n",prodavnice[i].ID);
	}
	
	uspjesno_sacuvana = sacuvaj(prodavnice,broj_ucitanih,"povoljne.bin");
	if(uspjesno_sacuvana){
		printf("Povoljne prodavnice su spasene u datoteci povoljne.bin!");
	}
	else{
		printf("Doslo je do greske prilikom otvaranja datoteke povoljne.bin!");
	}
	
	
	return 0;
}

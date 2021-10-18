#include <stdio.h>
#include <string.h>


struct Oblik{
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

int ucitaj(struct Oblik* oblici){
	int i,j;
	unsigned short broj_oblika;
	unsigned char X;
	float str[300];
	FILE* dat = fopen("oblici.dat","rb");

	if(dat==NULL){
		printf("Greska prilikom otvaranja datoteke!\n");
		return 0;
	}
	
	fread(&broj_oblika,2,1,dat);
	
	for ( i = 0; i < broj_oblika; i++) {
		fread(oblici[i].naziv, 1,20,dat);
		fread(&X,1,1,dat);
		oblici[i].br_stranica = X;
		
		fread(str,4,oblici[i].br_stranica,dat);
		for (j = 0; j < oblici[i].br_stranica; j++) {
			oblici[i].stranice[j] = str[j];
		}
	}

	fclose(dat);
	
	return broj_oblika;
}


int upisi(struct Oblik* oblici,int vel){
	int i,j;
	unsigned short broj_oblika=vel;
	unsigned char X;
	float str[300];
	FILE* dat = fopen("oblici.dat","wb");

	if(dat==NULL){
		printf("Greska prilikom otvaranja datoteke!\n");
		return 0;
	}

	fwrite(&broj_oblika,2,1,dat);
	
	for ( i = 0; i < broj_oblika; i++) {
		
		fwrite(oblici[i].naziv, 1,20,dat);

		X = oblici[i].br_stranica ;
		fwrite(&X,1,1,dat);
		

		for (j = 0; j < oblici[i].br_stranica; j++) {
			 str[j]=oblici[i].stranice[j];
		}
		fwrite(str,4,oblici[i].br_stranica,dat);
	}

	fclose(dat);
	
	return broj_oblika;
}


int dodaj_oblik(struct Oblik oblik){
	struct Oblik oblici[1000];
	int broj_oblika = ucitaj(oblici);
	
	oblici[broj_oblika]=oblik;
	broj_oblika++;
	upisi(oblici,broj_oblika);
	
	
	return broj_oblika;
}

int izbaci_duple(){
	struct Oblik oblici[1000];
	int broj_oblika = ucitaj(oblici);
	int i,j,dupli;
	
	for ( i = 1; i < broj_oblika; i++) {
		dupli=0;
		for (j=0; j < i; j++) {
			if(strcmp(oblici[i].naziv,oblici[j].naziv)==0){
				dupli=1;
				break;
			}
				
		}
		
		if(dupli){
				for (j=i; j < broj_oblika-1; j++) {
					oblici[j]=oblici[j+1];
				}
				broj_oblika--;
				i--;
		}
	}
	
	upisi(oblici,broj_oblika);
	
	
	return broj_oblika;
}


double dajObim(struct Oblik oblik){
	double obim = 0;
	int i;
	for ( i = 0; i < oblik.br_stranica; i++) {
		obim+=oblik.stranice[i];
	}
	return obim;
}


struct Oblik daj_najveci(){
	struct Oblik oblici[1000];
	int broj_oblika = ucitaj(oblici);
	int i, imax=0;
	
	
	
	for ( i = 1; i < broj_oblika; i++) {
		if(dajObim(oblici[i]) > dajObim(oblici[imax])){
			imax = i;
		}
	}
	
	return 	oblici[imax];
}
int main() {
	struct Oblik oblici[1000];
	int i,j;
	int broj_oblika = ucitaj(oblici);
	
	
	printf("PRIJE:");
	printf("Broj oblika:%d\n\n",broj_oblika);
	
	
	for ( i = 0; i < broj_oblika; i++) {
		printf("Naziv: %s\n",oblici[i].naziv);
		printf("Broj stranica: %d\n",oblici[i].br_stranica);
		for ( j = 0; j < oblici[i].br_stranica; j++) {
			printf("%f, ",oblici[i].stranice[j]);
		}
		printf("\n\n\n");
	}
	/*
	struct Oblik oblik = {"Kvadrat",4,{9,9,9,9}};
	
	dodaj_oblik(oblik);
	
	
    broj_oblika = ucitaj(oblici);
	
	
	printf("POSLIJE DODAVANJA:");
	printf("Broj oblika:%d\n\n",broj_oblika);
	
	
	for ( i = 0; i < broj_oblika; i++) {
		printf("Naziv: %s\n",oblici[i].naziv);
		printf("Broj stranica: %d\n",oblici[i].br_stranica);
		for ( j = 0; j < oblici[i].br_stranica; j++) {
			printf("%f, ",oblici[i].stranice[j]);
		}
		printf("\n\n\n");
	}
	
	
	izbaci_duple(oblici,broj_oblika);
	
    broj_oblika = ucitaj(oblici);
	
	
	printf("POSLIJE IZBACIVANJA DUPLIH:");
	printf("Broj oblika:%d\n\n",broj_oblika);
	
	
	for ( i = 0; i < broj_oblika; i++) {
		printf("Naziv: %s\n",oblici[i].naziv);
		printf("Broj stranica: %d\n",oblici[i].br_stranica);
		for ( j = 0; j < oblici[i].br_stranica; j++) {
			printf("%f, ",oblici[i].stranice[j]);
		}
		printf("\n\n\n");
	}
	
	
	struct Oblik najveci =  daj_najveci();
	printf("\n\n\nNAJVECI\n\n\n");
	printf("Naziv: %s\n",najveci.naziv);
	printf("Broj stranica: %d\n",najveci.br_stranica);
	for ( j = 0; j < najveci.br_stranica; j++) {
		printf("%f, ",najveci.stranice[j]);
	}
	printf("\n\n\n");*/
	return 0;
}

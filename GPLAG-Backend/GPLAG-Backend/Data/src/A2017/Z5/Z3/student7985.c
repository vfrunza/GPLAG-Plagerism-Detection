#include <stdio.h>
#include <string.h> /* zbog strcmp */
#include <math.h>  /* zbog fabs */
#include <stdlib.h>  /* zbog exit() */ 
#define KAPACITET 1000  /* broj oblika u dat treba biti 65535 */
#define EPS 0.001

struct Oblik{				
	char naziv[20];
	int br_stranica;
	double stranice[300];
};
struct Oblik beze; /*  jer daj_najveci vraca struct Oblik */


void dodaj_oblik(struct Oblik o){
	struct Oblik niz[KAPACITET];
	unsigned short N;
	unsigned char x;
	int i, k, pomN;
	
	FILE *dat=fopen("oblici.dat", "rb");
	if(dat==NULL){
		printf("Greska pri otvaranju datoteke.\n");
		exit(1);
	}
	fread(&N, 2, 1, dat);
	pomN=N;
	for(i=0; i<pomN; i++){
		fread(niz[i].naziv, 1, 20, dat);
		fread(&x, 1, 1, dat);
		niz[i].br_stranica=x;
		for(k=0; k<niz[i].br_stranica; k++){
			float pom;
			fread(&pom, 4, 1, dat);
			niz[i].stranice[k]=pom;
		}
	}
	fclose(dat);
	
	pomN++; /*  jer se u niz dopisuje oblik o */
	strcpy(niz[i].naziv, o.naziv);
	niz[i].br_stranica=o.br_stranica;
	for(k=0; k<o.br_stranica; k++)
		niz[i].stranice[k]=o.stranice[k];
	
	
	dat=fopen("oblici.dat", "wb");
	if(!dat){
		printf("Greska pri otvaranju datoteke.\n");
		exit(1);
	}
	N=pomN;
	fwrite(&N, 2, 1, dat);
	for(i=0; i<pomN; i++){
		fwrite(niz[i].naziv, 1, 20, dat);
		x=niz[i].br_stranica;
		fwrite(&x, 1, 1, dat);
		for(k=0; k<niz[i].br_stranica; k++){
			float tmp=niz[i].stranice[k];
			fwrite(&tmp, 4, 1, dat);
		}
	}
	fclose(dat);
	
}
int PorediNiz(double niz1[], int vel1, double niz2[], int vel2){
	int i, j;
	for(i=0; i<vel1; i++){
		for(j=i+1; j<vel2; j++)
			if(fabs(niz1[i]-niz2[j])<EPS) return 1; 
	} 
	return 0; /*  - ne postoji isti element u nizu1 i nizu2 */
} 
void izbaci_duple(){
	struct Oblik niz[KAPACITET];
	unsigned short N;
	unsigned char x;
	int pomN, i, j, k;
	
	
	FILE *dat=fopen("oblici.dat", "rb"); 
	if(!dat){
		printf("Greska pri otvaranju datoteke.\n");
		exit(1);
	}
	fread(&N, 2, 1, dat);
	pomN=N;
	for(i=0; i<pomN; i++){
		fread(niz[i].naziv, 1, 20, dat);
		fread(&x, 1, 1, dat);
		niz[i].br_stranica=x;
		for(k=0; k<niz[i].br_stranica; k++){
			float pom;
			fread(&pom, 4, 1, dat);
			niz[i].stranice[k]=pom;
		}
	}
	for(i=0; i<pomN; i++){
		for(j=i+1; j<pomN; j++){
			 /* sve ispod je poređenje struktura */
			
			int nazivi_razliciti=strcmp(niz[i].naziv, niz[j].naziv); 
			int stranice_iste=PorediNiz(niz[i].stranice, niz[i].br_stranica, niz[j].stranice, niz[j].br_stranica);
			if(nazivi_razliciti == 0 && niz[i].br_stranica==niz[j].br_stranica && stranice_iste == 0){
				for(k=j+1; k<pomN; k++)		/*  preko j-tog prepisujemo */
					niz[k-1]=niz[k];
				pomN--;
				j--;
			}
		}
	}
	fclose(dat);
	
	
	
	dat=fopen("oblici.dat", "wb"); 
	if(!dat){
		printf("Greska pri otvaranju datoteke.\n");
		exit(1);
	}
	
	 /* zapisivanje niza u ispraznjenu datoteku */
	 N=pomN;
	 fwrite(&N, 2, 1, dat);
	 if(ferror(dat)){
	 	printf("Greska prilikom pisanja datoteke.\n");
	 	printf("Zapisano je samo %d osoba", i);
	 	exit(3);
	 }
	 for(i=0; i<pomN; i++){
	 	fwrite(niz[i].naziv, 1, 20, dat);
	 	if(ferror(dat)) {
	 		printf("Greska prilikom pisanja datoteke.\n");
	 		printf("Zapisano je samo %d osoba", i);
	 		exit(3);
	 	}
	 	x=niz[i].br_stranica;	
	 	fwrite(&x, 1, 1, dat);
	 	if(ferror(dat))	{
	 		printf("Greska prilikom pisanja datoteke.\n");
	 		printf("Zapisano je samo %d osoba", i);
	 		exit(3);
	 	}
	 	for(k=0; k<niz[i].br_stranica; k++){
	 		float pom=niz[i].stranice[k];
	 		fwrite(&pom, 4, 1, dat);
	 		if(ferror(dat)){
	 			printf("Greska prilikom pisanja datoteke.\n");
	 			printf("Zapisano je samo %d osoba", i);
	 			exit(3);
	 		}
	 	}
	 }
	fclose(dat);
	
}
double DajObim(struct Oblik o){
	int i=0;
	double obim=0;

	for(i=0; i<o.br_stranica; i++)
		obim+=o.stranice[i];
	
	return obim;
}
struct Oblik daj_najveci(){
	struct Oblik niz[KAPACITET];
	unsigned short N=0;
	unsigned char x;
	int i=0, imax=0, k, pomN;/* potencijalan problem je pretp da je imax=0 ?? */

	FILE *dat=fopen("oblici.dat", "rb");
	if(!dat){
		printf("Greska pri otvaranju datoteke");
		return beze;
	}
	
	fread(&N, 2, 1, dat);
	pomN=N;
	for(i=0; i<pomN; i++){
		fread(niz[i].naziv, 1, 20, dat);
		fread(&x, 1, 1, dat);
		niz[i].br_stranica=x;	
		for(k=0; k<niz[i].br_stranica; k++){
			float pom;
			fread(&pom, 4, 1, dat);
			niz[i].stranice[k]=pom; 
		}
	}
	for(i=1; i<pomN; i++)
		if(DajObim(niz[i]) > DajObim(niz[imax]))	imax=i;
	fclose(dat);
	
	return niz[imax];
}

int main(){
	struct Oblik rez;
	struct Oblik niz[2]={
		{"Trougao", 3, {21.21, 18.18, 1.1}},
		{"Trougao", 3, {100.1, 100.1, 100.1}},
	};
	dodaj_oblik(niz[0]);
	dodaj_oblik(niz[1]);

	rez=daj_najveci();
	printf("%s %g %g %g \n", rez.naziv, rez.stranice[0], rez.stranice[1], rez.stranice[2]);
	
	return 0;
}
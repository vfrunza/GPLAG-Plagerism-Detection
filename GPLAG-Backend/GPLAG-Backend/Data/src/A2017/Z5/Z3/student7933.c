#include <stdio.h>
#include <stdlib.h>

typedef struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
} Oblik;

//Fercera
int strComp(const char *s1, const char *s2){
	
	while(*s1 != '\0' && *s2 != '\0' && *s1 == *s2){
		s1++;
		s2++;
	}
	
	if(*s1 == '\0' && *s2 == '\0') return 1;
	
	return 0;
}

//Fercera :)
void dodaj_oblik(Oblik o){
	
	FILE *oblici = fopen("oblici.dat", "ab");
	
	if(!oblici){
		printf("Greska prilikom otvaranja datoteke!");
		exit(1);
	}

	//Odgovarajuce velicine
	char brStr = o.br_stranica;
	float str[300];
	int i;
	//Double u float
	for(i = 0; i < brStr; i++){
		str[i] = o.stranice[i];
	}
	
	//Upisi
	fwrite(o.naziv, 1, 20, oblici);
	fwrite(&brStr, 1, 1, oblici);
	fwrite(str, 4, brStr, oblici);
	
	fclose(oblici);
	
	
	oblici = fopen("oblici.dat", "rb+");
	
	if(!oblici){
		printf("Greska prilikom otvaranja datoteke!");
		exit(1);
	}
	
	//Povecaj broj oblika za 1
	unsigned short brOblika;
	fread(&brOblika, 2, 1, oblici);
	fseek(oblici, 0, SEEK_SET);
	brOblika++;
	printf("Novi broj oblika: %d", brOblika);
	fwrite(&brOblika, 2, 1, oblici);
	
	fclose(oblici);
}

void izbaci_duple(){
	
	FILE *oblici = fopen("oblici.dat", "rb");
	
	if(!oblici){
		printf("Greska prilikom otvaranja datoteke!");
		exit(1);
	}
	
	int i, j, ponovioSe;
	Oblik nizOblika[65535];
	
	//Broj oblika
	unsigned short brOblika;
	fread(&brOblika, 2, 1, oblici);
	
	//Odgovarajuce velicine za svaki oblik
	char brStr;
	float str[300];
	char naziv[20];
	int endFile;
	
	//Citanje podataka u niz oblikaa
	i = 0;
	while(i < brOblika){
		
		fread(naziv, 1, 20, oblici);
		fread(&brStr, 2, 1, oblici);
		endFile = fread(str, 4, brStr, oblici);
		
		if(ferror(oblici)){
			printf("Doslo je do greske prilikom citanja iz file-a!");
			exit(1);
		}
		
		//Ako je kraj ucitavanja
		if(!endFile){
			break;
		}
		
		//Pretostavimo da se ucitani oblik nije prije ucitao
		ponovioSe = 0;
		for(j = 0; j < i; j++){
			
			if(strComp(naziv, nizOblika[j].naziv)){
				//Naziv odgovara, oblik postoji vec u nizu,
				//pa se nece ubacivati trenutni oblik u niz oblika
				ponovioSe = 1;
				brOblika--;
				i--;
				break;
			}
			
		}
		
		if(!ponovioSe){
			//Prepisi naziv
			j = 0;
			while(*(naziv+j) != '\0'){
				*(nizOblika[i].naziv + j) = *(naziv + j);
				j++;
			}
			*(nizOblika[i].naziv + j) = '\0';
			
			//Prepisi broj strnica
			nizOblika[i].br_stranica = brStr;
			
			//float u double za stranice
			for(j = 0; j < brStr; j++){
				nizOblika[i].stranice[j] = str[j];
			}
		}
		
		i++;
	}
	
	fclose(oblici);
	
	//Ocist idatoteku i upisi broj oblika
	oblici = fopen("oblici.dat", "wb");
	fwrite(&brOblika, 2, 1, oblici);
	fclose(oblici);
	
	//Upisuj oblike
	for(i = 0; i < brOblika; i++){
		dodaj_oblik(nizOblika[i]);
	}

}

Oblik daj_najveci(){
	/*
	FILE *oblici = fopen("oblici.dat", "rb");
	
	if(!oblici){
		printf("Greska prilikom otvaranja datoteke!");
		exit(1);
	}
	
	Oblik nizOblika[65535];
	int i, j;
	
	//Broj oblika
	unsigned short brOblika;
	fread(&brOblika, 2, 1, oblici);
	
	//Odgovarajuce velicine za svaki oblik
	char brStr;
	float str[300];
	char naziv[20];
	*/
	Oblik najveci;/*
	int maxObim = 0, obim = 0;
	
	//Citanje podataka u niz oblikaa
	i = 0;
	while(i < brOblika){
		
		fread(naziv, 1, 20, oblici);
		fread(&brStr, 2, 1, oblici);
		fread(str, 4, brStr, oblici);
		
		if(ferror(oblici)){
			printf("Doslo je do greske prilikom citanja iz file-a!");
			exit(1);
		}
		
		//Prepisi naziv
		j = 0;
		while(*(naziv+j) != '\0'){
			*(nizOblika[i].naziv + j) = *(naziv + j);
			j++;
		}
		*(nizOblika[i].naziv + j) = '\0';
		
		//Prepisi broj strnica
		nizOblika[i].br_stranica = brStr;
		
		obim = 0;
		//float u double za stranice
		for(j = 0; j < brStr; j++){
			nizOblika[i].stranice[j] = str[j];
			obim += nizOblika[i].stranice[j];
		}
		
		if(obim > maxObim){
			najveci = nizOblika[i];
		}
		
		i++;
	}
	
	fclose(oblici);*/

	return najveci;
}

int main() {
	
	return 0;
}

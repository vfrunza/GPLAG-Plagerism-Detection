#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};


void dodaj_oblik(struct Oblik o){
	
	unsigned short obliciBroj;	//br oblika
	struct Oblik oblici[100];
	int i, j;
	FILE* dat = fopen("oblici.dat", "rb");
	if(dat == NULL) exit(1);
	
	unsigned char straniceBroj;	//br str mnogougla
	float stranicaValue;	//duz str
	
	// dodajemo oblik u niz struct
	
	fread(&obliciBroj, 2, 1, dat);
	for(i = 0; i < obliciBroj; ++i) {
		fread(oblici[i].naziv, 1, 20, dat);
		fread(&straniceBroj, 1, 1, dat);
		
		oblici[i].br_stranica = (int) straniceBroj;
		//oblici[i].br_stranica=straniceBroj;
		
		for(j = 0; j < straniceBroj; ++j){
			fread(&stranicaValue, 4, 1, dat);
			oblici[i].stranice[j] = (double)stranicaValue;
		}
	}
	oblici[i] = o;	//dodajem novi
	++obliciBroj;
	
	FILE *dat2 = fopen("oblici.dat", "wb");
	if(dat2 == NULL) exit(1);
	
	// upisujemo u datotetku
	
	fwrite(&obliciBroj, 2, 1, dat2);
	for(i=0; i<obliciBroj; ++i){
		fwrite(oblici[i].naziv, 1,20, dat2);
		straniceBroj = (unsigned char ) oblici[i].br_stranica;
		fwrite(&straniceBroj, 1, 1, dat2);
		 
		for(j = 0; j < straniceBroj; ++j) {
			stranicaValue = (float) oblici[i].stranice[j];
			fwrite(&stranicaValue, 4, 1, dat2);
		}
	}
	
	fclose(dat); fclose(dat2);
	
}

void izbaci_duple(){
	int i,j,k;
	FILE* dat=fopen("oblici.dat","rb");
	if(dat==NULL) exit(1);
	
	float stranicaValue;
	struct Oblik oblici[100];
	unsigned short obliciBroj;
	unsigned char straniceBroj;
	
	fread(&obliciBroj,2,1,dat);
	for(i=0; i<obliciBroj;i++){
		fread(oblici[i].naziv,1,20,dat);
		fread(&straniceBroj,1,1,dat);
		oblici[i].br_stranica=(int)straniceBroj;
		for(j=0; j<straniceBroj; j++){
			fread(&stranicaValue,4,1,dat);
			oblici[i].stranice[j]=(double)stranicaValue;
		}
	}
	
	//isti izbacivanje
	for(i=0; i<obliciBroj; i++){
		for(j=i+1;j<obliciBroj;j++){
			if(!strcmp(oblici[i].naziv, oblici[j].naziv)){
				for(k=j; k<obliciBroj-1; k++){
					oblici[k]=oblici[k+1];
				}
				obliciBroj--;
				j--;
			}
		}
	}
	
	FILE* dat2=fopen("oblici.dat","wb");
	if(dat2==NULL) exit(1);
	
	fwrite(&obliciBroj,2,1,dat2);
	for(i=0; i<obliciBroj;i++){
		fwrite(oblici[i].naziv,1,20,dat2);
		straniceBroj=(unsigned char)oblici[i].br_stranica;
		fwrite(&straniceBroj,1,1,dat2);
		for(j=0; j<straniceBroj; j++){
			stranicaValue=(float)oblici[i].stranice[j];
			fwrite(&stranicaValue,4,1,dat2);
		}
	}
	
	fclose(dat2);
	fclose(dat);
}


struct Oblik daj_najveci(){	//najveci obim
	
	int i,j, obliciBroj=0;
	struct Oblik maxoblik;
	struct Oblik oblici[100];
	unsigned char straniceBroj;
	
	FILE* dat=fopen("oblici.dat","rb");
	if(dat==NULL) exit(1);
	
	float obimMaxVrijednost=0, obimoblika=0, stranicaValue;
	
	fread(&obliciBroj,2,1,dat);
	for(i=0; i<obliciBroj; i++){
		
		obimoblika=0;
		fread(oblici[i].naziv, 1,20,dat);
		fread(&straniceBroj,1,1,dat);
		oblici[i].br_stranica=(int)straniceBroj;
		
		for(j=0; j<straniceBroj; j++){
			fread(&stranicaValue,4,1,dat);
			oblici[i].stranice[j]=(double)stranicaValue;
			obimoblika+=oblici[i].stranice[j];
		}
		
		if(obimoblika>obimMaxVrijednost){
			obimMaxVrijednost=obimoblika;
			maxoblik=oblici[i];
		}
	}
	
	fclose(dat);
	return maxoblik;
	
}

int main() {
	
	struct Oblik niz[]={{"Trougao", 3, {1.1, 1.1, 1.1}},
						{"Trougao", 3, {1.1, 1.1, 1.1}},
						{"Trougao", 3, {100.1, 100.1, 100.1}},
						{"Kvadar", 4, {1.1, 1.1, 1.1, 1.1}},
						{"Trougao",3, {1.1,1.1,1.1}}};
	
	dodaj_oblik(niz[0]); dodaj_oblik(niz[1]); dodaj_oblik(niz[2]);
	dodaj_oblik(niz[3]); dodaj_oblik(niz[4]);
	
	izbaci_duple();
	
	struct Oblik najveci_obim=daj_najveci();
	
	// printf("%s %g %g %g\n", rez.naziv, rez.stranice[0], rez.stranice[1],rez.stranice[2])
	
	
	
	return 0;
}

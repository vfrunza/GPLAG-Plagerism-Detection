#include <stdio.h>
#include <stdlib.h>
#define KAPACITET 200
struct Vrijeme {
		int sati, minute, sekunde;
	};
	struct Cas {
		char predmet[10];
		int dan_u_sedmici;
		struct Vrijeme pocetak, kraj;
	};

int ucitaj_datoteku(struct Cas raspored[]){
	FILE* dat=fopen("raspored.dat", "rb");
	if(dat==NULL){
		printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	int ucitano=fread(raspored, sizeof(struct Cas), KAPACITET, dat);
	fclose(dat);
	return ucitano;
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	FILE* dat=fopen("raspored.dat", "wb");
	if(dat==NULL){
		printf("Greska prilikom otvaranja datoteke.\n");
		exit(1);
	}
	int zapisano=fwrite(raspored, sizeof(struct Cas), broj_casova, dat);
	if(ferror(dat)){
		printf("Greska prilikom pisanja datoteke.\n");
		return 0;
	}
	fclose(dat);
	return 1;
}
int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas){
	int i;
	int dan=cas.dan_u_sedmici;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici!=dan) return 0;
		else{
			if(raspored[i].pocetak.sati<cas.pocetak.sati && raspored[i].kraj.sati==cas.pocetak.sati && raspored[i].kraj.sati<cas.kraj.sati && raspored[i].kraj.minute>cas.pocetak.minute) return 1;
			else if(raspored[i].pocetak.sati<cas.pocetak.sati && raspored[i].kraj.sati>cas.kraj.sati) return 1;
			else if((raspored[i].pocetak.sati<cas.pocetak.sati && raspored[i].pocetak.sati<cas.kraj.sati) || (raspored[i].pocetak.sati>cas.pocetak.sati && raspored[i].pocetak.sati>cas.kraj.sati)) return 0;
			else if(raspored[i].pocetak.sati==cas.pocetak.sati && raspored[i].kraj.sati==cas.kraj.sati && raspored[i].pocetak.minute<cas.pocetak.minute && raspored[i].kraj.minute<cas.kraj.minute) return 0;
			
			
		}
		
	}
	return 1;
}



void ispis_rasporeda(struct Cas raspored[], int broj_casova){
	FILE* dat=fopen("raspored.dat", "r");
	char c;
	if(dat==NULL){
		printf("Greska prilikom otvaranja datoteke.\n");
		exit(1);
	}
	do{
		c=fgetc(dat);
		printf("%c", c);	
	}while(c<broj_casova);
}




int main() {
	
	return 0;
}

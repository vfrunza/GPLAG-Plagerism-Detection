#include <stdio.h>
#define KAPACITET 200
struct Vrijeme{
	int sati, minute, sekunde;
};

struct Cas{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

int zapisi_datoteku(struct Cas rasp[],int br_casova){
	FILE* dat=fopen("raspored.dat","wb");
	int br_ucitanih=fwrite(rasp, sizeof(struct Cas),br_casova,dat);
	fclose(dat);
	if(br_ucitanih>0)return 1;
	return br_ucitanih;
}

int ucitaj_datoteku(struct Cas rasp[]){
	FILE* dat=fopen("raspored.dat","rb");
	if(dat==NULL)return 0;
	int br_ucitanih=fread(rasp,sizeof(struct Cas),KAPACITET,dat);
	fclose(dat);
	return br_ucitanih;
}
void ispisi_raspored(struct Cas rasp[]){
	int i,z=0,j;
	printf("       PON       UTO       SRI       CET       PET       SUB");
	printf("\n");
	printf("9:00 ");
	for(i=0; i<4; i++){
		for(j=0; j<200; j++){
		if(rasp[j].dan_u_sedmici==i && rasp[j].pocetak.sati==9){printf("%-10s",rasp[j].predmet);z=1;}
		}
		if(z==0)printf("          ");
		z=0;
	}
	printf("\n");
	printf("10:00");
	for(i=0; i<4; i++){
		for(j=0; j<200; j++){
		if(rasp[j].dan_u_sedmici==i && (rasp[j].pocetak.sati==10 || rasp[j].kraj.sati==10)){printf("%-10s",rasp[j].predmet);z=1;}
		}
		if(z==0)printf("          ");
		z=0;
	}

	printf("\n");
	printf("11:00");
	for(i=0; i<4; i++){
		for(j=0; j<200; j++){
		if(rasp[j].dan_u_sedmici==i && (rasp[j].pocetak.sati==11 || rasp[j].kraj.sati==10)){printf("%-10s",rasp[j].predmet);z=1;}
		}
		if(z==0)printf("          ");
		z=0;
	}

	printf("\n");
	printf("12:00");
	for(i=0; i<4; i++){
		for(j=0; j<200; j++){
		if(rasp[j].dan_u_sedmici==i && (rasp[j].pocetak.sati==12 || rasp[j].kraj.sati==12)){printf("%-10s",rasp[j].predmet);z=1;}
		}
		if(z==0)printf("          ");
		z=0;
	}

	printf("\n");
	printf("13:00");
	for(i=0; i<4; i++){
		for(j=0; j<200; j++){
		if(rasp[j].dan_u_sedmici==i && (rasp[j].pocetak.sati==13 || rasp[j].kraj.sati==13)){printf("%-10s",rasp[j].predmet);z=1;}
		}
		if(z==0)printf("          ");
		z=0;
	}

	printf("\n");
	printf("11:00");
	for(i=0; i<4; i++){
		for(j=0; j<200; j++){
		if(rasp[j].dan_u_sedmici==i && (rasp[j].pocetak.sati==14 || rasp[j].kraj.sati==14)){printf("%-10s",rasp[j].predmet);z=1;}
		}
		if(z==0)printf("          ");
		z=0;
	}
}

void ispisi_dan(struct Cas rasp[], int broj_casova, int dan){
	int i,z=1;
	for(i=0; i<200;i++){
		if(rasp[i].dan_u_sedmici==dan){
			else printf("%d) %s (%02d:%02d-%02d:%02d)",z,rasp[i].predmet,rasp[i].pocetak.sati,rasp[i].pocetak.minute,rasp[i].kraj.sati,rasp[i].kraj.minute);
			printf("\n");
	}
	z++;
}
}
	
	
	
int main() {
	FILE* ulaz=fopen("raspored.dat","rb");
	if(ulaz==NULL){
		printf("Otvaranje datoteke nije uspjelo.");
		return 1;
	}
	struct Cas raspored[200];
	int br_ucitanih=ucitaj_datoteku(raspored);
	int izbor,obrisani_Dan;
	while(1){
	printf("1) Ispis rasporeda:\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada");
	scanf("%d",&izbor);
	fclose(ulaz);
	if(izbor==0){
		fclose(ulaz);
		return 0;
	}
	else if(izbor==1){
		ispisi_raspored(raspored);
	}
	else if(izbor==4){
		printf("Unesite dan(1=ponedjeljak, 2=utorak,..., 6=subota):\n");
		scanf("%d",&obrisani_Dan);
		printf("Uneseni casovi su: \n");
		ispisi_dan(Cas,)
	}
	}
	return 0;
}

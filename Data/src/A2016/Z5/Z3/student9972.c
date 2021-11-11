#include <stdio.h>
#include <string.h>
#define KAPACITET 200

struct Vrijeme {
	int sati,minute,sekunde;
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak,kraj;
};
char unesi(char niz[],int velicina) {
	char znak=getchar();
	int i=0;
	while(znak=='\n')
	znak=getchar();
	while(i< velicina-1 && znak !='\n' ) {
		niz[i++] = znak;
		znak = getchar();
	}
niz[i]='\0';
return znak; }
void ocisti(char znak){
	int ima=0;
	while(znak!='\n')
	znak=getchar(); }
int ucitaj_datoteku(struct Cas raspored[]){
FILE* dat=fopen("raspored.dat","rb");
if(dat == NULL) return 0;
int ucitanih=fread(raspored,sizeof(struct Cas),KAPACITET,dat);
fclose(dat);
return ucitanih; }
void ispisreda(){
printf("\n       PON       UTO       SRI");
printf("       CET       PET       SUB");
printf("\n"); }
void ispis_rasporeda(struct Cas raspored[], int broj_casova){
	int i,j,k,max=0,min=100;
	int indexmaxa=0;
	ispisreda();
	for(i=0;i<broj_casova;i++){
		if(raspored[i].pocetak.sati<min)
		min=raspored[i].pocetak.sati;}
	for(i=0;i<broj_casova;i++){
		if(raspored[i].kraj.sati>max ){
			max=raspored[i].kraj.sati;
			indexmaxa=i;
}} if(raspored[indexmaxa].kraj.minute==0) max=max-1;

int x;
int s,dan,n;

for(i=min;i<=max;i++){
	if(i<10) printf("9:00   ");
	else printf("%d:00  ",i);
	for(j=1;j<7;j++){
		for(k=0;k<broj_casova;k++){
			s=raspored[k].pocetak.sati;
			dan=raspored[k].dan_u_sedmici;
			n=raspored[k].kraj.sati;
			if(s<=i && dan==j && n>=i) {
				printf("%-10s",raspored[k].predmet);
				break;
			}}
			if(k==broj_casova)
			for(x=0;x<10;x++)
			printf(" ");}
			printf("\n"); }}
			
			void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
				int i;
				printf("Uneseni su casovi: ");
				int k=1;
				
			for(i=0;i<broj_casova;i++){
				if(raspored[i].dan_u_sedmici==dan){
					printf("\n%d) %s (",k++,raspored[i].predmet);
					if(raspored[i].pocetak.sati<10) printf("0");
					printf("%d:",raspored[i].pocetak.sati);
					if (raspored[i].pocetak.minute<10) printf("0");
					printf("%d-",raspored[i].pocetak.minute);
					printf("%02d:%02d)",raspored[i].kraj.sati,raspored[i].kraj.minute);
				}
			}}
			int zapisi_datoteku(struct Cas raspored[], int broj_casova){
				FILE* dat = fopen("raspored.dat", "wb");
				int ucitano=fwrite(raspored, sizeof(struct Cas), broj_casova, dat);
				fclose(dat);
				if(ucitano>0) return 1;
				return ucitano; }
				void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
					int i; int k=0; int j, brojac=1;
					for(i=0;i<broj_casova;i++){
					if(raspored[i].dan_u_sedmici==dan){ k++; brojac++;
					if(k==redni_broj){
						
						for(j=i;j<broj_casova-1;j++)
						raspored[j]=raspored[j+1];
						
						if(brojac>0)break; } }}}
						int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas){
							int i;
						int minpoc1,minpoc2,minkraj1,minkraj2;
						for(i=0;i<broj_casova;i++) {
							minpoc1=raspored[i].pocetak.minute+raspored[i].pocetak.sati*60;
							minkraj1=raspored[i].kraj.minute+raspored[i].kraj.sati*60;
							minpoc2=cas.pocetak.minute+cas.pocetak.sati*60;
							minkraj2=cas.kraj.minute+cas.kraj.sati*60;
						if (raspored[i].dan_u_sedmici==cas.dan_u_sedmici && (raspored[i].pocetak.minute+raspored[i].pocetak.sati*60<minpoc2 && minkraj1>minpoc2 || minpoc2<raspored[i].pocetak.minute+raspored[i].pocetak.sati*60 && cas.kraj.minute+cas.kraj.sati*60>minkraj1 || raspored[i].pocetak.minute+raspored[i].pocetak.sati*60<cas.kraj.minute+cas.kraj.sati*60 && minkraj1>cas.kraj.minute+cas.kraj.sati*60))
						return 1;
						if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici && (minpoc2==minpoc1 || minkraj1==minkraj2))
						return 1; 
						if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici &&(minpoc1<minpoc2 && minkraj1>minpoc2 || minpoc2<minpoc1 && minkraj2>minkraj1 || minpoc1<minkraj2 && minkraj1>minkraj2))
						return 1; }
						return 0;}
						int dodaj_cas(struct Cas raspored[], int broj_casova, const char*predmet, int trajanje){
							if (broj_casova==200) return 0;
							int i,j,preklop;
							for(i=0; i<6; i++)
								for(j=9; j<=19-trajanje; j++){
									struct Cas cas={"",i+1,{j,0,0},{j+trajanje,0,0}};
									char *q=cas.predmet,*p=(char*)predmet;
									struct Cas cc;
									while(*q++=*p++);
									preklop=preklapanje(raspored,broj_casova,cas);
									if(preklop==0){
										raspored[broj_casova]=cas;
										return 1;
									} if(preklop==1) continue; }
									return 0; }
									void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena){
								int i,redni=0;
								for(i=0;i<broj_casova; i++){
									if(raspored[i].dan_u_sedmici==dan) redni++;
									if(redni_broj==redni)
									raspored[i]=promjena; }}
								int main () {
									int opcija,broj_casova=0;
									struct Cas raspored[KAPACITET];
									ucitaj_datoteku(raspored);
									do{
										printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
										scanf("%d",&opcija);
										int broj=opcija;
										switch(opcija){
											case 0: {
												zapisi_datoteku(raspored,broj_casova);
												break;
											} case 1:{
												if(broj!=0)   ispis_rasporeda(raspored,broj_casova);
												break;}
												case 2:  if(broj!=0)
											{
								
												int br_casova,dodan=0;
												char  predmet[10];
												printf("Unesite naziv predmeta: Unesite broj casova: ");
												if(broj!=0)   ocisti(unesi(predmet,10));
												scanf("%d",&br_casova);
												dodan=dodaj_cas(raspored,broj_casova,predmet,br_casova);
												int vr=dodan;
											if(vr==0)
											printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br_casova);
											if(vr==1)  broj_casova++;
											
											break;}
											case 4: if(broj!=0)
											{
												int dan,redni;
												int br=broj_casova;
												printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
												scanf("%d",&dan);
												ispisi_dan(raspored,br,dan);
												printf("\nIzaberite koji cas zelite obrisati: ");
											    scanf("%d",&redni);
											    obrisi_cas(raspored,br,dan,redni);
											    printf(" Cas obrisan\n");
											    broj_casova--;
											}
											case 3:  if(broj!=0){
												struct Cas promjena;
												int dan,redni;
												char *q,*p;
												char znak,predmet[10];
												printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
												scanf("%d",&dan);
												ispisi_dan(raspored,broj_casova,dan);
												promjena.dan_u_sedmici=dan;
												printf("\nIzaberite koji cas zelite promijeniti: Naziv predmeta: ");
												scanf("%d",&redni);
												ocisti(unesi(predmet,10));
												q=promjena.predmet;
												p=predmet;
												strcpy(q,p);
												printf("Vrijeme pocetka: Vrijeme zavrsetka: ");
												scanf("%d%c",&promjena.pocetak.sati,&znak);
												scanf("%d",&promjena.pocetak.minute);
												scanf("%d%c%d",&promjena.kraj.sati,&znak,&promjena.kraj.minute);
												promijeni_cas(raspored,broj_casova,dan,redni,promjena);
												break;}
										} 
										
									} while(opcija!=0);
									    
									    
									    	return 0; 
									
								}
									
											
							
						
					
					
			
	



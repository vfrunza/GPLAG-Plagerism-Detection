#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KAPACITET 200
struct Vrijeme{
	int sati, minute,sekunde;
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};
struct Cas raspored[KAPACITET];

void Meni()
{
	printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa0) Kraj rada\nIzaberite opciju:");
}
	int ucitaj_datoteku(struct Cas raspored[])
	{
		FILE* ulaz;
		struct Cas elm;
		int redniBroj=0,brojCasova=0;
		ulaz=fopen("raspored.dat","r+b");
		/*if(ulaz=NULL)
		{
			printf("Greška prilikom otvaranja datoteke raspored.dat!\n");
			exit(1);
		}
		else*/
		
			fread(&brojCasova,sizeof(brojCasova),1,ulaz);
			for(redniBroj=0;redniBroj<brojCasova;redniBroj++)
			{
				fread(&elm,sizeof(elm),1,ulaz);
				raspored[redniBroj]=elm;
			}
		
		fclose(ulaz);
		return brojCasova;
	}
	
	
	int zapisi_datoteku(struct Cas raspored[], int broj_casova)
	{
		FILE* izlaz;
		int i=0;
		if((izlaz=fopen("raspored.dat","w+b"))==NULL)
		{
			printf("Greska kod upisivanja datoteke!\n");
			return 0;
		}
		fwrite(&broj_casova,1,sizeof(broj_casova),izlaz);
		for(i=0;i<broj_casova;i++)
		{
			fwrite(&raspored[i],1,sizeof(struct Cas),izlaz);
		}
		fclose(izlaz);
		return 1;
	}
	
	
	int dodaj_cas(struct Cas raspored[], int broj_casova,const char* predmet,int trajanje)
	{
		int i=0,j=0;
		float brojSati=0.;
		if(broj_casova>0) {
			for(i=0;i<broj_casova-1 || (broj_casova==1 && i==0);i++)
			{
				
				if( broj_casova>1 && raspored[i].dan_u_sedmici==raspored[i+1].dan_u_sedmici)  //isti dan pa gledamo medjuprostor izmedju casova
				{
					if(  -(raspored[i].kraj.sati + raspored[i].kraj.minute/60. + raspored[i].kraj.sekunde/3600.)+
					 (raspored[i+1].pocetak.sati + raspored[i+1].pocetak.minute/60. + raspored[i+1].pocetak.sekunde/3600.)>trajanje )
					{
						/* pomijeramo sve casove za jedno mjesto*/
						
						for(j=broj_casova;j>i+1;j--)
						{
							raspored[j]=raspored[j-1];
						}
						
						//upisemo novi cas jer ima dovoljno prostora
						strcpy(raspored[i+1].predmet,predmet);
						raspored[i+1].pocetak=raspored[i].kraj;
						raspored[i+1].dan_u_sedmici=raspored[i].dan_u_sedmici;
						brojSati=raspored[i+1].pocetak.sati+raspored[i+1].pocetak.minute/60.+raspored[i+1].pocetak.sekunde/3600.+trajanje;
						raspored[i+1].kraj.sati=(int)brojSati;
						raspored[i+1].kraj.minute=(int)((brojSati-raspored[i+1].kraj.sati)*60);
						raspored[i+1].kraj.sekunde=(int)(((brojSati-raspored[i+1].kraj.sati)*60-raspored[i+1].kraj.minute)*60);
						return 1;
					}
					else if( 19 - (raspored[i+1].kraj.sati + raspored[i+1].kraj.minute/60. + raspored[i+1].kraj.sati/3600.) > trajanje )
					{
						/* pomijeramo sve casove za jedno mjesto*/
						/*for(j=broj_casova;j>i+2;j--)
						{
							raspored[j]=raspored[j-1];
						}*/
						/*
						strcpy(raspored[i+2].predmet,predmet);
						raspored[i+2].pocetak=raspored[i+1].kraj;
						raspored[i+2].dan_u_sedmici=raspored[i+1].dan_u_sedmici;
						brojSati=raspored[i+2].pocetak.sati+raspored[i+2].pocetak.minute/60.+raspored[i+2].pocetak.sekunde/3600.+trajanje;
						raspored[i+2].kraj.sati=(int)brojSati;
						raspored[i+2].kraj.minute=(int)((brojSati-raspored[i+2].kraj.sati)*60);
						raspored[i+2].kraj.sekunde=(int)(((brojSati-raspored[i+2].kraj.sati)*60-raspored[i+2].kraj.minute)*60);
						*/
						strcpy(raspored[broj_casova].predmet,predmet);
						raspored[broj_casova].pocetak=raspored[i+1].kraj;
						raspored[i+2].dan_u_sedmici=raspored[i+1].dan_u_sedmici;
						brojSati=raspored[broj_casova].pocetak.sati+raspored[broj_casova].pocetak.minute/60.+raspored[broj_casova].pocetak.sekunde/3600.+trajanje;
						raspored[broj_casova].kraj.sati=(int)brojSati;
						raspored[broj_casova].kraj.minute=(int)((brojSati-raspored[broj_casova].kraj.sati)*60);
						raspored[broj_casova].kraj.sekunde=(int)(((brojSati-raspored[broj_casova].kraj.sati)*60-raspored[broj_casova].kraj.minute)*60);
						return 1;
					}
					else if(  -(raspored[i].kraj.sati + raspored[i].kraj.minute/60. + raspored[i].kraj.sekunde/3600.)+
					 (raspored[i+1].pocetak.sati + raspored[i+1].pocetak.minute/60. + raspored[i+1].pocetak.sekunde/3600.)<trajanje && 
					 19 - (raspored[i+1].kraj.sati + raspored[i+1].kraj.minute/60. + raspored[i+1].kraj.sati/3600.) < trajanje )
					{
						if(i+1==broj_casova-1 && raspored[i+1].dan_u_sedmici<7) //sljedeci dan nam je prazan
						{
							/* pomijeramo sve casove za jedno mjesto*/
							strcpy(raspored[i+2].predmet,predmet);
							raspored[i+2].pocetak.sati=9;
							raspored[i+2].pocetak.minute=0;
							raspored[i+2].pocetak.sekunde=0;
							raspored[i+2].dan_u_sedmici=raspored[i+1].dan_u_sedmici+1;
							brojSati=raspored[i+2].pocetak.sati+raspored[i+2].pocetak.minute/60.+raspored[i+2].pocetak.sekunde/3600.+trajanje;
							raspored[i+2].kraj.sati=(int)brojSati;
							raspored[i+2].kraj.minute=(int)((brojSati-raspored[i+2].kraj.sati)*60);
							raspored[i+2].kraj.sekunde=(int)(((brojSati-raspored[i+2].kraj.sati)*60-raspored[i+2].kraj.minute)*60);
							return 1;
						}
					}
				}
				
				else if( broj_casova>1 && raspored[i+1].dan_u_sedmici>raspored[i].dan_u_sedmici && 
					raspored[i+1].pocetak.sati -9 + raspored[i+1].pocetak.minute/60. + raspored[i+1].pocetak.sati/3600. > trajanje ) //vidimo mozemo li staviti ujutru
					{
						/* pomijeramo sve casove za jedno mjesto*/
						for(j=broj_casova;j>i+1;j--)
						{
							raspored[j]=raspored[j-1];
						}
						//upisemo novi cas jer ima dovoljno prostora
						strcpy(raspored[i+1].predmet,predmet);
						raspored[i+1].pocetak=raspored[i].kraj;
						raspored[i+1].dan_u_sedmici=raspored[i].dan_u_sedmici+1;
						brojSati=raspored[i+1].pocetak.sati+raspored[i+1].pocetak.minute/60.+raspored[i+1].pocetak.sekunde/3600.+trajanje;
						raspored[i+1].kraj.sati=(int)brojSati;
						raspored[i+1].kraj.minute=(int)((brojSati-raspored[i+1].kraj.sati)*60);
						raspored[i+1].kraj.sekunde=(int)(((brojSati-raspored[i+1].kraj.sati)*60-raspored[i+1].kraj.minute)*60);
						return 1;

					}
				
				else if( broj_casova>1 && raspored[i+1].dan_u_sedmici>raspored[i].dan_u_sedmici && 
					19 - (raspored[i].kraj.sati + raspored[i].kraj.minute/60. + raspored[i].kraj.sati/3600.) > trajanje ) //navece staviti
					{
						/* pomijeramo sve casove za jedno mjesto*/
						for(j=broj_casova;j>i+1;j--)
						{
							raspored[j]=raspored[j-1];
						}
						//upisemo novi cas jer ima dovoljno prostora
						strcpy(raspored[i+1].predmet,predmet);
						raspored[i+1].pocetak=raspored[i].kraj;
						raspored[i+1].dan_u_sedmici=raspored[i].dan_u_sedmici;
						brojSati=raspored[i+1].pocetak.sati+raspored[i+1].pocetak.minute/60.+raspored[i+1].pocetak.sekunde/3600.+trajanje;
						raspored[i+1].kraj.sati=(int)brojSati;
						raspored[i+1].kraj.minute=(int)((brojSati-raspored[i+1].kraj.sati)*60);
						raspored[i+1].kraj.sekunde=(int)(((brojSati-raspored[i+1].kraj.sati)*60-raspored[i+1].kraj.minute)*60);
						return 1;

					}
				else if(broj_casova==1 && 19 - (raspored[i].kraj.sati + raspored[i].kraj.minute/60. + raspored[i].kraj.sati/3600.) > trajanje )
				{
						strcpy(raspored[1].predmet,predmet);
						raspored[1].pocetak=raspored[0].kraj;
						raspored[1].dan_u_sedmici=raspored[0].dan_u_sedmici;
						brojSati=raspored[1].pocetak.sati+raspored[1].pocetak.minute/60.+raspored[1].pocetak.sekunde/3600.+trajanje;
						raspored[1].kraj.sati=(int)brojSati;
						raspored[1].kraj.minute=(int)((brojSati-raspored[1].kraj.sati)*60);
						raspored[1].kraj.sekunde=(int)(((brojSati-raspored[1].kraj.sati)*60-raspored[1].kraj.minute)*60);
						return 1;
				}
				//mozda jos koji else zafali
				
			}
			return 0;  //ako nema slobodnog mjesta
		}
		else {
				strcpy(raspored[0].predmet,predmet);
				raspored[0].pocetak.sati=9;
				raspored[0].pocetak.minute=raspored[0].pocetak.sekunde=0;
				brojSati=trajanje;
				raspored[0].kraj.sati=9+(int)trajanje;
				raspored[0].dan_u_sedmici=1;
				raspored[0].kraj.minute= (int)((trajanje-(int)trajanje)*60);
				raspored[0].kraj.sekunde=(int)(((trajanje-(int)trajanje)*60-raspored[0].kraj.minute)*60);		
				return 1;
		}
		return 0;
	}
	
	int preklapanje(struct Cas raspored[], int broj_casova,struct Cas cas)
	{
		int i;
		for(i=0;i<broj_casova;i++)
		{
			if(((raspored[i].pocetak.sati>cas.pocetak.sati || raspored[i].pocetak.sati==cas.pocetak.sati && raspored[i].pocetak.minute>cas.pocetak.minute)
			|| (raspored[i].pocetak.sati==cas.pocetak.sati && raspored[i].pocetak.minute==cas.pocetak.minute && raspored[i].pocetak.sekunde>cas.pocetak.sekunde)) &&
			
			((raspored[i].pocetak.sati<cas.pocetak.sati || raspored[i].pocetak.sati==cas.pocetak.sati && raspored[i].pocetak.minute<cas.pocetak.minute)
			|| (raspored[i].pocetak.sati==cas.pocetak.sati && raspored[i].pocetak.minute==cas.pocetak.minute && raspored[i].pocetak.sekunde<cas.pocetak.sekunde)) ||
			
			((raspored[i].pocetak.sati<cas.pocetak.sati || raspored[i].pocetak.sati==cas.pocetak.sati && raspored[i].pocetak.minute<cas.pocetak.minute)
			|| (raspored[i].pocetak.sati==cas.pocetak.sati && raspored[i].pocetak.minute==cas.pocetak.minute && raspored[i].pocetak.sekunde<cas.pocetak.sekunde)) &&
	
			((raspored[i].pocetak.sati>cas.pocetak.sati || raspored[i].pocetak.sati==cas.pocetak.sati && raspored[i].pocetak.minute>cas.pocetak.minute)
			|| (raspored[i].pocetak.sati==cas.pocetak.sati && raspored[i].pocetak.minute==cas.pocetak.minute && raspored[i].pocetak.sekunde>cas.pocetak.sekunde)))
			return 1; //vratimo 1 jer ima preklapanja
			
		}
		return 0;
	}
	
	void ispis_rasporeda(struct Cas raspored[], int broj_casova)
	{
		FILE* ulaz;
		struct Cas elm;
		int redniBroj=0,i=0,danSedmice=0,k=0,predmetJeIspisan=0;
		int dummy=0;
		char razmak6[6]="      ";
		char razmak10[10]="          ";
		char ponedjeljak[10]="PON";
		char utorak[10]="UTO";
		char srijeda[10]="SRI";
		char cetvrtak[10]="CET";
		char petak[10]="PET";
		char subota[10]="SUB";
		ulaz=fopen("raspored.dat","r+b");
		/*if(ulaz==NULL)
		{
			printf("Greska prilikom otvaranja datoteke raspored.dat!\n");
			exit(1);
		}
		else*/
		
			fread(&dummy,sizeof(dummy),1,ulaz);
			for(i=0;i<broj_casova;i++)
			{
				fread(&elm,sizeof(elm),1,ulaz);
				raspored[redniBroj++]=elm;
			}
		
		fclose(ulaz);
		
		printf("%6s%-10s%-10s%-10s%-10s%-10s%-10s\n",razmak6,ponedjeljak,utorak,srijeda,cetvrtak,petak,subota);
		for(i=0;i<6;i++)
		{
			printf("%2d:00 ",i+9);
			for(danSedmice=1;danSedmice<=6;danSedmice++)
			{
				for(k=0;k<redniBroj;k++)
				{
					if(raspored[k].dan_u_sedmici==danSedmice && raspored[k].pocetak.sati==i+9)
					{
						printf("%-10s",raspored[k].predmet);
						predmetJeIspisan=1;
						break;
					}
				}
				if(predmetJeIspisan==0) printf("%-10s",razmak10);
				predmetJeIspisan=0;
			}
			printf("\n");
		}
	}
	
	void ispisi_dan(struct Cas raspored[], int broj_casova, int dan)
	{
		int i=0,redniBroj=1;
		printf("Uneseni su casovi:\n");
		for(i=0;i<broj_casova;i++)
		{
			if(raspored[i].dan_u_sedmici==dan)
			{
				printf("%d) %s (%02d:%02d-%02d:%02d)\n",redniBroj,raspored[i].predmet,raspored[i].pocetak.sati,raspored[i].pocetak.minute,raspored[i].kraj.sati,raspored[i].kraj.minute);
				redniBroj++;
			}
		}
	}
	
	
	void promijeni_cas(struct Cas raspored[], int broj_casova,int dan,int redni_broj,struct Cas promjena)
	{
		int i=0, potrebanRedniBroj=0;
		for(i=0;i<broj_casova;i++)
		{
			if(raspored[i].dan_u_sedmici==dan)
			{
				if(potrebanRedniBroj==redni_broj-1)
				{
					strcpy(raspored[i].predmet,promjena.predmet);
					raspored[i].pocetak.sati=promjena.pocetak.sati;
					raspored[i].pocetak.minute=promjena.pocetak.minute;
					raspored[i].pocetak.sekunde=promjena.pocetak.sekunde;
					raspored[i].kraj.sati=promjena.kraj.sati;
					raspored[i].kraj.minute=promjena.kraj.minute;
					raspored[i].kraj.sekunde=promjena.kraj.sekunde;
					break;
				}
				potrebanRedniBroj++;
			}
		}
	}

	void obrisi_cas(struct Cas raspored[], int broj_casova,int dan , int redni_broj)
	{
		int i=0,j=0,potrebanRedniBroj=0;
		for(i=0;i<broj_casova;i++)
		{
			if(raspored[i].dan_u_sedmici==dan)
			{
				if(potrebanRedniBroj==redni_broj-1)
				{
					for(j=i;j<broj_casova-1;j++)
					{
						raspored[j]=raspored[j+1];
					}
					break;
				}
				potrebanRedniBroj++;
			}
		}
	}




int main() {
	int opcija=0;
	int trajanje=0;
	int dan=1;
	struct Cas casZaPromjenu;
	int redniBrojPromjena=1,redniBrojBrisanje=1;
	char uneseniPredmet[10];
	char predmetPromjena[10];
	int satiPocetak, minutePocetak, sekundePocetak=0;
	int satiKraj, minuteKraj,sekundeKraj=0;
	int broj_casova=ucitaj_datoteku(raspored);
	
	Meni();
	while(scanf("%d",&opcija)==1)
	{
		if(opcija==1)
		{
			ispis_rasporeda(raspored,broj_casova);
		}
		else if(opcija==2)
		{
			printf("Unesite naziv predmeta: ");
			scanf("%s",uneseniPredmet);
			printf("Unesite broj casova: ");
			scanf("%d",&trajanje);
			if(dodaj_cas(raspored, broj_casova,uneseniPredmet, trajanje)==1)
			{	printf("Dodan je cas.\n"); broj_casova++;}
		}
		
		else if(opcija==3)
		{
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d",&dan);
			printf("Uneseni su casovi:\n");
			ispisi_dan(raspored,broj_casova,dan);
			printf("Izaberite koji cas zelite promjeniti: ");
			scanf("%d",&redniBrojPromjena);
			printf("Naziv predmeta: ");
			scanf("%s",predmetPromjena);
			printf("Vrijeme pocetka: ");
			scanf("%d:%d",&satiPocetak,&minutePocetak);
			printf("Vrijeme zavrsetka: ");
			scanf("%d:%d",&satiKraj,&minuteKraj);
			casZaPromjenu.dan_u_sedmici=dan;
			strcpy(casZaPromjenu.predmet,predmetPromjena);
			casZaPromjenu.pocetak.sati=satiPocetak;
			casZaPromjenu.pocetak.minute=minutePocetak;
			casZaPromjenu.pocetak.sekunde=sekundePocetak;
			casZaPromjenu.kraj.sati=satiKraj;
			casZaPromjenu.kraj.minute=minuteKraj;
			casZaPromjenu.kraj.sekunde=sekundeKraj;
		
			promijeni_cas(raspored, broj_casova, dan, redniBrojPromjena,casZaPromjenu);
		}
		
		else if(opcija==4)
		{
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d",&dan);
			printf("Uneseni su casovi:\n");
			ispisi_dan(raspored,broj_casova,dan);
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d",&redniBrojBrisanje);
			obrisi_cas(raspored,broj_casova,dan,redniBrojBrisanje);
			broj_casova--;
			
		}
		else if(opcija==0)
		{
			if(zapisi_datoteku(raspored,broj_casova)!=1)
			printf("Greska prilikom upisa u datoteku!\n");
		}
		else
		{
			Meni();
		}
	}
	
	
	return 0;
}

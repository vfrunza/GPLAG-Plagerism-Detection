#include <stdio.h>
#include <string.h>
#define KAPACITET 200


struct Vrijeme
{
	int sati,minute,sekunde;
};
struct Cas
{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak,kraj;
};
/*vraca pokazivac na sljedeci znak*/
char unesi(char niz[],int velicina)
{
	char znak=getchar();
	if(velicina<0)
		return znak;
	if(znak=='\n')
		znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
	return znak;
}
/*cistim buffer*/
void ocisti(char znak)
{
	while(znak!='\n')
		znak=getchar();
}
int ucitaj_datoteku(struct Cas raspored[])
{
	FILE *ulaz=fopen("raspored.dat","rb+");
	int greska=0;
	FILE *ulaz1=fopen("raspored.dat","rb+");
	if(ulaz==NULL || ulaz1==NULL)
	{
		greska=1;
		return 0;
	}
	int ucitano1=fread(raspored,sizeof(struct Cas),KAPACITET,ulaz1);
	fclose(ulaz);
	fclose(ulaz1);
	if(greska==0)
		return ucitano1;
}
int mmm(int d)
{
	if(d==0)
		return -1;
	
	return 0;
}
/*funkcija vraca zadnji sat zadnjeg casa*/
int MAX(struct Cas raspored[], int broj_casova)
{
	int brojac=1;
	int i,max=0,indexmaxa=0;
	for(i=0;i<broj_casova;i++)
	{
		brojac++;
		if(raspored[i].kraj.sati>max)
		{
			max=raspored[i].kraj.sati;
			indexmaxa=i;
		}
	}
	/*ako su minute 0 smanjimo sate za 1*/
	max=max-mmm(raspored[indexmaxa].kraj.minute);
	return max;
}
/*funkcija vraca kada pocinje prvi cas*/
int MIN(struct Cas raspored[], int broj_casova)
{
	int i,min=25;
	for(i=0;i<broj_casova;i++)
		if(raspored[i].pocetak.sati<min)
			min=raspored[i].pocetak.sati;
	return min;
}
/*poredi dva vremena*/
int PorediVrj(struct Vrijeme t1, struct Vrijeme t2)
{
	int sat=t1.sati*3600, sat1=t2.sati*3600,min=t1.minute*60,min1=t2.minute*60;
	if(sat+min+t1.sekunde>sat1+min1+t2.sekunde)
		return 1;
	if(sat+min+t1.sekunde<sat1+min1+t2.sekunde)
		return -1;
	if(sat+min+t1.sekunde == sat1+min1+t2.sekunde)
		return 0;
}
int prvi(struct Cas raspored [], int casova)
{
	int i,j=25;
	for(i=0;i<casova;i++)
	{
		if(raspored[i].pocetak.sati<j)
			j=raspored[i].pocetak.sati;
	}
	return j;
}
int zadnji(struct Cas raspored [], int casova)
{
	int i,j=0,index=0;
	for(i=0;i<casova;i++)
	{
		if(raspored[i].pocetak.sati>j)
			j=raspored[i].kraj.sati;
		index=i;
	}
	if(raspored[index].kraj.minute==0)
		j--;
	return j;
}
void ispis_rasporeda(struct Cas raspored [], int broj_casova)
{
	int i,j,k,flag2=1,index_min=-1;
	/*nalazim odakle dokle treba ispisati*/
	int last=zadnji(raspored,broj_casova);
	int first=prvi(raspored,broj_casova);
	char sedmica[][7]={"PON","UTO","SRI","CET","PET","SUB"};
	char sati[][25]={"0:00","1:00","2:00","3:00","4:00","5:00","6:00","7:00","8:00","9:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00","21:00","22:00","23:00"};
	printf("\n");
	printf("%-7s"," ");
	for(i=0;i<6;i++)
	{
		printf("%-10s",sedmica[i]);
	}
	printf("\n");
	for(i=first;i-1<last;i++)
	{
		printf("%-7s",sati[i]);
		for(k=1;k<7;k++)
		{
			index_min=-1;
			flag2=1;
			for(j=0;j<broj_casova;j++)
			{
				/*ako je u intervalu ispisujemo ga*/
				if(raspored[j].dan_u_sedmici==k)
				{
					if((raspored[j].pocetak.sati<=i)&&(raspored[j].kraj.sati>=i)&& !(raspored[j].kraj.sati==i && raspored[j].kraj.minute==0))
					{
						if(flag2)
						{
							index_min=j;
							flag2=0;
						}
						else
							if(PorediVrj(raspored[j].pocetak,raspored[index_min].pocetak)== -1)
							{
								index_min=j;
							}
					}
				}	
			}
			if(index_min==-1)
			{
				printf("%-10s"," ");
			}
			else
				if(index_min!=-1)
				{
					printf("%-10s",raspored[index_min].predmet);
				}
				
		}
		printf("\n");
	}
}
void ispisi_dan(struct Cas raspored[],int broj_casova,int dan)
{
	int i;
	printf("Uneseni su casovi: ");
	int k=1;
	for(i=0;i<broj_casova;i++)
	{
		/*printamo sve predmete u tom danu*/
		if(raspored[i].dan_u_sedmici==dan)	
		{
			printf("\n");
			printf("%d) %s (",k++,raspored[i].predmet);
			printf("%02d:",raspored[i].pocetak.sati);
			printf("%02d-",raspored[i].pocetak.minute);
			printf("%02d:",raspored[i].kraj.sati);
			printf("%02d)",raspored[i].kraj.minute);
			
		}
	}
}
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj)
{
	int i,k=0,n=1;
	for(i=0;i<broj_casova;i++)
	{
		/*ako im je isti dan redni broj se povecava*/
		if(raspored[i].dan_u_sedmici==dan)
		{
			k++;
			n++;
		}
		/*ako je nadjen pravi redni broj izbacujemo*/
		if(k==redni_broj)
		{
			int j;
			for(j=i;j<broj_casova-1;j++)
			{
				raspored[j]=raspored[j+1];
			}
			if(n>0)
				break;
			return;
		}
	}
}
int minute(int min, int sati)
{
	return min+sati*60;
}
int prekl(int minpoc1, int minkraj1, int minpoc2, int minkraj2)
{
	return(minpoc1<minpoc2 && minkraj1>minpoc2 || minpoc2<minpoc1 && minkraj2>minkraj1 || minpoc1<minkraj2 && minkraj1>minkraj2);
}
int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas)
{
	int i;
	for(i=0;i<broj_casova;i++)
	{
		int vr=prekl(minute(raspored[i].pocetak.minute,raspored[i].pocetak.sati),minute(raspored[i].kraj.minute,raspored[i].kraj.sati),minute(cas.pocetak.minute,cas.pocetak.sati),minute(cas.kraj.minute,cas.kraj.sati));
		if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici && (minute(cas.pocetak.minute,cas.pocetak.sati)==minute(raspored[i].pocetak.minute,raspored[i].pocetak.sati) || minute(raspored[i].kraj.minute,raspored[i].kraj.sati)==minute(cas.kraj.minute,cas.kraj.sati)))
			return 1;
		if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici && vr==1)
			return 1;
		
	}
	return 0;
}
int dodaj_cas(struct Cas raspored[], int broj_casova, const char *predmet, int trajanje)
{
	if(broj_casova==200)
		return 0;
	int i,j,preklop;
	for(i=0;i<6;i++)
		for(j=9;j<=19-trajanje;j++)
		{
		/*trazimo gdje ima mjesta za nas cas*/	
		struct Cas cas={"",i+1,{j,0,0},{j+trajanje,0,0}};
		cas.pocetak.minute=0;
		cas.kraj.minute=0;
		cas.pocetak.sekunde=0;
		cas.pocetak.minute=0;
		strcpy(cas.predmet,predmet);
		preklop=preklapanje(raspored,broj_casova,cas);
			if(preklop==0)
			{
				/*dodjela u slucaju da ima mjesta*/
				raspored[broj_casova]=cas;
				return 1;
			}
		}
		return 0;
}
void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena)
{
	int i,redni=0;
	for(i=0;i<broj_casova;i++)
	{
		if(raspored[i].dan_u_sedmici==dan)
			redni++;
		if(redni_broj==redni)
			raspored[i]=promjena;
	}
}
int zapisi_datoteku(struct Cas raspored[], int broj_casova)
{
	FILE *ulaz=fopen("raspored.dat","wb+");
	FILE *ulaz1=fopen("raspored.dat","wb+");
	if(ulaz==NULL || ulaz1==NULL)
	{
		return 0;
	}
	int vel=sizeof(struct Cas);
	int nova=fwrite(raspored,vel,broj_casova,ulaz);
	fclose(ulaz);
	fclose(ulaz1);
	if(nova>0)
		return 1;
	else
		return 0;
}
int main() {
	int opcija,broj_casova=0;
	struct Cas raspored[KAPACITET];
	ucitaj_datoteku(raspored);
	do
	{
		printf("1) Ispis rasporeda\n");
		printf("2) Dodavanje casa\n");
		printf("3) Promjena casa\n");
		printf("4) Brisanje casa\n");
		printf("0) Kraj rada\n");
		printf("Izaberite opciju: ");
			
			scanf("%d",&opcija);
			if(opcija==2)
			{
				int br_casova,dodan=0;
				char predmet[10];
				printf("Unesite naziv predmeta: Unesite broj casova: ");
				ocisti(unesi(predmet,10));
				scanf("%d",&br_casova);
				dodan=dodaj_cas(raspored,broj_casova,predmet,br_casova);
				switch(dodan)
				{
					case 1: broj_casova++; break;
					default: printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",br_casova);
					
				}
				
			}
			if(opcija==0)
				zapisi_datoteku(raspored,broj_casova);
			if(opcija==1)
				ispis_rasporeda(raspored,broj_casova);
			if(opcija==3)
			{
				struct Cas promjena;
				int dan,redni;
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d",&dan);
				ispisi_dan(raspored,broj_casova,dan);
				promjena.dan_u_sedmici=dan;
				printf("\nIzaberite koji cas zelite promijeniti: ");
				scanf("%d",&redni);
				printf("Naziv predmeta: ");
				char predmet[10];
				if(opcija!=0)
					ocisti(unesi(predmet,10));
				char *q=promjena.predmet,*p=predmet;
				char znak;
				strcpy(q,p);
				printf("Vrijeme pocetka: ");
				scanf("%d",&promjena.pocetak.sati);
				scanf("%c",&znak);
				scanf("%d",&promjena.pocetak.minute);
				printf("Vrijeme zavrsetka: ");
				scanf("%d%c",&promjena.kraj.sati,&znak);
				scanf("%d",&promjena.kraj.minute);
				if(opcija!=0)
				promijeni_cas(raspored,broj_casova,dan,redni,promjena);
				
			}
			if(opcija==4)
			{
				int dan,redni;
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d",&dan);
				if(opcija!=0)
				{
					ispisi_dan(raspored,broj_casova,dan);
					printf("\nIzaberite koji cas zelite obrisati: ");
					scanf("%d",&redni);
					obrisi_cas(raspored,broj_casova,dan,redni);
					broj_casova=broj_casova-1;
					printf("Cas obrisan\n");
				}
			}
	}while(opcija!=0);
	return 0;
}

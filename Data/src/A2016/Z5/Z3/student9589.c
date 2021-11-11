#include <stdio.h>
#include <string.h>
#define KAPACITET 200
struct Vrijeme {
        int sati, minute, sekunde;
    };
    
    struct Cas {
        char predmet[10];
        int dan_u_sedmici;
        struct Vrijeme pocetak, kraj;
    };
    
  
    int ucitaj_datoteku(struct Cas raspored[])
    {
    	int x=0;
    	FILE* ulaz=fopen("raspored.dat","rb");
    	if(ulaz==NULL){
    		printf("greska pri otvaranju");
    		return x;
    	}
    	x=fread(raspored,sizeof(raspored),KAPACITET,ulaz);
    	fclose(ulaz);
    	return x;
    }
    int zapisi_datoteku(struct Cas raspored[], int broj_casova)
    {
    	int x;
    	int zapisano;
           FILE *dat=fopen("raspored.dat","wb");
           if(dat==NULL){
           	printf("greska pri otvaranju");
           	x=0;
           	return x;
           }
            zapisano=fwrite(raspored,sizeof(raspored),broj_casova,dat);
            if(zapisano<broj_casova){
            	printf("nisu svi zapisani");
            }
           if(ferror(dat)){
           	printf("greska prilikom pisanja");
           	x=0;
           	fclose(dat);
           	return x;
           }
           fclose(dat);
           return 1;
           
    	
    }
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan)
{
    int i;
    printf("Uneseni casovi su \n");
    for(i=0;i<broj_casova;i++)
    {
        if(raspored[i].dan_u_sedmici==dan){
            printf("%d %s (%d:%d0-%d:%d0)\n",i+1,raspored[i].predmet,raspored[i].pocetak.sati,
            raspored[i].pocetak.minute,raspored[i].kraj.sati,raspored[i].kraj.minute);
        }
    }
}
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj)
{int i,j;
int brojac=0;
    for(i=0;i<broj_casova;i++)
    {
        if(raspored[i].dan_u_sedmici==dan){
            brojac++;
            if(brojac==redni_broj){
                for(j=i;j<broj_casova-1;j++){
                    raspored[j]=raspored[j+1];
                }
                i--;
                broj_casova--;
            }
        }
    }
}
int dodaj_cas(struct Cas raspored[], int broj_casova,const char* predmet, int trajanje)
{
    int s=broj_casova+1;
if(s>KAPACITET){printf("Nema dovoljno mjesta!");
return 0;}

strcpy(raspored[broj_casova].predmet,predmet);




}


    
    



int main() {
    int opcija;
    int br1,br2;
    struct Cas raspored[KAPACITET];
  int brojcs;

/*do{
    printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju:");
    scanf("%d",&opcija);
    switch(opcija){
      case 0:zapisi_datoteku(raspored,brojcs);
      break;
      case 4:printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota):");
      scanf("%d",&br1);
      ispisi_dan(raspored,brojcs,br1);
      printf("Izaberite koji cas zelite obrisati: ");
      scanf("%d",&br2);
      obrisi_cas(raspored,brojcs,br1,br2);
      printf("Cas obrisan :)");
      break;
      
    }
}while(opcija!=0);*/
struct Cas pomocni_raspored[200];
 printf ("%i ", dodaj_cas(pomocni_raspored,0,A,1));
 printf ("%i ", dodaj_cas(pomocni_raspored,1,"TP",1));
 printf ("%i ", dodaj_cas(pomocni_raspored,2,"IF1",1));
 printf ("%i ", dodaj_cas(pomocni_raspored,3,"IM1",1));
 printf ("%i ", dodaj_cas(pomocni_raspored,4,"LAG",1));
 printf ("%i ", dodaj_cas(pomocni_raspored,5,"OE",1));
 printf ("%i ", dodaj_cas(pomocni_raspored,6,"MLTI",1));
 printf ("%i ", dodaj_cas(pomocni_raspored,7,"IM2",1));
 printf ("%i ", dodaj_cas(pomocni_raspored,8,"ViS",1));
 printf ("%i ", dodaj_cas(pomocni_raspored,9,"OS",1));
 ispisi_dan(pomocni_raspored, 10, 1);
	
	return 0;
}

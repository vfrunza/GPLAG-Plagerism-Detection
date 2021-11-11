#include <string.h>
#include <stdio.h>
#define epsilon 0.0001

struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena; 
};
int uporedi(char*s1,char*s2) {
	if(strcmp(s1,s2)==0) return 0;
	if(strcmp(s1,s2)<0)return 1;
	else return 2;
}
float prosjek(int niz[],int vel) {
	if(vel==0) return 5;
	int i=0,suma=0;
	for(i=0;i<vel;i++)
	if (niz[i]==5) return 5;
	for(i=0;i<vel;i++)
	suma=suma+niz[i];
	return(float)suma/vel; }
	int dalijeveci(struct Student pr,struct Student dr){
		float prosjekprvog=prosjek(pr.ocjene,pr.br_ocjena);
		float prosjekdrugog=prosjek(dr.ocjene,dr.br_ocjena);
		int sta_je_vratila_f=uporedi(pr.prezime,dr.prezime);
		if(prosjekprvog>prosjekdrugog) return 1;
		if(prosjekprvog<prosjekdrugog) return 0;
		if(sta_je_vratila_f==1) return 1;
		if(sta_je_vratila_f==2) return 0;
		int nesto=uporedi(pr.ime,dr.ime);
		if(nesto==1) return 1;
		if(nesto==2) return 0;
		else return 1; }
		int izbacivanj(struct Student niz[],int vel,double prosjekk){
			int i;int j; int izmjena=0;
			for(i=0;i<vel;i++){
				izmjena=0;
				if (prosjekk-prosjek(niz[i].ocjene,niz[i].br_ocjena)>epsilon) izmjena=1;
			if(izmjena==1){
				for(j=i;j<vel-1;j++){
					niz[j]=niz[j+1];
				}
				vel--; i--;
			} }return vel;}
			int genijalci(struct Student niz[],int vel, double prosjekk) {
				int i,indexprvi,indexdrugi,indextreci,indexmin=0;
				double min=10;
				
				vel=izbacivanj(niz,vel,prosjekk);
				if(vel==0) return 0;
				for(i=0;i<vel;i++) {
					if(min-prosjek(niz[i].ocjene,niz[i].br_ocjena)>epsilon){
						min=prosjek(niz[i].ocjene,niz[i].br_ocjena);
						indexmin=i;
					}
				}
				indexprvi=indexmin;
				indexdrugi=indexmin;
				indextreci=indexmin;
				if(vel==1){
					printf("\n%s %s",niz[indexprvi].prezime,niz[indexprvi].ime);
					return 1;
				}
			if(vel==2){
				for(i=0;i<vel;i++) {
					if(dalijeveci(niz[i],niz[indexprvi])==1)
					indexprvi=i;}
					printf("%s %s\n",niz[indexprvi].prezime,niz[indexprvi].ime);
					for(i=0;i<vel;i++){
						if(dalijeveci(niz[i],niz[indexdrugi])==1 && i!=indexprvi){
							indexdrugi=i;
						}
					} printf("%s %s\n",niz[indexdrugi].prezime,niz[indexdrugi].ime);
					return 2;}
					else { 
						for(i=0;i<vel;i++){
							if(dalijeveci(niz[i],niz[indexprvi])==1)
							indexprvi=i;}
							printf("%s %s\n",niz[indexprvi].prezime,niz[indexprvi].ime);
							for(i=0;i<vel;i++){
								if(dalijeveci(niz[i],niz[indexdrugi])==1 && i!=indexprvi){
									indexdrugi=i;
								}
							}
							printf("%s %s\n",niz[indexdrugi].prezime,niz[indexdrugi].ime);
								for(i=0;i<vel;i++){
									if(dalijeveci(niz[i],niz[indextreci])==1 && i!=indexprvi && i!=indexdrugi)
									indextreci=i;
								}
				
							printf("%s %s\n",niz[indextreci].prezime,niz[indextreci].ime);
					}
						 return vel;
						}
						int main() {
							struct Student studenti[5]={
								{"Mujo","Mujic",{7,7,7,7,8},5},
								{"Meho","Mujic",{7,7,7,7,8},5},
								{"Beba","Bebic",{10, 10, 10, 10, 5}, 5} 
							};
						genijalci(studenti, 3, 6.5);
						return 0; }
			
	
	


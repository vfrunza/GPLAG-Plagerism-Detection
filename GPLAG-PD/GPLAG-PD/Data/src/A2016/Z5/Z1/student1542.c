#include <stdio.h>
#include <string.h>

struct Student {
	char ime [20],prezime[20];
	int ocjene [50];
	int br_ocjena;
};

void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

float prosjek(int niz[], int velicina){
	int i,suma=0;
	float pr;
	for(i=0;i<velicina;i++){
		if(niz[i]==5 || velicina==0) return 5;
		suma+=niz[i];
	}
		pr=(float)suma/velicina;
	return pr;
}

int genijalci (struct Student *niz,int velicina,float pros){
	int i,j,indeks=0,indeks2=0,indeks3=0;
	float max=0;
	for(i=0;i<velicina;i++){
		if(niz[i].br_ocjena==0 || prosjek(niz[i].ocjene,niz[i].br_ocjena)<pros){
			for(j=i;j<velicina-1;j++){
				niz[j]=niz[j+1];
			}
			velicina--;
			i--;
		}
	}
	if(velicina==0)return 0;
		for(i=0;i<velicina;i++){
			if(prosjek(niz[i].ocjene,niz[i].br_ocjena)>max){
			max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
			indeks=i;
			}
			else if(prosjek(niz[i].ocjene,niz[i].br_ocjena)==max){
				if(strcmp(niz[indeks].prezime,niz[i].prezime)>0){
					indeks=i;
					max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
				}
				else if(strcmp(niz[indeks].prezime,niz[i].prezime)==0 && strcmp(niz[indeks].ime,niz[i].ime)>0){
					indeks=i;
					max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
				}
			}
		}
		printf("%s %s\n",niz[indeks].prezime,niz[indeks].ime);
		max=0;
		indeks2=-1;
	
		for(i=0; i<velicina; i++){
			if(i==indeks)continue;
			else {
				indeks2=i;
				break;
			}
		}
		if(indeks2==-1)return velicina;
		max=prosjek(niz[indeks2].ocjene,niz[indeks2].br_ocjena);
		for(i=0; i<velicina; i++){
			if(i==indeks)continue;
			if(prosjek(niz[i].ocjene,niz[i].br_ocjena)>max){
				max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
				indeks2=i;
			}
		else if(prosjek(niz[i].ocjene,niz[i].br_ocjena)==max){
			if(strcmp(niz[indeks2].prezime,niz[i].prezime)>0){
				indeks2=i;
				max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
			}
			else if(strcmp(niz[indeks2].prezime,niz[i].prezime)==0 && strcmp(niz[indeks2].ime,niz[i].ime)>0){
				indeks2=i;
				max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
			}
		}
		}
		printf("%s %s\n",niz[indeks2].prezime,niz[indeks2].ime);
		max=0;
		indeks3=-1;
		for(i=0; i<velicina; i++){
			if(i==indeks || i==indeks2)continue;
			else {
				indeks3=i;
				break;
			}
		}
		if(indeks3==-1)return velicina;
		max=prosjek(niz[indeks3].ocjene,niz[indeks3].br_ocjena);
		for(i=0; i<velicina; i++){
			if(i==indeks || i==indeks2)continue;
			if(prosjek(niz[i].ocjene,niz[i].br_ocjena)>max){
			max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
			indeks3=i;
			}
		else if(prosjek(niz[i].ocjene,niz[i].br_ocjena)==max){
			if(strcmp(niz[indeks3].prezime,niz[i].prezime)>0){
				indeks3=i;
				max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
			}
			else if(strcmp(niz[indeks3].prezime,niz[i].prezime)==0 && strcmp(niz[indeks3].ime,niz[i].ime)>0){
				indeks3=i;
				max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
			}
		}
		}
		printf("%s %s\n",niz[indeks3].prezime,niz[indeks3].ime);
		return velicina;
}
int main() {
	struct Student studenti[6] ={
		{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
		{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
		{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
		{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
		{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
		{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
	};
	genijalci(studenti, 6, 6.5);
	return 0;
}

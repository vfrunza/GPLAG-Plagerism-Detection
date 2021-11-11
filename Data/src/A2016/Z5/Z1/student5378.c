#include <stdio.h>
#include <string.h>
#include <math.h>
#define epsilon 0.0001
struct Student {
	char ime[20],prezime [20];
	int ocjene [50];
	int br_ocjena;
};
int uporedi(char*s1,char*s2){
	if(strcmp(s1,s2)==0) return 0;
	else {
		while(*s1!='\0'&& *s2!='\0'){
			if(*s1<*s2) return -1;
			if(*s1>*s2) return 1;
			s1++;
			s2++;
		}
		if(*s1!='\0') return 1;
		if(*s2!='\0') return -1;
	}
}
float prosjek(int niz[],int vel){
	if(vel==0) return 5;
	int i=0;
	float suma=0;
	for(i=0;i<vel;i++)
	if(niz[i]==5) return 5;
	else suma=suma+niz[i];
	float pr=suma/vel;
	return pr;
}
int dalijeveci(struct Student pr,struct Student dr,double prosjekk){
	if(prosjek(pr.ocjene,pr.br_ocjena)>prosjek(dr.ocjene,dr.br_ocjena)) return 1;
	if(prosjek(pr.ocjene,pr.br_ocjena)<prosjek(dr.ocjene,dr.br_ocjena)) return 0;
	if(uporedi(pr.prezime,dr.prezime)==-1) return 1;
	if(uporedi(pr.prezime,dr.prezime)==1) return 0;
	if(uporedi(pr.ime,dr.ime)==-1) return 1;
	if(uporedi(pr.ime,dr.ime)==1) return 0;
	else return 1;
}
void ispis(char*prezime,char*ime){
	printf("\n%s %s",prezime,ime);
}
int indexx(struct Student niz[],int vel){
	int indexmin=0,i,min;
	for(i=0;i<vel;i++){
		float temp_prosjek=prosjek(niz[i].ocjene,niz[i].br_ocjena);
		if(min-temp_prosjek>epsilon){
			min=temp_prosjek;
			indexmin=1;
		}
	}
	return indexmin;
}
int genijalci(struct Student niz[],int vel,double prosjekk){
	int i,j,indexprvi,indexdrugi,indextreci,indexmin=0;
	double maxprvi,maxdrugi,maxtreci,temp_prosjek,min=10;
	for(i=0;i<vel;i++){
		temp_prosjek=prosjek(niz[i].ocjene,niz[i].br_ocjena);
		if(prosjekk-temp_prosjek>epsilon){
			for(j=i;j<vel-1;j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	if(vel == 0 )return 0;
	indexmin=index(niz,vel);
	indexprvi=indexmin;
	indexdrugi=indexmin;
	indextreci=indexmin;
	if(vel==1){
		ispis(niz[indexprvi].prezime,niz[indexprvi].ime);
	return vel;
		
	}
	if(vel==2) goto dva;
	else goto tri;
	dva: 
	for(i=0;i<vel;i++)
	if(dalijeveci(niz[i],niz[indexprvi],prosjekk))
	indexprvi=i;
	for(i=0;i<vel;i++)
	if(dalijeveci(niz[i],niz[indexdrugi],prosjekk)&& i!=indexprvi)
	indexdrugi = i;
	ispis(niz[indexprvi].prezime,niz[indexprvi].ime);
	ispis(niz[indexdrugi].prezime,niz[indexdrugi].ime);
	return vel;
	
	tri :
	for(i=0;i<vel;i++)
	if(dalijeveci(niz[i],niz[indexprvi],prosjekk))
	indexprvi=i;
	for(i=0;i<vel;i++)
	if(dalijeveci(niz[i],niz[indexdrugi],prosjekk)&& i!=indexprvi)
	indexdrugi=i;
	for(i=0;i<vel;i++)
	if(dalijeveci(niz[i],niz[indextreci],prosjekk)&& i!=indexprvi && i!=indexdrugi)
	indextreci=i;
	ispis(niz[indexprvi].prezime,niz[indexprvi].ime);
	ispis(niz[indexdrugi].prezime,niz[indexdrugi].ime);
	ispis(niz[indextreci].prezime,niz[indextreci].ime);
	return vel;
}
int main() {
	struct Student studenti[] ={
		{"Meho","Behic",{10,9},2},
		{"Meho","Aehic",{10,8},2},
		{"Meho","Cehic",{10,9,8,7,6},5},
	} ;
	int i,vel=genijalci(studenti,3,9.8);
	printf("Vel: %dStudenti:",vel);
	for(i=0;i<vel;++i)
	printf("%s %s",studenti[i].prezime,studenti[i].ime);
	return 0;
}

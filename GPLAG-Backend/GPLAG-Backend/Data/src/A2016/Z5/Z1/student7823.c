#include <stdio.h>
#include <math.h>
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
    int br_ocjena;
};
int genijalci(struct Student *studenti, int velicinaNiza, float prosjek);
void izbaciClan(struct Student *niz, int duzinaNiza);
float prosjek(struct Student clan);
void ispisiNajbolje(struct Student *studenti, int velicinaNiza, float minProsjek);
int redoslijed(struct Student student0, struct Student student1);

int main() {
	//printf("Zadaća 5, Zadatak 1");
struct Student s = { "aaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaa", {}, 50 };
int i;
for (i=0; i<50; i++) s.ocjene[i]=10;
printf("Vel: %llu", sizeof s);
/* = 244 = 20*1 (char) + 20*1 (char) + 50*4 (int) + 4 (int) */

struct Student niz[1];
niz[0]=s;
genijalci(niz, 1, 9.9);
	return 0;
}

int genijalci(struct Student *studenti, int velicinaNiza, float minProsjek){
	int i;
	for(i=0; i<velicinaNiza; i++){
//		if(velicinaNiza==1 && !(prosjek(studenti[i])< minProsjek))	break;
		if(prosjek(studenti[i])< minProsjek){
			izbaciClan((studenti+i), velicinaNiza-i);
			velicinaNiza--;
			i--;
		}
	}
//	printf("\n%llu\n", velicinaNiza);
	ispisiNajbolje(studenti, velicinaNiza, minProsjek);
	return velicinaNiza;
}
void izbaciClan(struct Student *niz, int duzinaNiza){
	int i;
	for(i=1; i<duzinaNiza; i++){
		*(niz+i-1)= *(niz+i);
	}
}
float prosjek(struct Student clan){
	int i;
	float suma=0;
	for(i=0; i<clan.br_ocjena; i++){
		if(clan.ocjene[i]==5){
			break;
		}
		suma+=clan.ocjene[i];
	}
	if(clan.ocjene[i]==5 || clan.br_ocjena==0)
		return 5.0;
	return suma/clan.br_ocjena;
}
void ispisiNajbolje(struct Student *studenti, int velicinaNiza, float minProsjek){
	int i;
	int max0=0, max1=0, max2=0;
//	int tog0=0, tog1=0, tog2=0;
	//prvi najveci prosjek 
	for(i=0; i<velicinaNiza; i++){
		if(prosjek(studenti[i]) > prosjek(studenti[max0])){
			max0=i;
		}
	}
	for(i=0; i<velicinaNiza; i++){
		if(max0!=i && fabs(prosjek(studenti[max0])-prosjek(studenti[i]))<0.001){
			if(redoslijed(studenti[i], studenti[max0]))
				max0=i;
		}
	}
	//drugi najveci prosjek
	if(max0==max1 && velicinaNiza>1)
		max1=max0+1;
	for(i=0; i<velicinaNiza; i++){
		if(i!=max0 && prosjek(studenti[i]) > prosjek(studenti[max1])){
			max1=i;
		}
	}
	for(i=0; i<velicinaNiza; i++){
		if(max1!=i && max0!=i && fabs(prosjek(studenti[max1])-prosjek(studenti[i]))<0.001){
			if(redoslijed(studenti[i], studenti[max1]))
				max1=i;
		}
	}
	//treci najveci prosjek
	if((max0==max2 || max1==max2) && velicinaNiza>2)
		max2=max1+1;
	for(i=0; i<velicinaNiza; i++){
		if(i!=max0 && i!=max1 && prosjek(studenti[i]) > prosjek(studenti[max2])){
			max2=i;
		}
	}
	for(i=0; i<velicinaNiza; i++){
		if(max0!=i && max1!=i && max2!=i && fabs(prosjek(studenti[max2])-prosjek(studenti[i]))<0.001){
			if(redoslijed(studenti[i], studenti[max2]))
				max2=i;
		}
	}
	
	if(velicinaNiza>=3){
		printf("%s %s\n", studenti[max0].prezime, studenti[max0].ime);
		printf("%s %s\n", studenti[max1].prezime, studenti[max1].ime);
		printf("%s %s\n", studenti[max2].prezime, studenti[max2].ime);
	}
	if(velicinaNiza==2){
		printf("%s %s\n", studenti[max0].prezime, studenti[max0].ime);
		printf("%s %s\n", studenti[max1].prezime, studenti[max1].ime);
	}
	if(velicinaNiza==1)
		printf("%s %s\n", studenti[max0].prezime, studenti[max0].ime);
}
int redoslijed(struct Student student0, struct Student student1){
	int i=0;
	while(student0.prezime[i]!='\0' && student1.prezime[i]!='\0' && student0.prezime[i]==student1.prezime[i]) i++;
	if(student0.prezime[i] < student1.prezime[i])	return 1;
		else if(student1.prezime[i] < student0.prezime[i])	return 0;
			else{
				i=0;
				while(student0.ime[i]!='\0' && student1.ime[i]!='\0' && student0.ime[i]==student1.ime[i]) i++;
				if(student0.ime[i] < student1.ime[i])	return 1;
					else 
						return 0;
			}
	
}

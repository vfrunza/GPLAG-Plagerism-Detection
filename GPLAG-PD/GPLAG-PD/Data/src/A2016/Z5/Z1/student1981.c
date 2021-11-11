#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

void unesi(char niz[], int vel) {
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<vel-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

struct Student unos_osobe() {
	struct Student s;
	int i;
	unesi(s.ime,20);
	unesi(s.prezime,20);
	scanf("%d", &s.br_ocjena);
	
	for(i=0; i<s.br_ocjena; i++) 
	scanf("%d", &s.ocjene[i]);
	return s;
}


int genijalci(struct Student studenti[] ,int vel, float prosjek ) {
	float zbir=0;
	int i,j,s;
	float max=.00,niz[1000]={0.0};
	char ime[50]={""},prezime[50]={""};
	int br=0,index=0;
		
	for(i=0; i<vel; i++) {
		float p=0;
		if(studenti[i].br_ocjena==0) p=5.0;
		for(j=0; j<studenti[i].br_ocjena; j++) {
			zbir+=studenti[i].ocjene[j];
			if(studenti[i].ocjene[j]==5) {p=5.0; }
		}
		if(p!=5.0) p=zbir/studenti[i].br_ocjena;
		
		max=prosjek;
		if(max>p) {
			max=p;
		}
		niz[i]=p;
		if(p<prosjek) { 
			for(s=i; s<vel-1; s++) 
			studenti[s]=studenti[s+1];
			vel--;
			i--;
		}
		
		zbir=0;
	}
	/*sortiranje*/
	if(vel==0) return 0;
	if(vel==1) printf("%s %s", studenti[0].prezime,studenti[0].ime);
	if(vel==2) {
		
		if(niz[0]<niz[1]) {
			printf("%s %s\n", studenti[1].prezime,studenti[1].ime);
			printf("%s %s", studenti[0].prezime,studenti[0].ime);
		}
		
		if(niz[0]>niz[1]) {
			printf("%s %s\n", studenti[0].prezime,studenti[0].ime);
			printf("%s %s\n", studenti[1].prezime,studenti[1].ime);
		}
		else {
			if(strcmp(studenti[0].prezime,studenti[1].prezime)>0) {
				printf("%s %s\n", studenti[1].prezime,studenti[1].ime);
				printf("%s %s\n", studenti[0].prezime,studenti[0].ime);
				
			}
			if(strcmp(studenti[0].prezime,studenti[1].prezime)<0) {
				printf("%s %s\n", studenti[0].prezime,studenti[0].ime);
				printf("%s %s", studenti[1].prezime,studenti[1].ime);
			}
			if(strcmp(studenti[0].prezime,studenti[1].prezime)==0) {
				
				if(strcmp(studenti[0].ime,studenti[1].ime)<0) {
					printf("%s %s\n", studenti[0].prezime,studenti[0].ime);
					printf("%s %s", studenti[1].prezime,studenti[1].ime);
				}
				if(strcmp(studenti[0].ime,studenti[1].ime)>0) {
					printf("%s %s\n", studenti[1].prezime,studenti[1].ime);
					printf("%s %s", studenti[0].prezime,studenti[0].ime);
				}
				if(strcmp(studenti[0].ime,studenti[1].ime)==0) {
					printf("%s %s\n", studenti[1].prezime,studenti[1].ime);
					printf("%s %s", studenti[0].prezime,studenti[0].ime);
				}
				
			}
		}
	}
	
	
	if(vel==3) {
		for(i=0; i<vel; i++) {
			max=niz[0];
			strncpy(ime[i],studenti[0].ime,50);
			strncpy(prezime[i],studenti[0].prezime,50);
			index=0;
			for(j=1; j<vel; j++) { 
				if(niz[i]>max) {
					max=niz[i];
					strncpy(ime[i],studenti[j].ime,50);
					strncpy(prezime[i],studenti[j].prezime,50);
					index=j;
				}
			}
			
			for(j=0; j<vel; j++) { 
				if(niz[i]==max && index!=j) {
					if(strcmp(studenti[j].prezime,prezime[i])>0 || 
					strcmp(studenti[j].prezime,prezime[i])==0 ) {
						strncpy(ime[i],studenti[j].ime,50);
						strncpy(prezime[i],studenti[j].prezime,50);
						index=j;
					}
					
				}
				
			}
			
			niz[index]=0.0;
			printf("%s %s\n", studenti[index].prezime,studenti[index].ime);
		}
	}
	
	return vel;
}

int main() {
	struct Student studenti[100];
	struct Student s;
	int i=0,broj_studenata;
	float prosjek;
	
	scanf("%f", &broj_studenata);
	
	scanf("%f", &prosjek);
	
	for(i=0; i<broj_studenata; i++) 
	studenti[i]=unos_osobe();
	
	genijalci(studenti,i, prosjek);
	
	
	return 0;
}

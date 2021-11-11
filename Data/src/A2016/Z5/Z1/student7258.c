#include <stdio.h>
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float prosjecna_ocjena(int ocjene[], int vel) {
	int i;
	float prosjek,suma=0;
	for(i=0;i<vel;i++) {
	    if(ocjene[i]==5) return 5;
		suma=suma+ocjene[i];
	}
	prosjek=suma/vel;
	return prosjek;
}

int leksikografski (struct Student student1, struct Student student2) {
    char *prezime1=student1.prezime,*ime1=student1.ime,*prezime2=student2.prezime,*ime2=student2.ime;
    while((*prezime1!='\0') && (*prezime2!='\0')) {
        if(*prezime1>*prezime2) return 1;
        if(*prezime2>*prezime1) return 0;
        prezime1++;
        prezime2++;
    }
    if((*prezime1=='\0') && (*prezime2=='\0')) {
        while((*ime1!='\0') && (*ime2!='\0')) {
            if(*ime1>*ime2) return 1;
            else if(*ime2>*ime1) return 0;
            ime1++;
            ime2++;
        }
        if(*ime1!='\0') return 0;
        else if(*ime2!='\0') return 1;
    }
    else if(*prezime1!='\0') return 0;
    else if(*prezime2!='\0') return 1;
   
    return 1;
}

void najbolji (struct Student studenti[], int velicina) {
    int i;
    struct Student *jedan = NULL, *dva = NULL, *tri = NULL, *max = NULL;
    if(velicina!=0) {
        max=&studenti[0];
        for(i=0;i<velicina;i++) {
            if(prosjecna_ocjena((*max).ocjene, (*max).br_ocjena)<prosjecna_ocjena(studenti[i].ocjene, studenti[i].br_ocjena)) max=&studenti[i];
        	else if((prosjecna_ocjena((*max).ocjene, (*max).br_ocjena))==prosjecna_ocjena(studenti[i].ocjene, studenti[i].br_ocjena)) {
        	if(leksikografski(*max, studenti[i])) max=&studenti[i];
        	}
        }
        jedan=max;
    }
    if(velicina>1) {
        max=&studenti[0];
        if(max==jedan) max++;
        for(i=0;i<velicina;i++) {
            if(jedan==&studenti[i]) continue;
            else if(prosjecna_ocjena((*max).ocjene,(*max).br_ocjena)<prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena)) max=&studenti[i];
        	else if((prosjecna_ocjena((*max).ocjene, (*max).br_ocjena))==prosjecna_ocjena(studenti[i].ocjene, studenti[i].br_ocjena)) {
        	if(leksikografski(*max, studenti[i])) max=&studenti[i];
        	}
        }
        dva=max;
    }
    if(velicina>2) {
        max=&studenti[0];
        while(max==jedan||max==dva) max++;
        for(i=0;i<velicina;i++) {
            if((jedan==&studenti[i])||(dva==&studenti[i])) continue;
            else if(prosjecna_ocjena((*max).ocjene, (*max).br_ocjena)<prosjecna_ocjena(studenti[i].ocjene, studenti[i].br_ocjena)) max=&studenti[i];
        	else if((prosjecna_ocjena((*max).ocjene, (*max).br_ocjena))==prosjecna_ocjena(studenti[i].ocjene, studenti[i].br_ocjena)) {
        	if(leksikografski(*max, studenti[i])) max=&studenti[i];
        	}
        }
        tri=max;
    }
    if(jedan!=NULL) printf("%s %s\n",(*jedan).prezime,(*jedan).ime);
    if(dva!=NULL) printf("%s %s\n",(*dva).prezime,(*dva).ime);
    if(tri!=NULL) printf("%s %s\n",(*tri).prezime,(*tri).ime);
}
 
int genijalci(struct Student studenti[], int velicina, float prosjek) {
	int i,j,nova_velicina;
	for(i=0;i<velicina;i++) {
	    if(studenti[i].br_ocjena==0) {
	        for(j=i;j<velicina-1;j++) {
	            studenti[j]=studenti[j+1];
	        }
	    }
		if(prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena)<prosjek) {
			for(j=i;j<velicina-1;j++) {
				studenti[j]=studenti[j+1];
			}
			i--;
			velicina--;
		}
	}
	nova_velicina=velicina;
	najbolji(studenti,nova_velicina);
	
	return nova_velicina;
}

int main() {
	struct Student studenti[6]={
	{"Mujo","Mujic",{7,7,7,7,8},5},
	{"Meho","Mujic",{7,7,7,7,8},5},
	{"Pero","Peric",{8,8,8,8,7},5},
	{"Beba","Bebic",{6,6,6,6,6},5},
	{"Mujo","Mujic",{7,7,7,7,8},5},
	{"Fata","Fatic",{7,7,7,7,8},5},
	};
	genijalci(studenti,6,6.5);
	return 0;
}

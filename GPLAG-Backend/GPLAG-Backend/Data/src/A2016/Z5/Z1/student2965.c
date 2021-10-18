#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
/*Funkcija 'p_ocjena' kao rezultat vraca prosjek ocjena studenta'*/
double p_ocjena(struct Student m) {
    double suma=0,prosjek;
    int i;
	for(i=0; i<m.br_ocjena; i++) {
		suma=suma+m.ocjene[i];
		if(m.ocjene[i]==0 || m.ocjene[i]==5) return 5;
	}
	if(suma==0) return 5;
	prosjek=suma/m.br_ocjena; 
	return prosjek;
}

int genijalci(struct Student studenti[10000], int broj_studenata, double prosjek) {
	double prosjek_st[10000];
	int i,j,s,p,max=0,tri_studenta[3]={0};
	/*Ako je prosjek studenata manji od unesenog, ti se studenti izbacuju*/
	for(i=0;i<broj_studenata;i++) {
		prosjek_st[i]=p_ocjena(studenti[i]);
		if(prosjek_st[i]<prosjek) {
			for(j=i;j<broj_studenata-1;j++) {
				studenti[j]=studenti[j+1];
			}
			broj_studenata--;
			i--;
		}	
	}
	/*Trazimo studenta sa najvecim prosjekom*/
	max=0;
	for(i=1; i<broj_studenata; i++) {
		if(prosjek_st[i]>prosjek_st[max]) max=i;
		else if(prosjek_st[i]==prosjek_st[max]){
			s=strcmp(studenti[i].ime,studenti[max].ime);
			if(s>0) continue;
			else if(s<0) max=i;
			else if(s==0) {
				p=strcmp(studenti[i].prezime,studenti[max].prezime);
				if(p<0) max=i;
				else continue;
			}
		}
		else continue;
	}
	/*Trazimo studenta drugog po prosjeku*/
	tri_studenta[0]=max;
	max=0;
	for(i=1; i<broj_studenata; i++) {
		if(prosjek_st[i]>prosjek_st[max] && i!=tri_studenta[0]) max=i;
		else if(prosjek_st[i]==prosjek_st[max] && i!=tri_studenta[0]) {
			s=strcmp(studenti[i].ime,studenti[max].ime);
			if(s>0) continue;
			else if(s<0) max=i;
			else if(s==0) {
				p=strcmp(studenti[i].prezime,studenti[max].prezime);
				if(p<0) max=i;
				else continue;
			}
		}
		else continue;
	}
	/*Trazimo studenta treceg po prosjeku*/
	tri_studenta[1]=max;
	max=0;
	for(i=1; i<broj_studenata; i++) {
		if(prosjek_st[i]>prosjek_st[max] && i!=tri_studenta[0] && i!=tri_studenta[1]) max=i;
		else if(prosjek_st[i]==prosjek_st[max] && i!=tri_studenta[0] && i!=tri_studenta[1]) {
			s=strcmp(studenti[i].ime,studenti[max].ime);
			if(s>0) continue;
			else if(s<0) max=i;
			else if(s==0) {
				p=strcmp(studenti[i].prezime,studenti[max].prezime);
				if(p<0) max=i;
				else continue;
			}
		}
		else continue;
	}
	tri_studenta[2]=max;
	if(tri_studenta[0]==0) {
		tri_studenta[1]++;
		tri_studenta[2]++;
	}
	/*Ako ne postoje tri studenta koji zadovoljavaju prosjek, već ih ima manje*/
	if(broj_studenata<3) {
		for(i=0; i<broj_studenata; i++) {
			printf("%s %s\n",studenti[tri_studenta[i]].prezime,studenti[tri_studenta[i]].ime);
		}
	}
	else {
		printf("%s %s\n",studenti[tri_studenta[0]].prezime,studenti[tri_studenta[0]].ime);
		printf("%s %s\n",studenti[tri_studenta[1]].prezime,studenti[tri_studenta[1]].ime);
		printf("%s %s\n",studenti[tri_studenta[2]].prezime,studenti[tri_studenta[2]].ime);
	}
	return broj_studenata;
}
	
int main() {

	return 0;
}
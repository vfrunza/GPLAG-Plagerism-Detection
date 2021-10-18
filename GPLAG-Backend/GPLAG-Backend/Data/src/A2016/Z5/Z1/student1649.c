#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPSILON 0.0001

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
/*Funkcija za racunanje prosjeka ocjena studenta*/
float prosjekStudenta(struct Student student){
	int i,suma=0;
	float prosjek;
	/*Ako nema ocjena prosjeku mu je 5.0*/
	if(student.br_ocjena==0) return 5.0;
	for(i=0;i<student.br_ocjena;i++){
		/*Ako student ima jednu ocjenu 5 prosjek mu je 5.0*/
		if(student.ocjene[i]==5) return 5.0;
			else suma+=student.ocjene[i];
	}
	prosjek=(float)suma/(student.br_ocjena);
	return prosjek;
}

int genijalci(struct Student* studenti, int velicina, float prosjek){
	int i, j, leksikografskiIme, leksikografskiPrezime;
	float prosjekStudentai, prosjekPrvog, prosjekDrugog, prosjekTreceg;
	struct Student* prvi=NULL;
	struct Student* drugi=NULL;
	struct Student* treci=NULL;
	/*Racunanje prosjeka studenta i izbacivanje iz niza ako je njegov prosjek manji od unesenog*/
	for(i=0;i<velicina;i++){
		prosjekStudentai=prosjekStudenta(studenti[i]);
		if(prosjekStudentai<prosjek){
			for(j=i;j<velicina-1;j++){
				studenti[j]=studenti[j+1];
			}
			i--;
			velicina--;
		}
	}
	/*Trazenje studenta sa najvecim prosjekom*/
	for(i=0;i<velicina;i++){
		/*Prvog studenta u nizu postavljamo kao prvog po prosjeku*/
		if(i==0) prvi=studenti+i;
		prosjekStudentai=prosjekStudenta(studenti[i]);
		prosjekPrvog=prosjekStudenta(*(prvi));
		/*Ako je prosjek i-toga studenta veci od prosjeka (trenutno) prvog po prosjeku, on postaje prvi.*/
		if(prosjekStudentai>prosjekPrvog) prvi=studenti+i;
			/*Ako je prosjek i-toga studenta jednak prosjeku (trenutno) prvog po prosjeku vrsi se leksikografska provjera
			prvo prezimena a zatim imena preko funkcije strcmp. Ako i-ti student nije prije prvog ni po prezimenu ni po imenu nista se ne desava.*/
			else if(fabs(prosjekStudentai-prosjekPrvog)<EPSILON){
				leksikografskiIme=strcmp(studenti[i].ime,(*prvi).ime);
				leksikografskiPrezime=strcmp(studenti[i].prezime,(*prvi).prezime);
				if(leksikografskiPrezime<0)	prvi=studenti+i;
					else if(leksikografskiIme<0) prvi=studenti+i;
			}
	}
	/*Prvog studenta u nizu koji nije prvi postavljamo kao drugog po prosjeku*/
	for(i=0;i<velicina;i++){
		if((studenti+i)!=prvi){
			drugi=studenti+i;
			break;
		}
	}
	for(i=0;i<velicina;i++){
		if(drugi==NULL) break;
		prosjekStudentai=prosjekStudenta(studenti[i]);
		prosjekDrugog=prosjekStudenta(*(drugi));
		/*Ako u nizu postoji student koji ima prosjek veci od drugog a nije prvi postaje drugi*/
		if((prosjekStudentai>prosjekDrugog) && (studenti+i)!=prvi ) drugi=studenti+i;
			/*Ako i-ti student ima prosjek jednak prosjeku drugog po prosjeku a nije prvi po prosjeku vrsi se leksikografska provjera*/
			else if(fabs(prosjekStudentai-prosjekDrugog)<EPSILON && (studenti+i)!=prvi ){
				leksikografskiIme=strcmp(studenti[i].ime,(*drugi).ime);
				leksikografskiPrezime=strcmp(studenti[i].prezime,(*drugi).prezime);
				if(leksikografskiPrezime<0)	drugi=studenti+i;
					else if(leksikografskiIme<0) drugi=studenti+i;
			}
	}
	/*Prvog studenta u nizu koji nije prvi ni drugi postavljamo kao treceg po prosjeku*/
	for(i=0;i<velicina;i++){
		if((studenti+i)!=prvi && (studenti+i)!=drugi){
			treci=studenti+i;
			break;
		}
	}
	for(i=0;i<velicina;i++){
		if(treci==NULL) break;
		prosjekStudentai=prosjekStudenta(studenti[i]);
		prosjekTreceg=prosjekStudenta(*(treci));
		/*Ako u nizu postoji student koji ima prosjek veci od treceg a nije ni prvi ni drugi postaje treci*/
		if((prosjekStudentai>prosjekTreceg) && (studenti+i)!=prvi && (studenti+i)!=drugi) treci=studenti+i;
			/*Ako i-ti student ima prosjek jednaku prosjeku treceg a nije ni prvi ni drugi po prosjeku vrsi se leksikografska provjea prezimena pa imena.*/
			else if((prosjekStudentai-prosjekTreceg)<EPSILON && (studenti+i)!=prvi && (studenti+i)!=drugi){
				leksikografskiIme=strcmp(studenti[i].ime,(*treci).ime);
				leksikografskiPrezime=strcmp(studenti[i].prezime,(*treci).prezime);
				if(leksikografskiPrezime<0)	treci=studenti+i;
					else if(leksikografskiIme<0) treci=studenti+i;
			}
	}
	/*Stampanje imena prvog, drugog i treceg studenta po prosjeku (ako postoje)*/
	if(prvi!=NULL) printf("%s %s\n", (*prvi).prezime, (*prvi).ime);
	if(drugi!=NULL) printf("%s %s\n", (*drugi).prezime, (*drugi).ime );
	if(treci!=NULL) printf("%s %s", (*treci).prezime, (*treci).ime );
	return velicina;
}
int main() {
	
	return 0;
}

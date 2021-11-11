#include <stdio.h>
#include <math.h>
#define EPS 0.000001

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

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

struct O_studentima { /*struktura koja u sebi sadrži podatke iz strukture Student i prosjeka tog studenta*/
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
	double prosjek;
};

int prebroji(char *niz){ /*funkcija za prebrojavanje slova u riječi*/
	int i=0, brojac=0;
	while(niz[i]!='\0'){
		brojac++;
		i++;
	}
	return brojac;
}

int genijalci (struct Student *Student, int vel, double prosjek){
	int i, j, k, suma, pao_ispit=0, br_slova1, br_slova2, tacno_je, prezime, ime;
	double prosjek_studenta[500];
	struct O_studentima svi_podaci[500], prvi, drugi, treci;
	suma=0;
	for(i=0; i<vel; i++){ /*petlja kroz niz struktura Student*/
		suma=0;
		pao_ispit=0;
		for(j=0; j<Student[i].br_ocjena; j++){ /*provjerava da li je student pao jedan ispit*/
			if(Student[i].ocjene[j]==5){
				pao_ispit=1;
				break;
			}
			suma+=Student[i].ocjene[j];
		}
		/*računanje prosjeka studenta*/
		if(pao_ispit==1 || Student[i].br_ocjena==0) prosjek_studenta[i]=5.00;
		else prosjek_studenta[i]=(double)suma/Student[i].br_ocjena;
		/*izbacivanje studenta iz niza ukoliko je prosjek studenta manji od zadatog*/
		if(prosjek>prosjek_studenta[i]){ 
			for(k=i; k<vel-1; k++){
				Student[k]=Student[k+1];
				prosjek_studenta[i]=prosjek_studenta[i+1];
			}
			vel--;
			i--;
		}
	}
	/*prebacivanje svih podataka o studentima iz niza struktura i niza prosjek_studenta u jedinstvenu strukturu*/
	for(i=0; i<vel; i++){
		for(j=0; j<20; j++) svi_podaci[i].ime[j]=Student[i].ime[j];
		for(j=0; j<20; j++) svi_podaci[i].prezime[j]=Student[i].prezime[j];
		svi_podaci[i].br_ocjena=Student[i].br_ocjena;
		for(j=0; j<50; j++) svi_podaci[i].ocjene[j]=Student[i].ocjene[j];
		svi_podaci[i].prosjek=prosjek_studenta[i];
	}
	/*inicijalizovanje početnih vrijednosti prosjeka prvog, drugog i trećeg po redu na 0, koja se sigurno neće pojaviti u nizu struktura*/
	prvi.prosjek=0;
	drugi.prosjek=0;
	treci.prosjek=0;
	for(i=0; i<vel; i++){ /*petlja za pronalazak prvog, drugog i trećeg studenta po prosjeku*/
		if(fabs(svi_podaci[i].prosjek-prvi.prosjek)<EPS){ /*ispitivanje leksikografskog rasporeda*/
			br_slova1=prebroji(prvi.prezime);
			br_slova2=prebroji(svi_podaci[i].prezime);
			tacno_je=0;
			prezime=0;
			ime=0;
			if(br_slova1>=br_slova2){ /*provjerava da li je prezime studenta leksikografski ispred prvog*/
				for(k=0; k<br_slova2; k++){
					if(svi_podaci[i].prezime[k]<prvi.prezime[k]){
						prezime=1;
						break;
					}
				}
			}
			if(prezime==1){ 
			    br_slova1=prebroji(prvi.ime);
			    br_slova2=prebroji(svi_podaci[i].ime);
			    ime=0;
			    if(br_slova1>=br_slova2){
			    	for(k=0; k<br_slova2; k++){
			    		if(svi_podaci[i].ime[k]<prvi.ime[k]){
			    			ime=1;
			    			break;
			    		}
			    	}
			    }
			}
			if(prezime==1 && ime==1) tacno_je=1;
			if(tacno_je==1){
				treci=drugi;
				drugi=prvi;
				prvi=svi_podaci[i];
			}
		}
		else if(svi_podaci[i].prosjek>prvi.prosjek){
			treci=drugi;
			drugi=prvi;
			prvi=svi_podaci[i];
		}
		else if(fabs(svi_podaci[i].prosjek-drugi.prosjek)<EPS){
			br_slova1=prebroji(drugi.prezime);
			br_slova2=prebroji(svi_podaci[i].prezime);
			tacno_je=0;
			prezime=0;
			ime=0;
			if(br_slova1>=br_slova2){
				for(k=0; k<br_slova2; k++){
					if(svi_podaci[i].prezime[k]<drugi.prezime[k]){
						prezime=1;
						break;
					}
				}
			}
			if(prezime==1){
				br_slova1=prebroji(drugi.ime);
				br_slova2=prebroji(svi_podaci[i].ime);
				ime=0;
				if(br_slova1>=br_slova2){
					for(k=0; k<br_slova2; k++){
						if(svi_podaci[i].ime[k]<drugi.ime[k]){
							ime=1;
							break;
						}
					}
				}
			}
			if(prezime==1 && ime==1) tacno_je=1;
			if(tacno_je==1){
				treci=drugi;
				drugi=svi_podaci[i];
			}
		}
		else if(svi_podaci[i].prosjek>drugi.prosjek){
			treci=drugi;
			drugi=svi_podaci[i];
		}
	    	else if(fabs(svi_podaci[i].prosjek-treci.prosjek)<EPS){
			br_slova1=prebroji(treci.prezime);
			br_slova2=prebroji(svi_podaci[i].prezime);
			tacno_je=0;
			prezime=0;
			ime=0;
			if(br_slova1>=br_slova2){
				for(k=0; k<br_slova2; k++){
					if(svi_podaci[i].prezime[k]<treci.prezime[k]){
						prezime=1;
						break;
					}
				}
			}
			if(prezime==1){
				br_slova1=prebroji(treci.ime);
				br_slova2=prebroji(svi_podaci[i].ime);
				ime=0;
				if(br_slova1>=br_slova2){
					for(k=0; k<br_slova2; k++){
						if(svi_podaci[i].ime[k]<treci.ime[k]){
							ime=1;
							break;
						}
					}
				}
			}
			if(prezime==1 && ime==1) tacno_je=1;
			if(tacno_je==1){
				treci=svi_podaci[i];
			}
		}
		else if(svi_podaci[i].prosjek>treci.prosjek){
			treci=svi_podaci[i];
		}
	}
	if(prvi.prosjek!=0 && drugi.prosjek!=0 && treci.prosjek!=0){ /*ispisuje prva tri studenta iz niza, ukoliko postoje*/
		printf("%s %s\n%s %s\n%s %s", prvi.prezime, prvi.ime, drugi.prezime, drugi.ime, treci.prezime, treci.ime);
	}
	else if(treci.prosjek==0 && drugi.prosjek!=0 && prvi.prosjek!=0) printf("%s %s\n%s %s", prvi.prezime, prvi.ime, drugi.prezime, drugi.ime);
	else if(treci.prosjek==0 && drugi.prosjek==0 && prvi.prosjek!=0) printf("%s %s", prvi.prezime, prvi.ime);
	return vel;
}

int main() {
	struct Student Student[200];
	int i, j, vel, a;
	double prosjek;
	printf("Unesite velicinu: ");
	scanf("%d", &vel);
	for(i=0; i<vel; i++){
		printf("Unesite ime: ");
		unesi(Student[i].ime, 20);
		printf("Unesite prezime: ");
		unesi(Student[i].prezime, 20);
		printf("Unesite broj ocjena: ");
		scanf("%d", &Student[i].br_ocjena);
		for(j=0; j<Student[i].br_ocjena; j++){
			scanf("%d", &Student[i].ocjene[j]);
		}
	}
	printf("Unesite prosjek: ");
	scanf("%lf", &prosjek);
	a=genijalci(Student, vel, prosjek);
	printf("%d", a);
	return 0;
}

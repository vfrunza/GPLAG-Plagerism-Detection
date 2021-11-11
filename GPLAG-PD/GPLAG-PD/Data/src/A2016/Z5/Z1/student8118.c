#include <stdio.h>
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/*Funkcija za racunanje prosjeka studenata*/
float racunanje_prosjeka (int *ocjena, int broj_ocjena) {
	int i, s=0;
	float prosjek;
	for (i=0; i<broj_ocjena; i++) {
/*Ako postoji ijedna ocjena 5, smatra se da je prosjek studenta 5 (po uslovu zadatka)*/
        if (ocjena[i]==5) return 5;
		s=s+ocjena[i];
	}
/*Ako student nema nijednu ocjenu, smatra se da je njegov prosjek 5 (po uslovu zadatka)*/
	if (i==0) return 5;
	prosjek=(float)s/broj_ocjena;
	return prosjek;
}

/*Leksikografski poredak studenata*/
int Leksikografski (char *ime1, char *prez1, char *ime2, char *prez2) {
	while (*prez1!='\0' && *prez2!='\0') {
		if (*prez1<*prez2) return -1;
		if (*prez1>*prez2) return 1;
		prez1++;
		prez2++;
	}
	if (*prez1!='\0') return 1;
	if (*prez2!='\0') return -1;
	while (*ime1!='\0' && *ime2!='\0') {
		if(*ime1<*ime2) return -1;
		if (*ime1>*ime2) return 1;
		ime1++;
		ime2++;
	}
	if (*ime1!='\0') return 1;
	if (*ime2!='\0') return -1;
	return 0;
}
int genijalci (struct Student niz[], int vel, float prosjek) {
	int i, j, prvi, max1=0, max2=0, max3=0;
	float s1=0, s2=0, s3=0, prosj;
/*Izbacivanje studenta koji ne zadovoljava uneseni prosjek*/
	for (i=0; i<vel; i++) {
		if ((racunanje_prosjeka(niz[i].ocjene, niz[i].br_ocjena))<prosjek) {
			for (j=i; j<vel-1; j++) 
				niz[j]=niz[j+1];
			i--;
			vel--;
		}
	}
/*Ispisivanje imena i prezimena prva tri studenta sa najvecim prosjekom*/
    for (i=0; i<vel; i++) {
    	prosj=racunanje_prosjeka(niz[i].ocjene,niz[i].br_ocjena);
    	if (prosj>s1) {
    		s3=s2;
    		s2=s1;
    		s1=prosj;
    		max3=max2;
    		max2=max1;
    		max1=i;
    	}
        else if (prosj==s1) {
/*Ako dva student imaju isti prosjek ocjena, ispisujemo ih po leksikografskom poretku*/
       		prvi=Leksikografski(niz[i].ime, niz[i].prezime, niz[max1].ime, niz[max1].prezime);
       		if (prvi==-1) {
       			s3=s2;
       			s2=s1;
       			s1=prosj;
       			max3=max2;
       			max2=max1;
       			max1=i;
       		}
       		else if (prvi==1) {
       			prvi=Leksikografski(niz[i].ime, niz[i].prezime, niz[max2].ime, niz[max2].prezime);
       			if (prvi==-1) {
       				s3=s2;
       				s2=prosj;
       				max3=max2;
       				max2=i;
       		    }
       			else if (prvi==1) {
       				prvi=Leksikografski(niz[i].ime, niz[i].prezime, niz[max3].ime, niz[max3].prezime);
       				if (prvi==0 || prvi==-1) {
       					s3=prosj;
       					max3=i;
       				}
       			}
       		}
     		else if (prvi==0) {
    			s3=s2;
     			s2=prosj;
     			max3=max2;
     			max2=i;
     		}
       }
     	else if (prosj>s2) {
     		s3=s2;
     		s2=prosj;
     		max3=max2;
     		max2=i;
    	 }
    	 else if (prosj==s2) {
/*Ako dva student imaju isti prosjek ocjena, ispisujemo ih po leksikografskom poretku*/
     		prvi=Leksikografski(niz[i].ime, niz[i].prezime, niz[max2].ime, niz[max2].prezime);
    		if (prvi==1) {
     			prvi=Leksikografski(niz[i].ime, niz[i].prezime, niz[max3].ime, niz[max3].prezime);
     			if (prvi==-1) {
   					s3=prosj;
   					max3=i;
    			}
     		}
     		else if(prvi==-1) {
     			s3=s2;
     			s2=prosj;
     			max3=max2;
     			max2=i;
     		}
     		else if (prvi==0) {
     			s3=prosj;
     			max3=i;
     		}	
     	}
    	else if (prosj>s3) {
     		s3=prosj;
     		max3=i;
     	}
     	else if (prosj==s3) {
/*Ako dva student imaju isti prosjek ocjena, ispisujemo ih po leksikografskom poretku*/
     		prvi=Leksikografski(niz[i].ime, niz[i].prezime, niz[max3].ime, niz[max3].prezime);
     		if(prvi==-1) {
     			s3=prosj;
     			max3=i;
     		}
    		 else if (prvi==0) {
     			s3=prosj;
     			max3=i;
     		}	
        }
    }
    if(s1>0)
		 printf ("%s %s\n", niz[max1].prezime, niz[max1].ime);
    if(s2>0)
    	printf ("%s %s\n", niz[max2].prezime, niz[max2].ime);
    if(s3>0)
    	printf ("%s %s\n", niz[max3].prezime, niz[max3].ime);
	return vel;
}

int main() {
	struct Student studenti[4] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 4, 6.5);
	
	return 0;
}

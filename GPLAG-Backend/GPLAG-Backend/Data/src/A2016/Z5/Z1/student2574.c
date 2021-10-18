#include <stdio.h>
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float prosjek(int* niz,int velicina) {
        float *q = niz;
        double prosjekx = 0;
        double suma = 0;
        while(niz<q+velicina) {
                if (velicina==0) {
                        prosjekx=5.0;
                        return prosjekx;
                }
                if (*niz==5) {
                        prosjekx=5.0;
                        return prosjekx;
                }
                suma += *niz;
                niz++;
        }
        prosjekx = (double) suma/velicina;
        return prosjekx;
}

int uporedi(char* p1, char* p2, char* i1, char* i2) {
        while (*p1 != '\0' && *p2 != '\0') {
                if (*p1 < *p2) return -1;
                if (*p1 > *p2) return 1;
                p1++;
                p2++;
        }
        if (*p1 != '\0') return 1;
        if (*p2 != '\0') return -1;
        while (*i1 != '\0' && *i2 != '\0') {
                if (*i1 < *i2) return -1;
                if (*i1 > *i2) return 1;
                i1++;
                i2++;
        }
        if (*i1 != '\0') return 1;
        if (*i2 != '\0') return -1;
        return 0;
}

int genijalci (struct Student* niz, int velicina, float a) {
	int poredak=0,index1=0,index2=0,index3=0, i=0, j=0,k=0,x=velicina,max1=0,max2=0,max3=0;
	double prosjekstudenata=0;
	for (k=0;k<x;k++) {
	        prosjekstudenata = prosjek(niz[k].ocjene,niz[k].br_ocjena);
	        if (prosjekstudenata<a || prosjekstudenata<=5.0) {
		        for (j=k;j<x-1;j++) {
		                niz [j] = niz [j+1];
                        }
                        x--; 
                        k--;
                        }
                }
        for (k=0; k<x;k++) {
                prosjekstudenata = prosjek(niz[k].ocjene,niz[k].br_ocjena);
                        if (prosjekstudenata>max1) {
                                max3=max2;
                                index3=index2;
                                max2=max1;
                                index2=index1;
                                max1=prosjekstudenata;
                                index1=k;
                        }
                        else if(prosjekstudenata==max1) {
                                poredak=uporedi(niz[k].prezime, niz[max1].prezime,niz[k].ime, niz[max1].ime); 
                                if (poredak==-1) {
                                        if (prosjekstudenata>max2) {
                                                max3=max2;
                                                index3=index2;
                                        }
                                        else if(prosjekstudenata==max2) {
                                                poredak=uporedi(niz[k].prezime,niz[max2].prezime,niz[k].ime ,niz[max2].ime);
                                                if (poredak==-1) {
                                                        if (prosjekstudenata>max3) {
                                                                max3=k;
                                                        }
                                                        poredak=uporedi(niz[k].prezime,niz[max3].prezime,niz[k].ime ,niz[max3].ime);
                                                        if (poredak==1) { 
                                                                max3=prosjekstudenata;
                                                                index3=k;
                                                        }
                                                }        
                                                else if (poredak==1) {
                                                        max3=max2;
                                                        index3=index2;
                                                        max2=prosjekstudenata;
                                                        index2=k;
                                                        max1=max3;
                                                        index1=index3;
                                                }
                                        }
                                }
                                if (poredak==1) {
                                        poredak=uporedi(niz[max1].prezime,niz[max2].prezime,niz[max1].ime,niz[max2].ime); 
                                        if (poredak==-1) {
                                                poredak=uporedi(niz[max1].prezime,niz[max3].prezime,niz[max1].ime, niz[max3].ime);
                                                if (poredak==-1) {
                                                        poredak=uporedi(niz[max2].prezime,niz[max3].prezime,niz[max2].ime, niz[max3].ime);
                                                        if (poredak==-1) {
                                                                poredak=uporedi(niz[k].prezime,niz[max3].prezime,niz[k].ime, niz[max3].ime);
                                                                if (poredak==-1) {
                                                                        max3=max2;
                                                                        index3=index2;
                                                                        max2=prosjekstudenata;
                                                                        index2=k;
                                                                        max1=max3;
                                                                        index1=index3;
                                                                }
                                                                else if (poredak==1) {
                                                                        max1=prosjekstudenata;
                                                                        index1=k;
                                                                        max3=max2;
                                                                        index3=index2;
                                                                        max2=max3;
                                                                        index2=index3;
                                                                }
                                                        }
                                                        
                                                }
                                        }
                                }
                                   
                        }
        }
        for (i=0; i<x; ++i) {
                printf ("%s %s\n",niz[i].prezime,niz[i].ime);
        }
	return x;
}
	
int main() {
        int i=0,x=0;
        int velicina=20;
        int broj_genijalaca=0;
        struct Student studenti[20]={
            {"Meho", "Behic", {10, 9}, 2},
            {"Meho", "Aehic", {10, 8}, 2},
            {"Meho", "Cehic", {10, 9, 8, 7, 6}, 5},
            {"Meho", "Dehic", {6, 9}, 2},
            {"Meho", "Zehic", {10}, 1},
            {"Meho", "Oehic", {10, 9, 9, 9}, 4},
            {"Mujo", "Mujic", { 7,7,7,7,8}, 5},
            {"Neko", "Nekic", {10, 10, 5, 10, 10, 10, 10}, 7},
            {"Fata", "Fatic", { 7,7,7,7,8}, 5},
	    {"Meho", "Mujic", { 7,7,7,7,8}, 5}, 
            {"Pero", "Peric", { 8,8,8,8,7}, 5}, 
	    {"Beba", "Bebic", { 6,6,6,6,6}, 5},
	    { "Beba", "Bebic", {}, 0},
	    { "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}, 29}, 
	    { "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6}, 29}, 
        };
        double prosjek=0;
        printf("Prosjek: ");
        scanf ("%lf",&prosjek);
        x=genijalci(studenti,velicina,prosjek);
	printf ("%d\n",x);
	for(i=0; i<x;++i) {
	        printf ("%s %s \n",studenti[i].prezime,studenti[i].ime);
	}
	return 0;
}

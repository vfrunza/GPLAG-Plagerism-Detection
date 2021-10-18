#include <stdio.h>
#include <string.h>
struct Student {
char ime[20], prezime[20];
int ocjene[50];
	int br_ocjena;
};
/* Funkcija za racunanje prosjeka ocjena */
float prosjekstudenta(int *niz,int brojocjena){
	if(brojocjena==0) return 5;
	int i,suma=0;
	double prosjek1;
	for (i=0;i<brojocjena;i++){
		if(niz[i]==5) return 5;
		else suma+=niz[i];
	}
	prosjek1=(float)suma/brojocjena;
	return prosjek1;
}
int genijalci(struct Student *niz,int velicina,double prosjek){
	int i,j;
	/* Izbacivanje studenata sa manjim prosjekom od zadatog */
	for (i=0;i<velicina;i++){
		if (prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena)<prosjek){
			for (j=i;j<velicina-1;j++){
				niz[j]=niz[j+1];
			}
			velicina--;
			i--;
		}
	}
	/* Trazenje najboljih studenata */
	int max1=0,max2=0,max3=0;
	double prosjek1=0,prosjek2=0,prosjek3=0;
	for (i=0;i<velicina;i++){
		if ((prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena))>=prosjek&&prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena)>prosjek1){
			max1=i; 
			prosjek1=prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena);
		}
	}
	for (i=0;i<velicina;i++){
		if ((prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena))>=prosjek&&i!=max1&&prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena)>prosjek2){
			max2=i; 
			prosjek2=prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena);
		}
	}
	for (i=0;i<velicina;i++){
		if ((prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena))>=prosjek&&i!=max1&&i!=max2&&prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena)>prosjek3){
			max3=i; 
			prosjek3=prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena);
		}
	}
	int tmp;
	/* Leksikografsko poredjenje, a zatim ispis */
	for (i=0;i<velicina;i++){
		if (prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena)==prosjek1&&i!=max1){
			if (strcmp (niz[max1].prezime,niz[i].prezime)>0) {
				tmp=max1;
				max1=i;
			}
			if (max2==max1) max2=tmp;
			if (max3==max1) max3=tmp;
		}
	}
	for (i=0;i<velicina;i++){
		if (prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena)==prosjek2&&i!=max2&&i!=max1){
			if (strcmp (niz[max2].prezime,niz[i].prezime)>0){
				tmp=max2;
				max2=i;
			
			}
			if (max3==max2) max3=tmp;
		}
	}
	for (i=0;i<velicina;i++){
		if (prosjekstudenta(niz[i].ocjene,niz[i].br_ocjena)==prosjek3&&i!=max3&&i!=max1&&i!=max2){
			if (strcmp (niz[max3].prezime,niz[i].prezime)>0) max3=i;
		}
	}
	if (prosjek1!=0) printf ("%s %s \n",niz[max1].prezime,niz[max1].ime);
	if (prosjek2!=0) printf ("%s %s \n",niz[max2].prezime,niz[max2].ime);
	if (prosjek3!=0) printf ("%s %s \n",niz[max3].prezime,niz[max3].ime);

	
	return velicina;
	
	
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

#include <stdio.h>
#include <string.h>

void unesi (char niz[], int velicina){
	char znak=getchar();
	int i=0;
	if (znak=='\n')
		znak=getchar();
	while (i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double s_prosjek (int niz[], int velicina){
	int i=0,suma=0;
	for (i=0;i<velicina;i++){
		suma=suma+niz[i];
	}
	return (float)suma/velicina;
}

int prosjek_pet (int niz[], int velicina){
	int i=0;
	if (velicina==0)
		return 1;
	for (i=0;i<velicina;i++){
		if (niz[i]==5)
			return 1;
	}
	return 0;
}

int genijalci (struct Student s[],int velicina, double prosjek){
	int i,j,ostali,index_1,index_2,index_3,br_1=0;
	double max_1,max_2,max_3;
	for (i=0;i<velicina;i++){
		if (prosjek_pet(s[i].ocjene,s[i].br_ocjena) || s_prosjek(s[i].ocjene,s[i].br_ocjena)<prosjek ){
			for (j=i;j<velicina-1;j++){
				s[j]=s[j+1];
			}
			velicina--;
			i--;
		}
	}
	ostali=velicina;
	if (velicina==0)
		return velicina;
	else if (velicina>=3){
		max_1=-1;
		for (i=0;i<velicina;i++){
			if (s_prosjek(s[i].ocjene,s[i].br_ocjena)>max_1){
				max_1=s_prosjek(s[i].ocjene,s[i].br_ocjena);
				index_1=i;
			}
		}
	for (i=0;i<velicina-1;i++){
		for (j=i+1;j<velicina;j++){
			if (s_prosjek(s[i].ocjene,s[i].br_ocjena)==s_prosjek(s[j].ocjene,s[j].br_ocjena))
				br_1++;
		}
	}
	
		max_2=-1;
		for (i=0;i<velicina;i++){
			if (s_prosjek(s[i].ocjene,s[i].br_ocjena)>max_2 && s_prosjek(s[i].ocjene,s[i].br_ocjena)<max_1 && (s[i].ime!=s[index_1].ime || s[i].prezime!=s[index_1].prezime)){
				max_2=s_prosjek(s[i].ocjene,s[i].br_ocjena);
				index_2=i;
			}
		}
		max_3=-1;
		for (i=0;i<velicina;i++){
			if (s_prosjek(s[i].ocjene,s[i].br_ocjena)>max_3 && s_prosjek(s[i].ocjene,s[i].br_ocjena)<=max_2 && (s[i].ime!=s[index_2].ime || s[i].prezime!=s[index_2].prezime) && (s[i].ime!=s[index_1].ime || s[i].prezime!=s[index_1].prezime) ){
				max_3=s_prosjek(s[i].ocjene,s[i].br_ocjena);
				index_3=i;
			}
		}
	
			printf ("%s %s\n", s[index_1].prezime, s[index_1].ime);
			printf ("%s %s\n", s[index_2].prezime, s[index_2].ime);
			printf ("%s %s\n", s[index_3].prezime, s[index_3].ime);
	} 
	else if (velicina==2){
		max_1=-1;
		for (i=0;i<velicina;i++){
			if (s_prosjek(s[i].ocjene,s[i].br_ocjena)>max_1){
				max_1=s_prosjek(s[i].ocjene,s[i].br_ocjena);
				index_1=i;
			}
				
		}
		max_2=-1.0;
		for (i=0;i<velicina;i++){
			if (s_prosjek(s[i].ocjene,s[i].br_ocjena)>max_2 && s_prosjek(s[i].ocjene,s[i].br_ocjena)<max_1){
				max_2=s_prosjek(s[i].ocjene,s[i].br_ocjena);
				index_2=i;
			}
		}
			printf ("%s %s\n", s[index_1].prezime, s[index_1].ime);
			printf ("%s %s\n", s[index_2].prezime, s[index_2].ime);
	}
	
	else if (velicina==1){
		max_1=-1;
		for (i=0;i<velicina;i++){
			if (s_prosjek(s[i].ocjene,s[i].br_ocjena)>max_1){
				max_1=s_prosjek(s[i].ocjene,s[i].br_ocjena);
				index_1=i;
			}
		}
			printf ("%s %s\n", s[index_1].prezime, s[index_1].ime);
	}
	return ostali;
}

int main() {
	/*printf("Zadaća 5, Zadatak 1");*/
	struct Student s[100];
	int i,j,velicina;
	double prosjek;
	printf ("Unesite velicinu niza student: "),
	scanf ("%d", &velicina);
	for (i=0;i<velicina;i++){
		printf ("Unesite ime studenta: ");
		unesi (s[i].ime,20);
		printf ("Unesite prezime studenta: ");
		unesi (s[i].prezime,20);
		printf ("Unesite broj ocjena: ");
		scanf ("%d", &s[i].br_ocjena);
		printf ("Unesite ocjene: ");
		for (j=0;j<s[i].br_ocjena;j++){
			scanf ("%d", &s[i].ocjene[j]);
		}
	}
	printf ("Unesite prosjek sa kojim poredimo: ");
	scanf ("%lf", &prosjek);
	genijalci(s,velicina,prosjek);
	return 0;
}

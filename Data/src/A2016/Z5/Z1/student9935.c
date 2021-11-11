#include <stdio.h>

void unesi(char niz[], int velicina) {
	int i = 0;
	char znak = getchar();
	if (znak == '\n') znak=getchar();
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

struct Student unos_studenta(){
	struct Student studenti;
	int i;
	printf("Unesite ime: ");
	unesi(studenti.ime,20);
	printf("Unesite prezime: ");
	unesi(studenti.prezime,20);
	printf("Unesite broj ocjena: ");
	scanf("%d",&studenti.br_ocjena);
	printf("Unesite ocjene: ");
	for(i=0;i<studenti.br_ocjena;i++)
		scanf("%d",&studenti.ocjene[i]);
		
	return studenti;
}

void ispis_osobe(struct Student str){
		printf("%s %s\n", str.prezime, str.ime);
}

int genijalci(struct Student s[], int broj, float prosjek){
	int i,j,k,prvi=0,drugi=0,treci=0;
	float pr=0,suma=0,prosjeci[100]={0},max;
	for(i=0;i<broj;i++){
		/* Racunanje prosjeka u narednih 7 linija*/
		if(s[i].br_ocjena==0)
			pr=5.0;
		suma=0;
		for(j=0;j<s[i].br_ocjena;j++){
			suma+=s[i].ocjene[j];
			if(s[i].br_ocjena!=0 && s[i].ocjene[j]!=5)
				pr=suma/s[i].br_ocjena;
			if(s[i].ocjene[j]==5)
				pr=5.0;
		}
			if(pr<prosjek){
				/* Algoritam za izbacivanje */
				for(k=i;k<broj-1;k++){
					s[k]=s[k+1];
				}
				broj--;
				i--;
			}
	}
	
	/* Algoritam za ispisivanje najboljih */
	for(i=0;i<broj;i++){
		/* Racunanje prosjeka */
		suma=0;
		for(j=0;j<s[i].br_ocjena;j++)
			suma+=s[i].ocjene[j];
				prosjeci[i]=suma/s[i].br_ocjena;
	}
	max=prosjeci[0];
	for(i=0;i<broj;i++){
		if(prosjeci[i]>max){
			max=prosjeci[i];
			prvi=i;
		}
		else if(prosjeci[i]==max){
				prvi=i;
		}
	}
	max=prosjeci[0];
	for(i=0;i<broj;i++){
		if(prosjeci[i]>max && i!=prvi){
			max=prosjeci[i];
			drugi=i;
		}
		else{
			if(prosjeci[i]==max && i!=prvi){
				if(i!=broj && s[i].ime[1]>s[i+1].ime[1])
					max=prosjeci[i];
				drugi=i;
			}
		}
	}
	max=prosjeci[0];
	for(i=0;i<broj;i++){
		if(prosjeci[i]>max && i!=drugi && i!=prvi){
			max=prosjeci[i];
			treci=i;
		}
		else{
			if(prosjeci[i]==max && i!=drugi && i!=prvi)
				treci=i;
				max=prosjeci[i];
		}
	}
	if(broj>=3){
		ispis_osobe(s[prvi]);
		ispis_osobe(s[drugi]);
		ispis_osobe(s[treci]);
	}
	else{
		for(i=0;i<broj;i++)
			ispis_osobe(s[i]);
	
	}
	return broj;
}

int main() {
	int i=0,n,brojac=0;
	float prosjek;
	struct Student studenti[100];
	do{
		printf("Pritisnite 1 za unos, 0 za izlaz: ");
		scanf("%d",&n);
		if(n==1){
			studenti[i]=unos_studenta();
			brojac++;
			i++;
		}
	}while(n!=0);
	if(brojac!=0){
		printf("Unesite prosjek: ");
		scanf("%f",&prosjek);
	}
	genijalci(studenti,brojac,prosjek);
	return 0;
}
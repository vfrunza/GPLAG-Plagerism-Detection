#include <stdio.h>
void unesi(char niz[], int velicina) {
    char znak = getchar();
    int i=0;
    if (znak == '\n') znak=getchar();
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

int provjera(double niz){
	int i,j;
	
	
	return 0;
}
struct Student {
char ime[20],prezime[20];
int ocjene[50];
	int br_ocjena;
};
double prosj (int niz[], int br){
	int i=0,provj=0;
	double suma=0,pr;
	if(br==0) return 5;
	for(i=0;i<br;i++){
		if(niz[i]==5)
			return 5;
		suma=suma+niz[i];
	}
	pr=suma/br;
	
	return pr;
	
}

int genijalci (struct Student pod[], int velicina, double prosjek){
	struct Student temp;
	int i,j;
	double niz_prosjeka[100],max;
	for(i=0;i<velicina;i++) {
		if(prosj(pod[i].ocjene,pod[i].br_ocjena)>prosjek)
			niz_prosjeka[i]=prosj(pod[i].ocjene,pod[i].br_ocjena);
			
		if(prosj(pod[i].ocjene,pod[i].br_ocjena)<prosjek) {
			for(j=i;j<velicina-1;j++) {
				pod[j]=pod[j+1];
			}
			velicina--;
			i--;
		}	
	}


		
	
	for(i=0;i<velicina;i++){
		printf("%s %s\n", pod[i].prezime,pod[i].ime);
		
		
	}
		
	
	return velicina;
}
int main() {
	struct Student pod[100];
	double prosjek=0;
	int vel=0,i=0,j=0,br_studenata1;
	
	printf("Unesite broj studenata: ");
	scanf("%d", &br_studenata1);

	for(i=0;i<br_studenata1;i++){
		printf("Unesite prezime studenta");
		unesi(pod[i].prezime,20);
		printf("Unesite ime studenta");
		unesi(pod[i].ime,20);
		printf("Unesite broj ocjena studenta");
		scanf("%d", &pod[i].br_ocjena);
		printf("Unesite ocjene");
		for(j=0;j<pod[i].br_ocjena;j++){
			scanf("%d", &pod[i].ocjene[j]);
		}
	}
	printf("Unesite prosjek ocjena: ");
	scanf("%lf", &prosjek);
	
	vel=genijalci(pod,br_studenata1,prosjek);
	
	return 0;
}

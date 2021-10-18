#include <stdio.h>
struct Tacka{
	float x,y;
};
struct Kruznica{
	struct Tacka centar;
	float poluprecnik;
};
struct Pravougaonik{
	struct Tacka ugao; /*donji lijevi ugao*/
	int sirina,visina;
};
struct Trougao{
	struct Tacka t1,t2,t3;
};
enum TipOblika {TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};

struct Tacka unos_tacke(){
	struct Tacka t;
	printf("koordinate x,y: ");
	scanf("%f%f",&t.x, &t.y);
	return t;
}
struct Kruznica unos_kruznice(){
	struct Kruznica k;
	printf("Unesite centar kruznice: ");
	k.centar=unos_tacke();
	printf("Unesite poluprecnik kruznice: ");
	scanf("%f", &k.poluprecnik);
	return k;
}
struct Pravougaonik unos_pravougaonika(){
	struct Pravougaonik p;
	printf("Unesitedonji lijevi ugao: ");
	p.ugao=unos_tacke();
	printf("Unesite sirinu: ");
	scanf("%d", &p.sirina);
	printf("Unesite visinu: ");
	scanf("%d", &p.visina);
	return p;
}
struct Trougao unos_trougla(){
	struct Trougao tr;
	printf("Unesite prvi vrh: ");
	tr.t1=unos_tacke();
	printf("Unesite drugi vrh: ");
	tr.t2=unos_tacke();
	printf("Unesite treci vrh: ");
	tr.t3=unos_tacke();
	return tr;
}
int main() {
	enum TipOblika tipovi[50];
	// za sve niz
	struct Kruznica kruznice[50];
	struct Pravougaonik pravougaonici[50];
	int br_oblika,i,tip_oblika;
	do{
	printf("Unesite broj oblika: ");
	scanf("%d",&br_oblika);
	} while(br_oblika<0 || br_oblika>50);
	for(i=0; i<br_oblika; i++){
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ",i+1);
		scanf("%d", &tip_oblika);
		switch(tip_oblika){
			case 1: printf("Unesite tacku: "); niz[i]=TACKA; unos_tacke(); break;
			case 2: tipovi[i]= KRUZNICA; kruznice[i]=unos_kruznice(); break;//
			case 3: niz[i]= PRAVOUGAONIK; unos_pravougaonika(); break;
			case 4: niz[i]=TROUGAO; unos_trougla(); break;
			default: printf("Nepoznat tip oblika %d!\n",tip_oblika);break;
		}
	}
	//2 for petlje, i-ti, j+1-da li obuhvata
	
	return 0;
}

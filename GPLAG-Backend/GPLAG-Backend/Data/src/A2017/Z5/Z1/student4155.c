#include <stdio.h>

struct Datum {
	int dan;
	int mjesec;
	int godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

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

struct Uposlenik unos_uposlenika(){
	struct Uposlenik u;
	printf("Unesite ime i prezime: ");
	unesi(u.ime_prezime,50);
	printf("Unesite datum rodjenja (d, m, g): ");
	scanf("%d, %d, %d",&u.datum_rodjenja.dan,&u.datum_rodjenja.mjesec,&u.datum_rodjenja.godina);
	return u;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	
	int crtica=0,izbaci=0,nadjen=0,mladji=0,stariji=0,razlika_god,dan_direktor,dan_kandidat,pocetak=1,prijestupna_dir=0,prijestupna_kand=0;
	struct Uposlenik* p;
	struct Uposlenik* h;
	struct Uposlenik* u;
	char *q,*t,*z,*m,*c;

/*Provjeravamo da li je godina rodjenja direktora prijestupna*/	
	if((direktor.datum_rodjenja.godina%4==0 && direktor.datum_rodjenja.godina%100!=0) || (direktor.datum_rodjenja.godina%4==0 && direktor.datum_rodjenja.godina%100==0 && direktor.datum_rodjenja.godina%400==0))prijestupna_dir=1;

/*Racunamo dan u godini kada je rodjen direktor*/	
	switch(pocetak){
	case 1:	
		dan_direktor=0;
		if(direktor.datum_rodjenja.mjesec==1){
			dan_direktor=direktor.datum_rodjenja.dan;
			break;
		}
	case 2:	
		dan_direktor=31+dan_direktor;
		if(direktor.datum_rodjenja.mjesec==2){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;	
		}
	case 3:
		dan_direktor=28+dan_direktor;
		if(prijestupna_dir==1)dan_direktor++;
		if(direktor.datum_rodjenja.mjesec==3){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;	
		}
	case 4:	
		dan_direktor=31+dan_direktor;
		if(direktor.datum_rodjenja.mjesec==4){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;
		}
	case 5:	
		dan_direktor=30+dan_direktor;
		if(direktor.datum_rodjenja.mjesec==5){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;
		}	
	case 6:	
		dan_direktor=31+dan_direktor;
		if(direktor.datum_rodjenja.mjesec==6){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;
		}	
	case 7:	
		dan_direktor=30+dan_direktor;
		if(direktor.datum_rodjenja.mjesec==7){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;
		}
	case 8:	
		dan_direktor=31+dan_direktor;
		if(direktor.datum_rodjenja.mjesec==8){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;
		}
	case 9:	
		dan_direktor=31+dan_direktor;
		if(direktor.datum_rodjenja.mjesec==9){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;
		}
	case 10:	
		dan_direktor=30+dan_direktor;
		if(direktor.datum_rodjenja.mjesec==10){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;
		}
	case 11:	
		dan_direktor=31+dan_direktor;
		if(direktor.datum_rodjenja.mjesec==11){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;
		}
	case 12:	
		dan_direktor=30+dan_direktor;
		if(direktor.datum_rodjenja.mjesec==12){
			dan_direktor=dan_direktor+direktor.datum_rodjenja.dan;
			break;
		}	
	default: 
		break;
	}
	
/*Stavljamo jedan pokazivac na prvog kandidata a drugi na string koji sadrzi ime i prezime direktora*/	
	p=kandidati;
	t=direktor.ime_prezime;
/*Pokazivac klizi do zadnjeg slova prezimena; tu adresu spasavamo u jos jedan pokazivac*/	
	while(*t!='\0'){
			t++;
	}z=t;
	
/*Pokazivac klizi do zadnjeg slova prezimena; tu adresu spasavamo u jos jedan pokazivac*/	
/*Takodjer ako prezime kandidata sadrzi crticu spasavamo adresu crtice i povecavamo brojac*/
	while(p<kandidati+vel){
		
		q=p->ime_prezime;
		while(*q!='\0'){
			if(*q=='-'){
				c=q;crtica=1;
			}
			q++;
		} 
		q--;m=q;

/*Provjeravamo da li direktor i kandidat imaju isto prezime*/	
		while(*q!=' '){
			if(*q==*t){q--;t--;nadjen=1;}
			else if(*q!=*t){t--;q=m;nadjen=0;}
			if(*t==' ')break;
		}
/*Takodjer provjeravamo iduci od slova prezimena prije crtice*/	
		if(nadjen==0 && crtica==1){
			c--;
			t=z;
			q=c;
			while(*q!=' '){
				if(*q==*t){q--;t--;nadjen=1;}
				else if(*q!=*t){t--;q=c;nadjen=0;}
				if(*t==' ')break;
			}
			t=z;
			q=m;
		}
	
/*Provjeravamo da li je kandidat rodjen u prijestupnoj godini*/	
		if((p->datum_rodjenja.godina%4==0 && p->datum_rodjenja.godina%100!=0) || (p->datum_rodjenja.godina%4==0 && p->datum_rodjenja.godina%100==0 && p->datum_rodjenja.godina%400==0))prijestupna_kand=1;
		else prijestupna_kand=0;
		
	switch(pocetak){
	case 1:	
		dan_kandidat=0;
		if(p->datum_rodjenja.mjesec==1){
			dan_kandidat=p->datum_rodjenja.dan;
			break;
		}
	case 2:	
		dan_kandidat=31+dan_kandidat;
		if(p->datum_rodjenja.mjesec==2){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;	
		}
	case 3:
		dan_kandidat=28+dan_kandidat;
		if(prijestupna_kand==1)dan_kandidat++;
		if(p->datum_rodjenja.mjesec==3){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;	
		}
	case 4:	
		dan_kandidat=31+dan_kandidat;
		if(p->datum_rodjenja.mjesec==4){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;
		}
	case 5:	
		dan_kandidat=30+dan_kandidat;
		if(p->datum_rodjenja.mjesec==5){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;
		}	
	case 6:	
		dan_kandidat=31+dan_kandidat;
		if(p->datum_rodjenja.mjesec==6){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;
		}	
	case 7:	
		dan_kandidat=30+dan_kandidat;
		if(p->datum_rodjenja.mjesec==7){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;
		}
	case 8:	
		dan_kandidat=31+dan_kandidat;
		if(p->datum_rodjenja.mjesec==8){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;
		}
	case 9:	
		dan_kandidat=31+dan_kandidat;
		if(p->datum_rodjenja.mjesec==9){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;
		}
	case 10:	
		dan_kandidat=30+dan_kandidat;
		if(p->datum_rodjenja.mjesec==10){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;
		}
	case 11:	
		dan_kandidat=31+dan_kandidat;
		if(p->datum_rodjenja.mjesec==11){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;
		}
	case 12:	
		dan_kandidat=30+dan_kandidat;
		if(p->datum_rodjenja.mjesec==12){
			dan_kandidat=dan_kandidat+p->datum_rodjenja.dan;
			break;
		}	
	default: 
		break;
	}

/*Racunamo razliku izmedju rodjenja kandidata i direktora zavisno od toga ko je stariji a ko mladji*/		
		if(direktor.datum_rodjenja.godina==p->datum_rodjenja.godina){
			if(dan_direktor>=dan_kandidat)mladji=dan_direktor-dan_kandidat;
			else if(dan_direktor<dan_kandidat)stariji=dan_kandidat-dan_direktor;
		}
		
		else if(direktor.datum_rodjenja.godina>p->datum_rodjenja.godina){
			razlika_god=direktor.datum_rodjenja.godina-p->datum_rodjenja.godina;
			mladji=365-dan_kandidat+(razlika_god-1)*365+dan_direktor;
		}
		
		else if(direktor.datum_rodjenja.godina<p->datum_rodjenja.godina){
			razlika_god=p->datum_rodjenja.godina-direktor.datum_rodjenja.godina;
			stariji=365-dan_direktor+(razlika_god-1)*365+dan_kandidat;
		}
/*Zavisno od toga da li je kandidat mladji/stariji dovoljan broj dana u odnosu na broj_dana i da li je porodica direktoru odlucujemo da li ga treba izbaciti ili ne*/		
		if(broj_dana>0 && stariji==0){
			if(mladji>broj_dana && nadjen==0)izbaci=1;
			else izbaci=0;
		}
		else if(broj_dana>0 && mlad ji==0)izbaci=0;
		else if(broj_dana<0 && mladji==0){
			if(stariji<-broj_dana && nadjen==0)izbaci=1;
			else izbaci=0;
		}
		else if(broj_dana<0 && stariji==0 && nadjen==0)izbaci=1;

/*Ako kandidata treba izbaciti to radimo preko klasicnog algoritma za izbacivanje*/
		if(izbaci==1){
			h=p;
			u=h+1;
	
			while(h<kandidati+vel-1){
				*h=*u;
				h++;u++;
			}
			vel--;p--;
		}
		t=z;
		stariji=0;mladji=0;nadjen=0;crtica=0;
		p++;
	}
    return vel;
}


int main() {
	
	struct Uposlenik kandidati[100];
	int vel,broj_dana,i=0;
	struct Uposlenik direktor;
	
	direktor=unos_uposlenika();
	printf("Unesite broj uposlenika: ");
	scanf("%d",&vel);
	for(i=0;i<vel;i++)kandidati[i]=unos_uposlenika();
	printf("Unesite broj dana: ");	
	scanf("%d",&broj_dana);
	
	printf("%d",suzi_listu(kandidati,vel,direktor,broj_dana));
	
	return 0;
}

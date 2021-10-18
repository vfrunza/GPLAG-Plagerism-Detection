#include <stdio.h>
#include <string.h>
struct Datum{
	int dan, mjesec, godina;
};
struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
int prestupna(int god){
	if(god%4==0 && god%100!=0 || god%400==0) return 1;
	return 0;
}

int suma_dana(struct Datum d){
	int suma=0;
		switch(d.mjesec){
		case 1: suma=d.dan; break;
		case 2: suma=31+d.dan; break;
		case 3: suma=31+28+d.dan; break;
	    case 4: suma=31+28+31+d.dan; break;
	    case 5: suma=31+28+31+30+d.dan; break;
	    case 6: suma=31+28+31+30+31+d.dan; break;
	    case 7: suma=31+28+31+30+31+30+d.dan; break;
	    case 8: suma=31+28+31+30+31+30+31+d.dan; break;
	    case 9: suma=31+28+31+30+31+30+31+31+d.dan; break;
	    case 10: suma=31+28+31+30+31+30+31+31+30+d.dan; break;
	    case 11: suma=31+28+31+30+31+30+31+31+30+31+d.dan; break;
	    case 12: suma=31+28+31+30+31+30+31+31+30+31+30+d.dan; break;
	}
	if(prestupna(d.godina)) suma+=1;
	return suma;
}

int razlika_dana(struct Uposlenik radnik, struct Uposlenik direktor){
	int razlika;
	int br_dana1, br_dana2;
	int godina_r_pres=prestupna(radnik.datum_rodjenja.godina);
	int godina_d_pres=prestupna(direktor.datum_rodjenja.godina);
	br_dana1=suma_dana(radnik.datum_rodjenja);
	br_dana2=suma_dana(direktor.datum_rodjenja);
	/*ako je radnik rodjen krajem godine, razlika godine rodjenja 1*/
	if(direktor.datum_rodjenja.godina==radnik.datum_rodjenja.godina+1 && godina_r_pres==1) razlika=(br_dana2+366)-br_dana1;
	else if(direktor.datum_rodjenja.godina==radnik.datum_rodjenja.godina+1 && godina_r_pres==0) razlika=(br_dana2+365)-br_dana1;
	/*ako je direktor rodjen krajem godine, razlika godine rodjenja 1*/
	else if(radnik.datum_rodjenja.godina==direktor.datum_rodjenja.godina+1 && godina_d_pres==1) razlika=(br_dana1+366)-br_dana2;
	else if(radnik.datum_rodjenja.godina==direktor.datum_rodjenja.godina+1 && godina_d_pres==0) razlika=(br_dana1+365)-br_dana2;
	else if(br_dana1>=br_dana2) razlika=br_dana1-br_dana2;
	else if(br_dana2>br_dana1) razlika=br_dana2-br_dana1;
	return razlika;
}

int stariji(struct Uposlenik radnik, struct Uposlenik direktor, int broj_dana){
	int br_dana_izmedju=razlika_dana(radnik,direktor);
	int prestupnagod=prestupna(radnik.datum_rodjenja.godina);
	if(radnik.datum_rodjenja.godina==direktor.datum_rodjenja.godina-1 && br_dana_izmedju<=broj_dana) return 0;
	if(direktor.datum_rodjenja.godina==radnik.datum_rodjenja.godina-1 && br_dana_izmedju<=broj_dana) return 0;
	if((radnik.datum_rodjenja.godina<direktor.datum_rodjenja.godina)) return 1;
    if(radnik.datum_rodjenja.godina>direktor.datum_rodjenja.godina) return 0;
	if(radnik.datum_rodjenja.godina==direktor.datum_rodjenja.godina && radnik.datum_rodjenja.mjesec>direktor.datum_rodjenja.mjesec) return 0;
	if(radnik.datum_rodjenja.godina==direktor.datum_rodjenja.godina && br_dana_izmedju<broj_dana) return 0;
	if(radnik.datum_rodjenja.godina==direktor.datum_rodjenja.godina && prestupnagod==0 && br_dana_izmedju<=broj_dana) return 0;
	if(radnik.datum_rodjenja.godina==direktor.datum_rodjenja.godina && (radnik.datum_rodjenja.mjesec<direktor.datum_rodjenja.mjesec) && br_dana_izmedju>broj_dana) return 1;
}
int br_prezimena(char *s){
	int brp=0;
	char *pom=s;
	while(*pom!='\0'){
		if(((*pom>='A' && *pom<='Z')||(*pom>='a' && *pom<='z'))&&(pom==s || *(pom-1)==' ' || *(pom-1)=='-')){
			while((*pom>='A' && *pom<='Z') || (*pom>='a' && *pom<='z')) pom++;
			if(*pom=='-') brp++;
		}
		pom++;
	}
	return (brp+1);
}

/*La Familijaa*/
int porodica(char* kandidat ,  char* direktor){
	char kand1[50], kand2[50], dir1[50], dir2[50];
	char *pom=kandidat, *k1=kand1, *k2=kand2, *d1=dir1, *d2=dir2;
	int brp_r=0, brp_d=0;
	brp_r=br_prezimena(kandidat);
	brp_d=br_prezimena(direktor);
	pom=kandidat;
	while(*pom!='\0')pom++;
	while(*pom!=' ') pom--;
	pom++;
	if(brp_r==1){
		while(*pom!='\0')
		*k1++=*pom++;
		*k1='\0';
		kand2[0]='\0';
	}
	else if(brp_r==2){
		while(*pom!='-')
		*k1++=*pom++;
		*k1='\0';
		pom++;
		while(*pom!='\0')
		*k2++=*pom++;
		*k2='\0';
	}
	pom=direktor;
	while(*pom!='\0') pom++;
	while(*pom!=' ') pom--;
	pom++;
	if(brp_d==1){
		while(*pom!='\0')
		*d1++=*pom++;
		*d1='\0';
		dir2[0]='\0';
	}
	else if(brp_d==2){
		while(*pom!='-')
		*d1++=*pom++;
		*d1='\0';
		pom++;
		while(*pom!='\0')
		*d2++=*pom++;
		*d2='\0';
	}
	/*poredjenje prezimena*/
	if(brp_d==1 && brp_r==1){
		if(strcmp(kand1, dir1)==0) return 1;
	}
	else if(brp_d==2 && brp_r==1){
		if(strcmp(kand1,dir1)==0 || strcmp(kand1,dir2)==0) return 1;
	}
	else if(brp_r==2 && brp_d==1){
		if(strcmp(kand1,dir1)==0 || strcmp(kand2,dir1)==0) return 1;
	}
	else if(brp_r==2 && brp_d==2){
		if(strcmp(kand1,dir1)==0 || strcmp(kand1,dir2)==0 || strcmp(kand2,dir1)==0 || strcmp(kand2,dir2)==0) return 1;
	}
	return 0;
}
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	int i,j;
	int staro, rodbina;
	for(i=0; i<vel; i++){
		rodbina=porodica(kandidati[i].ime_prezime, direktor.ime_prezime);
		if(rodbina==1) continue;
		staro=stariji(kandidati[i], direktor, broj_dana);
		if(staro){
			for(j=i; j<vel-1; j++){
				kandidati[j]=kandidati[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	struct Uposlenik direktor = {"Mujo Mujic", {1,3,1980}};
    struct Uposlenik kandidati[7] = {
    {"Meho Mehic", {31,1,1980}},
    {"Pero Peric", {1,2,1980}},
    {"Sara Sarac", {2,2,1980}},
    {"Fata Mujic", {1,2,1976}},
    {"Jozo Jozic", {1,10,1980}},
    {"Mijo Mijic", {4,3,1979}},
    {"Suljo Suljic", {15,1,1982}},
};

int novi_br = suzi_listu(kandidati, 7, direktor, 28);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}

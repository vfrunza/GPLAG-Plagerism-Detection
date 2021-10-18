#include <stdio.h>
#include <math.h>

int duzinaRijeci(char* s){
	int brojac;
	brojac=0;
	
	while(*s != '\0'){
		brojac++;
		s++;
	}
	return brojac;
}

int rijecBrojac(char* s){
	char* kopija, *poredi;
	int brojRijeci;
	kopija=s;
	brojRijeci=1;
	poredi=kopija+1;
	
	while(*kopija != '\0' && *poredi != '\0'){
		if(*poredi==' ' || *poredi=='\0'){
			if(*poredi==*kopija) brojRijeci--;
			brojRijeci++;
		}
		kopija++;
		poredi++;
	}
	return brojRijeci;
}

char* trazilicafix(char* s, char* rijec){
	while(*s!='\0'){
		while(*s== ' '){
			s++;
		}
		char* p=s;
		char* start=s;
		char* q=rijec;
		
		while(*p++==*q++){
			if(*q=='\0' && (*p==' ' || *p=='\0')) return start;
		}
		while(*s != '\0' && *s != ' '){
			s++;
		}
	}
	return NULL;
}
char* trazilica(char* string, char* rijec){
	char* pamti=rijec,*lokacija;
	int radi=1;
	while(*string!='\0'){
		if(*string==*rijec){
			lokacija=string;
			while(*rijec!='\0' ){
				if(*rijec!=*string){radi=0;break;}
				rijec++;
				string++;
			}
			if(radi==1)return lokacija;
			else {radi=1;rijec=pamti;}
		}string++;
	}
	return NULL;
}

int trazilicaPonavljanja(char* string, char* rijec){
	char* pamti=rijec,*lokacija;
	int radi=1;
	while(*string!='\0'){
		if(*string==*rijec){
			lokacija=string;
			while(*rijec!='\0' ){
				if(*rijec!=*string){radi=0;break;}
				rijec++;
				string++;
			}
			if(radi==1)return 1;
			else {radi=1;rijec=pamti;}
		}string++;
	}
	return 0;
}




char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	int duzinaPrve, duzinaDruge;
	char* pocetak=tekst;
	int j, i, k, h, izbaciti, razlika;
	char* p;
	char* q;
	char* prazan=tekst;
	int ponavljanje=0,greska=1;
	int rijeciString;
	
	rijeciString=rijecBrojac(tekst);
	
	if(*prazan==' ') return tekst;


	for(i=0;i<broj_rijeci;i++){
		for(j=0;j<rijeciString;j++){
	/*	do{
		if(trazilicaPonavljanja(tekst, rijeci[i]))
		ponavljanje+=trazilicaPonavljanja(tekst, rijeci[i]);
		else greska=0;
	}while(greska==0);
	
	*/
	
		
	duzinaPrve=duzinaRijeci(rijeci[i]);
	duzinaDruge=duzinaRijeci(zamjene[i]);
	
	
		
	char* p= trazilicafix(tekst, rijeci[i]);

	if(p == NULL) continue;
	if(p != NULL){
	
	
	
	if(duzinaPrve<duzinaDruge){
		
		razlika=duzinaDruge-duzinaPrve;
		
		char* kraj=p;
		char* temp=kraj;
		while(*kraj != '\0') kraj++;
		while(kraj>p){
			*(kraj+razlika)=*kraj;
			kraj--;
		}
		
		char* prvoSlovo=p;
		char* z=zamjene[i];
		while(*z != '\0'){
			*prvoSlovo = *z;
			z++;
			prvoSlovo++;
		}
	}
	
	if(duzinaPrve>duzinaDruge){
		razlika=duzinaPrve-duzinaDruge;
		razlika=fabs(razlika);
		char* slovo=p;
		char* sljedeceSlovo=p+1;
		for(h=0;h<razlika;h++){
			char* slovo=p;
			char* sljedeceSlovo=p+1;
		while(*slovo++=*sljedeceSlovo++);}
		char* prvoSlovo=p;
		char* z=zamjene[i];
		while(*z != '\0'){
			*prvoSlovo = *z;
			z++;
			prvoSlovo++;
		}
		
	}
	
	else if(duzinaPrve==duzinaDruge){
	
		char* x= p;
		char* y=zamjene[i];
		while(*y !='\0'){
		
		*x=*y;
		
		x++;
		y++;
		}
	}
	}
	}
	}
	return pocetak;

}
	


int main() {
	
	char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));

	
	return 0;
}



	/*char* pocetak=tekst;
	char* pocetakRijeci;
	char* zamjenaPok;
	int duzinaStvarne, duzinaTrazene, duzina;
	int i;
	
	while(*tekst != '\0'){
		for(i=0;i<broj_rijeci;i++){
		pocetakRijeci=podstring(tekst,(*zamjene+i));
		zamjenaPok=*(zamjene+i);
		if(pocetakRijeci==NULL) return 0;
		
		duzinaStvarne= duzinaRijeci(pocetakRijeci);
		duzinaTrazene= duzinaRijeci(*zamjene);
		duzina=duzinaStvarne-duzinaTrazene;
		
		while(*pocetakRijeci != '\0'){
			
			
				char* kraj=pocetakRijeci;
				while(*kraj != '\0') kraj++;
				while(kraj > pocetakRijeci){
					*(kraj+duzina)=*kraj;
					kraj--;
				}
			
		
			*pocetakRijeci=*zamjenaPok;
			pocetakRijeci++;
			zamjenaPok++;
		}
		
		tekst++;
	}	
	}
	
	
	return pocetak;
}*/




/*-----------------------------------------------------------------------------	
	char* rijeci[2]={"beli", "sneg"};
	char* test[2]={"belise", "aneg"};
	char* zamjene[2]={"bijeli", "snijeg"};
	char tekst[100]= "beli sneg je pokrio beli breg";
	int d,i;
	char** pointer=test[1];
	char** pointer2=zamjene[1];
	
	d=duzinaRijeci(rijeci[0]);
	
	

	
	printf("%s", test[1]);
	

	/*printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	*/
/*	printf("%d", duzinaRijeci(test[1]));*/
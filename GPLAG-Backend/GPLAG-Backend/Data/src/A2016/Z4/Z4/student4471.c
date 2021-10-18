#include <stdio.h>
#define epsilon 0.0001

char *obuhvat(char *tekst, double x1,double y1,double x2,double y2){
	
	char *s = tekst;
	int brojac = 1;
	
	double x=0,y = 0;
	
	while(*s != '\0'){
		
		int imadec = 0,predznak = 1;
		
		char *poc;
		
		if(*s = '('){
			poc = s;
			//povecamo s da pokazuje iza zagrade 
			s++;
		
		}
		
		x = 0;
		double o = 0.1;
		
		//postavljamo brojac na nulu i ako se pojavi broj povecavamo ga na kraju ako je ostao nula znaci da je pogresno formatiran string
		brojac = 0;
		while(*s != ','){
			
			if(*s >= '0' && *s<='9')brojac++;
			
			//ako s nije ni broj ni zarez ni tacka ni minus s ovim smo se ogradili od svega u prvoj kordinati pa tako ako se negdje pojavi zarez u prvoj kordinati vratit ce NULL
			if(!((*s >=48 && *s <=87 || *s == '-' || *s =='.'))) return 0;
			
			//ako je neka kordinata negativna stavimo predznak -1 i predjemo na sljedeci znak
			if(*s == '-'){s++;predznak = -1;}
			
			//broj je obavezan ispred tacke !!
			if(*s == '.' && !((*(s-1)>='0' && *(s-1)<='9')))return 0;
		
			//ako naidjemo na tacku postavimo da kordinata ima decimala i predjemo na sljedeci znak
			//povecavamo brojac jer stavljamo s++ pa nam se moze desiti da preskoci broj 
			if(*s == '.'){imadec = 1;s++;brojac++;}
			
			
			//ako smo naisli na npr broj 2., bez nule iza znaci da smo dosli do druge kordinate pa brejkamo ovu petlju
			if(*s == ',') break;
			
			
			
			if(imadec == 0){
				
				//NAJLAKSI NACIN ZA SUMIRANJE CIFRI BROJA GDJE NE TREBAMO ODREDITI DUZINU BROJA...
				//oduzimamo '0' jer se radi o stringu pa ga moramo pretvorit u int
				x = x*10 + (*s - '0');
			}
			else {
				
				//ovdje npr za broj 12.346 prije ovog uslova broj ce biti 12 kad se ispuni i pojavi se tacka imadec postaje 1 te se ovaj 
				//uslov ispunjava; sada za 0.345 --> x = 12 + 3*0.1 = 12.3 ; o = 0.01 ; x = 12.3 + 4*0.01 = 12.34 ; o =0.001; x = 12.34 + 6*0.001 =12.346
				x = x + (*s - '0')*o;
				
				o = o / 10;
			}
			
			s++;
		}
		
		if(brojac == 0 ){return 0;}
		
		//na kraj petlje s pokazuje na zarez
		x = x*predznak;
		
		imadec = 0,predznak = 1;
		
		//pomjerimo iza zareza
		s++;
		
		y = 0;
		
		o = 0.1;
		
		brojac = 0;
		while(*s != ')'){
			
			
			//ako s nije ni broj ni zarez ni tacka
			if(!((*s >=48 && *s <=87 || *s == '-' || *s =='.'))) return 0;
			
			if(*s == '-'){s++;predznak = -1;}
			
			//broj je obavezan ispred tacke !!
			if(*s == '.' && !((*(s-1)>='0' && *(s-1)<='9')))return 0;
			
			if(*s >= '0' && *s<='9')brojac++;
			if(*s == '.'){imadec = 1;s++;brojac++;}
	
			//ovdje ne staljamo uslov ako if(*s ==',')break; jer ovdje je druga kordinata pa ako je (1.1,-2.,) ovo je neispravan format
			
			
			
			if(imadec == 0){
				
				y = y*10 + (*s - '0');
			}
			else {
				
				y = y + (*s - '0')*o;
				
				o = o / 10;
			}
			
			s++;
		}
		
		//provjeravamo ako nije bilo niti jednog broja poslije zareza znaci da je pogresno formatiran string !
		if(brojac == 0)return 0;
		
		y = y*predznak;
		
		
		//s sada pokazuje na kraj zagrade ")"
		//poc je pokazivao na pocetak zagrade "(" pa sada i a pokazuje na zagradu
		char *a = poc;
		
		int izb = 0;
		
		if(y > y2 || y< y1 || x<x1 || x >x2){
			
			//ako se deislo izbaciti
			
			izb = 1;
			
			//ako je zagrada na pocetku teksta i ako je poslije zagrade kraj stringa a treba tu zagradu izbaciti samo stavimo da je tekst = '\0'
			//ovo se moze dogoditi samo kod zadnje kordinate u stringu
			if(poc == tekst && *(s+1) ==  '\0'){
				*tekst = '\0';
				return tekst;
			} 
			
			//prvi uslov je za zadnju zagradu sa kordinatama ako smo dosli do ovdje znaci da je treba izbaciti
			//provjerimo da li je poslije zagrade '\0' ako jeste onda samo poc koji pokazuje na pocetak zagrade umanjimo za 1 i postavimo '\0
			if(*(s+1) == '\0'){
				*(poc-1)='\0';
				return tekst;
			}else{
				//ako se nista od gornjeg nije desilo tj ako treba izbacivat nesto u sredini preskocimo sa ")" preko "," na "("
				char *hod = s+2;
				
				while(*hod!= '\0'){
					*poc = *hod;
					poc++;
					hod++;
				}
				
				//posto je hod isao do kraja sada stavimo samo da string zavrsava sa \0
				*poc = '\0';
			}
		}
		
			if(izb == 1){
				//ako se desilo izbacivanje vracamo s na mjesto "(" da se provjere i kordinate koje su sada prepisane preko proslih...
				s = a;
				
			}
			
			//ako se nije desilo izbacivanje i ako se desi da je na s na zadnjoj zagradi u stringu  ne smije se izvrisiti s+=2(neinicijalizovano) pa imamo ovaj uvjet
			else if(*(s+1) == '\0')s++; 
			
			//ako se nista od ovo dvoje gore nije desilo povecamo s za 2 da predje na sljedecu "("
			else s+=2;
	}
	
	return tekst;
}

int main() {
	
char s[] = "(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)";
char* rez = obuhvat(s, -3, -3, 3, 3);

/* Funkcija modificira primljeni string i vraca pokazivac na njegov pocetak */
printf("%s %s", rez, s);


	return 0;
}

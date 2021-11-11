#include <stdio.h>
#define e 0.0001
#include <math.h> /**trebat ce fabsss**/
/**ovom zadatku treba bruku nekih provjera.....**/


	int pripada (float x1, float y1, float x2, float y2, float x, float y){
		int n=1;
		
		if (x<x1 && fabs(x-x1)>e) n=0;
		if (y<y1 && fabs(y-y1)>e) n=0;
		if (x>x2 && fabs(x-x2)>e) n=0;
		if (y>y2 && fabs(y-y2)>e) n=0;
		
		return n;
	}




	void promijeni (char *s, int n){ 
		char *temp=s;
		int i=0;
		if (n==0) return; 
		
			for (i=0; i<n; i++){  
			while (*s!='\0'){ 
				*s = *(s+1);
				s++;
			
			}
			
			s = temp;
		}
	}
		



	int broj(char s){
		if (s>='0' && s<='9') return 1;
		return 0;
	}


	void ucitaj_broj(char *s, float niz[3], char x){ 
		niz[1]=1;
		int minus =0, eksp=0;
		float pomjeraj=0, tmp=0, broj1=0, broj2=0, djelilac=0;/**treba mi pomjeraj da mi broji koliko ima karaktera unutar zagrada**/
		if (*s == '-'){
		minus = 1;
		s++;
		pomjeraj++;
		}
		
		while (*s != '.' && *s != x){ /**poslije broja moze biti . ili , ili ), zato imam char x koji je , ili ) kad ucitavam x odnosno y**/
			if (!broj(*s)) { /**sad moram provjeriti je li *s broj, ako nije broj onda ne valja, dakle jos jedna funkcija...**/
			  niz[1]=0;  /**niz[0] ce mi biti broj, niz[1] mi je provjera ima li gresaka u tekstu, niz[2] ce mi biti pomjeraj**/
			  return;
		}
		pomjeraj++;
		tmp = *s - '0';
		broj1 = broj1*10 + tmp;
		
		s++;
		
	}
		if (*s == '.'){
			if(!broj(*(s-1))){
				niz[1]==0;
				return;
			}
			s++;
		
			pomjeraj++;
			while (broj(*s)){
				pomjeraj++;
				tmp = *s - '0';
				broj2= broj2*10+tmp;
				eksp++;
				s++;
				
			}
			  if (*s != x){
			  	niz[1]=0;
			  	return;
			  }
			
			djelilac = pow(10, eksp);
			broj2=broj2/djelilac;
			broj1=broj1 + broj2;
			
		}
		
		if (minus == 1) broj1= -broj1;
		
		niz[0] = broj1;
		niz[2] = pomjeraj;

		
}
	char *obuhvat (char *s, float x1, float y1, float x2, float y2 ){
		/**prvo treba prebrojati koliko je koordinata**/
		int i=0,brojDesnih =0, brojLijevih=0, pomjeraj=0, ima_zarez=1,suzi=1,j=0;
		float niz[3],x,y;
		char *pocetak=s; /**treba uvijek pamtiti pocetak**/
		while (*s != '\0'){  /**treba napraviti posebnu funkciju za ovo dok je razlicito od \0 svega mi**/
			if (*s == '('){
				brojLijevih++;
			} else if (*s == ')'){
				brojDesnih++;
			}
			s++; /**umalo da udje u beskonacnu petlju hehe**/
		}
		if (brojLijevih!=brojDesnih) return NULL; /**ako nije isti broj otvorenih i zatvorenih zagrada nesto ne valja u tekstu**/
		s=pocetak;
		/**sad nam je broj koordinata broj zagrada yeeey**/
		/**trebat ce i ovdje funkcija nekih sigurno**/
		for (i=0; i<brojLijevih; i++){
		
			if (ima_zarez==1){
			if (*s!='(') return NULL; /**mora koordinata pocinjati sa (**/ 
			s++;/**idemo daljeee**/
			/**sad ovdje treba da je prvi broj tj.koordinata x, mislim da mi je najpametnije pravit funkciju za ucitavanje brojeva**/
			ucitaj_broj(s,niz,',');
			if ((int)niz[1]==0) return NULL;
			x=niz[0];
			pomjeraj = (int)niz[2];
			for (j=0; j<pomjeraj; j++){    /**sada hocu da mi pomjeri pokazivac iza broja**/
				s++; 
			}
			if (*s != ',') return NULL;/**izmedju brojeva mora biti zarez**/
			s++;
			/**ucitavamo y koordinatu**/
			ucitaj_broj(s,niz,')');
			if ((int)niz[1]==0) return NULL;
			y=niz[0];
			pomjeraj = (int)niz[2];
			for (j=0; j<pomjeraj; j++){
				s++;
			}
			if(*s!=')') return NULL; /**poslije drugog broja mora biti )**/
			s++;
			/**sada imamo ucitane x i y koordinate**/
			/**moramo provjeriti da li su u datom opsegu...moze opet funkcija**/
			if (pripada(x1,y1,x2,y2,x,y)==0){ /**ako ne pripada onda izbacujemo taj uredjeni par**/
				
				do {
					suzi++;
					s--;
				} while (*s!='(');
				
				/**za izbacivanje necega iz stringa mogu koristiti funkciju iz proslog zadatka**/
				promijeni(s, suzi); 
				
				ima_zarez=1;
				suzi=1;        
			}
			
		} else if (*s == ','){
			i--;
			s++;
			ima_zarez=1;
		} else return NULL;
		
		
		
		
		}
	
		*(s-1)=*s;

		return pocetak;
	}


int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}

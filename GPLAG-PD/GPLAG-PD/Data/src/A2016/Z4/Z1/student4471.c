#include <stdio.h>


//FUNKCIJA KOJA POREDI POCETKE(npr.(kralj je dzenan) i )dzenan)vratice 0) DVA STRINGA I AKO SE DRUGI NALAZI U PRVO VRACA 1 ako ne VRACA 0

int uporedi(char *s1,char *s2,char *p1,char *p2){
	
	while(s1 != s2 && p1 != p2){
		
		//nepravimo razliku izmedu malih i velikih slova(*p1 +32)
		if( !(*s1 == *p1 || *s1 == (*p1 + 32) || *s1 == (*p1-32)) ){
			return 0;
		}
		
		s1++;
		p1++;
	}
	
	//ako su oba pokazivaca dosla na kraj znaci da imamo poklapanje podstringova
	if(p1 == p2 && s1==s2)return 1;
	
	//ako se nista od gornjeg nije desilo vrati 0
	return 0;
}


//FUNKCIJA IZBACI PROSLIJEDIMO JOJ POKAzivac na cijel string i pokazivace na pocetak i kraj najcesce rijeci

void izbaci(char *s, char *poc, char *kraj){
	
	//u "rijeci" cemo upisivati rijec koju izbacujemo ona je od poc do kraj da je mozemo porediti sa rijecima u stringu s
	char *rijec[50];
	
	char *pom = rijec;
	
	//u "rijeci" upisemo rijec koju izbacujemo
	while(poc != kraj){
		*pom = *poc;
		pom++;
		poc++;
	}
	
	*pom = '\0';
	
	//restartujemo poc i pom da ponovo pokazuju na pocetak i kraj rijeci koju izbacujemo
	poc = rijec;
	kraj = pom;
	
	int neslovo = 1;
	
	while(*s != '\0'){
		
		//ako naidemo na neslovo
		if( !((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))){
			neslovo = 1;
		}
		
		else if(neslovo ==1){
			
			//ako se ovo ispunilo sada smo na pocetku rijeci
			neslovo = 0;
			
			char *p1 = s;
			
			while((*p1 >= 'A' && *p1 <= 'Z') || (*p1 >= 'a' && *p1 <= 'z')){
				p1++;
				//p1 je sada na kraju rijeci pa je rijec od s do p1
			}
			
			//ako su rijeci iste izbacujemo !
			if(uporedi(poc,kraj,s,p1)){
				
				//algoritam za izbacivanje
				
				char *s1 = s;
				
				while(*p1 != '\0'){
					*s1 = *p1;
					s1++;
					p1++;
					
				}
				
				*s1 = '\0';
				
				neslovo = 1;
				//ako je doslo do izbacivanja moramo vratiti neslovo na 1 sa nule jer cemo se opet sa s++ kretat kroz petlju
			}
		}
		
		s++;
	}
}


//funckija koja daje broj ponavljanja trenutne rijeci

int broj_pon_trenutne(char *poc,char *kraj){
	
	//ako je posljednja rijec u stringu ona u ostatku stringa ima 0 ponavlanja
	if(*kraj == '\0') return 0;
	
	int broj = 0;
	
	//ostatak stringa u kojem trazimo ponavljanje trenutne rijeci pocinje od kraja te trenutne rijeci
	char *ostatak = kraj +1;
	
	int neslovo = 1;
	
	while(*ostatak != '\0'){
		
		if( ! ((*ostatak >= 'A' && *ostatak <= 'Z') || (*ostatak >= 'a' && *ostatak <= 'z'))){
			neslovo = 1;
		}
		
		else if(neslovo ==1){
			
			//ako se ovo ispunilo sada smo na pocetku rijeci
			neslovo = 0;
			
			//p1 postavimo da pokazuje na pocetak rijeci s kojom poredimo nasu rijec
			char *p1 = ostatak;
			
			while((*p1 >= 'A' && *p1 <= 'Z') || (*p1 >= 'a' && *p1 <= 'z')){
				p1++;
				//p1 je sada na kraju rijeci pa je rijec od s do p1
			}
			
			//ako je rijec ista kao neka u ostatku stringa brojponavljanja++
			if(uporedi(poc,kraj,ostatak,p1) == 1)broj++;
			
	}
	
	ostatak++;
	
	
	}

	return broj;
	
}


char *izbaci_najcescu(char *s){
	
	//pamtimo s da ga poslije mozemo vratiti, radimo sa p
	char *p = s;
	char *pocetak_najcesce=0,*kraj_najcesce;
	char *pocetak_trenutne=0,*kraj_trenutne;
	
	char *p1;
	
	int max = 0;
	int rel_max = 0;
	
	int neslovo = 1;
	
	while(*p != '\0'){
		
			if(!((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))){
			neslovo = 1;
		}
		
		else if(neslovo ==1){
			
			//ako se ovo ispunilo sada smo na pocetku rijeci
			neslovo = 0;
			pocetak_trenutne = p ;
			p1 = p;
			
			while((*p1 >= 'A' && *p1 <= 'Z') || (*p1 >= 'a' && *p1 <= 'z')){
				p1++;
				//sa p1 odemo za jedno mjesto iza kraja trenutne rijeci
			}
			
			kraj_trenutne = p1;
			
			//uvecamo rel_max za 1 da ubroji i samu sebe u ponavljanja
			rel_max = broj_pon_trenutne(pocetak_trenutne,kraj_trenutne) +1;
			
			if(rel_max > max){
				max = rel_max;
				
				//nasa najcesca rijec postaje trenutna sve dok ne naidjemo na veci broj ponavljanja neke druge rijeci
				pocetak_najcesce = pocetak_trenutne;
				kraj_najcesce = kraj_trenutne;
			}
	}
	
	p++;
	}
	
	//prvo cemo provjeriti ako se posalje prazan string
	if(max == 0) return s;
	
	//ako string nije prazan obavi izbacivanje
	izbaci(s,pocetak_najcesce,kraj_najcesce);
	return s;
	

}

int main(){
	
	char t[] = "a-a-a-a-a";
	printf("%s",izbaci_najcescu(t));
	
	
	
	return 0;
}


































































































































































/*

//DRUGI NACIN RIJESAVANJA ZADATKA POSLIJE MODIFIKOVANJA OVOG DOLE DIJELA NE TREBA NAM FUNKCIJA s prototipom void izbaci_rijec(char *s1, char *s2)
//OVA FUNCKIJA ZAMJENJENA JE FUNCKIJAMA UPOREDI I DRUGOM FUNKCIJOM izbaci_rijec ALI OPET PROGRAM PRIJAVLJUJE MEMORIJSKU GRESKU I NEINICIJALIZOVANOST...

//USLOV ZA NESLOVO ( !(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z') );
int duzina_rijeci(char *s){
	
	int brojac = 0;
	
	
	while( *s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z' ){
		brojac++;
		s++;
	}
	
	
	return brojac;
}


void mystrcpy(char *s1, char*s2){
	
	char *p = s1;
	char *q = s2;
	
	while(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z'){
		*q = *p;
		p++;
		q++;
	}
	*q = '\0';
}



//FJA KOJA IZBACUJE SVE KOPIJE RIJECI 
/*
void izbaci_rijec(char *s1, char *s2){ //s1 je pokazivac na string , s2 je pokazivac na CHAR NIZ KOJI SADRZI NAJCESCU RIJEC
	

	
	char *s2copy = s2;
	
	
	int vel = 0;
	
	//treba nam velicina najsesce rijeci
	while(*s2 != '\0'){
	
		vel++;
		s2++;
	}
	
	s2 = s2copy;
	
	
	while(*s1 != '\0'){
		char *s1copy = s1;
		
		char *p = s1;
		char *q = s2;
		char temp1 = *p;
		char temp2 = *q;
		
		//pretvaramo sve u mala slova 
		if(temp1 >= 'A' && temp1 <= 'Z'){
			temp1 = temp1 + 32;
		}
		
		if(temp2 >= 'A' && temp2 <= 'Z'){
			temp2 = temp2 + 32;
		}
		
		
		
		while(temp1==temp2){
			
				p++;
				q++;
				temp1 = *p;
				temp2 = *q;
				
			if(temp1 >= 'A' && temp1 <= 'Z'){
			temp1 = temp1 + 32;
			}
		
			if(temp2 >= 'A' && temp2 <= 'Z'){
			temp2 = temp2 + 32;
			}
			
			if(*q == '\0' && !(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z') && (  !(*(s1copy-1) >= 'A' && *(s1copy-1) <= 'Z' || *(s1copy-1) >= 'a' && *(s1copy-1) <= 'z'))){
				
				while(*s1copy != '\0'){
					*s1copy = *p;
					s1copy++;
					p++;
				}
				
			}
		}
		
		
		s1++;
		
	}
	
}

*/




/*

int uporedi(char*s1,char*s2,char*p1,char*p2){
	
	while(s1!=s2 && p1!=p2){
		if(!(*s1==*p1 || (*(s1-1) >= 'A' && *(s1-1) <= 'Z' || *(s1-1) >= 'a' && *(s1-1)<= 'z'))) return 0;
		s1++;p1++;
	}
	if(p1==p2 && s1==s2) return 1;
	return 0;
	
}


void izbaci_rijec(char*s,char*r){
	char*poc=r;
	char*kraj=poc+duzina_rijeci(r);
	int neslovo=1;
	while(*s!='\0'){
		if ( !((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) )
		neslovo=1;
		else if(neslovo==1){
			char*p1=s;
			while((*p1>='A' && *p1<='Z')||(*p1>='a' && *p1<='z')) p1++;
			if(uporedi(poc,kraj,s,p1)){
				char*s1=s;
				while(*p1!='\0'){
					*s1=*p1;
					s1++;
					p1++;
				}
				*s1='\0';
				neslovo=1;
			}
		}
	
		s++;
	}
}





//funkcija broj_ponavljanja koja ce vracati koliko se puta jedna rijec ponavlja u stringu

int broj_ponavljanja(char const *s1, char const *s2, int vel){   //s1 na string, s2 na pocetak rijeci, vel velicina rijeci
	
	char *const niz = s1;
	int brojac = 0;

	while(*s1 != '\0'){
		
		char *p = s1;
		char *q = s2;
		char temp1 = *p;
		char temp2 = *q;
		
		//pretvaramo sve u mala slova 
		if(temp1 >= 'A' && temp1 <= 'Z'){
			temp1 = temp1 + 32;
		}
		
		if(temp2 >= 'A' && temp2 <= 'Z'){
			temp2 = temp2 + 32;
		}
		
		
		
		while(temp1==temp2){
			
				p++;
				q++;
				temp1 = *p;
				temp2 = *q;
				
			if(temp1 >= 'A' && temp1 <= 'Z'){
			temp1 = temp1 + 32;
			}
		
			if(temp2 >= 'A' && temp2 <= 'Z'){
			temp2 = temp2 + 32;
			}
			
			if(q == s2 + vel){
				
				if( !(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z') && (s1 ==niz || !(*(s1-1) >= 'A' && *(s1-1) <= 'Z' || *(s1-1) >= 'a' && *(s1-1) <= 'z'))){
				brojac++;
				
				break;
			
				}
				break;
			}
		}
		
		
		s1++;
	}
	
	return brojac;
}

//funkcija koja kada god nadje rijec definisano na nacin dat u zadatku zove fju broj_ponavljanja i vraca nam broj ponavljanja svake rijeci

void prebroj_rijeci(char *s){

	char *pocetak = s;
	
	char rijec_najcesca[100];
	char *p = rijec_najcesca;
	
	int max = 0;
	int duzinarijeci = 0;
	int broj_ponavljanja_rijeci = 0;
	
	
	int neslovo = 1,broj_rijeci = 0;
	
	while(*s != '\0'){
		if( ! (*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z') ){
			neslovo = 1;
			
		}else if(neslovo==1){
			
			neslovo = 0;
			broj_rijeci++;
			duzinarijeci = duzina_rijeci(s);
			
		//	printf("\nDUZINA RIJECI REDOM JE %d\n",duzinarijeci);
			
			broj_ponavljanja_rijeci = broj_ponavljanja(pocetak,s,duzinarijeci);
			
			if(broj_ponavljanja_rijeci > max){
				
				max = broj_ponavljanja_rijeci;
				mystrcpy(s,p);
				
			}
			
			
			
		}
		
		
		s++;
	}
	
//NASLI SMO NAJCESCU RIJEC ona je snimljena u char rijec_najcesca;
//	printf("Najcesca rijec iz funkcije prebroj_rijeci je %s",rijec_najcesca);
	
	izbaci_rijec(pocetak,p);
	
}


//TREBAM POPRAVITI GORNJU FUNKCIJU !!!













char* izbaci_najcescu(char s[]){
	
	
	prebroj_rijeci(s);
	
	
	
	return s;
	
}




int main() {
	
	
	
	char s[] = "&Dzenan_%&# je e ndzenan  &&i 6#213dzenan5 eDzenan je i 63DZ5ENAN_ je3dzenan";
	char s1[] = "dzenan";
	
	
//	printf("Broj ponavljanja rijeci i u stringu je %d\n",broj_ponavljanja(&s,&s[11],1));
	// OVA FIJA RADI kad joj se posalju adrese!!!!
	 //izbaci_rijec(&s,&s1);
	
	//problem je funkcijom prebroj rijeci
	//prebroj_rijeci(s);
	izbaci_najcescu(s);
	
//	prebroj_rijeci(&s);
	printf("\n%s\n",s);
	
//radi i ova fja	printf("Duzina rijeci dzenan je %d",duzina_rijeci(s1));
	
	
	return 0;
}

*/

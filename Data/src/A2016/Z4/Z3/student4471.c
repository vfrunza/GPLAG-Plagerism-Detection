#include <stdio.h>


int duzina_rijeci(char *s){
	
	int duzina = 0;
	
	while(*s != '\0'){
		duzina++;
		s++;
	}
	
	return duzina;
}



char *trazi_rijec(char *tekst,char *rijec){
	
	char *poc = tekst;
	
	char *p = tekst;
	char *q = rijec;
	
	while(*tekst != '\0'){
		
		p = tekst;
		q = rijec;
		
		if(*p == *q){
			
			while(*q != '\0'){
				
				if(*q != *p)break;
				p++;
				q++;
				
				//MORAMO SE OBEZBJEDITI OSIM USLOVA DA JE q doslo na kraj mora i rijec koju smo nasli u stringu ili biti na pocetku 
				//i imati iza razmak ili biti negdje u sredini i imati s obe strane razmak!
				if(*q == '\0'  && (tekst == poc || *(tekst-1)==' ') && (*p==' ' || *p == '\0'))return tekst;
			}
			
			
			
		}
		
		
		tekst++;
	}
	
	return NULL;
	
}


//fji izbaci posaljemo pokazivac na dio pocetak neke rijeci u stringu i velicinu te rijeci i ona izbaci tu rijec
void izbaci(char *p, int vel){
	
	char *kraj = p + vel;
	
	
	while(*kraj != '\0'){
		*p = *kraj;
		p++;
		kraj++;
		
	}
	
	*p = '\0';
}


//s1 pokazivac na mjesto gdje treba ubaciti rijec a s2 pokazivac na rijeci koju treba ubaciti
void ubaci(char *s1,char *s2){
	
	int duzina = duzina_rijeci(s2);
	
	char *kraj = s1;
	
	while(*kraj != '\0')kraj++;
	//kraj sada pokazuje na nul pokazivac
	
	//vracamo se unazad sa kraja stringa i sva slova pomjeramo udesno za "duzinu"
	while(kraj >= s1){
		*(kraj + duzina) = *kraj;
		kraj--;
	}
	
	while(*s2 != '\0'){
		*s1 = *s2;
		s1++;
		s2++;
	}
	
}





char *zamjena_rijeci(char *tekst,char **rijeci,char **zamjene,int broj_rijeci){
	
	char *s = tekst;
	
	int i;
	
	//idemo petljom kroz niz pokazivaca rijeci
	for(i=0;i<broj_rijeci;i++){
		
		//p prima pokazivac na pocetak rijeci ako je nadjena u stringu iz funckije trazi_rijec
		char *p = trazi_rijec(tekst,rijeci[i]);
		
		if(p != NULL){
			
			//pozivamo funckiju izbaci sa pokazivacem na pocetak rijeci koju treba izbaciti i njenom duzinom
			izbaci(p,duzina_rijeci(rijeci[i]));
			
			//pozivamo funckiju ubaci koja ce ubaciti novu rijeci na mjesto gdje je bila izbacena rijec vidimo da p i dalje pokazuje na pocetak izbacene rijeci
			ubaci(p,zamjene[i]);
			
			//smanjujemo i da se ponovo provjeri ima li te rijeci u stringu !
			i--;
		}
	}
	
	return s;
	
}



int main(){
	
	char tekst[] = "Kralj je dzenan begovic";
	char rijec[] ="dzenan";
	
	char *p = &tekst[9];
	
	izbaci(p,6);
	ubaci(p,rijec);
	
	printf("%s",tekst);
	
	
	
	return 0;
}




/*
char gg[2000];
int pozicija(char vrijednost,char s[]){
	
	int i;
	for(i=0;i<=94;i++) if(vrijednost==s[i]) return i;
	
}


char* kodiraj(char*tekst, char*tablica){
	char*pocetak=tekst;
	char*poc=tablica;
	char slova[200];
	char*s=tekst;
	int i ;
	
	for(i=32;i<=126;i++){
		slova[i-32] = i;
	}
	char*global=gg;
	while(*s!='\0'){
		*global=*s;
		global++;s++;
	}
	*global='\0';
	
	
	int niz[200] = {0};
	while(*tekst != '\0'){
		int poz = (int)*tekst;
		
		niz[poz - 32]++;
		tekst++;
		
	}
	

	int j;
	int temp1;
	char temp2;
	
	for(i=0;i<=94;i++){
		for(j=i+1;j<=94;j++){
			
			if((niz[j] > niz[i]) || (niz[j]==niz[i] && slova[j]<slova[i])){
				temp1 = niz[i];
				niz[i] = niz[j];
				niz[j] = temp1;
				
				temp2 = slova[i];
				slova[i] = slova[j];
				slova[j] = temp2;
				
			}
		}
	}
	
		for(i=0;i<=94;i++){
		*(tablica+i) = slova[i];

	}
	*(tablica+i) = '\0';
	tekst=pocetak;

	
	while(*tekst != '\0'){
		
		*tekst = 126 - pozicija(*tekst,poc);
		tekst++;
	}
	return pocetak;
}
char* dekodiraj(char*tekst,char*tablica){
	char*gl=gg;
	char*poc=tekst;
	while(*tekst!='\0'){
		*tekst=*gl;
		tekst++; gl++;
	}
	return poc;
}
int main() {
 char tekst[] = "Ovo cemo sifrirati 2 puta";
    char sifrarnik[100] = "";
    char sifrarnik2[100] = "";
    int i;
    kodiraj(tekst, sifrarnik);
    printf("\n%s", tekst);
    for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
    kodiraj(tekst, sifrarnik2);
    printf("\n%s", tekst);
    for (i=0; i<10; i++) printf("%c", sifrarnik2[i]);
    dekodiraj(tekst, sifrarnik2);
    printf("\n%s", tekst);
    dekodiraj(tekst, sifrarnik);
    printf("\n%s", tekst);


	return 0;
}

*/
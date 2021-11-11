#include <stdio.h>


int duzina_rijeci (char *s){
	int duz=0;
	while(*s!='\0'){
		duz++;
		s++;
	}
	return duz;
}

char *zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci){
	int i, logicka=0;
	char *pok;
	char *pok2;
	char *pok3;
	char *pok_na_slovo;
	int duz_tekst, duz_zamjena, razlika; 
	char *pok4;
	for(i=0; i<broj_rijeci; i++){
		//Radimo sa "i"-tom rijecju u nizu rijeci "rijeci"
		
		for(pok=tekst; *pok; pok++){
			logicka=1;
			duz_tekst=0;
			if(*pok!=' ' && *pok!='\0'){
				//Sada da pok2 pointa na kraj neke rijeci u tekst
				for(pok2=pok; *pok2!=' ' && *pok2!='\0'; pok2++)
				duz_tekst++;
				
				//Sada da poredimo sa "i"-tom rijecju;
				for(pok3=pok, pok_na_slovo=rijeci[i]; pok3<pok2; pok3++, pok_na_slovo++){
					if(*pok_na_slovo!=*pok3 || duz_tekst!=duzina_rijeci(rijeci[i])){
						logicka=0;
						pok=pok2;
						break;
					}
				}
				if(logicka){
					//Pokazivac pok5 na ono sto je u zamjene
					char *pok5;
					duz_zamjena=duzina_rijeci(zamjene[i]);
					if(duz_tekst<duz_zamjena){
						//Ako je duzina rijeci u tekstu manja od one koja je mijenja
						//Moramo prosiriti string za razliku duzina
						razlika=duz_zamjena-duz_tekst;
						//moramo pok4 poslati na kraj stringa
						for(pok4=pok; *pok4; pok4++);
						//Sad prosiriti string za razliku
						
						for(; pok4>pok2-1; pok4--){
							*(pok4+razlika)=*pok4;
						}
						*(pok4+razlika)=' ';
						//Sad kopiramo string iz niza zamjene na mjesto onog u tekst
						for(pok5=zamjene[i]; *pok5; pok5++, pok++){
							*pok=*pok5;
						}
						pok=pok2;
					} else if (duz_tekst==duz_zamjena){
						//Ako su duzine rijeci iste onda mozemo
						//samo kopirati
						for(pok5=zamjene[i]; *pok5; pok5++, pok++){
							*pok=*pok5;
						}
						pok=pok2;
					} else if (duz_tekst>duz_zamjena){
						//Ako je rijec u zamjene kraca, string 
						//treba kompresovati
						razlika=duz_tekst-duz_zamjena;
						//Saljemo pok4 do mjesta skracenja
						for(pok4=pok, pok5=zamjene[i]; *pok5; pok5++, pok4++);
						//Kompresija
						for(; *(pok4+razlika); pok4++){
							*pok4=*(pok4+razlika);
						}
						*pok4='\0';
						//A sad samo kopiranje
						for(pok5=zamjene[i]; *pok5; pok5++, pok++){
							*pok=*pok5;
						}
					}
				}
				
			}
			//Uslov da ne ulazimo u neinicijaliziranu memoriju
			if (! *pok ) break;
		}
	}
	
	return tekst;
}



int main() {
	//printf("Zadaća 4, Zadatak 3");
	char* rijeci[2] = {"testiranje", "test"};
	char* zamjene[2] = {"zamjena", "swap"};
	char tekst[] = "test testiranje test";
	printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}

#include <stdio.h>

/*Kompariramo ako su 2 rijeci jednake*/
int komparacija_rijeci(char* trenutnaRijec, char** rijeci, int broj_rijeci){
	int istinost=-8, i=0, j=0;
	
	for (;j<broj_rijeci;j++){
		while (trenutnaRijec[i] != '\0' || rijeci[j][i] != '\0'){
			if (trenutnaRijec[i] == rijeci[j][i]){
				istinost=1;
			}
			else{
				istinost=0;
				break;
			}
			i++;
		}
		if (istinost) {
			break;
		}
	}
	if (istinost == 0){
		return 0;
	}
	
	return j+1;
}

/*Funckija koja racuna duzinu literala*/
int duzina_literala(char** rijeci, int index){
	int brojac=0;
	while (rijeci[index][brojac] != '\0') {
		brojac++;
	}
	return brojac;
}


char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char* reset = tekst;
	char* pocetak;
	char* kraj;
	char* krajStringa=tekst;
	char* krajStringaRecovery; 
	char* bespotrebniPokazivac; /*Pokazivac sluzi kao temp u ralika <0 slucaju.*/
	char kopija[100], trenutnaRijec[100];
	int i, istinost, razlika, razlikaRecovery;

	/*Nadji kraj stringa*/
	while (*krajStringa != '\0'){
		krajStringa++;
	}
	krajStringaRecovery = krajStringa;
	
	/*Rubni slucajevi*/
	if (*tekst == '\0'){
		return reset;
	}
	if (broj_rijeci == 0){
		return reset;
	}

	i=0;
	/*Kopija stringa - pravi se kako se ne bi slucajno obrisao originalni string*/
	while (*tekst != '\0'){
        kopija[i]=*tekst;
        tekst++;
        i++;
    }
    kopija[i]='\0';
    i=0;
    tekst=reset;
	
	while (kopija[i]!='\0') {
        if (kopija[i] >= 'A' && kopija[i] <= 'Z'){
            kopija[i]+=32;
        }
        i++;
    } /*Formiran niz gdje su sva slova mala, prilikom rada, slova idu u temp i sa ovim se kompariraju.*/
    i=0;
    tekst = reset;
    
    while(*tekst != '\0'){
    	if (*tekst == ' '){
    		tekst++;
    		continue;
    	} /*Pomjera string dok ne dodje do rijeci*/
    	else if (*tekst != ' '){
    		i=0;
    		pocetak = tekst;
    		do {
    			trenutnaRijec[i] = *tekst;
    			i++;
    			tekst++;
    			if (*tekst == '\0'){
    				break;
    			}
    		} while (*tekst != ' ');
    		kraj = tekst;
    		trenutnaRijec[i] = '\0';
    	
    		/*printf("|%s|", trenutnaRijec);You can print this out to make sure that the correct words are entered*/
    		
    	} /*Pronalazi rijec za analizu*/
    	i=0;
    	/*Zamjena- prvo test ako su rijeci iste*/
    	istinost=komparacija_rijeci(trenutnaRijec, rijeci, broj_rijeci);
    	if (istinost==0) {
    		kraj++;
    		tekst=kraj;
    		continue;
    	}
    	else if (istinost != 0) {
    		istinost -=1;
    		/*Ako smo dosli do ovog dijela koda, dvije rijeci su iste
    		Istinitost sadrzi index pomocu kojeg mozemo dobiti rijec koja nam treba
    		Sada kompariramo duzine stringova i iz toga mozemo dobiti 3 slucaja (4 je stavljen u slucaju neocekivane greske)
  			*/
    		razlika = duzina_literala(rijeci, istinost) - duzina_literala(zamjene, istinost);
    		
    		i = 0;
    		if (razlika == 0){
    			while (pocetak != kraj){
    				*pocetak = zamjene[istinost][i];
    				i++;
    				pocetak++;
    			}
  
    		} /*Kod ako su iste duzine*/
    		else if (razlika > 0) {
				
    			while (zamjene[istinost][i] != '\0'){
    				*pocetak = zamjene[istinost][i];
    				i++;
    				pocetak++;
    			}
    			
    			while (*(pocetak+1) !='\0'){
    				*pocetak = *(pocetak+1);
    				pocetak++;
    			}
    			*pocetak='\0';
    		} /*Kod ako su vece duzine*/
    		else if (razlika < 0) {
    			krajStringa = krajStringaRecovery;
    			razlika *= -1;
    			razlikaRecovery = razlika;
    			
    			while (razlika!=0){
    				*krajStringa = '0';
    				krajStringa++;
    				razlika--;
    			}
    	
    			*krajStringa = '\0';
    			krajStringaRecovery = krajStringa;
    			krajStringa--;
    			
    			razlika = razlikaRecovery;
    			while (krajStringa != (pocetak+razlika)){
    				*krajStringa = *(krajStringa-razlika);
    				krajStringa--;
    			}
    			
    			while (zamjene[istinost][i]!='\0') {
					*pocetak = zamjene[istinost][i];
    				i++;
    				pocetak++;
    			}
    			tekst = pocetak;
    			
    		} /*Kod ako su manje duzine*/
    		else{
    			printf("Undocumented case");
    		} /*Kod ako je macka presla preko tastature*/
    	}
 	
    }
    return reset;
}

int main() {
	char* rijeci[2] = {"beli", "sneg"};
	char* zamjene[2] = {"", ""};
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("\nFINALNI STRING %s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	
	
	return 0;
}

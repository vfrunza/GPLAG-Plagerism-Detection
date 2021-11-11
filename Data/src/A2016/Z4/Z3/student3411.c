#include <stdio.h>
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char *pocetak=tekst;
	//prebrojavamo duzinu svake rijeci u rijeci i spremamo ih u novi niz tipa int
	int i=0, duzina[1000]={0},j, duzinarijeci=0, duzina2[1000]={0},duz,k;
	for(i=0; i<broj_rijeci; i++){
		j=0;
		duzinarijeci=0;
		while(*(rijeci[i]+j)!='\0'){
			duzinarijeci++;
			j++;
		}
		duzina[i]=duzinarijeci;
		
	}
	//preborajavamo duzinu svake rijeci u zamjene i spremamo ih u novi niz tipa int
	for(i=0; i<broj_rijeci; i++){
		j=0;
		duzinarijeci=0;
		while(*(zamjene[i]+j)!='\0'){
			duzinarijeci++;
			j++;
		}
		duzina2[i]=duzinarijeci;
		
	}
	while(*tekst!='\0'){
		//for petlja koja ide do broj_rijeci i koja sluzi da se ispitaju svi stringovi iz **rijeci
		for(i=0; i<broj_rijeci; i++){
			//uslov koji ispituje da li je prvi karakter stringa iz **rijeci jednak karakteru na koji pokazuje pokazivac tekst
			// uslovi (tekst==pocetak || *(tekst-1)==' ') sluze da se osiguramo da je rijec propisno odvojena, kako to nalaze zadatak
			if(*tekst==*rijeci[i] &&(tekst==pocetak || *(tekst-1)==' ')){
				char *q=rijeci[i];
				char *p=tekst;
				while(*p++ == *q++)
				//uslov koji ispituje da li je pronađen string iz **rijeci
				if (*q == '\0' && (*p == ' ' ||*p == '\0')){
					//zadatak razdvajamo na 3 slucaja. Ovo je slucaj kada je zamjena duza od rijeci koji treba mijenjati
					//string "izduzujemo" za onoliko mjesta za koliko je zamjena duza od rijeci u tekstu
					if(duzina2[i]>duzina[i]){
						duz=duzina2[i]-duzina[i];
						char *kraj=tekst;
						while(*kraj!= '\0') kraj++;
						while (kraj > tekst) {
                    		*(kraj+duz) = *kraj;
                    		kraj--;
                		}
                		//petlja kojom u tekst ubacujemo zamjensku rijec
                		j=duzina2[i];
                		char *r=zamjene[i];
                		while(j>0){
                    		*tekst=*r;
                    		tekst++;
                    		r++;
                    		j--;
                    	}
                    	tekst--;
                    	continue;
					}
					//slucaj kada su zamjena i rijec u tekstu jednake duzine. Nije potrebno izduziti niti suzavati pocetni string
					else if(duzina2[i]==duzina[i]){
						j=duzina2[i];
                		char *r=zamjene[i];
                		//petlja kojom u tekst ubacujemo zamjensku rijec
                		while(j>0){
                    		*tekst=*r;
                    		tekst++;
                    		r++;
                    		j--;
                    	}
                    	tekst--;
                    	continue;
					}
					//slucaj kada je zamjena kraca od rijeci koja se mijenja. Potrebno je "suziti" pocetni tekst
					if(duzina2[i]<duzina[i]){
						duz=duzina[i]-duzina2[i];
						char *skrati=tekst;
						//petlja kojom suzavamo tekst za onoliko mjesta za koliko je zamjena kraca od rijeci koja se mijenja
						while (duz>0) {
							k=0;
							while(*(skrati+k)!='\0'){
								*(skrati+k)=*(skrati+k+1);
								k++;
							}
                    		duz--;	
                		}
                		j=duzina2[i];
                		char *r=zamjene[i];
                		//petlja kojom ubacujemo zamjenu u tekst
                		while(j>0){
                    		*tekst=*r;
                    		tekst++;
                    		r++;
                    		j--;
                    	}
                    	tekst--;
                    	continue;
					}
				}
			}
		}
		tekst++;
	}
return pocetak;
}
int main() {
	
	return 0;
}

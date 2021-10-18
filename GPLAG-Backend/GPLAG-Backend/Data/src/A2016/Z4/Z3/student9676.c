#include <stdio.h>


	void promijeni (char *s, int n){ /**funkcija prima pokazivac na rijec koju treba zamijeniti i broj mjesta za koje treba modifikovati recenicu da bi zamjena legla fino**/
		char *temp, *temp2=s;/**temp2 mi je pocetak rijeci**/
		int i=0;
		if (n==0) return; /**funkcija ne treba da radi nista ako su rijeci jednake duzine**/
		if (n>0){
			while (*s != '\0'){ 
				s++;
			}
			temp = s; /**temp mi je kraj rijeci**/
		for (i=0; i<n; i++){   /**pomjeri mi recenicu za onoliko koliko treba napraviti mjesta tj. n**/
			while (s!=temp2){
				*(s+1) = *s;
				if (*s=='\0') *s='x';
				if (*s==' ') *s='x';
				s--;
			}           
			temp++;
			s = temp;
		}
	} else{          
         	n = -n; /**ako je rijec kojom se zamjenjuje manja treba da suzi recenicu pa ce razlika zamjene i rijeci bit negativna**/
		
			for (i=0; i<n; i++){  
			while (*s!='\0'){ 
				*s = *(s+1);
				s++;
			}
			s = temp2;
		}
	}
		
	}
/**definitivno treba i funkcija duzina**/

int duzina (char *s){
	int n =0;  
	while(*s != '\0'){
		n++;
		s++;
	}
	return n;
}

char* zamjena_rijeci(char* tekst, char** rijeci,char** zamjene, int broj_rijeci){
	
	char *povrat = tekst, *temp;
	int nova = 1, i=0, jednak=0, j=0, duzinaZamjene=0, duzinaRijeci=0;
	
	
	while(*tekst != '\0'){
		if (*tekst == ' '){  /** rijeci su odvojene razmacima tako da kad pokazivac naidje na razmak to je kraj neke rijeci**/
			nova = 1;        /**nova rijec**/
		} else if (nova){
			temp = tekst;
			for (i=0; i<broj_rijeci; i++){
				tekst = temp;
				jednak = 1;
				j=0;
					while (*tekst != '\0' && *tekst != ' '){
						if (*tekst != *(*(rijeci + i)+j)){     /** duplim dereferenciranjem dobijamo karakter rijeci**/
							jednak = 0;                       
						}
						j++;
						tekst++;
					}
				if (*(*(rijeci + i)+j) != '\0') jednak = 0; /**ako rijec nije zavrsila znaci da rijec iz teksta i rijec iz niza nisu jednake nego je samo rijec iz teksta podstring rijeci iz niza**/
				
				tekst--; /**zbog preskakanja razmaka**/
				
				if (jednak == 1){
					tekst = temp;
					duzinaRijeci = duzina(*(rijeci+i));
					duzinaZamjene = duzina(*(zamjene+i)); /**funkcija duzina ce da broji karaktere rijeci koju treba zamijeniti i rijeci kojom je treba zamijeniti**/
					promijeni (tekst, duzinaZamjene-duzinaRijeci); /**funkcija promijeni ce ovisno o potrebi prosiriti ili suziti tekst tako da zamjena taman stane u slucaju da nije iste duzine kao rijec koju mijenja**/
					
					j=0;
					while(*tekst != '\0' && *tekst != ' '){
						*tekst = *(*(zamjene+i)+j);
						j++;
						tekst++;
					}
					
					tekst--;
					break;
					
				}
				
			}
			nova = 0;
		}
		tekst++;
	}

	return povrat;
}


int main() {
	
	 
	 char tekst[100]={"Mozda nekad i padnem programiranje"};
	 char *rijeci[]={"nekad", "i"};
	 char *zamjene[]={"nikad", "ne"}; 
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	
	return 0;
}

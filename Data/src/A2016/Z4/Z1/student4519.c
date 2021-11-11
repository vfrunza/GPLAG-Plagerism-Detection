#include <stdio.h>

char* izbaci_najcescu(char *s);

int main() {
	/* testiranje */	
		/*char t[]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
		char t[]=" stop Stop stopa sam stop";
		printf("%s", izbaci_najcescu(t));
		*/
	return 0;
}

char* izbaci_najcescu(char *s){
	
	    int  najcesca; /* polozaj najcesce rijeci u nizu */
		char* rijec[20];    /*sadrzi rijeci */
		int velicina_r[20] = {0};
		int ponavljanje[20] = {0};
		int kopija_od[20]={0}; /*pokazuje cija je kopija trebutna rijec*/

		/*funkcija vraca pokazivac na pocetak stringa*/
		char *ret = s;
	
		/*prebrojavanje rijeci*/	
		int broj_rijeci = 0;
		int i,j,brojac; /*brojac nam sluzi da poredimo samo rijeci, a ne simbole iza njih */
		char *p, *q;
		
		while(*s != '\0') {
			if((*s >= 'A' && *s <='Z') || (*s >='a' && *s <='z')){
				rijec[broj_rijeci] = s;
				ponavljanje[broj_rijeci]++;
				broj_rijeci++;
				while((*s >= 'A' && *s <='Z') || (*s >='a' && *s <='z')){
					velicina_r[broj_rijeci-1]++;
					s++;
				}
			}
			else s++;		
		}

	
		/* postavlja vrijednosti od niza na -1 jer garbage value moze 
		biti isti kao pozicija orginala*/
		for(i = 0; i < 20; i++)
			kopija_od[i] = -1;
		
		/* ako je broj rijeci 0, funkcija ne radi nista */
		if(broj_rijeci == 0) return ret;
	
	
		/* poredjenje rijeci */
		for(i = 0; i < broj_rijeci; i++) {
			for(j = i+1; j < broj_rijeci-i; j++) { 
				if(velicina_r[j] == 0) continue;
				if(velicina_r[i] == velicina_r[j]){
					p = rijec[i];
					q = rijec[j];
					brojac = 0;
					while ((*p == *q || *p+32 == *q || *p-32 == *q)) {
						p++;
						q++;
						brojac++;
						if(brojac == velicina_r[i]){
							ponavljanje[i]++;
							velicina_r[j] = 0;
							ponavljanje[j] = 0;
							kopija_od[j]=i;
						}
					}
				}
			}
		}
		
		
		/* trazenje najcesce rijeci */
		najcesca = 0;
		for(i = 1; i < broj_rijeci; i++)
			if(ponavljanje[najcesca] < ponavljanje[i]) 
				najcesca = i;  
		kopija_od[najcesca] = -2;

		
		/* pronalazak kopija najcesce rijeci i*/
		
			for(j = broj_rijeci-1; j >= 0; j--){
				if(kopija_od[j] == najcesca || kopija_od[j] == -2){
					p = rijec[j];
					q = rijec[j] + velicina_r[najcesca];
					while (*q != '\0'){
						*p = *q;
						p++;
						q++;
				    }
					*p = '\0';
			    }
			}
			
		
		
	return ret;	
}
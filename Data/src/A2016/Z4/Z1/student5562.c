#include <stdio.h>

void unesi(char* string, int d){
	
	int i = 0;
	char znak = getchar();
	
	if (znak == '\n') znak = getchar();
	
	while (i < d - 1 && znak != '\n'){
		string[i] = znak;
		i++;
		znak = getchar();
	}
	
	string[i] = '\0';
}

int jednaki (char a, char b){ /*Funkcija koja provjerava jednakost izmedju 2 slova*/
	
	if ((int)a == (int)b)
		return 1;
	
	if ((int)a > (int)b)
		if ((int)a == (int)b + 32)
			return 1;
		
	if ((int)b > (int)a)
		if ((int)b == (int)a + 32)
			return 1;
	
	return 0;
}

char* izbaci_najcescu(char *s){
	
	int i = 0, k = 0, j, m;
	int duzina[200];
	int pon[200];
	int maxpon = 0, ista, ima_slova = 0;
	char rijec[200][200];
	char* p = s;
	char* ppoc;
	
	/*Inicijalizuj pocetne duzine*/
	for (m = 0; m < 200; m++)
		duzina[m] = 0;
	/*Inicijalizuj pocetna ponavljanja*/
	for (m = 0; m < 200; m++)
		pon[m] = 0;
	
	while (*p != '\0'){
		if (((int)*p >= 65 && (int)*p <= 90) || ((int)*p >= 97 && (int)*p <= 122)){
			ima_slova = 1;
			break;
		}
		p++;
	}
	p = s;
	
	if (ima_slova == 1){ /*Ako slova nema, ne mora se raditi nista*/
		/*Rascjepkati string i rijeci (bez razmaka) staviti u niz*/
		
		if ((int)*(s) < 65 || (int)*(s) > 122 || ((int)*(s) > 90 && (int)*(s) < 97))
			k--;
		
		while (*p != '\0'){
			
			while ((((int)*p >= 65 && (int)*p <= 90) || ((int)*p >= 97 && (int)*p <= 122)) && *p != '\0'){ 
				rijec[k][i] = *p;
				i++;
				p++;
				duzina[k]++;
			}
		
			if (((int)*p < 65 || (int)*p > 122 || ((int)*p > 90 && (int)*p < 97)) && *p != '\0'){ 
				
				while (((int)*p < 65 || (int)*p > 122 || ((int)*p > 90 && (int)*p < 97)) && *p != '\0')
					p++;
				
				if ((((int)*p >= 65 && (int)*p <= 90) || ((int)*p >= 97 && (int)*p <= 122)) && *p != '\0')
					k++;
				i = 0;
			}
			
		}
		
		for (i = 0; i < k + 1; i++){ /*Zapikamo rijec iz niza*/
			
			for (j = 0; j < k + 1; j++){ /*Listamo ostale i trazimo ponavljanje*/
				
				if (duzina[i] == duzina[j]){ /*Ako su duzine nejednake, nema sanse da je u pitanju ponavljanje*/
					
					for (m = 0; m < duzina[i]; m++){ /*Dodatni uslov da rijec bude ponavljanje, vrsimo poredjenje*/
						
						if (jednaki(rijec[i][m], rijec[j][m]) == 0)
							break;
						
						if (m == (duzina[i] - 1))
							pon[i]++;
						
					}
					
				}
				
			}
			
		}
	
	
		/*Trazimo najveci broj ponavljanja (indeks rijeci koja je najcesca)*/
		for (i = 0; i < k + 1; i++){
			
			if (i == 0)
				maxpon = i;
			
			if (pon[i] > pon[maxpon]){
				maxpon = i;
			
			}
			
		}
	
		p = s;
		
		while (*p != '\0'){ 
		
			if (jednaki(*p, rijec[maxpon][0]) == 1){ /*Ako naidjemo na jednako slovo, to je potencijalno ta ista rijec*/
					
				ppoc = p; 
				i = 0;
				ista = 0; 
					
				while (i < duzina[maxpon] && *p != '\0' && (((int)*p >= 65 && (int)*p <= 90) || ((int)*p >= 97 && (int)*p <= 122))){ 
						
					if (jednaki(*p, rijec[maxpon][i]) == 0){ /*Provjeravamo ostala slova*/
						ista = 0;
						break;
					}
					
					if (i == duzina[maxpon] - 1)	
						if (((int)*(p + 1) < 65 || (int)*(p + 1) > 122 || ((int)*(p + 1) > 90 && (int)*(p + 1) < 97)) || *(p + 1) == '\0'){
							ista = 1;
						}
					
					
					if (*p != '\0'){
						p++;
						i++;
					}
				}
					
				p = ppoc;
					
				if (ista == 1){
						
					for (i = 0; i < duzina[maxpon]; i++){
							
						while (*p != '\0'){
							*p = *(p + 1);
							p++;
						}
						p = ppoc;
					}
				}
			}
		
		while ((((int)*p >= 65 && (int)*p <= 90) || ((int)*p >= 97 && (int)*p <= 122)) && *p != '\0') /*Ako se ispostavi da rijec nije jednaka treba "izaci" iz nje*/
			p++;
		while (((int)*p < 65 || (int)*p > 122 || ((int)*p > 90 && (int)*p < 97)) && *p != '\0') /*I doci do slijedece, ako je ima*/
			p++;
		}

		
	}
	return s;
}

int main() {
	
	char recenica[100];
	unesi(recenica, 100);
	
	izbaci_najcescu(recenica);
	//printf("%s\n", izbaci_najcescu(recenica));
	
	return 0;
}

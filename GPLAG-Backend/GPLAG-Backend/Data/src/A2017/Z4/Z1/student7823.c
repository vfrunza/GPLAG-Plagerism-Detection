#include <stdio.h>

/**
 char * tekst
 int * broj_razmaka => ovdje smjestamo broj razmaka izmedju dvije rijeci
 return char* pokazivac na prvo slovo slijedece rijeci
 */
char * nadji_slijedecu_rijec(char * tekst, int * broj_razmaka) {
	char * p = tekst;
	*broj_razmaka = 0;
	if (*p == '\0') return NULL; 
	while (*p == ' ') p++; 
	while (*p != '\0' && *p != ' ') p++;  
	while (*p++ == ' ') (*broj_razmaka)++;  
	p--; // p moram pomaknuti ispred prvog slova naredne rijeci
	
	if (*p == '\0') return NULL; // da izbjegnem ubacivanje broja kad p dodje na kraj stringa zato sto broj mora biti izmedju dvije rijeci
	return p;
	
}

int duzina_stringa(char * s) { //funkcija koja vraca duzinu stringa
	int vel = 0;
	while (*s++ != '\0') vel++;
	return vel;
}

char * int_to_string(int value, char * result) {   // pretvara broj u string (int u string)
	char * ptr = result, *ptr1 = result, tmp_char;
	int tmp_value = value; 
	if (value < 0) value *= -1; 
	
	do {
		*ptr++ = "0123456789" [value % 10];  //niz
		value /= 10;
	} while (value!=0);
	
	/* ako treba promijenimo predznak */
	if (tmp_value < 0) *ptr++ = '-'; //dodamo minus ako je vrijednost negativna 
	*ptr-- = '\0';
	
	// sada jednostavno obrnemo broj u stringu
	while (ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr-- = *ptr1; // ptr je na kraju broja i tu prepisem broj na koji pokazuje ptr1 (prvi broj)
		*ptr1++ = tmp_char; //prepisujem na prvu cifru zadnju cifru
	}
	
	return result; 
}




char * ubaci_broj(char * tekst, int broj) {
	char broj_string[100] = "";    //tu smjestam brojeve
	/** 
	 * 	@var char * pb => pokazivac na broj (kao string) 
	 */
	char * pb = int_to_string(broj, broj_string); 
	
	/*int vel_broja predstavlja velicinu broja kao stringa
	 */
	int vel_broja = duzina_stringa(broj_string);   //duzina stringa, to jeste broja 
	
	char * t = tekst, *pom = NULL;

	int broj_razmaka = 0, i = 0;
	
	char * kraj_teksta = tekst, *temp = NULL;
	
	while (*kraj_teksta != '\0') kraj_teksta++;
	kraj_teksta--;    // kraj_teksta stavili na kraj recenice "tekst" koja je parametar funkcije 
	
	/* 't' pokazuje na pocetak slijedece rijeci */
	while ((t = nadji_slijedecu_rijec(t, &broj_razmaka))) { 
		
		if (broj_razmaka > 1) {
			/* pomjerimo se na mjesto upisivanja broja */
			for (i = 0; i < broj_razmaka; i++) t--;  // pomaknem t unazad za onoliko koliko ima razmaka
		}
		
		pom = kraj_teksta;
		for (i = 0; i < vel_broja; i++) pom++;
		
		if (broj_razmaka <= 1) {
			pom++;
			t--;   // pomaknem t unazad za jedno mjesto ako je 1 razmak
		}  
		
		
		
		/* 'temp' pamti novi kraj 'teksta' */
		temp = pom;
		while (kraj_teksta != t) {
			
			*pom = *kraj_teksta;     //prebacujem svako slovo u desno i tako pravim prostor gdje cu ubaciti broj
			pom--;
			kraj_teksta--;
		}
		*pom = *t; 
		kraj_teksta = temp++;   //kraj_teksta stavljam na kraj, pomaknem temp++
		*temp = '\0';    //pomakli da dodamo jos i \0
		 t++;  // zato sto mora postojati razmak izmedju rijeci i broja kojeg ubacujem

       
       
       while (*pb != '\0') *t++ = *pb++; 
		pb = broj_string;   // vracam pb na pocetak broj zbog narednog ubacivanja
		*t = ' ';   //dodam razmak
		t++;  // tu upisujem naredni broj
	}
	return tekst;    //funkcija vraca pokazivac na pocetak primljenog stringa
}

int main() {
	char s[77] = "Ovdje izmedju    rijeci   ima   po     nekoliko   razmaka";
	printf("\"%s\"", ubaci_broj(s, 320));
    return 0;
}

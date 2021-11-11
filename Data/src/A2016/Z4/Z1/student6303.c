#include <stdio.h>


void unesi(char niz[], int velicina){
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i = 0;
	while(i < velicina-1 && znak != '\n'){
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

int isLetter(char c){
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') )
		return 1;
	return 0;
}



int prebroji_ponavljanja(char *kandidat_org, int duzina, char* recenica_org){
	//kopiranje recenice:
	char recenica[200];
	char *x = recenica;
	char *y = recenica_org;
	
	while(*y != '\0'){
		if (*y >= 'A' && *y <= 'Z')
			*x = *y + 32;
		else
			*x = *y;
			
		x++; y++;
	}
	*x = '\0';
	
	//prebrojavanje
	char *kandidat = kandidat_org;
	char *p = recenica;
	int br = 0;
	
	while(*p != '\0'){
		int d = duzina;
		
		char *kandidat_tmp = kandidat;
		char *k = kandidat;
		
		if (*p == *k && *p != '\0' && (p == recenica ||isLetter(*(p-1))==0 )){
			while(d > 0){
				if (*p != *k || *p == '\0') break;
				p++; k++; d--;
			}
		}
		kandidat = kandidat_tmp;
		
		if (d == 0 && (*p != '0' && isLetter(*p)==0)) 
			br++; //ako je 0 dosli do kraja rijeci
		
		if (*p == '\0') break;
		p++;
	}
	
	return br;
}


void izbrisi_rijec(char *rijec, int duzina, char* recenica){
	char *p = recenica;
	while (*p != '\0'){
		char *r = rijec;
		
		if ( (*p == *r || *p == *r + 32 || *p == *r -32 ) && *p != '\0'){
			int d = duzina;
			char *k = rijec;
			char *pozicija = p;
			
			//provjera da li je to ta rijec
			if (*p != '\0')
			if ( (*p == *k || *p == *k + 32 || *p == *k - 32) && (p == recenica || isLetter(*(p-1)) == 0)  ){
				
				while (d > 0){
					char c;
					
					if (*p >= 'A' && *p <= 'Z')
						c = *p + 32;
					else
						c = *p;
					
					if (c != *k || *p == '\0') break;
					p++; k++; d--;
				}
			}
			
			if (d == 0 && (*p != '0' && isLetter(*p)==0)) { //zaisa ta rijec
				char * q = pozicija;
				
				//brisanje rijeci:
				while(*(q+duzina) != '\0'){
					*q = *(q+duzina);
					q++;
				}
				*q = '\0';
				
				p = pozicija;
				p--;
			}
		}
		
		p++;
	}
}


char* izbaci_najcescu(char* s){
	char *recenica = s;
	char *pocetak = recenica;
	char *p = recenica;
	
	int max = 0;
	char *najcesca;
	int najcesca_duzina = 0;
	
	while(*p != '\0'){
		if (p==recenica || isLetter(*p) == 0 ){
			while(*p != '\0' && isLetter(*p) == 0 ) { p++;}
			if (*p == '\0') break;
			//if (*(p+1) != '\0' && p!= recenica) p++;
			
			char *kandidat = p; 
			char *k = p;
			
			int duzina = 0;
			while (  ((*p>='a' && *p<='z') || ( *p>='A' && *p<='Z' )) && *p!='\0'  ){
				k++; p++; duzina++;
			}
			p--;
			
			//kopija rijeci
			char *ktt = kandidat;
			int i;
			char kandidat_tmp[200];
			char* kt = kandidat_tmp;
			
			for(i = 0; i < duzina; i++){
				if (*ktt >= 'A' && *ktt <= 'Z')
					*kt = *ktt + 32;
				else
					*kt = *ktt;
				kt++; ktt++;
			}
			*kt = '\0';
			
			//printf("kandidat: %s", kandidat_tmp);
			
			int koliko = prebroji_ponavljanja(kandidat_tmp, duzina, recenica);
			
			//printf("%d \n", koliko);
			
			if(koliko > max){
				max = koliko;
				najcesca = kandidat;
				najcesca_duzina = duzina;
			}
		}
		
		p++;
	}
	
	
	//kopija najcesce rijeci
	int j;
	char najcesca_kopija[200];
	char* nk = najcesca_kopija;
	for (j = 0; j < najcesca_duzina; j++){
		if (*najcesca >= 'A' && *najcesca <='Z')
			*nk = *najcesca + 32;
		else
			*nk = *najcesca;
		nk++; najcesca++;
	}
	*nk = '\0';
	
	//printf("najcesca: %s \n", najcesca_kopija);
	
	if (najcesca_duzina > 0)
		izbrisi_rijec(najcesca_kopija, najcesca_duzina, recenica);
	
	return s;
}


int main() {
	/*
	char recenica[200];
	unesi (recenica, 200);
	
	char *s = recenica;
	s = izbaci_najcescu(recenica);
	
	printf("%s", recenica);*/
	printf("IZLAZ: \n");
	
	char t[]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
	printf("'%s'", izbaci_najcescu(t));
	
	
    
	return 0;
}

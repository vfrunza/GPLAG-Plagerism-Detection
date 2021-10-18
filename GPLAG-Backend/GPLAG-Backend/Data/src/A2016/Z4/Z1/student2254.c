#include <stdio.h>
int trazi_rijec(char *s1, char *s2);
char *izbaci_najcescu(char *s);
int duz_string (char *s);
void unesi(char niz[], int velicina); 

int main() {
	char k[] =  "AYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY L";
	printf("'%s'", izbaci_najcescu(k));
	return 0;
}

int trazi_rijec(char* s1, char* s2) {
	int u = 0;
	while (*s1 != '\0') {
		while (*s1 == ' ') s1++;
		char* p = s1;
		char* q = s2;
	while (((*p == *q) && (*p != 0)) || (*p + 32 == *q && *p != 0) || (*p -32 == *q && *p != 0)){
		p++;
		q++;
		if (*q == '\0' && (*p == ' ' || *p == '\0')){
		 u++;
		 q = s2;
		}
	}
		
	while (*s1 != ' ' && *s1 != '\0')
	s1++;
	}
	return u;
}

int duz_string (char *s){
	char *p = s;
	int duz = 0;
	
	while(*p != 0){
		p++;
		duz++;
	}
	
	return duz;
}

void unesi(char niz[], int velicina){
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char *izbaci_najcescu(char *s){
	char rijec[100000], nova_recenica[100000] ,  naj_pon_rijec[100000], rijec2[100000];
	char  *d = naj_pon_rijec, *q = rijec, *f = nova_recenica, *p = s, *k = s, *q2 = rijec2;
	int br_pon[100000], i = 0, j = 0, nemaslovo = 1, samoslovo = 1;
	
	while (*p != 0){
		if (!(*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))	samoslovo = 0;
		p++;
	}
	
	p = s;
	
	if(samoslovo)
		*p = '\0';
	
	while (*p != 0){
		if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))	nemaslovo = 0;
		p++;
	}
	
	if (i==50000)
		i=1;
	
	if(nemaslovo) return s;
	
	p = s;
	
	while(*p != 0){
		
		//Pronalazenje rijeci koja se najvise ponavlja (obracajuci paznju na redoslijed)
		
		while ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')){
			*q++ = *p++; 
		}
		
		*q = '\0';
		
		while(!((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) && *p != 0) p++;
			
		q = rijec;
		
		br_pon[i] = trazi_rijec(s, rijec);
		
		//prvu rijec odmah staviti kao rijec koju treba izbaciti
		if(i == 0){
			while(*q != 0)
				*d++ = *q++;
				
			*d = '\0';
		}
		d = naj_pon_rijec;

		// trazenje rijeci koja se najvise ponavlja
		
		if(i != 0){
			if(br_pon[j] < br_pon[i]){
				while(*q != 0)
					*d++ = *q++;
				*d = '\0';
				j = i;
			}
		}
		d = naj_pon_rijec;
		
		i++;
	
	}
	
	p = s; //vracanje na pocetak recenice
	
	//Izbacivanje rijeci koja se najvise ponavlja
	
	while(*p != 0){
		q = rijec;
		
		while(!((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) && *p != 0 ){
			*q2++ = *p++;
		}
		
		*q2 = '\0';
		q2 = rijec2;
		
		while ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')){
			*q++ = *p++; 
		}
		
		*q = '\0';
		q = rijec;
		
		
		// dodavanje brojeva, simbola, razmaka (u slucaju da ih ima)
		while (*q2 != 0)
			*f++ = *q2++;
		
		q2 = rijec2;
		
		// kreiranje recenice bez rijeci koja se najvise ponavlja
		if (trazi_rijec(rijec, naj_pon_rijec) == 0 ){
			while (*q != 0){
				*f++ = *q++;
			}
			q = rijec2;
		}
		
	}
	

		
	k = s;
	*f = '\0';
	f  = nova_recenica; 
	
	// mjenjanje pocetne recenice
	while (*f != 0){
		*k++ = *f++;
	}
	
	
	
	*k = '\0';
	return s;
}



#include<stdio.h>
#include<ctype.h>

/*funkcija za unos stringa*/
void unesi (char niz[], int velicina){
	
	char znak=getchar();
	
	if (znak == '\n'){
		znak=getchar();
	}
	
	int i=0;
	
	while (i<velicina-1 && znak != '\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	
	niz[i]='\0';
}

/*funkcija koja vraća pokazivač na n-tu riječ u stringu*/
char* vrati_rijec (char* s, int n){
	
	int neslovo=1, broj_rijeci1=0;
	
	while (*s != '\0'){
		
		if (!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))){
			neslovo=1;
		}
		else if (neslovo == 1){
			
			neslovo=0;
			broj_rijeci1++;
		}
		
		if (broj_rijeci1 == n){
			return s;
		}
	
	s++;
	}
}

/*funkcija koja vraća broj riječi*/
int broj_rijeci (char* s){
	
	int neslovo=1, broj_rijeci1=0;
	
	while(*s != '\0'){
		
		if (!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))){
			neslovo=1;
		}
		else if (neslovo == 1){
			
			neslovo=0;
			broj_rijeci1++;
		}
		s++;
	}
	
	return broj_rijeci1;
}

/*funkcija koja izbacuje n-tu riječ*/
void izbaci_rijec (char* s, int n){
	
	int neslovo=1, broj_rijeci1=0;
	char* pocetak;
	while (*s != '\0'){
		
		if (!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))){
			neslovo=1;
		}
		else if (neslovo == 1) {
			
			neslovo=0;
			broj_rijeci1++;
			
			if (broj_rijeci1 == n){
				pocetak=s;
				
				while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
					s++;
				}
				
				if (*s == '\0'){
					*pocetak='\0';
					return;
				}
				else {
					while (*pocetak++ = *s++);
					return;
				}
			}
		}
		
	s++;	
	}
}

/*funkcija izbaci_najcescu*/
char* izbaci_najcescu (char* s){
	
	int broj_rijeci1=broj_rijeci(s);
	int i,j;
	int broj_izbacenih=0;
	int pozicija=0, jednak, broj_jednakih=0, max=0;
	
	char* a;
	char* b;
	
	if (broj_rijeci1 == 0){
		return s;
	}
	
	/*123-153 Traži najučestaliju riječ i u varijablu pozicija sprema 
	mjesto u stringu na kojem se ta riječ prvi put pojavila.*/
	for (i=1; i<=broj_rijeci1; i++){
		for (j=i; j<=broj_rijeci1; j++){
			a=vrati_rijec(s, i);
			b=vrati_rijec(s, j);
			jednak=1;
			
			while (((*a>='a' && *a<='z') || (*a>='A' && *a<='Z')) && ((*b>='a' && *b<='z') || (*b>='A' && *b<='Z'))){
				if (tolower(*a) != tolower(*b)) {
					jednak=0;
					break;
				}
				a++;
				b++;
			}
			
			if (!((*a>='a' && *a<='z') || (*a>='A' && *a<='Z')) && !((*b>='a' && *b<='z') || (*b>='A' && *b<='Z')) && jednak==1){
				broj_jednakih++;
			}
		}
		
		if (broj_jednakih > max){
			max=broj_jednakih;
			pozicija=i;
		
		}
		if(max>broj_rijeci(s)-i){
			break;
		}
		broj_jednakih=0;
		
	}
	
	/*  157-180 Prolazi kroz sve riječi, provjerava da li se podudaraju sa najučestalijom.
	Ako da, izbacuje tu riječ*/
	for (i=broj_rijeci(s); i>= pozicija; i--){
		
		a=vrati_rijec(s, pozicija);
		b=vrati_rijec(s, i);
		jednak=1;
		
		while (((*a>='a' && *a<='z') || (*a>='A' && *a<='Z')) && ((*b>='a' && *b<='z') || (*b>='A' && *b<='Z'))){
				if (tolower(*a) != tolower(*b)) {
					jednak=0;
					break;
				}
				a++;
				b++;
			}
			
			if (!((*a>='a' && *a<='z') || (*a>='A' && *a<='Z')) && !((*b>='a' && *b<='z') || (*b>='A' && *b<='Z')) && jednak==1){
				izbaci_rijec(s, i);
				broj_izbacenih++;
			}
			
			if(broj_izbacenih==max){
				break;
			}
	}
	
	return s;
}

int main () {
	
	char niz[100000];
	unesi(niz, 100000);
	
printf("%s", izbaci_najcescu(niz));
	
	
	
	return 0;
}
#include <stdio.h>

int broj_rijeci(char* s){
	
	char* p=s;
	int br_rijec=0;
	int i=0;
	
	while (*p != '\0') {
		
		if((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))
		i++;
		
		else if(i>0){
			
			br_rijec++;
			i=0;
		}
		
		p++;
	}
	

	if(  (*(p-1)>='A' && *(p-1)<='Z') || (*(p-1)>='a' && *(p-1)<='z') ) br_rijec++;
	
	
	return br_rijec; /* Broj rijeci u stringu */
}



int provjeri_duzine (char* s, int* niz, int vel_niz){
	
	int br_rijeci=broj_rijeci(s);
	
	if(br_rijeci!=vel_niz) return 0; /* ako nije isti broj rijeci i clanova niza, nema ih smisla porediti */
	
	char* p=s;
	char* q=s;
	int brojac=0;
	int i=0;
	
	
	while(*p!='\0' && i<vel_niz){
		
		q=p;
		
		while(!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && *p!='\0') p++;  /* p na pocetku  rijeci*/
		
		q=p;
																				
		while(((*q>='A' && *q<='Z') || (*q>='a' && *q<='z')) && *q!='\0'){
			q++;														    	/* q na kraju rijeci*/
		}
		
		
		
		while(p!=q && *p!='\0'){
			brojac++;					/* brojac = broj znakova  rijeci*/
			p++;
		}
		
		p--;
		
		
		if(*(niz+i)!=brojac)  return 0; /* Poredimo broj znakova rijeci sa odgovarajucim clanom niza */
		
		
		brojac=0; 
		i++;
		p++;
	}
	
	
	return 1;
	
}


int main() {

char tekst[] = " ";
int niz[] = {5,2,3,4};
int niz2[] = {5,2,3,8};
int niz3[] = {5,2,3,4,0};

printf("%d\n", broj_rijeci(tekst));
printf("%d ", provjeri_duzine(tekst, niz3, 5));
printf("%d ", provjeri_duzine(tekst, niz2, 4));
printf("%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}

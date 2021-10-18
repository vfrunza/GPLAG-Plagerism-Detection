#include <stdio.h>

void unesi(char niz[], int velicina) {
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak != '\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
	
}

int provjeri_duzine(char *s, int niz[], int velicina_niza) {
	char *pocetak=s;
	int brojac_rijeci=0;
	int brojac_slova=0;
	int i=0;
	
	
	
	
	while(*s!='\0') {
	   /*	while(*s !='\0' && *s == ' ') s++; */
	   	if(*s!='\0' &&   (!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')))) s++; 
		
		if(*s!='\0' && ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) brojac_rijeci++;
		while(*s!='\0' && ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) s++;
		
	}
	if(brojac_rijeci!=velicina_niza) return 0;
	
	 
	 
	s=pocetak;   
	
	i=0;
	
	   	
	   	

		while(*s!='\0') {
			while(*s!='\0' && *s==' ') s++;
				if(*s!='\0' && ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) {
					brojac_slova=0; 
		while(*s!='\0' && ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) {
		
				brojac_slova++;
				s++;
			}
			if(brojac_slova!=niz[i]) return 0;
			i++;
		}
     
           	
		if(*s =='\0')
		  break;
		s++;
	}
	
	
	
	
	return 1; 
}



int main() {
	
 
 

	return 0;
}

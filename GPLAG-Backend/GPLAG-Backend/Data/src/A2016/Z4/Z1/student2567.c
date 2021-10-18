#include <stdio.h>

void unesi (char niz[], int velicina) {
	
	char znak=getchar(); 
	if (znak=='\n') znak=getchar(); 
	int i=0; 
	
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak; 
		i++; 
		znak=getchar(); 
	}
	niz[i]='\0'; 
}

 char* izbaci_najcescu (char*s) {
	
	char*p=s;
	char*kraj=s; 
	char*q=s;
	int neslovo=1,razmak=1; 
	
	while (*s!='\0') { 
		
		if (*s==' ') razmak=1; 
		
		else if (razmak==1) {
			
			razmak=0; 
			if (*s>='A' && *s<='Z' || *s>='a' && *s<='z') neslovo=1; 
			
			else if (neslovo==1) {
				
				q++; 
				
				if (*q=='\0') break; 
				
				if (*p++==*q++) {
					kraj=s; 
					
					while (*kraj!='\0' && *kraj!=' ') 
					kraj++; 
				}

			}
			
		}
		s++; 
		*kraj='\0';
	}
	return q; 
}

int main() {
	
	char tekst[100]; 
	
	printf ("Unesite neki tekst: "); 
	unesi(tekst, 100); 
	
	izbaci_najcescu(tekst); 
	printf ("%s", tekst); 
	
	return 0;
}

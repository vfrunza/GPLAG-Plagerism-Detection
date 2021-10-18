#include <stdio.h>

void unesi (char* niz, int velicina) {
	char znak=getchar();
	int i=0;
	if (znak=='\n') znak=getchar();
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int Dalijeslovo (char s) {
    if ((s>='A' && s<='Z') || (s>='a' && s<='z')) return 1;
    else return 0;
}

void najduzi_bp (char* s1, char* s2) {
    char* pomocna;
    char* pocetak;
    int duzina=0, max=0, i, br=0;
    
    while (*s1!='\0') {
    	if (Dalijeslovo(*s1)==1) {
    	    pocetak=s1;
    	    pomocna=s1;
    	    duzina=0;
    	    while (Dalijeslovo(*s1)==1) {
    	        s1++;
    	        duzina++;
    	    }
    	    s1--;
    	    br=0;
    	    while (s1>pocetak) {
    	        if (*s1==*pocetak || *s1==(*pocetak)+32) {
    	            duzina-=1;
    	            s1--;
    	            pocetak-=br;
    	        } else {
    	            pocetak++;
    	            br++;
    	       }
    	    }
    	    
    	    if (duzina>max) {
    	        max=duzina;
    	        pocetak=pomocna;
    	        for (i=0; i<max; i++) {
    	            *(s2+i)=*pocetak;
    	            pocetak++;
    	        }
    	        *(s2+i)='\0';
    	    }
    	    
    	}
    	
    	s1++;
    }
}

int main() {
    char s1 [200], s2[200];
    
    printf ("Unesite neki tekst: ");
    unesi (s1, 200);
    
    printf ("\nNajduzi trazeni podniz je: ");
    najduzi_bp(s1, s2);
    
    printf ("%s", s2);
	
	
	return 0;
}

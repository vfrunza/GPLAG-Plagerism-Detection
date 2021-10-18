#include <stdio.h>

char veliko(char c) {
     if (c >= 'a' && c <= 'z')
        c -= 32;
        
     return c;
}

int duzina_podniza(char* p, char* k) {
    char* s1 = p;
    char* s2;
    
    while (s1 < k - 1) {
        s2 = s1 + 1;
        while (s2 < k) {
            if (veliko(*s1) == veliko(*s2))
                return s2 - p;
            s2++;
        }
        s1++;
    }
    
    return k - p;
}

void najduzi_bp(char* s1, char* s2) {
   char* t = s1;
   char* p = 0;
   char* p1;
   char* p2;
   char *s;
   int maks_duz = 0;
   int duzina;

   *s2 = '\0';
   while (*t != '\0') {
        if ((*t < 'a' || *t > 'z') && (*t < 'A' || *t > 'Z')) {
            if (p != 0) {
            	p1 = p;
            	while (p1 < t) {
            	    duzina = duzina_podniza(p1, t);
        			if (maks_duz < duzina) {
        			    maks_duz = duzina;
                		s = s2;
                		p2 = p1;
                		while (p2 < p1 + duzina)
                			*s++ = *p2++;
                		*s = '\0';
        			}
	            	p1++;
            	}
            	p = 0;
            }
        }
        else if (p == 0)
        	p = t;
           
        t++;
    }
    
    if (p != 0) {
    	p1 = p;
    	while (p1 < t) {
    	    duzina = duzina_podniza(p1, t);
			if (maks_duz < duzina) {
			    maks_duz = duzina;
        		s = s2;
        		p2 = p1;
        		while (p2 < p1 + duzina)
        			*s++ = *p2++;
        		*s = '\0';
			}
        	p1++;
    	}
    	p = 0;
    }
}

int main() {

    char niz[10];
    najduzi_bp ("abcde etankera cdefg", niz);
    printf ("Niz: '%s'", niz);

	return 0;
}
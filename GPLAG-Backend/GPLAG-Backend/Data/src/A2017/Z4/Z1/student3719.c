#include <stdio.h>

 int duzina_broja(int b) {
    int r;
    
    r = 0;
    if (b <= 0) {
        r++;
        b = -b;
    }
    
    while (b > 0) {
        r++;
        b /= 10;
    }

    return r;
} 

char* upis_broja(char* s, int b) {
    char* t = s;
    int duz = duzina_broja(b);
    
    if (b < 0) {
        *t++ = '-';
        duz--;
        b = -b;
    }
    else if (b == 0)
        *t = '0';
    
    while (b > 0) {
        *(t + duz - 1) = (b % 10) + '0';
        duz--; 
        b /= 10;
    }

    return s;
}

void unesi(char niz[], int velicina) {
    int i;
    
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    
    i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char* ubaci_broj(char* tekst, int broj) {
   char* t = tekst;
   char* kraj;
   int duzina;
   int dodatni_razmak;
   int rijec;

   duzina = 0;
   rijec = 0;
   while (*t != '\0') {
        if (*t == ' ') {
            if (rijec == 1) {
                rijec = 0;

       			kraj = t;
       			while (*kraj != '\0') {
       			    if (*kraj != ' ')
       			        break;
       			    kraj++;
       			}
       			
                if (*kraj != '\0') {                        
                    dodatni_razmak = 0              
                    if (*(t + 1) != ' ')
                        dodatni_razmak = 1;
           			kraj = t;
           			while (*kraj != '\0') kraj++;
           			duzina = duzina_broja(broj) + dodatni_razmak;
           			while (kraj > t) {
           			    *(kraj+duzina) = *kraj;
           			    kraj--;
           			}
           			t++;
           			upis_broja(t, broj);
           			t += duzina - dodatni_razmak;
           			if (dodatni_razmak == 1)
           			    *t = ' ';
                }
            }
        }
        else
           rijec = 1;
        t++;
    }

    return tekst;
}

int main() {
	char tekst[100];
	printf("Unesite tekst: ");
    unesi(tekst, 100);
	printf("Nakon zamjene: %s", ubaci_broj(tekst, -123));

	return 0;
}
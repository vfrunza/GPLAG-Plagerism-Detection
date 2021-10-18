#include <stdio.h>
#include <string.h>

// funkcija u kojoj osiguravamo da znak koji posmatramo nije razmak

int JeLiSlovo (char znak)
{
	return znak != ' ';
	//return ((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z'));
}
// potrebna duzina broja da znamo za koliko treba prosiriti nas string

int dajDuzinuBroja(int x) {
	int brojCifara = 0;
	while (x) {
		brojCifara++;
		x /= 10;
	}
	return brojCifara;
}

char* ubaci_broj (char* tekst, int broj)
{
	char * p = tekst;
	char * q = tekst;
	char *kraj = tekst;

	int minus = 0, brojac = 0;
	// koristit cemo apsolutnu vrijednost broja, a na kraju vracati minus, ako je to potrebno
	if (broj < 0) {
		minus = 1;
		broj = - broj;

	} else minus = 0;
	int duzinaRijeci = 0;

	while ( *p != '\0') {
		//printf("%c", *p);
		if (JeLiSlovo (*p)) {
			duzinaRijeci++;
		}
		// za slucaj da ima razmaka nakon zadnjeg slova stringa, prije \0
		else {
			int nasaoZnak = 0;
			char *pomocni = p;
		
			while (*pomocni != '\0') {
				if (JeLiSlovo(*pomocni)) {
					nasaoZnak = 1;
					break;
				}
				pomocni++;
			}
			if (duzinaRijeci > 0 && nasaoZnak) {
				brojac ++;
				if (*p != '\0'){ 
					kraj = p;
					while (*kraj != '\0') kraj ++;
					int duzinaBroja = dajDuzinuBroja(broj);
				
					if (minus) duzinaBroja++;
					p++;
					int tacno = 0;
				
					if (*p != ' ') {duzinaBroja++; tacno = 1;}
					// algoritam sirenja stringa
					while (kraj >= p) {
						*(kraj + duzinaBroja) = *kraj;
						kraj--;
					}
					
				// direktno uvrstavanje broja u string 
					int tmp = broj;
					int tmp2 = 0;
					int vodecaNula = (tmp % 10) == 0;
				
					while (tmp) {
						tmp2 = tmp2 * 10 + ( tmp % 10 );
						tmp /= 10;
					}
					// ako je negativan broj, vracamo minus koji smo uklonili na pocetku
					if (minus) *p++ = '-';
					while (tmp2) {
						*p++ = (tmp2 % 10) + '0';
						tmp2 /= 10;
					}
					// pri upisivanju broja, ako je zadnja cifra 0, pri upisivanju je to prva cifra, jer se upisuje "unatrag" 
					//zbog karakteristike dijeljenja broja na cifre, ako je prva nula, moramo je zapisati
					if (vodecaNula) *p++ = '0';
					
					if (tacno) *p = ' ';
					p--; 
					duzinaRijeci = 0; 
				}
			}
		}

		p++;
	}
	return q;
}






int main()
{
	printf("blabla");
	char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
printf("\"%s\"", ubaci_broj(s, 320));
	
}

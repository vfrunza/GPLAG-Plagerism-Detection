#include <stdio.h>
#include <math.h>

int vel_broja (int n)
{
	int br=0;
	n = fabs(n);
	while (n!=0) {
		n = n / 10;
		br++;
	}
	return br;
}

char* ubaci_broj (char* tekst, int broj)
{
	char *pok = tekst;
	char *kraj = tekst;
	int cifra=0, k=0, vel=0, n=broj; 
	
	while (*tekst == ' ') tekst++;
	
	while (*tekst!='\0') {
		
		if (*tekst==' ' && *(tekst+1)!=' ' && *(tekst+1)!='\0') {
			kraj = tekst;
			while (*kraj!='\0') kraj++;
			while (kraj > tekst) {
				if (broj>0)			*(kraj + vel_broja(broj) + 1) = *kraj;
				else				*(kraj + vel_broja(broj) + 2) = *kraj;
				kraj--;
			}
			
			k = vel_broja(broj);
			vel = k;
			n = broj;
				
			if (n<0) {
				n = fabs(broj);
				*(tekst+1) = '-';
				k++;
				vel = k + 1;
			}
			
			while (n!=0) {
				cifra = n % 10;					
				*(tekst+k) = '0' + cifra;
				n = n / 10;
				k--;
			}
			if (broj>0)				*(tekst + vel + 1) = ' ';
			else					*(tekst + vel) = ' ';
			
			tekst = tekst + vel + 2;
		}
		
		tekst++;
		
	}

	return pok;
}

int main()
{
	return 0;
}
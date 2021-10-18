#include <stdio.h>
//Provjerava da li je karakter slovo
int slovo(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
int provjeri_duzine(const char *s, int *niz, int dim)
{
	int i = 0, br = 0;
	s--;
	while (*++s)
		if (slovo(*s)) {
			br = 0;
			//Brojac slova u rijeci
			while (*s && slovo(*s++))
				br++;
			s--;
			//Ako niz ima vise elemenata nego recenica rijeci, ili element niza ne predstavlja duzinu rijeci, vraca 0
			if (i >= dim || niz[i++] != br)
				return 0;
		}
	//Vraca 1 ako je duzina niza jednaka broju rijeci
	return i == dim;
}

int main()
{
	return 0;
}
#include <stdio.h>

int slovo(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
//Pretvara malo slovo u veliko
char v(char c)
{
	if (c >= 'a' && c <= 'z')
		return c + 'A' - 'a';
	return c;
}
//Provjerava da li se char pojavljuje ranije u stringu
int ponavlja(char c, char *a, char *b)
{
	while (a < b)
		if (v(*a++) == v(c))
			return 1;
	return 0;
}
void najduzi_bp(char *s1, char *s2)
{
	int max_duz = 0, duz;
	char *najduzi = s1, *p;
	while (*s1) {
		if (slovo(*s1)) {
			p = s1;
			duz = 0;
			//Ako se slovo ne ponavlja, povecati duzinu
			while (slovo(*p) && !ponavlja(*p, s1, p)) {
				duz++;
				p++;
			}
			if (duz > max_duz) {
				max_duz = duz;
				najduzi = s1;
			}
		}
		s1++;
	}
	p = najduzi;
	//Pohranjivanje najduzeg podstringa u s2
	while (p - najduzi < max_duz)
		*s2++ = *p++;
	*s2 = 0;
}

int main()
{
	return 0;
}
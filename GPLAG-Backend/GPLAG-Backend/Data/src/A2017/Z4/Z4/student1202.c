#include <stdio.h>

typedef struct {
	const char* poc, *kraj;
	int vel;
} Tag;

int cheq(char c1, char c2)
{
	c1 = c1 >= 'A' && c1 <= 'Z' ? c1 + 'a' - 'A' : c1;
	c2 = c2 >= 'A' && c2 <= 'Z' ? c2 + 'a' - 'A' : c2;
	return c1 == c2;
}

int isti(Tag t1, Tag t2)
{
	const char *s1 = t1.poc, *s2 = t2.poc;
	int i = 0;
	while(i < t1.vel && i < t2.vel) {
		if (!cheq(s1[i], s2[i])) return 0;
		i++;
	}
	return t1.vel == t2.vel;
}
//Provjerava da li je otvarajuci tag ispravan
Tag *otv(const char *s, Tag *t)
{
	const char *p = s;
	int br = 0, kraj = 0;
	if (*(t->poc = s+1) == ' ') return 0;
	while (*++p)
		if (*p == '<') return 0;
		else if (*p == ' ') kraj = 1;
		else if (*p == '>' && br) {
			t->vel = br;
			t->kraj = p;
			return t;
		} else if (!kraj) br++;
	return 0;
}
//Provjerava da li je zatvarajuci tag ispravan
Tag *zatv(const char *s, Tag *t)
{
	const char *p = s+1;
	int br = 0, kraj = 0;
	if (*(t->poc = s+2) == ' ') return 0;
	while (*++p)
		if (*p == '<') return 0;
		else if (*p == ' ') kraj = 1;
		else if (*p == '>' && br) {
			t->vel = br;
			t->kraj = p;
			return t;
		} else if (!kraj) br++;
	return 0;
}

int provjeri(const char* s)
{
	const char *p = s, *q;
	Tag a, b;
	int br_otv = 0, br_istih_otv, br_istih_zatv, br_istih_zatv_iza, l = 0;
	while (*p) {
		if (*p == '>' && !l) return 0;
		if (*p == '<' && *(p+1) != '/') { //Pronadjen otvoren tag
			if (!otv(p, &a)) return 0;
			l = 1;
			q = s;
			br_istih_otv = br_istih_zatv = br_otv = br_istih_zatv_iza = 0;
			while (*q) {
				//Pronadjen otvarajuci tag
				if (*q == '<' && *(q+1) != '/') {
					if (!otv(q, &b)) return 0; //Nepravilno otvoren
					else if (isti(a, b))
						br_istih_otv++;
					if (q > a.kraj) //Brojac otvorenih podtagova
						br_otv++;
				} else if (*q == '<' && *(q+1) == '/') { //Pronadjen zatvarajuci tag
					if (!zatv(q, &b)) return 0; //Nepravilno zatvoren
					else if (isti(a, b)) {
						br_istih_zatv++;
						if (q > a.kraj) br_istih_zatv_iza++;
					}
					if (q > a.kraj && !br_otv && !br_istih_zatv && !isti(a, b)) //Zatvoren neki drugi tag prije ovog
						return 0;
				}
				q++;
			}
			if (br_istih_zatv != br_istih_otv || !br_istih_zatv_iza) return 0; //Razlicit broj otvorenih i zatvorenih tagova istog imena ili ne postoji zatvarajuci tag koji odgovara ovome tagu
		} else if (*p == '<' && *(p+1) == '/') {
			l = 1;
			if (!zatv(p, &a)) return 0; //Nepravilno zatvoren
			q = s;
			br_istih_otv = br_istih_zatv = 0;
			while (*q) {
				//Ne postoji odgovarajuci tag koji otvara ovaj element
				if (q > a.poc && !br_istih_otv) return 0;
				if (*q == '<' && *(q+1) != '/') { //Pronadjen otvarajuci tag
					if (!otv(q, &b)) return 0; //Nepravilno otvoren
					else if (isti(a, b))
						br_istih_otv++;
				} else if (*q == '<' && *(q+1) == '/') {
					if (!zatv(q, &b)) return 0; //Nepravilno zatvoren
					else if (isti(a, b))
						br_istih_zatv++;
				}
				q++;
			}
			if (br_istih_zatv != br_istih_otv) return 0;//Razlicit broj otvorenih i zatvorenih tagova istog imena
		}
		p++;
	}
	return 1;
}

int main()
{
	return 0;
}
#include <stdio.h>
#include <math.h>
#include <string.h>

#define eps 0.0001

int duzina(char *s) {
	int i = 0;
	while (*s != '\0') {
		s++;
		i++;
	}
	return i;
}
void moj_memset(int p[]) {
	int i;
	for (i = 0; i < 10000;i++) p[i] = 0;
}
int manji_od(float a, float b) {
	return (a - b <= eps && fabs(a - b) >= eps);
}

int u_pravougaoniku(float X, float Y, float x1, float y1, float x2, float y2) {
	return (X >= x1 && X <= x2 && Y >= y1 && Y <= y2);
}
int validan_znak(char c) {
	if (c >= '0' && c <= '9') return 1;
	if (c == '(' || c == ')' || c == '.' || c == ',' || c == '-') return 1;
	return 0;
}
char *obuhvat(char *s, float x1, float y1, float x2, float y2) {
	char *p = s;
	if (duzina(s) == 0) return s;
	int duzine[10000];
	int ukljucen[10000];
	int N = 0;
	moj_memset(duzine); moj_memset(ukljucen);
	int zagrade, zarezi;
	
	zagrade = 0;
	zarezi = 0;
	while (*p != '\0') {
		if (!validan_znak(*p)) return 0;
		if (*p == '(') zagrade++;
		if (zagrade > 0 && *p == ',') zarezi++;
		if (*p == ')') zagrade--;
		if (zagrade == 0) {
			if (zarezi > 1) return 0;
			zarezi = 0;
		}
		p++;
	}
	if (zagrade != 0) return 0;
	p = s;
	while (*p != '\0') {
		p++;
		int prvi_broj = 1;
		int decimale_prvog, decimale_drugog;
		int minus_prvog, minus_drugog;
		int brojim1, brojim2;
		int duzina_brojeva;
		float xCurr, yCurr;
		
		duzina_brojeva = 0;
		brojim1 = brojim2 = 0;
		minus_prvog = minus_drugog = 0;
		decimale_drugog = decimale_prvog = 0;
		xCurr = yCurr = 0;
		
		while (*p != ')') {
			duzina_brojeva++;
			if (*p == ',') {
				prvi_broj = 0;
				p++;
				continue;
			}
			if (prvi_broj) {
				if (*p == '-') {
					minus_prvog = 1;
					p++;
					continue;
				}
				if (*p == '.') {
					brojim1 = 1;
					p++;
					continue;
				}
				if (brojim1) decimale_prvog++;
				
				if (*p >= '0' && *p <= '9')
					xCurr = xCurr * 10 + (*p - '0');
			}
			else if (!prvi_broj) {
				if (*p == '-') {
					minus_drugog = 1;
					p++;
					continue;
				}
				if (*p == '.') {
					brojim2 = 1;
					p++;
					continue;
				}
				if (brojim2) decimale_drugog++;
				
				if (*p >= '0' && *p <= '9')
					yCurr = yCurr * 10 + (*p - '0');
			}
			p++;
		}
		//printf(" P mi je %c\n", *p);
		if (minus_prvog) xCurr = -xCurr;
		if (minus_drugog) yCurr = -yCurr;
		
		xCurr /= pow(10, decimale_prvog);
		yCurr /= pow(10, decimale_drugog);

		duzine[N] = duzina_brojeva + 2;

		if (!u_pravougaoniku(xCurr, yCurr, x1, y1, x2, y2)) {
			ukljucen[N] = 0;
			//printf("nije\n");
		}
		else {
			ukljucen[N] = 1;
			//printf("Jeste\n");
		}
		N++;
		if (p + 2 > s + duzina(s)) break;
		p+=2;
	}
	
	int i, j;
	p = s;
	for (i = 0; i < N; i++) {
		if (i == N - 1 && !ukljucen[i]) {
			*p = '\0';
			break;
		}
		if (ukljucen[i]) p += duzine[i];
		else {
			char *x = p;
			p += duzine[i];
			char *y = p + 1;
			while (*y != '\0') {
				//printf("%c postaje %c\n", *x, *y);
				*x = *y;
				x++;
				y++;
			}
			*x = '\0';
			//printf ("KRAJ ITERACIJE\n\n");	
			//break;
			p -= duzine[i];
		}
	}
	p = s;
	if (duzina(p) <= 5) p = '\0';
	return s;
}
int main() {
	char s[] = "(100,-100),(50,50),(70,20),(-1,-1)";
	char pom[100];

	strcpy(pom,s);
	obuhvat(pom, 1, -100, 100, 50);
	printf("%s", pom);
	return 0;
}

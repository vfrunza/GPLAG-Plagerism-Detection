#include <stdio.h>

#define eps 0.0001

int da_li_je_broj(int broj) {
	return broj >= '0' && broj <= '9';
}

char* obuhvat (char* koordinate, double x1, double y1, double x2, double y2) {
	char* pom = koordinate, *pocetak, *kraj; 
	double x, y, predznakX, predznakY, decimala;
	int f;
	while (*koordinate != 0) {
		if (*koordinate == '(') {
			x = y = decimala = 0;
			predznakX = predznakY = 1;
			f = 10;
			
			koordinate++;
			if (*koordinate == '.' || *koordinate == ',' || *koordinate == '(') 
				return NULL;
			if (*koordinate == '-') {
				predznakX = -1;
				koordinate++;
			}
			while (da_li_je_broj(*koordinate)) {
				x *= 10;
				x += *koordinate - 48;
				koordinate++;
			}
			if (*koordinate == '.') {
				koordinate++;
				while (da_li_je_broj(*koordinate)) {
					decimala += (double)(*koordinate - 48)/f;
					f *= 10;
					koordinate++;
				}
			} else if (*koordinate != ',') return NULL;
			x += decimala;
			x *= predznakX;
			f = 10;
			decimala = 0;
			if (*koordinate == ',') { 
				koordinate++;
				if (*koordinate == '.' || *koordinate == ')') 
					return NULL; 
				if (*koordinate == '-') {
					predznakY = -1;
					koordinate++;
				}
				while (da_li_je_broj(*koordinate)) {
					y *= 10;
					y += *koordinate - 48;
					koordinate++;
				}
				if (*koordinate == '.') {
					koordinate++;
					while (da_li_je_broj(*koordinate)) {
						decimala += (double)(*koordinate - 48)/f;
						f /= 10;
						koordinate++;
					}
				}
				if (*koordinate != ')') 
					return NULL;
				y += decimala;
				y *= predznakY;
				koordinate++;
				if (*koordinate == ')' || (*koordinate == ',' && *(koordinate + 1) != '('))
					return NULL; 
			} else return NULL;
			if ((x < x1 || x > x2 || y < y1 || y > y2)) { 
				if (*koordinate == 0) {
					koordinate--;
					while (*(koordinate+1) != '(' && koordinate != pom)
						koordinate--;
					*koordinate = 0;
				} else {
					kraj = koordinate + 2;
					while (*(koordinate-1) != '(') 
						koordinate--;
					pocetak = koordinate;
					if (koordinate-1 == pom)
						koordinate--;
					else
						koordinate-=2;
					while (*kraj != '\0') {
						*pocetak = *kraj;
						pocetak++;
						kraj++;
					}
					*pocetak = 0;
				}
			}
		}
		else return NULL;
		if (koordinate != pom && *koordinate != 0) {
			koordinate++;
		}
	}
	return pom;
}

int main() {
	char koordinate[1000] =  "(1.1,5.5),(1.2,5.5),(1.3,5.5),(1.4,5.5),(1.5,5.5)";
	printf("%s\n", obuhvat(koordinate, 1.2, 5.499, 1.4, 5.501));
	
	return 0;
}

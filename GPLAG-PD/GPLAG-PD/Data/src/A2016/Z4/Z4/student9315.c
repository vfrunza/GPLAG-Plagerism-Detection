#include <stdio.h>
#define E 0.0001

char *obuhvat(char *niz, float x1, float y1, float x2, float y2);
void shrink(int x, char *tekst);
int scanCoord(char *coord, float par[2], char start, char kraj);
int xNaY(int x, int y);
int pripadaPravoug(float par[2], float x1, float y1, float x2, float y2);
int manjeIlJed(float x, float y);
int veceIlJed(float x, float y);

int xNaY(int x, int y){
	//mat funkcija x na y
	int i, ret = x;
	for(i = 1; i < y; i++){
		ret *= x;
	}
	return ret;
}

int jeBroj(char x){
	//vraca 1 ako je x broj
	if(x >= '0' && x <= '9')
	return 1;
	return 0;
}
int scanCoord(char *coord, float par[2], char start, char kraj){
//popuni proslijedjeni uredjeni par(niz); vraca duzinu ako je string bio ispravno formatiran, 0 ako ne
//kad bude pozvana cita x koordinatu, pa onda sama sebe poziva da ocita y koordinatu, mijenja start i kraj
	int tacka = 0;//kad dodjemo do . posmatramo dec dio u while coord petlji
	float cioDio = 0, decDio = 0;
	int decMjesta = 0;
	int rekurz = 0; //da li je funk pozvala samu sebe da odredi y koord
	int len = 0;//duzina od start do kraj
	int lenRekurz = 0;//duzina dijela za drugu koord
	int sgn = 1;
	int imaCioDio = 0;
	
	if(kraj == ')')
		rekurz = 1;
	if(*coord++ != start)
		return 0;
	len++;	
	if(*coord == '-'){
		sgn = -1;
		coord++;
		len++;
	}
	
	while(*coord != kraj){
		if(*coord == '.' && tacka == 0){
			if(!imaCioDio)
				return 0;
			tacka = 1;
			coord++;
			len++;
			continue;
		}
		
		if(!tacka){
			if(!jeBroj(*coord)){
				return 0;	
			}
			cioDio = cioDio * 10 + (*coord - '0');
			imaCioDio = 1;
		}
		else if(tacka){
			if(!jeBroj(*coord)){
				return 0;
			}
			decDio = decDio * 10 + (*coord - '0');
			decMjesta++;
		}
		coord++;
		len++;
	}
	if(decMjesta != 0){
		decDio = decDio / xNaY(10, decMjesta);
	}
	
	par[rekurz] = (cioDio + decDio) * sgn;
	if(!rekurz){
		lenRekurz = scanCoord(coord, par, ',', ')');
		if(lenRekurz && (len > 1))
			return len + lenRekurz + 1;// 1 zbog zadnje zagrade )
		else
			return 0;
	}
	if(len > 1)
		return len;
	else
		return 0;
}
int veceIlJed(float x, float y){
	//vraca 1 ako je x vece ili jednako od y, tolerancija E
	float razlika = x - y;
	if (razlika < 0)
	razlika = - razlika;
	if(razlika < E || x > y)
	return 1;
	return 0;
}
int manjeIlJed(float x, float y){
	//vraca 1 ako je x manje  ili jednako od y, tolerancija E
	float razlika = x - y;
	if (razlika < 0)
	razlika = - razlika;
	if(razlika < E || x < y)
	return 1;
	return 0;
}
int pripadaPravoug(float par[2], float x1, float y1, float x2, float y2){
	float x = par[0];
	float y = par[1];
	if(veceIlJed(x,x1) && veceIlJed(y, y1) && manjeIlJed(y, y2) && manjeIlJed(x,x2))
	return 1;
	return 0;
}

char *obuhvat(char *niz, float x1, float y1, float x2, float y2){
	char *ret = niz;
	char *pok = niz;
	int trenutniBrojKoord = 0;
	int obrisan = 0; //da li smo uklonili neke koordinate
	int brojKoord = 0;
	int zarez = 1; //da li ima zarez izmedju koord
	int pomjeraj;//za koliko se pomjeramo nakon skeniranja koordinata
	float par[2];//prvi x, drugi y
	
	while(*pok != '\0'){
		if(*pok == '(')
		brojKoord++;
		pok++;
	}
	pok = ret;
	
	while(*pok != '\0'){
		
		if(zarez){
			trenutniBrojKoord++;
			pomjeraj = scanCoord(pok, par, '(', ',');
			if(!pomjeraj){
				return NULL;
			}
			else if(pripadaPravoug(par, x1, y1, x2, y2)){
				pok += pomjeraj;
			}
			else if(!pripadaPravoug(par, x1, y1, x2, y2)){
				shrink(-pomjeraj, pok);	
				obrisan = 1;
			}
			zarez = 0;
		}
		else if(*pok == ','){
			if(*(pok + 1) == '\0'){
				return NULL;//ako je zarez na kraju 
			}
			zarez = 1;
			if(obrisan){
				if(trenutniBrojKoord >= 1){
					shrink(-1, pok);
				}
				obrisan = 0;
			}
			else
			pok++;
		}
		else{
			return NULL;
		}
	}
	if(obrisan){
		pok--;
		shrink(-1, pok);
	}
	return ret;
}

void shrink(int x, char *tekst){
	//brise/suzava niz za zadano x
	char *temp;
	//suzava
		if(x < 0){
		x = -x;
		while(x--){
			temp = tekst;
			while(*tekst != '\0'){
				*tekst = *(tekst + 1);
				tekst++;
			}
			tekst = temp;
		}
	}
	
}
int main() {
	return 0;
}
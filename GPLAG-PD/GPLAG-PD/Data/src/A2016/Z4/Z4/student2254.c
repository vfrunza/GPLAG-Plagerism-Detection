#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int abs(float x);
int br_el_rijeci(char *s);
char *obuhvat(char *s, float x1, float y1, float x2, float y2);

int main() {
	char s[] = "(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)";
	char *rez = obuhvat(s, -3, -3, 3, 3);
	printf("'%s'", rez);
	return 0;
}

int br_el_rijeci(char *s){
    int broj = 1;
    while (*s != ')' && *s != 0) {
        broj++;
        s++;
    }
    return broj;
}

int abs(float x){
	if(x < 0)
		x *= -1;
	
	return x;
}


char *obuhvat(char *s, float x1, float y1, float x2, float y2){
	char *p = s, *q = s, *z = s;
	float x_koord[1000] = {0}, y_koord[1000] = {0};
	int i = 0, kraj_niza, jenegativan, br_el_stringa, j = 1, k, brojac = 0, nijebilo = 1, br_zagrada1 = 0, br_zagrada2 = 0, br_zareza = 0;
	
	
	if (*p == 0)
		return s;
	
	while(*p != 0){
		
		
		if(*p == '(')
			br_zagrada1++;
			
		else if(*p == ')')
			br_zagrada2++;
		else if(*p == ',')
			br_zareza++;
			
		j++;
		p++;
			
		}		//saznajemo broj elemenata stringa
	
	if(br_zagrada1 - br_zagrada2 != 0) // ako je ispravan zapis mora biti isti broj i otvorenih i zatvorenih zagrada
		return *s = 0;
	if(br_zareza != br_zagrada1 + br_zagrada1-1) 
		return *s = 0;
		
	p = s;
		

		while(*p != 0){
			
			jenegativan = 0;
			nijebilo = 1;
			br_zareza = 0;
			brojac = 0;
			
		while(*p != '('){ //preskačemo do prve zagrade (kada je završen rad sa prvim koordinatama)
			
				if(*p != ',' && *p != '(') //ako prilikom preskakanja naiđemo na nešto što nije zagrada ili zarez nije pravilan format
					return s[0] = 0;
				p++;
			}
			
			p++; //prelazimo na broj

			if(!(*p >= '0' && *p <= '9') && *p != '-') return *s = 0; //ako nije broj/minus onda nije pravilan format
			
	
			while(*p != ','){
				

				if(!(*p >= '0' && *p <= '9') && *p != '-' && *p != '.' || *p == ')'){ // ako naiđe na nesto sto nije broj/minus ili ako nema zareza u zagradi niej tačan fromat
					return *s = 0;
				}
			
				
				if(*p == '-'){
					jenegativan = 1;
					p++;
				}
				
				if(nijebilo) //osigurava da se samo jednom broji broj cifara
					k = -1;
	
				q = p;
				
				while(*q != ',' && nijebilo == 1){
					q++;
					
					if(*q != '.')
						k++;
				}
				
				
				
				if(*p == '.'){
					p++;
					z = p;
				
					while(*z != ','){ //tražimo koliko decimala ima broj
						z++;
						brojac++;
					}

				}
				nijebilo = 0;
				

				
				x_koord[i] += (*p - '0')*(pow(10,k));	//pretvaramo x koordinatu u broj
	
				
				if(*p != ',')	//Da ne preskače zarez kada nakon prvog broja ima samo jedna tačka
					p++;
				k--;

				
			}
			x_koord[i] /= pow(10,brojac); // ako je decimalan broj

			if(jenegativan)
				x_koord[i] = -x_koord[i];

			
			jenegativan = 0;
			brojac = 0; //vraćamo na 0 da možemo brojati decimale drugog broja
			nijebilo = 1;
			
			p++; //prelazimo na sljedeći broj
			
			if(!(*p >= '0' && *p <= '9') && *p != '-'){ // u slučaju da nije broj/minus prvo šta nailazimo nakon zareza
				return s[0] = 0;
			}
				

			
			while(*p != ')'){
				
				if(!(*p >= '0' && *p <= '9') && *p != '-' && *p != '.' ){ // ako naiđe na nesto sto nije broj/minus
					return s[0] = 0;
				}
	
				if(*p == '-'){
					
					jenegativan = 1;
					p++;
					
					if(!(*p >= '0' && *p <= '9')){    // ako poslije minusa nije broj
						*s = 0;
						return s[0];
					}
					
				}
				
				
				if(nijebilo)
					k = -1;
				
				q = p;
				
				while(*q != ')'){
					
					q++;
					
					if(*q != '.')
						k++;
				}
				
				if(*p == '.'){
					p++;
					z = p;
				
					while(*z != ')'){ //tražimo koliko decimala ima broj
						z++;
						brojac++;
					}
					
				
				}
				
			
				y_koord[i] += (*p - '0')*pow(10,k); // pretvaramo y koordinatu u broj
				
				
				p++;
				k--;
	
				
			}
			
			y_koord[i] /= pow(10,brojac);
			
			if(jenegativan)
				y_koord[i] = -1.*y_koord[i];
				
			i++;
			p++;
				
		}
		

		
		kraj_niza = i;
		p = s;
		
		for(i = 0; i < kraj_niza; i++){
			q = p;
	
			if((x1 < x2 || abs(x1 - x2) < EPSILON) && (y1 < y2 || abs(y1 -y2) < EPSILON)){
				if(((x_koord[i] > x1 || (abs(x_koord[i] - x1) < EPSILON)) && ((x_koord[i] < x2) || (abs(x_koord[i] - x2) < EPSILON))) && ((y_koord[i] > y1 || (abs(y_koord[i] - y1) < EPSILON)) &&(y_koord[i] < y2 || (abs(y_koord[i] - y2) < EPSILON))))
				{
					while(*p != ')')
						p++;
						p += 2; //prelazimo na drugu zagradu (ako pređe u neinicijalzovanu vrijednost ionako ga nigdje ne dereferencujemo pa nema problema)
				}
						
					else{
						br_el_stringa = br_el_rijeci(p); //nalazimo koliko elemanata treba izbaciti
						
						if (kraj_niza == 1){
							*q = 0;
							return s;
						}

						while(q < s + j)
							*q++ = *(q+br_el_stringa); 

						j -= br_el_stringa;
							
					}
			}
			
			else{
				*s = 0;
				return s[0];
			}

		}
		
	if(p != s && *(p-1) != ')')
		*(p-1) = 0;

		return s;
}
		
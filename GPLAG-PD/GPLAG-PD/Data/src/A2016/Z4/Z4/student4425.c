#include <stdio.h>
#include <math.h>
#define EPS 0.0001

struct Tacka {
	int x_main;
	int y_main;
	int x_dec;
	int y_dec;
	int neg;
	float x;
	float y;
};

int stepenuj (int counter) {
	int vrati;
	if (counter == 0) vrati = 0;
	else if (counter == 1) vrati = 1;
	else if (counter != 1) vrati = pow (10, counter-1);
	return vrati;
}

int IsInside (float x, float y, float x1, float y1, float x2, float y2) {
	int flag = 0;
	if (x >= x1 - EPS && x <= x2 + EPS && y >= y1 - EPS && y <= y2 + EPS) flag = 1;
	return flag;
}

char* obuhvat (char* string, float x1, float y1, float x2, float y2) {
	char* vrati = string, *pocetak, *kraj, *pocetak_y;
	struct Tacka tacka;	
	int counter, counter_main, counter_dec, IsDec, stepen1, stepen2, power, pripada_li, count=0;
	
	if (*string == '\0') return vrati;

	while (*string != '\0') {
		if (*string != '.' && *string != ',' && *string != '-' && *string != ')' && *string != '(' && !(*string >= '0' && *string <= '9' )) return NULL;
		string++;
		count++;
	}
	
	if(*(string-1)!=')') return NULL;
	string = vrati;
	
	while (*string != '\0') {
		if (*string != '(') return NULL;
		pocetak = string; 
		counter = 1;
		while (*string != ')' && *string!='\0'){ 
			counter++;
			string++;
		}
		if(*string=='\0') return NULL;
		string = pocetak;
		kraj = string + counter +1;
		string++; 


		/*  KOORDINATA X */
		if (*string == '-') tacka.neg = 1; 
		else tacka.neg = 0; 
		if(*string != '-' && !(*string >= '0' && *string <= '9' )) return NULL;
		string = pocetak;

		
		counter_main = 0; IsDec = 0; counter_dec = 0;
		while (*string != ',' && *string!='\0') {
			if (*string == '.'){
				if(*(string-1)=='(')
					return NULL;
				IsDec = 1;
			}
			if(*string == '\0') return NULL;
			string++;
		}
		string++;
		if(!(*string >= '0' && *string <= '9') && *string!='-')return NULL;
		string = pocetak;
		string++;
		
		if (IsDec == 0) {
			while (*string != ',') {
				if(*string=='-'){
					tacka.neg=1;
					string++;
					if(*string=='-')
						return NULL;
					continue;
				}
				if (*string >= '0' && *string <= '9') counter_main++;
				else 
					return NULL;
				string++;
			}
		} 
		else if (IsDec == 1) {
			while (*string != '.') {
				if(*string=='-'){
					tacka.neg=1;
					string++;
					if(*string=='-')
						return NULL;
					continue;
				}
				if (*string >= '0' && *string <= '9') counter_main++;
				else return NULL; 
				string++;
			}
			string++; 
			while (*string != ',') {
				if (*string >= '0' && *string <= '9') counter_dec++;
				else return NULL; 
				string++;
			}
		}
		string = pocetak;
		
		stepen1 = stepenuj(counter_main);
		stepen2 = pow(10, counter_dec); 
		power = stepen2;
		stepen2 = stepenuj(counter_dec);
		tacka.x_main = 0; tacka.x_dec = 0;
		if (IsDec == 0) {
			while (*string != ',') { 
				if (*string >= '0' && *string <= '9') {
					tacka.x_main += stepen1 * ((int)(*string)-'0');
					stepen1/=10;
				}
				string++;
			}
			if (tacka.neg == 0) tacka.x = tacka.x_main;
			else if (tacka.neg == 1) tacka.x = - tacka.x_main;
		}
		else if (IsDec == 1) {
			while (*string != '.') {
				if (*string >= '0' && *string <= '9') {
					tacka.x_main += stepen1 * ((int)(*string)-'0');
					stepen1/=10;
				}
				string++;
			}
			string++; 
			while (*string != ',') {
				if (*string >= '0' && *string <= '9') {
					tacka.x_dec += stepen2 * ((int)(*string)-'0');
					stepen2/=10;
				}
				string++;
			}
			tacka.x = tacka.x_main + 1.0*tacka.x_dec/power; 
			if (tacka.neg == 1) tacka.x = - tacka.x;
		}
		
		/* KOORDINATA Y */
		
		
		string++;
		pocetak_y = string;
		if (*string == '-') tacka.neg = 1;  
		else tacka.neg = 0; 
		if(*string != '-' && !(*string >= '0' && *string <= '9' )) return NULL;

		counter_main = 0; IsDec = 0; counter_dec = 0;
		while (*string != ')' && *string !='\0') {
			if (*string == '.'){
				if(*(string-1)==',')
					return NULL;
				IsDec = 1;
			}
			if(*string=='\0')
				return NULL;
			string++;
		} 
		string = pocetak_y;

		if (IsDec == 0) {
			while (*string != ')') {
				if(*string=='-'){
					tacka.neg=1;
					string++;
					if(*string=='-')
						return NULL;
					continue;
				}
				if (*string >= '0' && *string <= '9') counter_main++;
				else 
					return NULL;
				string++;
			}
		}
			
		else if (IsDec == 1) {
			while (*string != '.') {
				if(*string=='-'){
					string++;
					if(*string=='-')
						return NULL;
					continue;
				}
				if (*string >= '0' && *string <= '9') counter_main++;
				else return NULL; 
				string++;
			}
			string++; 
			while (*string != ')') {
				if (*string >= '0' && *string <= '9') counter_dec++;
				else return NULL; 
				string++;
			}
		}
		string = pocetak_y;
		
		stepen1 = stepenuj(counter_main); 
		stepen2 = pow(10, counter_dec); 
		power = stepen2;
		stepen2 = stepenuj(counter_dec);
		tacka.y_main = 0; tacka.y_dec = 0;
		if (IsDec == 0) {
			while (*string != ')') {
				if (*string >= '0' && *string <= '9') {
					tacka.y_main += stepen1 * ((int)(*string)-'0');
					stepen1/=10;
				}
				string++;
			}
			if (tacka.neg == 0) tacka.y = tacka.y_main;
			else if (tacka.neg == 1) tacka.y = - tacka.y_main;
		}
		else if (IsDec == 1) {
			while (*string != '.') {
				if (*string >= '0' && *string <= '9') {
					tacka.y_main += stepen1 * ((int)(*string)-'0');
					stepen1/=10;
				}
				string++;
			}
			string++; 
			while (*string != ')') {
				if (*string >= '0' && *string <= '9') {
					tacka.y_dec += stepen2 * ((int)(*string)-'0');
					stepen2/=10;
				}
				string++;
			}
			tacka.y = tacka.y_main + 1.0*tacka.y_dec/power;
			if (tacka.neg == 1) tacka.y = - tacka.y;
		}

		
		pripada_li = IsInside (tacka.x, tacka.y, x1, y1, x2, y2);
		kraj=string+1;
		if(*kraj==',')
			kraj++;

		if (pripada_li == 0) {
			string=pocetak;
			while (*string != '\0') {
				if(*(string+counter)=='\0'){
					*string='\0';
					string--;}
				else
					*string = *(string+counter+1);
				string++;
			}
			string=pocetak;
		}
		else
		string = kraj;
		if(*string=='\0' && *(string-1)==',')
			*(string-1)='\0';
		else if(*string==',' && ((*(string-1)>='0' && *(string-1)<='9') || *(string-1)=='.'))
			string++;
	}
	
	return vrati;
}

int main() {
	return 0;
}
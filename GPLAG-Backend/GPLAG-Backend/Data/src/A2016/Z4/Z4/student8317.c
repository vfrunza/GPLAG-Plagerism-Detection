#include <stdio.h>
#define eps 0.0001

/*funkcija koja vraća broj ponavljanja određenog znaka u stringu*/
int prebroji (char* s, char znak) {
	
	int broj=0;
	while (*s != '\0'){
		
		if (*s == znak){
			broj++;
		}
		s++;
	}
	return broj;
}

/*funkcija koja vraća dužinu stringa*/
int duzina_stringa (char* s){
	
	int duzina=0;
	while (*s != '\0'){
		duzina++;
		s++;
	}
	return duzina;
}

/*funkcija koja provjerava ispravnost stringa*/
int ispravan_string(char* s){
	
	char *a=s;
	
	/*provjerava da li je svaki karakter unutar stringa validan*/
	while (*a != '\0'){
		
		if (*a != '(' && *a != ')' && *a != '.' && *a != ',' && !(*a>='0' && *a<='9') && *a != '-'){
			return 0;
		}
		a++;
	}
	
	/*provjerava da li je validan prvi i zadnji karakter u stringu*/
	if (s[0] != '('){
		return 0;
	}
	
	if (s[duzina_stringa(s)-1] != ')'){
		return 0;
	}
	
	/*provjerava da li je jednak broj otvorenih i zatvorenih zagrada*/
	if(prebroji(s,'(') != prebroji(s, ')')){
		return 0;
	}
	
	/*provjerava ima li dvije otvorene zagrade zaredom*/
	a=s;
	while (*a != '\0'){
		if (*a == '('){
			a++;
			while (*a != ')' && *a != '\0'){
				if (*a == '('){
					return 0;
				}
				a++;
				
			}
		}
		if (*a != '\0'){
			a++;
		}
	}
	
	
	/*provjerava broj zareza, ukoliko ima regularan broj zagrada, i ukoliko
	su regularno zatvorene i otvorene, broj zareza treba da bude 2*broj ili otvorenih
	ili zatvorenih zagrada - 1*/
	if (prebroji(s,',') != 2*prebroji(s,'(')-1){
		return 0;
	}
	
	/*provjerava da li ima broj prije tačke*/
	a=s;
	while (*a != '\0'){
		
		if (*a == '.'){
			if(*(a-1)=='(' || *(a-1)==','){
				return 0;
			}
		}
		a++;
	}
	
	/*provjerava da li je minus na ispravnom mjestu*/
	a=s;
	while (*a != '\0'){
		
		if (*a == '-'){
			if(*(a-1)!='(' && *(a-1)!=','){
				return 0;
			}
			if(!(*(a+1)>='0' && *(a+1)<='9')){
				return 0;
				}
		}
		a++;
	}
	
	/*provjerava ima li šta između zagrada osim zareza "),("*/
	a=s;
	while (*a != '\0'){
		if (*a == ')' && *(a+1) != '\0'){
			if(*(a+1)!=',' || *(a+2)!='('){
				return 0;
			}
		}
		a++;
	}
	
	/*provjerava fali li koordinata*/
	a=s;
	while (*a != '\0'){
		
		if (*a == ','){
			if(*(a-1)=='(' || *(a+1)==')'){
				return 0;
			}
		}
		a++;
	}
	
	
	return 1;
}

/*funkcija koja prima pokazivač na početak jedne tačke, i na kraj i ispituje
li pripada pravougaoniku*/
int pripada (char* pocetak, char* kraj, float x1, float y1, float x2, float y2){
	
	float xmax=x2, xmin=x1 ,ymax=y2 ,ymin=y1;
	
	if(x2<x1){
		return 0;
		
	}
	if(y2<y1){
		return 0;
		
	}

	float xx=0 , yy=0;
	float b=0;
	float aa;
	int predznak=1;
	
	while (*pocetak != *kraj) {
		pocetak++;
		/*pretvaranje prve koordinate*/
		while (*pocetak != '.' && *pocetak != ','){
			if (*pocetak == '-'){
				predznak=-1;
				pocetak++;
			}
			else if (*pocetak>='0'&&*pocetak<='9'){
				b= b*10 + *pocetak - '0';
				pocetak++;
			}
		}
		
		if (*pocetak == '.'){
			pocetak++;
			aa=0.1;
			while (*pocetak != ','){
				if (*pocetak>='0'&&*pocetak<='9'){
					b = b + aa * (*pocetak - '0');
					aa = aa * 0.1;
					pocetak++;
				}
			}
		}
		
		xx=b*predznak;
		
		/*provjera x koordinate*/
		if(xx+eps>=xmin && xx-eps <= xmax);
		else{
			return 0;
			
		}
		
		b=0;
		predznak=1;
		
		pocetak++;
		/*pretvaranje druge koordinate*/
		while (*pocetak != '.' && *pocetak != ')'){
			if (*pocetak == '-'){
				predznak=-1;
				pocetak++;
			}
			else if (*pocetak>='0'&&*pocetak<='9'){
				b= b*10 + *pocetak - '0';
				pocetak++;
			}
		}
		
		if (*pocetak == '.'){
			pocetak++;
			aa=0.1;
			while (*pocetak != ')'){
				if (*pocetak>='0'&&*pocetak<='9'){
					b= b + aa * (*pocetak - '0');
					aa = aa * 0.1;
					pocetak++;
				}
			}
		}
		
		yy=b*predznak;
		
	}
	/*provjera y koordinate*/
	if(yy+eps>=ymin && yy-eps<=ymax) return 1;
		else return 0;
}

char* obuhvat(char* s, float x1, float y1, float x2, float y2) {
	
	if (ispravan_string(s)==0){
		return NULL;
	}

	char*a =s;
	
	char* pocetak;
	char* kraj;
	
	while (*a != '\0'){
		if (*a == '('){
			pocetak=a;
			kraj=a;
			while (*kraj!=')') {
				kraj++;
			}
			if (pripada(pocetak, kraj, x1,y1,x2, y2)==0){
				if (*(kraj+1)=='\0') {
					kraj=kraj+1;
				}
				else{
					kraj=kraj+2;}
				while (*pocetak++=*kraj++);
				a--;
				}
			}
		a++;
	}
	
	if(s[duzina_stringa(s)-1] == ','){
		s[duzina_stringa(s)-1] = '\0';
	}
	
	return s;
}
		

int main () {
	
char a[]="(0,0),(2,2),(3,3),(5,5)";
char* b=a;
while (*b !=')') b++;


char pom[] = "(-15,-30)";
obuhvat(pom, -32, -31, -16, -15);
printf("'%s' \n", pom);


printf ("%d", pripada(a,b,1,1,3,3));

printf("%s", obuhvat(a,2,2,1,1));
return 0;
}
#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

struct tocka{
	double x, y;
};
char* obuhvat(char* string, double x1, double y1, double x2, double y2);
void printajString(char *znak){
	while(*znak!='\0'){
		printf("%c", *znak);
		znak++;
	}
	printf("\n");
}
double stringTodouble(char* string);
void unesi(char niz[], int velicina);
int duzinaBroja(char* string);
void ukloniTocku(char* string);
int daLiPripadaKvadratu(struct tocka daLiPripada, struct tocka ivica1, struct tocka ivica2);
int provjeriNiz(char* string);
int daLiPripadaOsi(double tocka, double var1, double var2);
int provjeriTocku(char* string);
int main() {
	//printf("Zadaća 4, Zadatak 4");
	char rijec1[100];
//	char rijec2[100];
//	rijec2[0]='\0';
	// struct tocka trenutna, ivica1, ivica2;
	// trenutna.x=2;
	// trenutna.y=5;
	// ivica1.x=7;
	// ivica1.y=3;
	// ivica2.x=3;
	// ivica2.y=1;
	while(1){
		printf("Rijec 1:");
		unesi(rijec1, 100);
		
//		printf("%d",'^ ');
//		printf("Rijec 2:");
//		unesi(rijec2, 100);
//		ukloniRijec(rijec1);
//		ukloniTocku(rijec1);
//		ukloniTocku(rijec1);
//		printf("\nRijeci su: %s\n", rijec1);
		printf("\nRijeci su: %s\n", obuhvat(rijec1,1,6,2,5));
//		izbaci_najcescu(rijec1);
//		printf("\n");
	}
	return 0;
}


char* obuhvat(char* string, double x1, double y1, double x2, double y2){
	char* pocetak= string;
	char* pomocniPocetak; //:D
	struct tocka trenutna, ivica1, ivica2;
	ivica1.x=x1;
	ivica1.y=y1;
	ivica2.x=x2;
	ivica2.y=y2;
	if(provjeriNiz(string)==0){
		while(*string++);
		return string;
	}
	while(*string){
		pomocniPocetak= string;
		string++;
		trenutna.x=stringTodouble(string);
		while(*string++!=',');
		trenutna.y=stringTodouble(string);
		if(daLiPripadaKvadratu(trenutna, ivica1, ivica2)==0){
			string=pomocniPocetak;
			ukloniTocku(string);
		}
		while(*string!='(' && *string!='\0')
			string++;
		if(*string=='(')
			string++;
	}
	
}
int provjeriNiz(char* string){
	while(*string){
		if(provjeriTocku(string)==0)
			return 0;
		while(*string++!=')');
		if(*string!=',' && *string!='\0')
			return 0;
		if(*string==','){
			string++;
			if(*string=='\0')
				return 0;
		}
	}
	return 1;
}
int provjeriTocku(char* string){
	if(*string++!='(')
		return 0;
	if(!(*string>='0' && *string<='9'))
		return 0;
	while(*string>='0' && *string<='9')
		string++;
	if(*string!='.' && *string!=',')
		return 0;
	
	if(*string=='.'){
		string++;
		if(*string!=','){
			if(!(*string>='0' && *string<='9'))
				return 0;
			while(*string>='0' && *string<='9')
				string++;
			if(*string!=',')
				return 0;
		}
	}
	//ovdje je zarez;
	string++;
	if(!(*string>='0' && *string<='9'))
		return 0;
	while(*string>='0' && *string<='9')
		string++;
	if(*string!='.' && *string!=')')
		return 0;
	if(*string=='.'){
		string++;
		if(*string!=')'){
			if(!(*string>='0' && *string<='9'))
				return 0;
			while(*string>='0' && *string<='9')
				string++;
			if(*string!=')')
				return 0;
		}
	}
	return 1;
}

void ukloniTocku(char* string){
	int duzina=1;
	char* pocetak= string;
	if(*string=='('){
		while(*string!='\0' && !(*string==',' && *(string-1)==')')){
			duzina++;
			string++;
		}
		string= pocetak;
		while(*(string+duzina)!='\0'){
			*string=*(string+duzina);
			string++;
		}
		*string= *(string+duzina);
	}
}

double stringTodouble(char* string){
	double broj=0, dec=1;
	int duzina= duzinaBroja(string);
	for(; duzina>0; duzina--)
		dec*=10;
	while((*string!='\0' && *string>='0' && *string<='9' && dec>0.000001) || *string=='.'){
		if(*string=='.'){
			string++;
			continue;
		}
		broj+= (9-('9' - *string))*dec;
		dec/=10;
		string++;
	}
	return broj;
}
int duzinaBroja(char* string){
	int broj=-1;
	while(*string!='\0' && *string>='0' && *string<='9'){
		broj++;
		string++;
	}
	return broj;
}
void unesi(char niz[], int velicina){
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
int daLiPripadaKvadratu(struct tocka daLiPripada, struct tocka ivica1, struct tocka ivica2){
	if(daLiPripadaOsi(daLiPripada.x, ivica1.x, ivica2.x) && daLiPripadaOsi(daLiPripada.y, ivica1.y, ivica2.y))
		return 1;
	return 0;
}
int daLiPripadaOsi(double tocka, double var1, double var2){
	if(fabs(tocka-var1)<epsilon || fabs(tocka-var2)<epsilon)
		return 1;
	if((var2<tocka && tocka<var1) || (var1<tocka && tocka<var2))
		return 1;
	return 0;
}


#include <stdio.h>
#define eps 0.0001

void izbaci(char *s, char *poc){ //izbacivanje, prekopiramo sve iduce ( na nasu (
	char *hod=s+2;

	while(*hod!='\0'){
		*poc=*hod;
		poc++; hod++;
	
	} *poc='\0';
}


double ididozareza(char *s){ //vrati broj koji smo nasli do zareza, tj x koordinatu, isto kao i za y
		double k=0.1;
		int predznak=1;
		double suma=0;
		int imadecimala=0;
	
		while(*s!=','){
			if(*s=='-') {predznak=-1;s++;}
			if(*s=='.') {imadecimala=1;s++;}
			if(*s==',') break;
		
			if(imadecimala==0)	suma=suma*10+(*s-'0');
			else {suma=suma+(*s-'0')*k; k/=10;}
		s++;
		}
	suma=suma*predznak;
	return suma;
}

	
int fun(char *n){ //funkcija vrati 0 ako ima neki los format u stringu
	int otvorena=0, zatvorena=0, zarez=0;
	
	while(*n!='\0'){ //prebrojimo broj zagrada i zareza
		if(*n==',') zarez++;
		if(*n=='(') otvorena++;
		if(*n==')') zatvorena++;
		n++;
	}
n--;
if(otvorena!=zatvorena) return 0; //ako negdje fali zagrada
if(((otvorena+zatvorena)/2)+otvorena-1!=zarez) return 0; //ako ima premalo ili previse minusa
return 1;
}
	
	
char *obuhvat (char *tekst, double x1, double y1, double x2, double y2){
	char *poc; char *s=tekst; char *n=tekst;
	if(*n!='(') return 0; //provjerimo da li je na pocetku zagrada, ako nije onda odmah vrati nulu jer je pogresan format
	int vr=fun(n); //u nasu varijablu vr spasimo sta funkcija vraca
	if(vr==0) return 0; //ako funkcija vrati nulu, to je pogresan format i zavrsimo program
	
	while(*n!='\0'){ /*sa jednom petljom prodjemo kroz string, do iza kraja, pa se vratimo na jednu poziciju nazad i 
				tu mora biti zatvorena zagrada (to se ispituje u narednim linijama koda) */
		n++;
	}
	n--;
	
	if(*n!=')') return 0;
	
	while(*s!='\0'){ //sa ovom petljom prolazimo kroz string i kupimo x i y koordinate
		if(*s=='(') {poc=s;  //pamtimo pocetak zagrada u slucaju da bude izbacivanje da znamo dokle treba i na ove zagrade prekopiramo nove od iduceg broja
		if(*(s+1)=='.' || *(s+1)==',') return 0; s++;} //autotestovi ako je poslije (. ili (, to je los format
		
	double suma=ididozareza(s); //u sumu spasimo sve cifre do zareza, to ce nam biti x koordinata
	
	while(*s!=','){ //ovom petljom pomjerimo s do zareza i usput provjerimo ima li nekog smeca
		if(!((*s>=48 && *s<=87) || *s=='-' || *s=='.')) return 0;
		s++;
	}
if(*(s+1)==')' || *(s+1)=='.') return 0; //autotest ako je poslije zareza tacka ili zagrada, to je los format, mora biti broj

int predznak=1;
int imadecimala=0;
double sumay=0;
double k=0.1;
s++;
	while(*s!=')'){ //ovdje kupimo y koordinatu
		if(!((*s>=48 && *s<=87) || *s=='-' || *s=='.')) return 0; //ispitamo da li je smece
		if(*s=='-') {predznak=-1;s++;}
		if(*s=='.') {imadecimala=1; s++;}
		if(imadecimala==0) //ako nije doslo do . racunamo cijeli dio broja pa suma izgleda ovako, a u suprotnom moramo imati k koje smanjuje broj
		sumay=sumay*10+(*s-'0');
		else {sumay=sumay+(*s-'0')*k;
	k/=10;
	}
s++;
}
sumay=sumay*predznak;
	
char *a=poc; //pomocni koji nam govori gdje je bila zagrada, da mozemo novu ubaciti i vratit s na nju
int izb=0;
	
if(sumay-y2>eps || y1-sumay>eps || x1-suma>eps || suma-x2>eps){ // da li treba izbaciti
	izb=1;
	if(poc==tekst && *(s+1)=='\0'){ //ako je prva rijec i ako je to jedina rijec, onda samo stavimo pocetak na \0 i vratimo to
		*tekst='\0';
		return tekst;
	}
	if(*(s+1)=='\0'){ 
		*(poc-1)='\0'; return tekst;
	}
	else izbaci(s,poc);
}
   
	if(izb==1) {s=a;} //ako se desilo izbacivanje onda s vratimo na a, tj. na (
	else if(*(s+1)=='\0') s++; //ovdje ispitujemo da li smo na kraju, da znamo da li s treba povecati dva puta da bi otislo na ( ili jednom da ode na \0
	else s+=2;
	suma=0; sumay=0;
}
	return tekst;
}


int main() {
	char s[] = "(1.1,5.5),(1.2,5.5),(1.3,5.5),(1.4,5.5),(1.5,5.5)";
	char* rez = obuhvat(s, 1.2, 5.499, 1.4, 5.501);
	printf("%s", rez);

	
	return 0;
}

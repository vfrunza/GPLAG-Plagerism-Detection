#include <stdio.h>
#include <math.h>
#define E 0.0001
char* obuhvat(char* s, float x1, float y1, float x2, float y2){
	char* pocetak;
	char*p;
	char*q;
	char*px;  /*pokazuje na elem. x koji treba izbacit, i na ostale koji se izbacuju do prve ')'*/
	char*py;  /*pokazuje na elem. y koji treba izbacit, ali moramo izbacit i elemnt ispred njega tj. x)*/
	float x=0, y=0;
	int jelx=0, jely=0;                /*ako su x i y negativni brojevi*/
	pocetak=s;
	if(*s=='\0') return NULL;
	if(*s!='(')return 0;
	while(*s!='\0') {
		if(*s!=',' && *s!='(' && *s!=')' && *s!='-' && *s!='.' && (*s<='0' || *s>='9')) return 0; /*ako ne ulazi u while nikako prolazi 5 AT*/
		if(*s>='0' && *s<='9') {
			p=s;
			if(*(s-1)=='(' || *(s-1)=='-'){
				if(*(p-1)=='-') jelx=1;
				while(*s>='0' && *s<='9'){
					if(*s>='0' && *s<='9'){
						x+=*s-'0';
						if(*(s+1)>='0' && *(s+1)<='9') x*=10;
						if(*(s+1)=='.' && (*(s+2)>'0' && *(s+2)<'9')) {
							x+=(*(s+2)-'0')*0.1;
							break;
						}
						else if(*(s+1)=='.' || *(s+1)==',' || *(s+2)==',')break;
					}
					s++;
				}
			}
		}
		if(fabs(x-x1)<E && fabs(x-x2)<E) {
			if(*s>='0' && *s<='9'){
				q=s;
				if(*(s-1)==',' || (*(s-1)=='-' && *(s-2)==',')){
					if(*(q-1)=='-') jely=1;
					while(*s>='0' && *s<='9'){
						if(*s>='0' && *s<='9'){
							y+=*s-'0';
							if(*(s+1)>='0' && *(s+1)<='9') y*=10;
						}
						s++;
					}
				}
			}
		}
		//else {
		//	if(*s>='0' && *s<='9') {
		//		px=s;
		//		while(*s!='(') s++;
		//		while(*s!='\0') {
		//			*px++=*s++;
		//		}
		//		s=p;
		//	}
		//}
		s++;
		x=0;
		y=0;
	}
	
	
	return pocetak;
}
void unesi(char niz[], int velicina) {
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


int main() {
	char str[1000];
	float x1,y1,x2,y2;
	int rez;
	printf("Unesite string sa tackama: ");
	unesi(str,1000);
	printf("Unesite cetiri realna broja: ");
	scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
	rez = obuhvat(str, x1, y1, x2 ,y2);
	if (rez == 0)
		printf("String nije ispravno formatiran");
	else
		printf("Pravougaonik [%g,%g]-[%g,%g] obuhvata tacake: %s", x1, y1, x2, y2, rez);
	return 0;
}
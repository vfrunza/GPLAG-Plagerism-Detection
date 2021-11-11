#include <stdio.h>

void novi_red()
{
	char c;
	scanf("%c", &c);
}

int pizza(char s)
{
	if(s=='P') {
		return 1;
	}
	return 0;
}

int hamburger(char s)
{
	if(s=='H') {
		return 1;
	}
	return 0;
}

int cevapi(char s)
{
	if(s=='C') {
		return 1;
	}
	return 0;
}

int main()
{
	char t, m, b;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	novi_red();
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	novi_red();
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	novi_red();
	double restoran=0;
	double fast=0;
	double bistro=0;
	double popust=0;

	restoran=6.8*pizza(t) + 6.8*pizza(b) + 6.8*pizza(m) + 3.3*hamburger(t) + 3.3*hamburger(b) + 3.3*hamburger(m) + 5*cevapi(t) + 5*cevapi(b) + 5*cevapi(m);
	
	fast=8*pizza(t) + 8*pizza(b) + 8*pizza(m) + 3*hamburger(t) + 3*hamburger(b) + 3*hamburger(m) + 3.9*cevapi(t) + 3.9*cevapi(b) + 3.9*cevapi(m);
	
	bistro=5.3*pizza(t) + 5.3*pizza(b) + 5.3*pizza(m) + 5*hamburger(t) + 5*hamburger(b) + 5*hamburger(m) + 6*cevapi(t) + 6*cevapi(b) + 6*cevapi(m);

	//popust proracunajmo
	if(t=='P' || b=='P' || m=='P') {
		popust=(6.8 -(6.8*0.1))*pizza(t) + (6.8 -(6.8*0.1))*pizza(b) + (6.8 -(6.8*0.1))*pizza(m) + 3.3*hamburger(t) + 3.3*hamburger(b) + 3.3*hamburger(m) + 5*cevapi(t) + 5*cevapi(b) + 5*cevapi(m);
	} 
	else if(t=='C' || b=='C' || m=='C') {
		popust=6.8*pizza(t) + 6.8*pizza(b) + 6.8*pizza(m) + 3.3*hamburger(t) + 3.3*hamburger(b) + 3.3*hamburger(m) + (5-(5*0.1))*cevapi(t) + (5-(5*0.1))*cevapi(b) + (5-(5*0.1))*cevapi(m);
	}
	else if(t=='H' || b=='H' || m=='H') {
		popust=6.8*pizza(t) + 6.8*pizza(b) + 6.8*pizza(m) + (3.3- (3.3*0.1))*hamburger(t) + (3.3- (3.3*0.1))*hamburger(b) + (3.3- (3.3*0.1))*hamburger(m) + 5*cevapi(t) + 5*cevapi(b) + 5*cevapi(m);
	}
	
	double najniza=restoran;
	if(fast< najniza) {
		najniza=fast;
	}
	if(bistro<najniza) {
		najniza=bistro;
	}
	if(najniza==restoran) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%3.2lf KM).\n", najniza);
		return 0;
	}
	if(najniza==fast) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%3.2lf KM).\n", najniza);
	}
	if(najniza==bistro) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%3.2lf KM).\n", najniza);
	}
	if(popust<najniza) {
		printf("Sa popustom bi Restoran bio jeftiniji (%3.2lf KM).", popust);
	}
	return 0;
}

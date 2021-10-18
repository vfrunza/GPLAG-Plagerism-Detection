#include <stdio.h>

char* ubaci_broj (char* tekst, int broj )
{
	int brojCifara=0, pomVarijabla=broj;
	int cifra;
	if(broj<0) {
		brojCifara++;
		pomVarijabla=-broj;
	}
	while(pomVarijabla!=0) {
		pomVarijabla=pomVarijabla/10;
		brojCifara++;
	}
	
	char stringBroj[pomVarijabla+1];

	if(broj<0) {
		*pok='-';
		pok++;
	}
	while(pomVarijabla!=0) {
		cifa=pomVarijabla%10;
		*pok=cifra+'0';
	}


}
int main()
{
	printf("Zadaća 4, Zadatak 1");
	return 0;
}

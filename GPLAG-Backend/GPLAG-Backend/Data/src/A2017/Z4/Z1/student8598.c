#include <stdio.h>
void unesi(char niz[], int velicina)
{
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
char* ubaci_broj (char* tekst, int broj)
{
	int i=0, a=0, c[100]=0;
	char* p=tekst;
	while(broj!=0) {
		c[i]=broj%10;
		i++;
		broj/=10;
	}
	if(broj<0)
		i++;
	while(*tekst!='\0') {
		if(*tekst==' ' && *(tekst-1)!=' ' && !(*(tekst-1)>=0 && *(tekst-1)<=9)) {
			char* kraj=tekst;
			while(*kraj!='\0') kraj++;
			while(kraj>tekst) {
				*(kraj+i)= *kraj;
				kraj--;
			}
			tekst++;
			char* q=tekst;
			if(broj<0) {
				char* q++='-';
				for(a=i; a>0; a--) {
					*q=c[a];
					while(*q!='\0') *tekst++=*q++;
				}
			} else {
				for(a=i; a>0; a--) {
					*q=c[a];
					while(*q!='\0') *tekst++=*q++;
				}
			}
		}
		tekst++;
		if(*tekst!=' ') {
			char* kraj1=tekst;
			while(*kraj1!='\0') kraj1++;
			while(kraj1>tekst) {
				*(kraj1+1)= *kraj1;
				kraj1--;
			}}
			*tekst=' ';
	}
	return p;
}
int main()
{
	char x[100];
	int a;
	printf("Unesite string: ");
	unesi(x,100);
	printf("Unesite broj: ");
	scanf("%d", &a);
	printf("%s", ubaci_broj(x,a));
	return 0;
}

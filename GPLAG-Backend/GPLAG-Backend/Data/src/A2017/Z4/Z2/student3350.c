#include <stdio.h>
void unos_stringa(char niz[],int velicina)
{
	char znak=getchar();
	int i=0;
	if(znak=='\n') znak=getchar();
	while(i<velicina-1&&znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
int broj_rijeci(char niz[])
{
	char *p=niz;
	int razmak=1,broj=0;
	while(*p!='\0') {
		if(*p<'A'||((*p>'Z')&&(*p<'a'))||*p>'z') razmak=1;
		else if(razmak==1) {
			razmak=0;
			broj++;
		}
		p++;
	}
	return broj;
}
int provjeri_duzine(char string[],int *brojevi,int duzina)
{
	int br=0,t=0,i=0,brojac=0,novi=0,n;
	int b;
	char *p=string;
	char *q=string;
	int *s=brojevi;
	b=broj_rijeci(string);
	if(b!=duzina) return 0;
	while(*p!='\0') {
		q=p+1;
		if((*p>='A' && *p<='Z')||(*p>='a' && *p<='z')) {
			br++;
			novi++;
		}
		if(*p<'A'||(*p>'Z'&& *p<'a')||*p>'z'||*q=='\0') {
			br=0;
			t=1;
		}
		if(t==1 && novi==*s)  {
			brojac++;
			s++;
			novi=0;
		}
		t=0;
		p++;
	}
	if(brojac==duzina) return 1;
	else return 0;
}
int main()
{
	char niz[100];
	int novi[5]={0};
	int p;
	printf("Unesite recenicu ");
	unos_stringa(niz,100);
	p=provjeri_duzine(niz,novi,100);
	printf("P= %d",p);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
char *ubaci_broj(char *tekst,int broj)
{
	int duzina=0,sirina,br=0,predznak=1;
	char *pocetak=tekst;
	char *kraj=tekst;
	char *q=tekst;
	char *p=tekst;
	char *pom=tekst;
	char *tmp=tekst;
	char *nesto=tekst;
	int zadnji=0,nazad=0,broji=0;
	while (*kraj!='\0') {
		duzina++;
		kraj++;
	}
	pom=kraj-1;
	while(*pom==' ') {
		pom--;
		nazad++;
	}
	if(broj<0) {
		broj=abs(broj);
		predznak=-1;
	}
	int cifra,broj1,broj2=0,novi_broj,t=0,t1=0,d=0,prvi=0,brojac=0;
	while(broj!=0) {
		brojac++;
		q++;
		if(brojac==1&&(*(q-1))==' ') prvi=1;
		q--;
		cifra=broj%10;
		if(t==0) {
			broj1=cifra;
			novi_broj=broj1;
		} else {
			broj1=broj1*10;
			novi_broj=broj1+cifra;
			broj1=novi_broj;
		}
		t++;
		broj/=10;
	}
	printf("Broj= %d",broj1);
	d=t;
	broj=novi_broj;
	while(*q!='\0') {
		broji++;
		if(broji==duzina-nazad) break;
		if(*q==' ' && br==0 && prvi==0 ) {
			t=0;
			if(*(q-1)!='\0') 
			{
				q++;
				if(*q!=' ')
					t=1;
			}
			q--;
			if(predznak==-1) {
				t1=1;
			}
			tmp=kraj+d+t+t1;
			p=tmp;
			while (kraj!=q) {
				*p=*kraj;
				kraj--;
				p--;

			}
			kraj=tmp;
			novi_broj=broj;
			if(predznak==-1) {
				*q++;
				*q='-';
			}
			while(broj!=0) {
				q++;
				*q=broj%10+'0';
				broj/=10;
			}
			if(t==1) {
				q++;
				*q=' ';
			}
			broj=novi_broj;
			br=1;
		}
		q++;
		if(*q!=' ') {
			br=0;
			prvi=0;
		}
	}
	printf("%s",tekst);
	return pocetak;
}
int main()
{
	int br;
	scanf("%d",&br);
	char recenica[1000]=" Ovdje  izmedju "; //   rijeci ima      po nekoliko   razmaka";
	char *p=ubaci_broj(recenica,125);
	printf("\n%d",br);
	return 0;
}

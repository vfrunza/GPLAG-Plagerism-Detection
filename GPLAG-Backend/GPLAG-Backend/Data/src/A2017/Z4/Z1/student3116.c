#include <stdio.h>
#include <math.h>

int duzina_broja(int broj){
	int br=0;
	do{
		broj/=10;
		br++;
	}while(broj!=0);
	return br-1;
}

    char* ubaci_broj(char*tekst, int broj){
	char *s=tekst, *p=tekst, *q=tekst;
	int cifra, predznak=0, n, br=0, k, stepen, j, dodaj=0;
	k=duzina_broja(broj);
	if(broj<0) predznak=1;
	while(*s!='\0'){
		dodaj=1;
		if(br==0 && *s==' '){
			while(*s==' ') s++;
			while(*s!=' ' && *s!='\0') s++;
			s--;
		}
		if(*s==' '){
			p=s;
			while(*p==' '){
				p++;
			}
			if(*p=='\0') return tekst;
			
			s++;
			q=s;
			while(*q!='\0') q++;
			if(*s==' '){ dodaj=0; }
			while(q>=s){
				*(q+k+predznak+dodaj+1)=*q;
				q--;
			}
			if(predznak==1) { *s='-'; s++; }
			j=k;
			if(broj<0) n=-broj;
			else n=broj;
			do{
				stepen=pow(10, j);
				cifra=n/stepen;
				n=n-cifra*stepen;
				*s=cifra+'0';
				s++;
				j--;
			} while(j!=-1); if(dodaj==1) {*s=' '; s++;}
			if(*s==' '){
				while(*s==' ') s++;
			}
		}
		s++;
			br++;
	}
	return tekst;
}

int main() {
	char s[44] = "Ovo je neki primjer teksta";
	printf("\"%s\"", ubaci_broj(s, 123));
	
	return 0;
}
#include <stdio.h>

char *ubaci_broj (char *s, int broj) 
{
	char *p;
	int *b=&broj;
	int i=0,broj_rijeci=0,neslovo=1,duzina=0,cifra=0,broj_cifara=0;
	while(broj!=0) {
	cifra=broj%10;
	broj/=10;
	broj_cifara++;
		
	}
	
	while (*s !='\0') {
		if(!((*s>='A' &&  *s<='Z') || (*s>='a' && *s<='z')))
		{ 
			neslovo=1;
			
		} else if(neslovo==1) {
			neslovo=0;
			broj_rijeci++;
			p=s;
			char *kraj=s;
			while(*kraj!='\0') kraj++;
			while(kraj>s) {
				*(kraj+duzina)=*kraj;
				kraj--;
				if((!(*kraj>='A' && *kraj<='Z') || (*kraj>='a' && *kraj<='z'))) {
					i=0;
					while(i<broj_cifara) {
						kraj=b;
						i++;
					}
				}
			}
			
		}
			*p=*b;
			
		
	
		
		s++;
	}
	return p;
	
}
int main() {
	char s[12]="hello.world";
	int broj=123;
	printf("%s",ubaci_broj(s,broj));
	return 0;
}

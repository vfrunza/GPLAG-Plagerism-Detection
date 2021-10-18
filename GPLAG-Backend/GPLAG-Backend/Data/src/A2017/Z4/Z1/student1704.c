#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak=getchar();
	int i=0; 
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char* ubaci_broj(char* s, int broj) {
	char*pocetak=s;
	char* kraj;
	char*p;
	char*poc;
	int x, brojac=0, logicko=0, duzina=0, duzina1=0, i, y, nerazmak=0;
	
	if(broj<0) {
		x=-1*broj;
		logicko=1;
	}
	
	else
	x=broj;
	
	while(x>0) {
		brojac++;
		x=x/10;
	}
	
	if(logicko==1)
	duzina=brojac+1;
	else
	duzina=brojac;
	
	while(*s!='\0') {
		if(*s!=' ')
		nerazmak=1;
		if(nerazmak==1)
		{
			p=s;
			break;
		}
		s++;
	}
	
	while(*p!='\0') {
		if(*p==' ') {
			poc=p;
			while(*poc==' ') poc++;
			if(*poc=='\0')
			return pocetak;
		
			
			
			if(*(p+1)!=' ') {
				duzina1=duzina+1;
				kraj=p;
				while(*kraj!='\0') kraj++;
				while(kraj>p) {
					*(kraj+duzina1)=*kraj;
					kraj--;
				}
				
				i=0;
				while(i<duzina1) {
					p++;
					i++;
				}
				
				*p=' ';
				p--;
				
				if(logicko==1)
				y=-broj;
				else
				y=broj;
				while(y>0) {
					*p= y%10 + '0';
					y=y/10;
					p--;
				}
				if(logicko==1)
				*p='-';
				
				i=0;
				while(i<duzina1) {
					p++;
					i++;
				}
				while(*p==' ') p++;
			}
			
			else {
				duzina1=duzina;
				kraj=p;
				while(*kraj!='\0') kraj++;
				while(kraj>p) {
					*(kraj+duzina1)=*kraj;
					kraj--;
				}
				
				i=0;
				while(i<duzina1) {
					p++;
					i++;
				}
				
				if(logicko==1)
				y=-broj;
				else
				y=broj;
				
				while(y>0) {
					*p= y%10 + '0';
					y=y/10;
					p--;
				}
				
				if(logicko==1)
				*p='-';
				
				i=0;
				while(i<duzina1) {
					p++;
					i++;
				}
				if(logicko==0)
				p++;
				while(*p==' ') p++;
				
			}
		}
		
		if(*p=='\0') return pocetak;
		p++;
	}
	
	return pocetak;
}

int main() {
	char niz[10000];
	int broj;
	printf("Unesite recenicu: ");
	unesi(niz,10000);
	printf("Unesite broj: ");
	scanf("%d", &broj);
	printf("%s", ubaci_broj(niz,broj));
	
	return 0;
}
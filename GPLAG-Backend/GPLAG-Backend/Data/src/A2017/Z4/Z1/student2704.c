#include <stdio.h>
#include <stdlib.h>

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

void pretvaranje(char* br, int broj) {
	int temp, cifra, i=0, vel=0, flag_neg=0;
	temp=abs(broj);
	if(broj==0) {
		br[0]='0';
		br[1]='\0';
	}
	while(temp!=0) {
		temp=temp/10;
		vel++;
	}
	if(broj<0) {
		broj=abs(broj);
		br[0]='-';
		flag_neg=1;
	}
	if(flag_neg==1) {
		i=0;
		while(broj!=0) {
			cifra=broj%10;
			br[vel-i]=(char)('0'+cifra);
			broj=broj/10;
			i++;
		}
		br[vel+1]='\0';
	} else {
		i=0;
		while(broj!=0) {
			cifra=broj%10;
			br[vel-1-i]=(char)('0'+cifra);
			broj=broj/10;
			i++;
		}
		br[vel]='\0';
	}
}

int velicina_stringa(char* s) {
	int vel=0;
	while(*s!='\0') {
		vel++;
		s++;
	}
	return vel;
}

char* ubaci_broj(char* tekst, int broj) {
	char* kraj;
	char* pocetak;
	char* p; 
	char* s=tekst; 
	char* pokaz;
	char number[100]="nesto";
	int duzina, razmak=0;
	pretvaranje(number, broj);
	duzina=velicina_stringa(number);
	pokaz=number;
	while(*s!='\0') {
		pokaz=number;
		if(*s==' ' && *(s-1)==' ') {
			razmak=1;
			while(*s!='\0') {
				if(*s!=' ') {
					break;
				}
				s++;
			}
		}
		if(*s==' ' && razmak==0) {
			pocetak=s;
			kraj=s+1;
			p=kraj;
			while(*pocetak!='\0') pocetak++;
			*(pocetak+1)='\0';
			while(pocetak>s) {
				*pocetak=*(pocetak-duzina);
				pocetak--;
			}
			while(*pokaz!='\0') {
				*kraj=*pokaz;
				kraj++;
				pokaz++;
			}
			if(*(kraj+1)!=' ' && *(kraj+1)!='\0') {
				while(*p!='\0') p++;
				while(p>kraj) {
					*(p+1)=*p;
					p--;
				}
				*p=' ';
			}
		}
		razmak=0;
		s++;
	}
	return tekst;
} 

int main() {
	int n;
	char s[10]="primjercic", tek[1000];
	char* p;
	printf("Unesi broj: ");
	scanf("%d", &n);
	printf("Unesi neki tekst: ");
	unesi(tek, 1000);
	pretvaranje(s,n);
	printf("%s, %d\n", s, velicina_stringa(s));
	p=ubaci_broj(tek, n);
	printf("%s", tek);
	return 0;
}

#include <stdio.h>
#include <math.h>
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

/*
char* pretvori_u_string(int broj)
{
	int temp=broj;
	char broj_string[12];
	char* broj_s=broj_string;
	if(broj<0) {
		broj=-broj;
		*broj_s++='-';
	}
	do {
		broj_s++;
		temp/=10;
	} while(temp!=0);
	*broj_s--='\0';
	do {
		*broj_s--=broj%10+'0';
		broj/=10;
	} while(broj!=0);
	return broj_string;
}*/
int okreni_broj(int broj)
{
    int broj_unazad=0;
	broj=fabs(broj);
	while(broj!=0) {
		broj_unazad*=10;
		broj_unazad+=broj%10;
		broj/=10;
	}
	return broj_unazad;
}

/*funkcija koja vraca broj ispisan unazad i pretvoren u string
(broj ispisujemo unazad jer cemo u trazenoj funkciji morati da unijeti broj rastavimo na cifre, pri cemu
ce on biti ispisan u unazad)

char* ubaci_broj(char* tekst, int broj)
{
	int i=0;
	char broj_string[12];
	char* broj_s=broj_string;
	char novi_tekst[1000];
	char* p=novi_tekst;
	int temp=broj;
	int br_neslova=0;
	char* pok=tekst;
	/*trazimo znak koji nije rijec i koliko se puta ponavlja
	while(*tekst!='\0') {
		if(!((*tekst>='A' && *tekst<='Z') || (*tekst>='a' && *tekst<='z'))) {
			br_neslova++;
			if((*tekst>='A' && *tekst<='Z') || (*tekst>='a' && *tekst<='z')) {
				br_neslova=0;
			}
		}
		tekst++;
	}
	/*pretvaramo broj(int) u string
	if(broj<0) {
		broj=-broj;
		*broj_s++='-';
	}
	do {
		broj_s++;
		temp/=10;
	} while(temp!=0);
	*broj_s--='\0';
	do {
		*broj_s--=broj%10+'0';
		broj/=10;
	} while(broj!=0);

	trazimo duzinu stringa
	int duzina=-1;
	while(*broj_s!='\0') {
		duzina++;
		broj_s++;
	}

	while(*pok!='\0') {
		if(!((*pok>='A' && *pok<='Z') || (*pok>='a' && *pok<='z')) && br_neslova==1) {
			novi_tekst[i]=' ';
			i++;
			novi_tekst[i]=broj_s;
			novi_tekst[i++]=' ';
			pok++;
		}
		novi_tekst[i]=pok;
		novi_tekst[i]='\0';
	}
	return p;

}






/*char* kraj=pok;
while(*kraj!='\0') kraj++;
while(kraj>pok){
	*(kraj+duzina)=*kraj;
	kraj--;
}
char* p=broj_string;
while(*p!='\0') *pok++=*p++;
}
pok++;
}
}
while(*tekst!='\0'){
tekst++;
}
*/



char* ubaci_broj(char *tekst, int broj)
{
	int broj_unazad,temp;
	int i=0,j=0;
	char novi_tekst[1000];
	char* p=novi_tekst;
	broj_unazad=okreni_broj(broj);
	temp=broj_unazad;
	broj=fabs(broj);

	while(tekst[j]!='\0') {
		if(!((tekst[j]>='A' && tekst[j]<='Z') || (tekst[j]>='a' && tekst[j]<='z'))) {
			novi_tekst[i]=' ';
			i++;
			broj_unazad=temp;
			while(broj_unazad!=0) {
				novi_tekst[i]=(char)(broj_unazad%10+48);
				broj_unazad/=10;
				i++;
			}
			novi_tekst[i++]=' ';
			j++;
		}
		novi_tekst[i]=tekst[j];
		i++;
		j++;
	}
	novi_tekst[i]='\0';
	return p;
}
/*
char* ubaci_broj(char *tekst, int broj){
	int i=0;
	char novi_tekst[1000];
	char* p=novi_tekst;
	int broj_unazad;
	int temp, br_neslova=0;;
	broj_unazad=okreni_broj(broj);
	temp=broj_unazad;
	while(*tekst!='\0') {
		if(!((*tekst>='A' && *tekst<='Z') || (*tekst>='a' && *tekst<='z'))) {
			br_neslova++;
			if((*tekst>='A' && *tekst<='Z') || (*tekst>='a' && *tekst<='z')) {
				br_neslova=0;
			}
		}
		tekst++;
	}
	while(*tekst!='\0'){
		if(br_neslova==1){
			novi_tekst[i]=' ';
			i++;
			broj_unazad=temp;
			while(broj_unazad!=0){
			novi_tekst[i]=(char)(broj_unazad%10+'0');
			broj_unazad/=10;
			i++;
			}
			novi_tekst[i++]=' ';
			tekst++;
		}
		novi_tekst[i]=*tekst;
		i++;
		tekst++;
	}
	novi_tekst[i]='\0';
	return p;
}
*/
int main()
{
	printf("Zadaća 4, Zadatak 1");
	return 0;
}

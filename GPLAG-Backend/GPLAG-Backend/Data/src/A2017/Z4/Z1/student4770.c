#include <stdio.h>
int br_cifara(int br)
{
	int duzina=0;
	while(br!=0) {
		duzina++;
		br/=10;
	}
	return duzina;
}
char* ubaci_broj(char* tekst, int broj)
{
	char* pocetak=tekst;
	char* p=tekst;
	char* q=tekst;
	char* kraj=tekst;
	char* temp;
	int  razmaci=0,pomocni=broj,duzina_broja,a=1;
	duzina_broja=br_cifara(broj);
	a+=duzina_broja;
	if(broj<0) {
		a++;
		pomocni=pomocni*(-1);
	}
	while(*tekst!='\0') {
		if(*tekst==' ') {
			if(tekst==p) {
				while(*tekst!='\0' && *tekst==' ') {
					tekst++;
				}
			}
			while(*tekst!=' '&& *tekst!='\0') {
				tekst++;
			}
			temp=tekst;
			razmaci=0;
			while(*temp!='\0' && *temp==' '){
				razmaci++;
				temp++;
			}
			if(*temp=='\0') break;
			kraj=tekst;
				
			while(*kraj!='\0') {
				kraj++;
			}
			while(kraj>tekst) {
				*(kraj+a)=*kraj;
				kraj--;
			}
			tekst+=a;
			*tekst--=' ';
			
			pomocni=broj;
			if(broj<0) {
				pomocni=pomocni*(-1);
			}	
			while(pomocni!=0) {
				*tekst=(pomocni%10)+'0';
				tekst--;
				pomocni/=10;
			}
			if(broj<0) *tekst='-';
			tekst+=a;
			if(razmaci>1){
				kraj=tekst;
				while(*kraj!='\0') {
					*kraj=*(kraj+1);
					kraj++;
					
				}
			}
		}
		if(*tekst==' ') {
			while(*tekst==' ' && *tekst!='\0') {
				tekst++;
			}
		}
		if(*tekst!='\0') tekst++;
	}

	return pocetak;
}
int main()
{

	char s[77]="Ovo je neki primjer testa";
	printf("%s",ubaci_broj(s,0));
	return 0;
}

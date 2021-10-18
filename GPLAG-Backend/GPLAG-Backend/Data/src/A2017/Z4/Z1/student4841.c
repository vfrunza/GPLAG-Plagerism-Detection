#include <stdio.h>
#include <math.h>

int brojrijeci(char* tekst){
	int razmak=1, broj=0;
	while(*tekst!='\0'){
		if(*tekst==' ') razmak=1;
		else if (razmak==1){
			razmak=0;
			broj++;
		}
		
		tekst++;
	}
	return broj;
}

char* ubaci_broj (char* tekst,  int broj){
	int  temp=fabs(broj), brojcifara=0, i=0;
	char* s=tekst;
	char* kraj;
	char cifre[11];
	while(temp!=0){
		cifre[brojcifara]='0' + temp%10;
		brojcifara++;
		temp/=10;
	}
	cifre[brojcifara]='\0';
	temp=fabs(broj);
	while(*tekst==' '){
		tekst++;
	}
	while(*tekst!='\0'){
		if(brojrijeci(tekst)==0) break;
		i=brojcifara-1;
		temp=fabs(broj);
		if(*tekst==' ' && *(tekst-1)!=' '){
			kraj=tekst;
			while(*kraj!='\0') kraj++;
			if(broj>=0){
				if(*(tekst+1)==' '){
					while(kraj>tekst){
						*(kraj+brojcifara)=*kraj;
						kraj--;
					}
				}
				else{
					while(kraj>tekst){
						*(kraj+brojcifara+1)=*kraj;
						kraj--;
					}
				}
			}
			else{
				if(*(tekst+1)==' '){
					while(kraj>tekst){
						*(kraj+brojcifara+1)=*kraj;
						kraj--;
					}
				}
				else{
					while(kraj>tekst){
						*(kraj+brojcifara+2)=*kraj;
						kraj--;
					}
				}
			}
			tekst++;
			if(broj<0){
				*tekst='-';
				tekst++;
			}
			while(i>=0){
				*tekst=cifre[i];
				*tekst++; i--;
			}
			*tekst=' ';
			
		}
		tekst++;
	}
	return s;
}

int main() {
char s[65] = "Sada cemo probati sa negativnim brojem";
printf("\"%s\"", ubaci_broj(s, -528));
return 0;
}

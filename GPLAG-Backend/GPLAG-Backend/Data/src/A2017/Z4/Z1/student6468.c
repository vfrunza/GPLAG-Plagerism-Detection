#include <stdio.h>

char intBuffer[12];

int brojCifara(int broj)
{
	int pov=0;
	
	if(broj < 0)
		pov++;

	while(broj!=0) {
		broj/=10;
		pov++;
	}
	
	return pov;
}
void loadBuffer(int broj)
{
	int broj_cifara=brojCifara(broj);
	int i;
	int pocetni = 0;

	if(broj < 0) {
		intBuffer[0] = '-';
		pocetni = 1;
		broj *= -1;
	}
	
	intBuffer[broj_cifara]='\0';
	
	for(i=broj_cifara-1; i>=pocetni; i--) {
		intBuffer[i]='0'+broj%10;
		broj/=10;
	}
}

char* ubaci_broj(char* tekst, int broj)
{
	int ubaciBroj=0;
	int i;
	int broj_cifara=brojCifara(broj);
	char* kraj;
	char* startTmp = tekst;
	char* tmp = tekst;
	char* tmp2;
	char* posljednjaRijec;
	char* posljednjaRijec2;
	char* prvaRijec = tekst;
	int tmp3 = 0;
	char* tmp4;

	loadBuffer(broj);
	
	while(*tmp != '\0') {
		tmp++;
	}
	
	kraj = tmp;
	tmp2 = kraj-1;
	
	posljednjaRijec = kraj - 1;
	posljednjaRijec2 = kraj - 1;
	
	while(*posljednjaRijec == ' ' && posljednjaRijec != startTmp) {
		posljednjaRijec--;
		posljednjaRijec2--;
	}
	
	while(*posljednjaRijec != ' ' && posljednjaRijec != startTmp) {
		posljednjaRijec--;
	}
	
	posljednjaRijec++;

	while(*prvaRijec == ' ') {
		prvaRijec++;
	}

	while(*tekst!='\0') {
		if(*tekst==' ') {
			tmp4 = tekst;
			while(*tmp4 == ' ' && tmp4 != startTmp) {
				tmp4--;
			}
			
			if(tmp4 == posljednjaRijec2)
				ubaciBroj = 0;
		}
		
		if(*tekst==' ' && ubaciBroj==1 && posljednjaRijec2 != tekst - 1) {
			*(kraj+broj_cifara+1)='\0';
			*kraj=' ';
			kraj+=broj_cifara+1;
			posljednjaRijec2+=broj_cifara+1;

			while(tmp2!=tekst) {
				*(tmp2+broj_cifara+1)=*tmp2;
				tmp2--;
			}
			
			tmp2=kraj-1;
			tekst++;

			for(i=0; i<broj_cifara; i++) {
				*tekst=intBuffer[i];
				tekst++;
			}
			
			*tekst = ' ';
			
			if(*(tekst+1) == ' ') {
				tmp2 = tekst;
				
				while(tmp2 != kraj) {
					*tmp2 = *(tmp2 + 1);
					tmp2++;
				}
				
				kraj--;
				tmp2 = kraj - 1;
				posljednjaRijec2--;
			}
			
			ubaciBroj=0;
		}
		else {
			if(*tekst!=' ' && ubaciBroj!=1 && posljednjaRijec != prvaRijec && tmp3 == 0) 
				ubaciBroj=1;
			
			tekst++;
		}
	}
	

	return startTmp;
}
int main()
{
char s[19] = "     auto!stp   ";
char s2[22] = "     auto stp   ";
printf("\"%s\"\n", ubaci_broj(s2, 9));
printf("\"     auto 9 stp   \"\n\n");
return 0;
}











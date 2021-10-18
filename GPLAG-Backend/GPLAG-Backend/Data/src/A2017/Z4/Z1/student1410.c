#include <stdio.h>
#include <math.h>

void unesi(char niz[],int velicina)
{
	int i;
	char znak =getchar();
	if(znak=='\n')znak=getchar();
	i=0;
	while(i<velicina-1 && znak!= '\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char* ubaci_broj(char* tekst,int broj)
{
	int brojac_c=0,razmak,brojac_r=0,pomak=1,brojac_razmaka,count,rijeci=0;
	int niz[20]= {0};
	char *novo=tekst;
	char* novitekst=tekst;
	char *kraj1=novitekst;
	char *novi_kraj=tekst;
	int number=broj;
	int ubacivanje=0;
	char *kraj=tekst;
	char *razmak1=kraj;
	char *text=tekst;
	int br=broj;
	int n=broj;
	/*odredjivanje broja cifri u broju*/

	if(broj<0)
		brojac_c++;
	do {
		broj=broj/10;
		brojac_c++;
	} while(broj!=0);



	/*smjestanje cifri broja u niz...zavrsiti!!!*/

	count=0;

	while(number!=0) {
		if(number<0)
			number*=-1;
		niz[count]=number%10;
		number/=10;
		count++;
	}



	/*odredjivanje broja rijeci*/
	razmak=1;
	while(*novo !='\0') {
		if(*novo==' ')
			razmak=1;
		else if(razmak==1) {
			razmak=0;
			brojac_r++;
		}
		novo++;
	}

	if(brojac_r>1) {




		while(*tekst !='\0') {


			if(*tekst=='\377')
				*tekst=' ';



			if( *tekst==' ' )
				pomak=1;
			if(*tekst>='0' && *tekst <='9')
				pomak=0;

			if((*tekst>='a' && *tekst<='z') || (*tekst>='A' && *tekst<='Z')) {
				if(rijeci!=0)
					if(*(tekst-1)==' ') {
						ubacivanje=0;
						pomak=1;
					}
			}

			if(*tekst==' ' && ubacivanje==1)
				pomak=0;

			else if(pomak==1) {
				pomak=0;
				rijeci++;
				if(rijeci==brojac_r) break;
				char *kraj=tekst;
				while(!(*kraj ==' ' || *kraj=='\0') )kraj++;
				/*"kraj" je kraj jedne rijeci  PROVJERITI MOZE LI OVO*/

				brojac_razmaka=0;
				char *razmak1=kraj;
				while(*razmak1 ==' ') {
					brojac_razmaka++;
					razmak1++;
				}

				if(brojac_razmaka==1) {
					/*pomjeranje sve za broj mjesta*/

					/*pomjeranje pokazivac na kraj stringa*/
					char *novi_kraj=tekst;
					while(*novi_kraj !='\0') novi_kraj++;
					if(n<0)
						while(novi_kraj>=kraj) {
						/* +1, da bi se stvorio jos jedan razmak izmedju broja i sljedece rijeci*/
						*(novi_kraj + brojac_c+ 1)=*novi_kraj;
						novi_kraj--;

					}
					
					else
					while(novi_kraj>kraj) {
						/* +1, da bi se stvorio jos jedan razmak izmedju broja i sljedece rijeci*/
						*(novi_kraj + brojac_c+ 1)=*novi_kraj;
						novi_kraj--;

					}


					char *kraj1=tekst;
					while(*kraj1 !=' ' )kraj1++;

					++kraj1;
					int j;
					
			
				for(j=brojac_c-1; j>=0; j--) {
						if(br<0) {

							*kraj1='-';
							kraj1++;
						}
						br=fabs(br); 

						*kraj1++ = niz[j];

					}

					ubacivanje=1;


			}



			
		}

tekst++;

	}




		
}
return text;

}
int main()

{
	int n;
	char s[100];
	printf("Unesite tekst: ");
	unesi(s,100);
	printf("Unesite broj: ");
	scanf("%d",&n);
	printf("%s",ubaci_broj(s,n));


	return 0;
}

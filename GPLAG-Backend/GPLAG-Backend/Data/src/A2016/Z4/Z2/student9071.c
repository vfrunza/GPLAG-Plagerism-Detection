#include <stdio.h>
#include <stdlib.h>
char *kodiraj(char *string,char *tablica)	//naizgled radi
{

	int i,j,temp,n=0,k=0,flag=0,max,histogram[95]= {0};
	char *resetstring,*resettablica,ascii[95],karakter;

	resetstring=string;
	resettablica=tablica;
//formiranje ascii tabele, za koju je histogram i namijenjen.
	for(i=0; i<95; i++) {
		karakter=i+32;
		ascii[i]=karakter;
	}

//pravljenje histograma za tekst
	while(*string!='\0') {
		histogram[(*string-32)]++;
		string++;
	}

//na osnovu sortiranja histograma se sortira i ascii tabela (Selection sort)
	for(i=0; i<95; i++) {
		max=i;
		for(j=i+1; j<95; j++) {
			if(histogram[j]>histogram [max])
				max=j;
		}
		temp=histogram[i];
		histogram[i]=histogram[max];
		histogram[max]=temp;

		temp=ascii[i];
		ascii[i]=ascii[max];
		ascii[max]=temp;
	}

//formiranje finalne tablice "sifriranja", uzimamo histogram i prebrojimo nenulte vrijednost, taj broj clanova cemo gledati iz nase tabele.
	for(i=0; histogram[i]!=0; i++) {
		n++;
	}
	for(i=0; i<n; i++) {
		tablica[i]=ascii[i];
	}
	for(i=n; i<95; i++) {
		karakter=k+32;
		for (j=0; j<n; j++) {
			if (ascii[j]==karakter) {
				flag=1;
				i--;
				break;
			}
		}
		if (flag!=1) {
			tablica[i]=karakter;
		}
		flag=0;
		k++;
	}
	tablica[i]='\0';

//kraj formiranja tablice



//Glavno kodiranje

	string=resetstring;
	tablica=resettablica;
	while(*string!='\0') {
		tablica=resettablica;
		for(i=0; i<95; i++) {
			if(*string==*tablica) {
				*string='~'-i;
				break;
			}
			tablica++;
			if (tablica=='\0') break;
		}
		string++;
	}
	string=resetstring;
	return resetstring;
}



char *dekodiraj(char *string,char *tablica)
{
	int i;
	char *resetstring,equivalent[95];
	resetstring=string;
	//u niz equiv. upisujemo ekvivalentne karaktere, odgovaraju onim iz tablice samo su pomjereni.
	for(i=0; i<95; i++) {
		equivalent[i]='~'-i;
	}
	//desifriranje, prvo trazimo u nasoj tablici slovo koje je isto slovu *string, te ga zamijenjujemo ekvivalentnim i tako do '\0'.
	while(*string!='\0') {
		for(i=0;; i++) {
			if (*string==equivalent[i]) {
				*string=tablica[i];
				break;
			}
		}
		string++;
	}

	return resetstring;
}

int main()
{

	char tekst[] = "LLMLNLNMONM";
	char sifrarnik[100];
	int i;
	kodiraj(tekst, sifrarnik);
	printf("%s", tekst);
	for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
	dekodiraj(tekst, sifrarnik);
	printf("%s", tekst);
	return 0;
}

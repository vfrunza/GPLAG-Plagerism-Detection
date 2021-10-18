#include <stdio.h>
#include <stdlib.h>

void unesi(char niz[], int velicina)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char* ubaci_broj (char* tekst, int broj)
{
	char *vrati=tekst, *s=tekst, *q=tekst, *kraj=tekst;
	int razmak_uracunat=1, temp1=0, temp2=broj, br_cifara=0, minus=0, nula=0, i;

	if(temp2<0) {
		br_cifara++;
		temp2=abs(temp2); 
		minus=1;
	}
 
	while (temp2!=0) {
		br_cifara++;
		if(temp2%10==0) {
			nula++;
			br_cifara++;
			temp2/=10;
		}
		temp1= temp1*10 + temp2%10;
		temp2/=10;
	}

	/*pomjeranje pokazivaca kraj na posljednje znak u stringu koji nije razmak*/
	while (*kraj++!='\0');
	kraj-=2;
	while (*kraj==' ') kraj--;


	while (*s!='\0' && s!=kraj) {

		if(*s==' ' && razmak_uracunat==0) {
			razmak_uracunat=1;

			while (*q++!='\0');
			q--;

			while (q>s) {
				*(q+br_cifara+1)=*q;
				q--;
			}

			kraj+=br_cifara+1;

			*s++=' ';
			if(minus) *s++='-';
			temp2=temp1;
			while (temp1!=0) {
				*s++= temp1%10 + '0';
				temp1/=10;
			}
			temp1=temp2;
			for(i=0; i<nula; i++) {
				*s='0';
				s++;
			}
			*s=' ';

		} else if(razmak_uracunat && *s!=' ') {
			razmak_uracunat=0;
		}
		s++;
	}

	return vrati;
}

int main()
{
	char tekst[100];
	int broj;
	printf("Unesite tekst: ");
	unesi(tekst,100);
	printf("Unesite broj: ");
	scanf("%d", &broj);
	printf("Nakon ubacivanja tekst izgleda ovako: %s", ubaci_broj(tekst,broj));
	return 0;
}

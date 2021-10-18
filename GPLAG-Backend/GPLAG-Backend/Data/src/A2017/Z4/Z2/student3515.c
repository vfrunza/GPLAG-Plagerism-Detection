#include <stdio.h>
int provjeri_duzine(char *s,int duzine[],int duz_niza)
{
	int i,razmak=1,br_rijeci=-1,duzina1=0;
	char*p=s;
	/*slaganje broja rijeci i broja clanova niza  PROVJERA*/

	while (*p!='\0') {
		if(*p<'A'||(*p>'Z'&& *p<'a')||*p>'z') {
			razmak=1;
			p++;
		} else if(razmak==1) {
			razmak=0;
			br_rijeci++;
			p++;
		} else p++;
	}
	if (br_rijeci!=duz_niza-1)
		return 0;
	razmak=1;
	br_rijeci=-1;


	while(*s!='\0') {
		if(*s<'A'||(*s>'Z'&& *s<'a')||*s>'z') {
			razmak=1;
			s++;
		} else if(razmak==1) {
			/* dodje na rijec*/
			duzina1=0;
			razmak=0;
			p=s;
			/*mjesto rijeci*/
			br_rijeci++;
			if(br_rijeci> duz_niza-1)
				return 0;
			/*	 brojanje slova*/
			while((*p>='A'&& *p<'Z')||(*p>='a'&& *p<='z')) {
				p++;
				duzina1++;
			}
			s=p-1;
			/*provjera duzine*/
			if(duzine[br_rijeci]!=duzina1)
				return 0;
			s++;
		} else s++;
	}

	if(br_rijeci!=duz_niza-1)
		return 0;
	return 1;
}

int main()
{
	printf("Zadaća 4, Zadatak 2");
	return 0;
}

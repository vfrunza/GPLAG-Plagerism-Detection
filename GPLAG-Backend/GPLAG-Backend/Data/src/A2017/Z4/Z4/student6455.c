#include <stdio.h>
void najduzi_bp(char*s1, char* s2)
{
	int nizslova[128]= {0};
	char*pocetak=s1;
	char*krajnja_pozicija=s1;
	char*pocetaks2=s2;
	int pomocni;
	int kraj;
	int max;
	int i=0;
	int duzina_prve_rijeci=0;
	int brojac=0;
	while(*s1!='\0') {
		if((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
			pomocni=*s1;
			if(pomocni>='A' && pomocni<='Z')
				pomocni+='a'-'A';

			nizslova[pomocni]++;
			if(nizslova[pomocni]>1){
		printf("%d ", duzina_prve_rijeci);
				break;}
			duzina_prve_rijeci++;
			s1++;
		}
		max=duzina_prve_rijeci;
		for(i=0; i<128; i++) {
			nizslova[i]=0;
		}
		while(*s1!='\0') {
			if((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
				pocetak=s1;

				krajnja_pozicija=s1;
				kraj=*s1;
				if(kraj>='A' && kraj<='Z')
					kraj+=32;

				nizslova[kraj]++;
				if(nizslova[kraj]>1){
					printf("%d", brojac);
				}
					break;}
				brojac++;
				s1++;
				krajnja_pozicija++;
			}
			if(brojac>max) {
				max=brojac;
				while(pocetak<krajnja_pozicija) {
					*s2=*pocetak;
					pocetak++;
					s2++;
				}
				*s2='\0';
				while(s2>pocetaks2) {
					s2--;
				}

				for(i=0; i<128; i++) {
					if(nizslova[i]!=0)
						nizslova[i]=0;
					brojac=0;
				}
			}

			s1++;
		}
	}
int main()
{
	char niz[10];
	najduzi_bp ("abca", niz);
	printf ("Niz: '%s'", niz);

	return 0;
}

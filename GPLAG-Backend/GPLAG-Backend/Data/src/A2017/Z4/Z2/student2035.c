#include <stdio.h>


int jel_slovo(char znak)
{
	if((znak<='z' && znak>='a') || (znak<='Z' && znak>='A')) return 1;
	else return 0;
}


int broj_rijeci(char *s)
{
	char *p=s;
	int brojrijeci=0;
	int slovo=0;
	while(*p!='\0') {
		if(jel_slovo(*p)==0)
			slovo=0;
		else {
			if(slovo==0) {
				brojrijeci++;
				slovo=1;
			}
		}
		p++;
	}
	return brojrijeci;
}



int provjeri_duzine(char *s, int niz[], int velicina)
{
	int i;
	char *pok=s;
	int brojrijeci=broj_rijeci(pok);
//	int slovo=0;
	if(brojrijeci!=velicina) return 0;
	for(i=0; i<velicina; i++)
		if(niz[i]<=0) return 0;
	i=0;
//	printf("TU SAM");
	while(*s!='\0') {
	//	printf("TU SAM");	
		if(jel_slovo(*s)) {
			int brojac=0; 
			while(*s!='\0' && jel_slovo(*s)) {
			s++;
			brojac++; }
			s--;
			if(brojac!=niz[i]) return 0;
			i++;
		}

		s++;
	}
	return 1;

}

int main()
{
	char sr[100]="Ovo je neki primjer teksta";
	printf("%d ", broj_rijeci(sr));
	return 0;
}

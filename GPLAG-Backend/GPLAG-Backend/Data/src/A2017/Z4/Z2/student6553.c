#include <stdio.h>

int izbroji_rijeci(char*s)
{
	int razmak=1,br=0;

	while(*s!='\0') {
		if(!((*s>='A' && *s<='Z')||(*s>='a' && *s<='z'))) razmak=1;
		else if(razmak) {
			br++;
			razmak=0;
		}
		s++;
	}

	return br;
}

int provjeri_duzine(char*s, int *p, int vel)
{
	int br=0;
	if(izbroji_rijeci(s)!=vel) return 0;
	while(*s!='\0') {
		br=0;
		if((*s>='A' && *s<='Z')||(*s>='a' && *s<='z')) {
			while((*s>='A' && *s<='Z')||(*s>='a' && *s<='z')) {
				s++;
				br++;
			}
			s--;

			if(br==*p) p++;
			else return 0;
		}

		s++;
	}


	return 1;

}

int main()
{
	char s[]="  Ovo     je neki   primjer teksta ";
	int niz[5]= {3,2,4,7,6};
	printf("%d", provjeri_duzine(s,niz,5));
	return 0;
}

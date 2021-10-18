#include <stdio.h>
char provjeri_duzine(char *s,int *niz_brojeva,int velicina_niza)
{
	int slova=0;
	int pozicija_rijeci=-1;
	int uslo_u_while=0;
	while(*s!='\0') {
		if((*s>=65 && *s<=90) || (*s>=97 && *s<=122)) {
			if(slova==0) pozicija_rijeci++;
			slova++;
			if(*(s+1)==a'\0')
			{
				if(pozicija_rijeci!=velicina_niza-1 || slova!= *(niz_brojeva + pozicija_rijeci))
					{
						return 0;
					}
			}
		}
		while(*s<65 || (*s>90 && *s<97) || *s>122 ) {
			uslo_u_while = 1;
			if(slova!=0) {
				if(slova!= *(niz_brojeva + pozicija_rijeci))
					{
						return 0;
					}
				
				slova=0;
			}
			if(*(s+1)=='\0' && pozicija_rijeci==velicina_niza-1) return 1;
			if(*(s+1)=='\0' && pozicija_rijeci!=velicina_niza-1) return 0;
			s++;
		}
		if(uslo_u_while==0) s++;
		else uslo_u_while = 0;
	}
	return 1;

}
int main()
{
	return 0;
}

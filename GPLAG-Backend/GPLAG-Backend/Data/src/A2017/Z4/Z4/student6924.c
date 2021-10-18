#include <stdio.h>

int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
#include <stdio.h>

void unesi(char *s, int velicina)
{
	int i=0;
	char c;
	do {
		c=getchar();
		s[i]=c;
		i++;
	} while(c!='\n' && i<velicina);
	s[i-1]='\0';
}

void najduzi_bp(char* s1, char* s2)
{
	int pom, brojac[123], i, najduzi=0, duzina=0, max=0, j=0;
	char *pok_najduzi;
	char *pom_pok;

	
		
	while(*s1!='\0') {
		for(i=0; i<122; i++) {
			brojac[i]=0;
		}
		pom=*s1;
		if((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')) pom_pok=s1;
	
		while((pom>='a' && pom<='z') || (pom>='A' && pom<='Z')) {
			if(pom>='A' && pom<='Z') pom+='a'-'A';
			brojac[pom]++;
			s1++;
			pom=*s1;
		}

		for(i=0; i<123; i++) {
			if(brojac[i]>1) {
				break;
			} else {
				duzina++;
			}
		}
		
		if(duzina>max) {
			max=duzina;
			pok_najduzi=pom_pok;
		}
		s1++;
	}
	
	while(j<duzina) {
		*s2++=*pok_najduzi++;
		j++;
	} *s2='\0';
}

int main()
{
/*	char s1[100], s2[33];

	printf("Unesi tekst: ");
	unesi(s1,100);

	najduzi_bp(s1,s2);
	printf("%s", s2);*/

	return 0;
}

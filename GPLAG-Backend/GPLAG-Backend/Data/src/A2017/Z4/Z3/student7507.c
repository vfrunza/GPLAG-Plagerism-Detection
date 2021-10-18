#include <stdio.h>

void unesi(char niz[], int vel)
{
	int i=0; 
	char znak=getchar();
	if (znak=='\n') znak=getchar();
	while(i<vel-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

void najduzi_bp(char* s1, char* s2)
{
	int duzina=0, max_duzina=0, i, brojaci[26]= {0};
	char *p=s1,*q=s2, *kraj=s1, *pocetak=s1;

	while (*p!='\0') {
		if(*p>='a' && *p<='z') {

			if(brojaci[*p-97]==0) {
				brojaci[*p-97]++;
				duzina++;
			} else {
				for(i=0; i<26; i++) brojaci[i]=0;
				if(duzina>max_duzina) {
					max_duzina=duzina;
					kraj=p-1;
				}
				duzina=0;
			}
		} else if(*p>='A' && *p<='Z') {
			if(brojaci[*p-65]==0) {
				brojaci[*p-65]++;
				duzina++;
			} else {
				for(i=0; i<26; i++) brojaci[i]=0;
				if(duzina>max_duzina) {
					max_duzina=duzina;
					kraj=p-1;
				}
				duzina=0;
			}
		} else {
			for(i=0; i<26; i++) brojaci[i]=0;
			if(duzina>max_duzina) {
				max_duzina=duzina;
				kraj=p-1;
			}
			duzina=0;
		}
		p++;
	}

	/*ako je i zadnji znak u stringu dio podniza brojaci nisu ispraznjeni i pok kraj nije pomjeren*/
	for(i=0; i<26; i++) {
		if(brojaci[i]!=0) {
			if(duzina>max_duzina) {
				max_duzina=duzina;
				kraj=p-1;
				break;
			}
		}
	}

	pocetak=kraj-max_duzina+1;

	while(pocetak<=kraj) {
		*q=*pocetak;
		q++;
		pocetak++;
	}
	*q='\0';

}

int main()
{
	char niz[10];
	najduzi_bp ("Ovo je primjer", niz);
	printf("niz: %s", niz);
	return 0; 
}

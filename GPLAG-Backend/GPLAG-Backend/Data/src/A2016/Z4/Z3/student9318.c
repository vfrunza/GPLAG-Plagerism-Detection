#include <stdio.h>

char *zamjena_rijeci(char *tekst,char** rijeci,char** zamjene,int broj_rijeci){
	int i,duz,duz1,duzina, pronasao;
	char *vrati = tekst;
	char *p, *q, *a, *b, *kraj , *pom;  
	for(i = 0; i < broj_rijeci; i++){
		while(*tekst != '\0'){
			p = rijeci[i];
			duz = 0;
			while(*p != '\0'){ p++; duz++;}
			q = zamjene[i];
			duz1 = 0;
			while(*q != '\0'){q++; duz1++;}
			a = tekst; b = rijeci[i];
			pronasao = 1;
			while(*b != '\0'){
				if(*a != *b)pronasao = 0;
				if(pronasao == 0)break;
				a++; b++;
			}
			
			if(pronasao){
				if(	(tekst == vrati || *(tekst - 1) == ' ') && (*a == ' '  || *a == '\0') ){
					if(duz1 >= duz){
						duzina = duz1 - duz;
						a--;
						kraj = a;
						while(*kraj != '\0')kraj++;
						while(kraj != a){ 	*(kraj + duzina) = *kraj;	kraj--;} 
							b = zamjene[i];
							while(*b != '\0')*tekst++ = *b++;
					tekst--;
						
					}
					else if(duz1 < duz){
						b = zamjene[i];
						while(*b != '\0'){*tekst++ = *b++;}
						b = tekst; pom = tekst;
						while(*pom != ' ' && *pom != '\0')pom++;
						while(*pom != '\0')*b++ = *pom++;
						*b = '\0';
						tekst--;
					}
				}
			}
			tekst++;
		}
		tekst = vrati;
	}

return vrati;
}

int main() {
/*	char* rijeci[2] = { "beli", "sneg" };
    char* zamjene[2] = { "bijeli", "snijeg" };
    char tekst[100] = "beli sneg je pokrio beli breg";
  printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
*/
char* rijeci[2] = { "test" };
char* zamjene[2] = { "zamjena" };
char tekst[100] = "test protest testiranje protestiranje test";
printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 1));
	return 0;
}
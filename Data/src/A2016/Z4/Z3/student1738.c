#include <stdio.h>

void pomocna_fun(char *s,char *rijec,char *z){
	int zamijeni,duzina_prve,duzina_druge = 0,pomjeri;
		char *a,*b, *pocetak = s;
		while(*s != '\0'){
				zamijeni = 1;
				a = s;
				b = rijec;
				duzina_prve = 0;
				while(*b != '\0'){
					if(*b != *a)zamijeni = 0;
					a++; b++; duzina_prve++;
					if(zamijeni == 0)break;
				}
				if(zamijeni == 1){
					duzina_druge = 0;
					b = z;while(*b != '\0'){b++; duzina_druge++;}
					if((pocetak == s || *(s - 1) == ' ')  && (*a == ' ' || *a == '\0')){		
							if(duzina_druge >= duzina_prve){
								pomjeri = duzina_druge - duzina_prve;
				          	a--;
							b = a;
							while(*b != '\0')b++;
							while(b != a){	*(b + pomjeri) = *b; b--;}
							b = z;
							while(*b != '\0')*s++ = *b++;
							}
						
						else {
							b = z;
							while(*b != '\0')*s++ = *b++;
							a = s;
							b = s;
							while(*a != ' ' && *a != '\0')a++;
							while(*b++ = *a++);
						}
						s--;
					}
				}
			s++;
		}
}

char *zamjena_rijeci(char *tekst,char** rijeci,char **zamjene,int broj_rijeci){
	char* poc = tekst;
	int i = 0;
	while(i < broj_rijeci){
		pomocna_fun(tekst,rijeci[i],zamjene[i]);
		i++;	
}

return poc;
}

int main() {
char* rijeci[2] = { "auto", "stop" };
char* zamjene[2] = { "vozilo", "start" };
char tekst[100] = "auto-stop auto. stop auto kj stop";
printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}

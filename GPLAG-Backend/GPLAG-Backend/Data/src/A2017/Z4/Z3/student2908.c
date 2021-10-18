#include <stdio.h>

void unesi(char *s, int duzina){
	int znak = getchar();
	if(znak == '\n') znak = getchar();
	int i = 0;
	while(i < duzina - 1 && znak != '\n'){
		s[i] = znak;
		i++;
		znak = getchar();
	}
	s[i] = '\0';
}

void najduzi_bp(const char *s1, char *s2){
	/*const char *p = s1;
	const char *q = s1;*/
	const char *t = s1;
	//char *drugi = s2;
	char k[200];
	int hist[128] = {0},brojac = 0,neslovo = 1,br = 0,taj = 0;
	
	while(*t != '\0'){
		if(!((*t >= 'a' && *t <= 'z') || (*t >= 'A' && *t <= 'Z'))){
			if(taj)
			*drugi = '\0';
			char *provjera = k;
			while(*provjera != '\0'){
			br++;
			provjera++;
		}
		neslovo = 1;
		int i;
		for(i = 0; i < 128; i++){
			hist[i] = 0;
		}
	
		}
		else if(neslovo){
			neslovo = 0;
			brojac++;
		}
		else if((*t >= 'a' && *t <= 'z') || (*t >= 'A' && *t <= 'Z')){
		
			char *drugi = k;
			while((*t >= 'a' && *t <= 'z') || (*t >= 'A' && *t <= 'Z')){
			const char *p = t;
			if(*p >= 'A' && *p <= 'Z')
				hist[*p]++;
			else if(*p >= 'a' && *p <= 'z')
				hist[(*p)-32]++;
				
				if(hist[*p] == 1 || hist[(*p)-32] == 1){
					*drugi=*p;
					drugi++;
				}
				else{
				*drugi = '\0';
				taj = 1;
				break;
				}
				t++;
			}
			
	}
	t++;
	
	}

}
int main() {
	char tekst1[500], tekst2[27];
	
	printf("Unesite neki tekst: ");
	unesi(tekst1,500);
	
	najduzi_bp(tekst1,tekst2);
	printf("-%s",tekst2);
	//printf("Z adaća 4, Zadatak 3");
	return 0;
}

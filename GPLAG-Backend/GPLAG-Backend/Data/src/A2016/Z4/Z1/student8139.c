#include <stdio.h>

/*void unesi(char niz[], int velicina){
	char znak =  getchar();
	if(znak == '\n') znak = getchar();
	int i=0;
	while(i < velcina-1 && znak != '\n'){
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}*/

int prebroji(char* s1, char* s2){
	int br=0;
	char* p = s1;
	while(*p != '\0'){
		char *q = s2;
		while(*p == *q || *p == *q + 32 || *p == *q - 32){
			p++;
			q++;
			if(*q == '\0' && (*p < 'A' || *p > 'z')){
				br++;
				break;
			}
		}
		p++;
		
	}
	return br;
}

char* izbaci_najcescu(char *s){
	char* pok = s;
	int i=0, max=1;
	char najmnogobrojnijichartrenutni[100];
	/*char** pokazivaci[100];
	for(i=0; i<100; i++) pokazivaci[i]=NULL;*/
	int brojac[100];
	for(i=0; i<100; i++) brojac[i]=1;
	for(i=0; i<100; i++){
		char rijec[100];
		int j=0;
		if(*pok < 'A' || *pok > 'z') s++;
		while(!(*pok <'A'  || *pok > 'z')){
			rijec[j] = *pok;
			j++;
			pok++;
		}
		rijec[j] = '\0';
		brojac[i]+=prebroji(pok,rijec);
		/*//printf("rijec: %s\n", rijec);*/
		if(brojac[i]>max){
			max=brojac[i];
			int k=0;
			while(rijec[k] != '\0'){
				najmnogobrojnijichartrenutni[k] = rijec[k];
				k++;
			}
			najmnogobrojnijichartrenutni[k] = '\0';
		}
	}
	/*//printf("(najmnogobrojnijichartrenutni: %s)", najmnogobrojnijichartrenutni);
	
	printf("brojaci: ");
	for(i=0; i<100; i++) printf("%d ", brojac[i]);*/
	
	return pok;
}

int duzina(char* s){
	int duz=0;
	while(*s!='\0'){
		duz++;
		s++;
	}
	return duz;
}

void izbaci(char* s1, char* s2){
	while(*s1 != '\0'){
		char *poc = s1;
		if(*s1 != *s2){
			s1++;
			continue;
		}
		else{
			while(*s1 ==  *s2){
				s1++;
				s2++;
				if(*s2 == '\0'){
					while(*(poc+duzina(s2)+1) != '\0'){
						*poc = *(poc+duzina(s2)+1);
						poc++;
					}
					*poc = '\0';
				}
			}
		}
	}
}

int main() {
	char string1[] = "Pet plus pet plus pet daje plus plus petnaest";
	char string2[] = "plus";
	/*char string2[100];
	char* pok=string1;
	int i=0;
	if(*pok < 'A' || *pok > 'z') pok++;
	while(!(*pok < 'A' || *pok > 'z')){
		string2[i] = *pok;
		i++;
		pok++;
	}
	string2[i]='\0';
	printf("prebrojano: %d\n", prebroji(string1, string2));
	printf("string2: %s", string2);
	char* pomoc= izbaci_najcescu(string1);*/
	izbaci(string1, string2);
	printf("String: %s", string1);
	return 0;
}

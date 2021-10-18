#include <stdio.h>

char maloslovo(char slovo){
	if(slovo<='Z' && slovo>='A') return slovo + 'a' - 'A';
	else return slovo;
}
char* delete_word(char *s, const char *word) {
   
	int i = 0,index = 0, nasao = 0;
	char* povratna = s;
	int prvaRijec = 0;
	while(*s != '\0'){
		if(maloslovo(*s) == *word && (prvaRijec == 0 || !(s[-1] <= 'z' && s[-1] >='a' )|| (s[-1] <='Z' &&s[-1]>='A'))){
			i = 0;
			
			prvaRijec = 1;
			while(((s[i] <= 'z' && s[i] >='a' )|| (s[i] <='Z' &&s[i]>='A')) && word[i] != '\0' && maloslovo(s[i])== word[i]){
					i++;
			}
			if(word[i] == '\0' && !((s[i] <= 'z' && s[i] >='a' )|| (s[i] <='Z' &&s[i]>='A'))){
				nasao = 1;
				index = 0;
				while(s[i + index] != '\0'){
					s[index] = s[i + index];
					index++;
				}
				s[index] = s[i + index];
				return povratna;
			} else  {
				s+=i;
			
			}
			
		}
		s++;
		
	}
	if(nasao == 0) return NULL;
    return povratna;
}

char* izbaci_najcescu(char *s) {
	
	if(*s == '\0') return s;
	int br = -1, k, i = 0;
	char *pocetak = s;;
	char rijeci[100][100];
	while(s[i] != '\0'){
		if((s[i] <= 'z' && s[i] >='a' )|| (s[i] <='Z' &&s[i]>='A')){
			br++;
			k = 0;
			while((s[i+k] <= 'z' && s[i+k] >='a' )|| (s[i+k] <='Z' &&s[i+k]>='A')){
				rijeci[br][k] = s[i+k];
				if(rijeci[br][k] <= 'Z' && rijeci[br][k] >='A') {
					rijeci[br][k]+= 'a' - 'A';
				}
				k++;
			}
			rijeci[br][k] = '\0';
			i+=k;
		} else {
			i++;
		}
	}
//	for(i = 0; i <= br; i ++){printf("%s|\n",rijeci[i]);}
	int najcescaRijec = 0,ponavljanje = -1, j;
	for(i = 0; i <= br; i++){
		int trenutnoPonavljanje = 0;
		for(k = i + 1; k <= br; k++){
			
			j = 0;
			while(rijeci[i][j] != '\0' && rijeci[k][j] != '\0' && rijeci[i][j] == rijeci[k][j]){
				j++;
			}
			if(rijeci[i][j] == '\0' && rijeci[k][j] == '\0'){
				trenutnoPonavljanje++;
			}
		}
		if(trenutnoPonavljanje > ponavljanje){
			najcescaRijec = i;
			ponavljanje = trenutnoPonavljanje;
		}
	}
	if(ponavljanje == -1) return pocetak;
	while(delete_word(s,rijeci[najcescaRijec]) != NULL){}
	return pocetak;
}

int main() {

char t[10] = "";
izbaci_najcescu(t);
printf("%d '%s'", t[0], t);

return 0;
}

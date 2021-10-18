char* ubaci_broj(char *tekst, int broj){
	char s[]="-123";
	int duzina = strlen(s)-1;
	while(*tekst != '\0'){
		if(*tekst == ' '){
			char* kraj = tekst;
			while(*kraj != '\0')
			kraj++;
			while(kraj > tekst){
				*(kraj+duzina) = *kraj;
				kraj--;
			}
			char* p = s; 
			while(*p != '\0')
			*s++ = *p++;
		}
		s++;
	}
}

int main() {
	printf("Zadaća 4, Zadatak 1");
	return 0;
}

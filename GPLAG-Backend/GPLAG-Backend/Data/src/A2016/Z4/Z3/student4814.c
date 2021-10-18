#include <stdio.h>

int duzina_rijeci(char *str){
	char *p;
	for(p=str; *p!='\0'; p++);
	return p-str;
}
char *kopiraj(char *drugi, char *izvorni){
	char *prvi=drugi;
	while((*drugi++ = *izvorni++)!='\0');
	return prvi;
}
char *podstring(char *s2, char *s1){
	int i=0,j;
	int pomocna=0;
	if(s2==NULL || s1==NULL) return NULL; /*null pokazivac*/
	for(i=0; s2[i]!='\0'; i++){
		
		if(s2[i]==s1[0] && (i==0 || s2[i-1]==' ') && (s2[i+duzina_rijeci(s1)]==' '|| s2[i+duzina_rijeci(s1)]=='\0')) {
			for(j=i; ; j++){
				if(s1[j-i]=='\0'){
					pomocna=1;
					break;
				}
				if(s2[j]==s1[j-i]) continue;
				else break;
			}
		}
			if(pomocna==1) break;
	}
	if(pomocna) return(s2+i);
	else return NULL;
}
char *prepisi(char *recenica, const char *izvor){
	kopiraj(recenica+duzina_rijeci(recenica), izvor);
	return recenica;
}
char *kopiraj_n_karaktera(char *novi, const char *izvor, int n){
	int i;
	char *temp;
	temp=novi;
	for(i=0; i<n; i++) 
	*novi++=*izvor++;
	return temp;
}
void zamijeni (char string[], char original[], char zamjene[]){
	char pomocni[1000];
	char *p=string;
	while((p=podstring(p,original))){
		kopiraj_n_karaktera(pomocni,string, p-string);
		pomocni[p-string]='\0';
		prepisi(pomocni,zamjene);
		prepisi(pomocni, p+duzina_rijeci(original));
		kopiraj(string,pomocni);
		p++;
	}
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char *p=tekst;
	int i;
	for(i=0; i<broj_rijeci; i++)
	zamijeni(tekst, rijeci[i], zamjene[i]);
	return p;
}

int main() {
	char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}

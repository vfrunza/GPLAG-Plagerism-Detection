#include <stdio.h>
void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
int provjeri_duzine(char* s1, int niz[], int duzina){
	int brojac=0, i=0, p=0, brojac1=0;
	char* tmp=s1;
	while(*s1!='\0'){
		if((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')){
			if(p==0){
				brojac1++;
				p=1;
			}
		} 
		else{
				p=0;
			}
		s1++;
	}
	if(brojac1!=duzina) return 0;
	s1=tmp;
	for(i=0; i<duzina; i++){
		while(*s1!='\0'){
			if((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')){
				brojac++;
			}
			if(!((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))){
				if(brojac!=0){
					if(brojac!=niz[i]) return 0;
					else{
						brojac=0;
						s1++;
						break;}
					}
			
			}
			s1++;
		
		}
	}
	return 1;
}

int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}

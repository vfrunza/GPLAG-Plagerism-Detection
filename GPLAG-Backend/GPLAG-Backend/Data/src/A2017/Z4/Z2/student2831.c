#include <stdio.h>

void unesi (char niz [],int velicina) {
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar(;)
	}
	niz[i]='\0';
}


char* s provjeri_duzine(char* s, niz[], int vel) {
	
	char *p=s;
	int i;
	int br=0,prekid=1;
	
	while(*s!='\0'){
		
		
		if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
			
			br++;
		}
		else if(br>0){
			if(s+1>vel) return 0;
			
			
			
		}
		
	}
}
int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}

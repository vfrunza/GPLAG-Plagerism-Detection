#include <stdio.h>


void unesi (char niz[], int velicina) {
	char znak = getchar();
	if(znak == '\n') znak = getchar();
	int i = 0;
	while(i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}


int provjeri (char niz[]) {
    char * p = niz;
    char * q = niz;
    
    while(p < 300){
    	if(*p == '<'){
    		p++;
    		for(p; ; p++) {
    			if(*p)
    		}
    	}
    }
}


int main() {
	char niz[300];
	
	printf("Unesite HTML kod:\n");
	
	unesi(niz, 300);
	
	provjeri(niz);
	
	return 0;
}

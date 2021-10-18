#include <stdio.h>

void najduzi_bp(char* s1, char* s2){
	char* poc, *kraj;
	poc=s1;
	kraj=s1;
	while(*kraj!=' ' && *kraj!='\0'){
		kraj++;
		//ovim je izdvojena rijec
		if(*kraj)
	}
}

int main() {
	char niz[10];
    najduzi_bp ("Ovo je neki primjer teksta", niz);
    printf ("Niz: '%s'", niz);
	return 0;
}

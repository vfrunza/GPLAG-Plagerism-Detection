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

void najduzi_bp8 (char *s1, char *s2){
	
	
	
}

int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}

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

int provjeri_duzine(char *tekst,int niz) {
	int niz_tekst[0],duzina=0;
	
	while(*tekst!='\0') {
		
		
		
		
		tekst++;
	}
	
	
	
}

int main() {
	char tekst[100];
	int niz[10],i;
	
	printf("Unesite tekst: ");
	unesi(tekst,100);
	
	printf("Unesite niz: ");
	for(i=0;i<10;i++) {
		scanf("%d",&niz[i]);
	}
	
	return 0;
}

#include <stdio.h>

void unesi(char niz[], int velicina) {
    int i = 0;
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

int provjeri_duzine (char *s, int *niz) {
	char* poc = s;
	int brojac = 0, i, stat=0;
	int *poknaniz = niz, poknabrojac = brojac;
	while (*s != '\0') {
		s++;
	    brojac++;
	    while (*s == ' ') {
	    	for (i=0; i<*poknaniz ; i++) {
	        	if (*poknaniz == poknabrojac) {
	        		stat = 1;
	        	}
	    	}
	    	poknaniz++;
		}
	}
	*s = '\0';
	
	return stat;
}

int main() {
	char a[100];
	int niz[] = {3, 2, 4, 7, 6};
	printf ("Unesite neku recenicu:\n");
	unesi(a, 100);
	printf ("Recenica sadrzi %d znakova", provjeri_duzine(a,niz));
	return 0;
}

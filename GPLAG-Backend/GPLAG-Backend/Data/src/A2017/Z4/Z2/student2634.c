#include <stdio.h>

void unesi (int niz [], int velicina) {
	char znak = getchar ();
	if (znak == '\n') znak = getchar ();
	int i = 0; 
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}


int provjeri_duzine (char* s, int* niz, int n) {
	int duzina_rijeci=0;
	int broj_rijeci=0;
	char* p = s;
	int redni_broj=0;
	char* p2 = s;
	while (*p != '\0') {
		if ((p==s && ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))) || (p!=s && (((*p >= 'A' && *p <= 'Z') || (*p>='a' && *p <= 'z'))) && (*(p-1)<'A' || (*(p-1)>'Z' && *(p-1)<'a') || *(p-1)>'z'))) {
			duzina_rijeci=0;
			broj_rijeci++;
			p2=p;
			while ((*p2 >= 'A' && *p2 <= 'Z') || (*p2 >= 'a' && *p2 <= 'z')) {
				duzina_rijeci++;
				p2++;
			}
			if ( duzina_rijeci != niz[redni_broj] ) return 0;
			redni_broj++;
	}
		p++;
	

}	
	if (broj_rijeci != n) return 0;
	return 1;
}


int main () {
	char tekst [1000]; 
	int niz[100];
	int n;
	printf ("Unesite tekst: ");
	unesi (tekst, 1000);
	provjeri_duzine (tekst, niz, n);
	return 0;
}
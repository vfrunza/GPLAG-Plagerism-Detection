#include <stdio.h>


void unesi (char niz[], int velicina){
	char znak=getchar();
	if (znak=='\n') znak=getchar();
	int i=0;
	while (i<velicina-1 && znak!= '\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int izbroji (char *niz){
	int n=0;
	char *o;
	o=niz;
	while (*o!='\0'){
		n++;
		o++;
	}
	return n;
}

int trazi_rijec (char *tekst, char *rijec){
	char *p, *q, *z, *s;
	z=tekst;
	s=tekst;
	p=tekst;
	q=tekst;
	while (*s!='\0'){
		p=s;
		q=rijec;
		while (*p++ == *q++)
		if (*q=='\0' && (s==z || *(s-1)==' ') && (*p==' ' || *p=='\0')) 
		return 1;
		s++;
	}
	return 0;
}

char* zamjena_rijeci (char* tekst, char** rijec, char** zamjene, int broj_rijeci){
	
}

int main() {
	char tekst [100];
	char *rijeci[2]={"beli", "sneg"};
	char *zamjene[2]={"bijeli", "snijeg"};
	printf ("Unesite tekst:\n");
	unesi (tekst,100);
	zamjena_rijeci (tekst, rijeci, zamjene, 2);
	printf ("%s", tekst);
	
	
	
	
	
	return 0;
}

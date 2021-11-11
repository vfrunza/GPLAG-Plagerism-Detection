#include <stdio.h>

void unesi(char *niz, int velicina) {
	
	int i = 0;
	char znak = getchar();
	if(znak == '\n') znak = getchar();
	
	while(i < velicina-1 && znak!='\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

void izbaci_H(char *s) {
	char *i = s;
	char *j = s;
	
	while(*j!='\0') {
		*i = *j;
		j++;
		if(*i!='H') {
			i++;
		}
	}
	*i = '\0';
}

char* kodiraj(char* s1, char* s2) {
	
	int temp_niz[101], niz_brojac[100], i=0, j=0, k=0, max, spasi,brojevi[100];
	char niz[101],aski[100],a;
	char *r, *z, *p;
	
	r=s1;
	while(*r!='\0') {
		niz[i] = *r;
		i++;
		r++;
	}
	niz[i]='\0';
	z=niz;
	
	for(i=0; i<100; i++) { 
		temp_niz[i] = 1;
	}
	
	while(*z!='\0') {
		p=z+1;
		while(*p!='\0') {
			if(*z==*p && *z!='H') {
				temp_niz[j]++;
				*p = 'H';
			}
			else if(*z=='H') {
				temp_niz[j] = -1;
				
			}
			p++;
		}
		j++;
		z++;
	}
	izbaci_H(niz);
	
	for(i=0; i<j; i++) {
		if(temp_niz[i]!=-1) {
			niz_brojac[k] = temp_niz[i];
			k++;
		}
	}

	z = s2;
	for(i=0; i<k; i++) {
		max = 0;
		for(j=0; j<k; j++) {
			if(max<niz_brojac[j]) {
				max = niz_brojac[j];
				spasi = j;
			}
		}
		brojevi[i]=niz_brojac[spasi];
		niz_brojac[spasi] = -1;
		*z = niz[spasi];
		z++;
	}
	*z='\0';
	
	z=s2;
	for(j=0;j<k;j++){
		niz[j]=*z;
		z++;
	}
	z=s2;
	for(i=0;i<(k);i++){
		for(j=i+1; j<(k); j++){
			if(brojevi[i]==brojevi[j] && niz[i]>niz[j] && niz[j]!='\0'){
				a=niz[i];
				niz[i]=niz[j];
				niz[j]=a;
			}
		}
	}
	
	for(i=0; i<k; i++){
		*z=niz[i];
		z++;
	}
	*z='\0';
	z=s2;
	
	aski[0]=' ';
	r=aski;
	z=s2;
	while(*r!='~'){
		z=s2;
		while(*z!='\0'){
			if(*z==*r){
				if(*r=='~') break;
				
				(*r)++;
				z=s2-1;
			}
			z++;
		}
		
		if(*r=='~') break;
		
		r++;
		*r=*(r-1)+1;
		
	}
	r++;
	*r='\0';
	r=aski;
	z=s2;
	while(*z!='\0'){
		z++;
	}
	while(*r!='\0'){
		*z=*r;
		z++;
		r++;
	}
	*z='\0';
	
	/*KODIRANJE*/
	r=s1;
	z=s2;
	
	while(*r!='\0') {
		z=s2;
		while(*z!='\0') {
			if(*r==*z) {
				*r=126-(z-s2);
				break;
			}
			z++;
		}
		r++;
	}
	
	return s1;
}

char* dekodiraj(char* s1, char*s2) {
	char *r, *z;
	
	r=s1;
	z=s2;
	
	/*DEKODIRANJE*/
	while(*r!='\0') {
		z=s2;
		while(*z!='\0') {
			if(126-*r==z-s2) {
				*r = *z;
				break;
			}
			z++;
		}
		r++;
	}
	return s1;
}


int main() {
	
	char niz[100] = "LLMLNLNMONM", tablica[100];
	
	/*printf("Unesi text: ");
	unesi(niz, 97);*/
	/*kodiraj(niz, tablica);*/
	
	printf("%s", kodiraj(niz, tablica));
	
	
	return 0;
}

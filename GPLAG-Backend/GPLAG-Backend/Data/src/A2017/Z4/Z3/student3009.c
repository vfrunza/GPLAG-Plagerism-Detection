#include <stdio.h>
void najduzi_bp(char*s1,char*s2){
	char* tekst=s1;
	char* kraj=s1;
	int brojac[10]={0},i=0;
	int slovo=0,broj=0;
	while (*tekst!='\0'){
		char*zapamti=tekst;
		slovo=0;
		while ((*tekst >='A' && *tekst<='Z') || (*tekst>='a' && *tekst<='z')){
		slovo=1;
		
		tekst++;
		}
		kraj=tekst;
		if (slovo==1){
			broj=0;
				tekst--;
			while (zapamti<=kraj){
				char*zapamti2=zapamti;
			while (*zapamti2!=*(zapamti2+1) && zapamti2<=kraj){zapamti2++;}
			zapamti++;
	broj++;

			}
		brojac[i]=broj;
			zapamti++;
			i++;
		}
		tekst++;
	}
	
	int j;
	int max;
	max=0;
	for (j=0;j<i;j++) {
		if (brojac[j]>max) max=j;
	}
	int max_rijeci;
	max_rijeci=1;
	char*m=s1;
	

	int temp=0;
	char*pocetak_maxa;
	while (*m!='\0'){
		temp=0;
		pocetak_maxa=m;
		while ((*m>='A' && *m<='Z')||(*m>='a'&&*m<='z')) {
			m++;
			temp=1;
			
		}
		if (temp==1){
			
			
			if ((max_rijeci)==max) break;
			max_rijeci++;
			m--;
		}
		m++;
	}
	int k;
	for (k=0;k<brojac[max];k++){
		char b;
		b=*pocetak_maxa;
		*s2=b;
		s2++;
		pocetak_maxa++;
	}
	*(s2-1)='\0';
	
}
int main() {
	printf("Zadaća 4, Zadatak 3");
	        char niz[10];
        najduzi_bp ("Ovo je neki primjer teksta", niz);
        printf ("Niz: '%s'", niz);
	return 0;
}


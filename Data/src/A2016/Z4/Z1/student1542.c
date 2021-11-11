#include <stdio.h>

char* izbaci_najcescu(char* s)
{
	char *p=s,*p2,*pok=s,*kraj,*pocetak,pomocni_niz[50][50]={" "};
	int broj_ponavljanja[50];
	int brojac=0,i=0,j=0,z=0,max=0,pozicija=0,duzina=0;
	while(*p!='\0'){
		
		while(*p>='A'&& *p<='z'){
		pomocni_niz[i][j]=*p;
			p++;j++;
		}
		pomocni_niz[i][j]='\0';
		if(*p!='\0')p++;
		i++;j=0;
	}
	
	for(j=0;j<i;j++){
		p2=pomocni_niz[j];
		while (*pok != '\0') {
		while (*pok == ' ') pok++;
		char* p = pok;
		char* q = p2;
		while (*p!='\0' && *q!='\0' && (*p == *q || *p+32==*q || *p==*q+32) ){
			p++;q++;
			if (*q == '\0' && (*p == ' '||*p == '\0' || *p<'A' || *p>'z' )) brojac++;
		}
		pok++;
		}
		broj_ponavljanja[j]=brojac;
		brojac=0;
		pok=s;
	}
	for(z=0; z<j; z++){
		if(max<broj_ponavljanja[z]){
			max=broj_ponavljanja[z];
			pozicija=z;
			
		}
	}
		
	pok=s;
	while (*pok != '\0') {
		p2=pomocni_niz[pozicija];
		while (*pok == ' ') pok++;
		char* p = pok;
		char* q = p2;
		while (*p!='\0' && *q!='\0' && (*p == *q || *p+32==*q || *p==*q+32) ){
			p++;q++;duzina++;
			if (*q == '\0' && (*p == ' ' || *p=='-' ||*p == '\0')){
				if(*p!='\0')kraj=p;
				pocetak=p-duzina;
				while (*pocetak++ = *kraj++);
				*pocetak='\0';
			}   
		}
		pok++;
		duzina=0;
		}
	return s;
}
int main() {
	char text[1000];
	int i=0,velicina=1000;
	char znak;
	printf("Unesite neki text: ");
	znak = getchar();
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		text[i] = znak;
		i++;
		znak = getchar();
	}
	text[i]='\0';
	printf("%s",izbaci_najcescu(text));
	return 0;
}

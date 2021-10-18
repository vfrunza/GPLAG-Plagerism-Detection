#include <stdio.h>

void unesi(char niz[], int velicina){
	int i=0;
	char znak=getchar();
	if(znak=='\n')znak=getchar();
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int duzina_rijeci(char* s){
	int brojac=0;
	while( (*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
		brojac++;
		s++;
	}
	return brojac;
}

int broj_rijeci(char* s){
	int brojac=0;
	char* pomocni=s;
	while(*pomocni!='\0'){
		if((*pomocni>='A' && *pomocni<='Z') || (*pomocni>='a' && *pomocni<='z')){
		while((*pomocni>='A' && *pomocni<='Z') || (*pomocni>='a' && *pomocni<='z')) pomocni++;
		if(!(*pomocni>='A' && *pomocni<='Z') || (*pomocni>='a' && *pomocni<='z')) brojac++;
		pomocni--;
		
		}
		pomocni++;
	}
	return brojac;
}

int provjeri_duzine(char* s, int niz[],int vel){

	if(broj_rijeci(s)!=vel || duzina_rijeci(s)!=niz[0]) return 0;
	else return 1;
	
}   
    int main() {
	int i,n;
	int niz1[100];
	char niz[100];
	printf("Unijeti string: ");
	unesi(niz,100);
	printf("Unijeti velicinu niza: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&niz1[i]);
	}
	printf("%d",provjeri_duzine(niz,niz1,n));
    return 0;
}

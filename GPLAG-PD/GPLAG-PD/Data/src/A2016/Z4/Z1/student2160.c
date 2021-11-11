#include <stdio.h>
void unesi(char niz[],int velicina){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
	niz[i]=znak;
	i++;
	znak=getchar();
    }
  niz[i]='\0';
}

char *izbaci_najcescu(char *s){
	char *pok=s;
	int razmak=1,broj_rijeci=0;
	while(*s!='\0'){
		if(!((*s<='A' && *s>='Z') || (*s>='a' && s<='z')))
		razmak=1;
		else if (razmak=1){
			razmak=0;
			broj_rijeci++;
		}
	s++;
} 
	char *p=s;
	while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')){
		broj_rijeci++;
		p++;
	}
	char *q=s;
	q+= broj_rijeci;
	while(*q!='\0'){
		*s=*q;
		q++;
		
		s++;
	}
	*s='\0';
	return pok;
}
 
	
int main() {
	
	char niz[100];
	unesi(niz,100);
	printf("%s",izbaci_najcescu(niz));
	return 0;
}

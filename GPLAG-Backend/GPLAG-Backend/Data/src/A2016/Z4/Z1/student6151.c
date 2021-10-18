#include <stdio.h>

void unesi(char niz[],int velicina){
	char znak= getchar();
	if(znak=='\n') znak=getchar();
	
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
			znak=getchar();
	}
	niz[i]='\0';
}

int iste(char *s,char *kraj1,char*poc,char*kraj2){
	if(kraj2-poc!=kraj1-s) return 0;
	
	while(s!=kraj1){
		if(*s!=*poc) return 0;
		s++;
		poc++;
	}
	return 1;
}


char* izbaci_najcescu(char* s){
	char* kraj1=s;
	int brojac[100]={0};
	int i;
	char *max;

		for(i=0;i!='\0';i++){
		
	while(*kraj1!='\0' && *kraj1!=' '){
	kraj1++;
	}
	
	char* poc=kraj1+1;
	while(*poc!='\0' && *poc!=' '){
		poc++;
	}
	char* kraj2=poc;
	
	if(iste(s,kraj1,poc,kraj2))
	brojac[i]++;
	max=brojac[i];
	if(brojac[i+1]>brojac[i]) max=brojac[i+1];

	s++;
	}
	
/*	char nova[100];
	char *n=nova;
	
	while(*s!='\0'){
		while(*s!='\0' && *s!=' '){
			if(*s==*max){
				while(*s==*max){
					s++;
					max++;
				}
			}
			*n++=*s++;
		}
		*n++=*s++;
	}
	*n='\0';
	*/
	return s;
}

int main() {
	
	char niz[100];
	char*nova[100];
	char*p=nova;
	
	printf("Unesi tekst: ");
	unesi(niz,100);
/*	p=izbaci_najcescu(niz);
	
	while(*p!='\0')
	printf("%c",*p++);
	*/
	
	printf("%s",izbaci_najcescu(niz));
	return 0;
}

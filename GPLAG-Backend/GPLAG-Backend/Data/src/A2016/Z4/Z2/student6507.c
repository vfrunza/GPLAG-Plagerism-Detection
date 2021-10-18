#include <stdio.h>

char* kodiraj(char* s, char* q){
	char* t=s;
	char *p=s;
	char* x=q;
	int brojac[95]={0}, max=0, i, j;
	while(*t != '\0'){
		for(i=0; i<95; i++){
				if((i+32)==*t) brojac[i]++;
			}
		t++;
	}

	for(i=0; i<95; i++){
		max=i;
		if(brojac[i]==0) continue;
		for(j=0; j<95; j++){
			if(brojac[j]>brojac[max]) max=j;
			if((brojac[j]==brojac[max]) && max>j) max=j;
			
		}
		*q++=max+32;
		brojac[max]=-1;
	}
	
	for(i=0; i<95; i++){
		if(brojac[i]==0) *q++=i+32;
	}
	*q='\0';
	
	while(*p != '\0'){
		for(i=0; i<95; i++){
			if(*p==*(x+i)) {
				*p=126-i;
				break;
			}
		}
		p++;
	}
	return s;
}
	
char* dekodiraj(char* s, char* q){
	char* p=s;
	char* x=q;
	int i;
	while(*p != '\0'){
		for(i=0; i<95; i++){
			if(*p==126-i) {
				*p=*(x+i);
				break;
			}
		}
		p++;
	}
	
	
return s;
}

int main() {
	char niz[]="Jeste li dobro kreirali sifrarnik?", prazan[100]="";
	kodiraj(niz,prazan);
	printf("\n%s\n", prazan);
	printf("\n%s", niz);
	return 0;
}

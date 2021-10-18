#include <stdio.h>

	char* ubaci_broj (char* tekst, int broj){
		char *p=tekst, *q, *r;
		int tmp=broj, i=0, j=0, *niz[12];
		do{
			i++;
			tmp=tmp/10;
		}while(tmp!=0);
		for(j=0; j<i; j++);
		do{
			niz[j]=broj%10+'0';
			j--;
		}while(broj!=0 && j!=0);
		while(*p!='\0'){
			if(*p==' '){
				q=p+1;
			}
			if(!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))){
				q=p;
			}
			r=q;
			while(*r!='\0') r++;
			while(r>q){
				*(r+i)=*r;
				r--;
			}
			while(j<i){
				*q++=*niz++;
			}
			*q='\0';
			p++;
		}
		return tekst;
	}

int main() {
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
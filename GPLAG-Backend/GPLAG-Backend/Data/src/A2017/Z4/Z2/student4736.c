#include <stdio.h>

int daLiJeSlovo(char z){
	if( (z>='A'&&z<='Z') || (z>='a'&&z<='z')) return 1;
	return 0;
}


int provjeri_duzine(char*s,int duzine[],int velicina){
	int duzina;
	int i=0;
	while (*s!='\0') {
		
		if(daLiJeSlovo(*s)){
			duzina=1;
			++s;
			while(daLiJeSlovo(*s)){
				duzina++;
				s++;
			}
			s--;
			if(i==velicina)return 0;
			if(duzine[i++]!=duzina)return 0;
			
			
		}
		
		s++;
	}
	
	if(velicina>i)return 0;
	
	return 1;
}

int main() {
	char t[1000]="Ovo je neki primjer teksta";
	int d[]={3,2,4,7,6,8};
	if(provjeri_duzine(t,d,6)){
		printf("OK!");
	}
	else{
		printf("NIJE OK!");
	}
	return 0;
}

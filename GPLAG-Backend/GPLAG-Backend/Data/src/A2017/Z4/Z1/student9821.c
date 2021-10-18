#include <stdio.h>



char *ubaci_broj(char str[],int velicina){
	char *p=string;
	int broj_cirfi=0;
	int istina=0;
	if(velicina>0)istina=1;
	if(velicina<0)istina=0;
	/* TRAZI BROJ CIFRI U BROJU*/
	if(istina==1){
		int temp=velicina;
		while(temp!=0){
			broj_cirfi++;
			temp/=10;
		}
	
		while(*str==' ')str++;
	
		while(*str!='\0'){
			while(*str!=' ')str++;
			if(*str==' '){
				s++;
			}
		}
	}	
	return p;
}

int main() {
	printf("Zadaća 4, Zadatak 1");
	return 0;
}

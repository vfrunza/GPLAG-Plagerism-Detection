#include<stdio.h>

void najduzi_bp(char *s1, char *s2){
	int i=0;
	int brojac,najduzi;
	while(*(s1+i)!=0){
		
		najduzi=0;
		while((*(s1+i)>='A' && *(s1+i)<='Z') || (*(s1+i)>='a' && *(s1+i)<='z')){
			najduzi++;
			i++;
		}
		i++;
		break;
	}
	while(*(s1+i)!='\0'){
		brojac=0;
		while((*(s1+i)>='A' && *(s1+i)<='Z') || (*(s1+i)>='a' && *(s1+i)<='z')){
			brojac++;
			i++;
		}
		if(brojac>najduzi){
			najduzi=brojac;
		}
		i++;
	}
	i=0;
	while(*(s1+i)!='\0'){
		
	}
}
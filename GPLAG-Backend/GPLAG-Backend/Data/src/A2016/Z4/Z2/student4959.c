#include <stdio.h>
#define vel 95
char *kodiraj( char*string,char* tablica){
	int i,j,temp,a=0,b=0,c=0,max,hist[95]={0};
	char *resettab,*resetstr,ascii[vel],d;
	resettab=tablica;
	resetstr=string;
	for(i=0;i<vel;i++){
		d=i+32;
		ascii[i]=d;
	}
	while(string!='\0'){
		hist[(*string-32)]++;
		string++;
	}
	for(i=0;i<vel;i++){
		max=i;
		for(j=i+1;j<95;j++){
			if (hist[j]>hist[max]) max=j;
		} 
		
		temp=hist[i];
		hist[i]=hist[max];
		hist[max]=temp;
		temp=ascii[i];
		ascii[i]=ascii[max];
		ascii[max]=temp;
	}
	for(i=0;hist[i]!=0;i++){
		a++;}
	for(i=0;i<a;i++){
		
		tablica[i]=ascii[i];
	
		}
	for(i=a;i<vel;i++){
		d=b+32;
		for(j=0;j<a;j++){
			if(ascii[j]==d){
				c=1;
				i--;
				break;
			}
		}
    if(c!=1){
    	tablica[i]=d;
    }
    c=0;
    b++;
	}
	tablica[i]='\0';
	string=resetstr;
	tablica=resettab;
	while(string!='\0'){
		tablica=resettab;
	for(i=0;i<vel;i++){
		if(*string==*tablica){
			*string='~'-i;
			break;
		}
		tablica++;
		if(tablica=='\0') break;
	}
	string++;
	
	}
	string=resetstr;
	return resetstr;
}
char*dekodiraj(char *string,char*tablica){
	int i;
	char *resetstring,e[vel];
	resetstring=string;
	for(i=0;i<vel;i++){
		e[i]='~'-i;
	}
	while(*string!='\0'){
		for(i=0;;i++){
			if(*string==e[i]){
				*string=tablica[i];
				break;
			}
		}
		string ++;
	}
	
	
	
	
	return resetstring;
}
int main() {
	
	return 0;
}

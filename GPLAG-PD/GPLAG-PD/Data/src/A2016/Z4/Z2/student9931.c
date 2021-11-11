#include <stdio.h>
#include <stdlib.h>
char *kodiraj(char *string,char *tablica){
	int i,j,temp,n=0,k=0,flag=0,max,histogram[95]={0};
	char *resetstring,*resettablica,ascii[95],karakter;
	resetstring=string;
	resettablica=tablica;
	for(i=0;i<95;i++){
		karakter=i+32;
		ascii[i]=karakter;
	}
	while (*string!='\0') {
		histogram[(*string-32)]++;
		string++;
	}
	for(i=0;i<95;i++){
		max=i;
		for(j=i+1;j<95;j++){
			if(histogram[j]>histogram[max])
			max=j;
		}
		temp=histogram[i];
		histogram[i]=histogram[max];
		histogram[max]=temp;
		temp=ascii[i];
		ascii[i]=ascii[max];
		ascii[max]=temp;
	}
	for(i=0;histogram[i]!=0;i++){
		n++;
	}
	for(i=0;i<n;i++){
		tablica[i]=ascii[i];
	}
	for(i=n;i<95;i++){
		karakter=k+32;
		for(j=0;j<n;j++){
			if(ascii[j]==karakter){
				flag=1;
				i--;
				break;
			}
		}
		if(flag!=1){
			tablica[i]=karakter;
		}
		flag=0;
		k++;
	}
	tablica[i]='\0';

string=resetstring;
tablica=resettablica;
while(*string!='\0'){
	tablica=resettablica;
	for(i=0;i<95;i++){
		if(*string==*tablica){
			*string='~'-i;
			break;
		}
		tablica++;
		if(tablica=='\0') break;
	}
	string++;
}
string=resetstring;
return resetstring;
}
char *dekodiraj(char *string,char *tablica){
	int i;
	char *resetstring,equivalent[95];
	resetstring=string;
	for(i=0;i<95;i++){
		equivalent[i]='~'-i;
	}
	while (*string!='\0'){
		for(i=0;;i++){
			if(*string==equivalent[i]){
				*string=tablica[i];
				break;
			}
		}
		string++;
	}
	return resetstring;
}
int main(){
	
	return 0;
}
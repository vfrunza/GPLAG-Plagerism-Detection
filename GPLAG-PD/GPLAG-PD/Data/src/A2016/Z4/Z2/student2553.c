#include <stdio.h>
char* kodiraj(char *string,char tablica[96]){
	int znakovi[97]={0},i,max,*p,kraj=0,pozicija=97;
	char *temp=string,*temptab=tablica;
	p=znakovi;
	while(*string!='\0'){
		znakovi[*string-32]++;
		string++;
	}
	while(kraj==0){
		
		max=0;
		kraj=1;
		for(i=0;i<96;i++){
			if(znakovi[i]>max){max=znakovi[i];  pozicija=i;}
			
			if(max!=0){ kraj=0;}
		}
		znakovi[pozicija]=-1;
		if(max!=0){
			*tablica=(char)(pozicija+32);
			tablica++;
		}
	}
	p=znakovi;
	for(i=0;i<95;i++){
		if(*p==0){
			*tablica=(char)(i+32);
			tablica++;
		}
		p++;
	}
	*tablica='\0';
	tablica=temptab;
	string=temp;
	pozicija=0;
	
	while(*string!='\0'){
		tablica=temptab;
		pozicija=0;
		while(*string!=*tablica && *tablica!='\0'){tablica++; pozicija++;}
		*string=(char)(126-pozicija);
		string++;
	}
	string=temp;
	return string;
}
char* dekodiraj(char *string,char *tablica){
	char *temp=string;
	char zamijeni=*string;
	int max=0,i;
	int tabela[96]={-1};
	int checked[96]={0};
	int x=1;
	
	
	
	while(*string!='\0'){
		checked[*string-32]++;
		string++;
	}
	max=0;
	do{
		max=0;
		for(i=0;i<96;i++){
			if(checked[i]>=max)
				max=checked[i];
		}
		for(i=95;i>=0;i--){
			if(checked[i]==max){
				zamijeni=i+32;
				break;
			}
		}
		tabela[zamijeni-32]=*tablica;
		checked[zamijeni-32]=0;
		tablica++;
		x=1;
		for(i=0;i<96;i++){
			if(checked[i]!=0)x=0;
		}
	}while(x==0);

	string=temp;
	while(*string!='\0'){
		*string=tabela[*string-32];
		string++;
	}
	

	
	return temp;
}
int main() {
	char string[]="";
	char kodovoi[100]="";
	
	kodiraj(string,kodovoi);
	printf("%s",string);
	printf("\n");
	printf("%s\n",kodovoi);
	
	dekodiraj(string,kodovoi);
	printf("%s",string);
	return 0;
}

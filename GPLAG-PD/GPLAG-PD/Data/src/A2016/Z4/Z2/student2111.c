#include <stdio.h>
char* kodiraj(char* s,char tablica[96]){
int znakovi[97]={0},*d,end=0,poz=97, max,i=0;
char* temp=s;
char* tmptab=tablica;
d=znakovi;
while(*s!='\0'){
	znakovi[*s-32]++;
	s++;
}
while(end==0){
	max=0;
	end=1;
	for(i=0;i<96;i++){
		if(znakovi[i]>max){max=znakovi[i]; 
		poz=i;}
		if(max!=0){
		end=0;}
		} 
		znakovi[poz]=-1;
		if(max!=0){
			*tablica=(char)(poz+32);
			tablica++;
		}
	}
d=znakovi;
for(i=0;i<95;i++){
	if(*d==0){
		*tablica=(char)(i+32);
			tablica++;
		
	}
	d++;
}
*tablica='\0';
tablica=tmptab;
s=temp;
poz=0;

while(*s!='\0'){
	tablica=tmptab;
	poz=0;
	while(*s != *tablica  && *tablica!='\0'){
	tablica++;
	poz++;}
	*s=(char)(126-poz);
	s++;
}
s=temp;
return s;
	
}

char* dekodiraj(char*s, char* tablica){
	char* temp=s;
	char c=*s;
	int i, max=0, a=1; 
	int cd[96]={0}, tbl[96]={-1};
	
	while(*s!='\0'){
		cd[*s-32]++;
		s++;
	}
	max=0;
	do{
		max=0;
		for(i=0;i<96;i++){
			if(cd[i]>=max){
				max=cd[i];
			}
		}for(i=95;i>=0;i--){
			if(cd[i]==max){
				c=i+32;
				break;
			}
		}
		tbl[c-32]=*tablica;
		cd[c-32]=0;
		tablica++;
		a=1;
		for(i=0;i<96;i++){
			if(cd[i]!=0)a=0;
		}
		
	}while (a==0);
	s=temp;
	while(*s!='\0'){
		*s=tbl[*s-32];
		s++;
	}
	return temp;
}
int main() {
	char t[]="LLMLNLNMONM";
	char b[100]="";
	
	kodiraj(t, b);
	printf("%s", t);
	printf("\n");
	printf("%s\n", b);
	
	dekodiraj(t, b);
	printf("%s", t);
	
	return 0;
}
#include <stdio.h>
void ispisi(char* s){
	while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
		printf("%c", *s);
		s++;
	}
}
void unesi(char niz[], int vel){
	char znak=getchar(); 
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<vel-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	} 
	niz[i]='\0';
}  
int duzina(char* s){
	int br=0;
	while(((*s>='A' && *s<='Z')||(*s>='a' && *s<='z')) && *s!='\0'){
		br++;
		s++;
	} 
	return br;
} 
int iste(char* s, char* q){ 
	int br=0; 
	char* poc_prve=s;
	char* poc_druge=q;
	while((((*s>='A' && *s<='Z')||(*s>='a' && *s<='z'))&&((*q>='A' && *q<='Z')||(*q>='a' && *q<='z'))) && *s!='\0' && *q!='\0'){
		if(*s==*q) br++; 
		s++;
		q++;
	} 
	if(br==duzina(poc_prve) && br==duzina(poc_druge)) return 1;
	else return 0;
}
char* izbaci_najcescu(char* s){
	char* q=s;
	char* r; 
	char* t;  
	char* x=s;
	int max=0;
	int br=0; 
	char* u; 
	char* y;
	while(*s!='\0'){ 
		t=q;
		while(((*q>='A' && *q<='Z')||(*q>='a' && *q<='z')) && *q!='\0'){
			q++;
		} 
		r=q+1;   
		while(*r!='\0'){
			if(iste(t,r)==1)  
			{
				br++; 
			}
			r++;
		}   
		if(br>max){ 
			max=br;
			u=t; 
			y=u;
		} 
		br=0;
		s++;  
	}   
	return u;
}
int main() {
	char niz[100]; 
	char* x;
	printf("Unesite tekst: ");
	unesi(niz, 100);  
	x=izbaci_najcescu(niz); 
	ispisi(x);
	return 0;
}

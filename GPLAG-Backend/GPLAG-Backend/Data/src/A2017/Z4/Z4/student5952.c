#include <stdio.h>

int Slovo_Broj(char c){
	if(c>='0' && c<='9') return 3;
	else if(c>='A' && c<='Z') return 2;
	else if(c>='a' && c<='z') return 1;
	return 0;
}

int provjeri(char *s){
	float br_poc=0, br_kr=0, br_kosih=0;
	char *poc=s;
	char *kraj=s;
	char *poc_prvog, *poc_drugog;
	
	while(*kraj != '\0') kraj++;
	
	while(s != kraj){
		if(*s == '<') br_poc++;
		else if(*s == '>') br_kr++;
		else if(*s == '/' && s-1 >= poc && *(s-1) == '<') br_kosih++;
		
		s++;
	}
	if(br_poc != br_kr || br_poc/2 != br_kosih) return 0;
	
	s=poc;
	while(s < kraj){
		if(*s == '/' && s-1 >= poc && *(s-1)=='<'){
			if(*(s+1)=='\0') return 0;
			s++;
			if(!Slovo_Broj(*s)) return 0;
			poc_drugog=s;
			
			while(poc_prvog>=poc && *poc_prvog != '<')	poc_prvog--;
			if(poc_prvog<poc) return 0;
			poc_prvog++;
			if(!Slovo_Broj(*poc_prvog)) return 0;
			
			
			while(*poc_prvog != '>' || *poc_drugog != '>' || *poc_prvog != ' ' || *poc_drugog != ' '){
				char slovo1=*poc_prvog, slovo2=*poc_drugog;
				if(Slovo_Broj(slovo1)==2) slovo1+=32;
				if(Slovo_Broj(slovo2)==2) slovo2+=32;
				
				if(slovo1 != slovo2) return 0;
				
				poc_prvog++;
				poc_drugog++;
			}
			
			
		}
		
		
		s++;
	}
	
	
	
	return 1;
}

int main() {
	printf("%d ", provjeri("<h1><P><a h</B></P></h1>"));
	
	return 0;
}
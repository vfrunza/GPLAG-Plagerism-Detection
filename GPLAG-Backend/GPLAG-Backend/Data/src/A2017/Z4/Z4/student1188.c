/*

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

*/


//Medinino:

#include <stdio.h>

int Slovo(char c){
    if(c>='a' && c<='z') return 1;
    if(c>='A' && c<='Z') return 2;
    return 0;
}

int UporediTagove(char* tag1, char* tag2, char* imeTaga1, char* imeTaga2, int razmak){
	if(razmak%2==0) return 0;
	if(*(tag2+1)!='/') return 0;
	if(!Slovo(*(tag2+2))) return 0;
	if(!Slovo(*(tag1+1))) return 0;
	return 1;
}

int UporediStringove(char* str1, char* str2){
	char a, b;
	
	while(*str1 != '\0' && *str2 != '\0'){
		if(*str1>96 && *str1<123) a=*str1-32;
		else a=*str1;
		if(*str2>96 && *str2<123) b=*str2-32;
		else b=*str2;
		
		if(a != b) return 0;
		str1++;
		str2++;
	}
	if(*str1 != '\0' || *str2 != '\0') return 0;
	
	return 1;
}

int provjeri(char* string){
	int i=0, j=0, velicina, provjereni[100]={0};
	char *pok=string;
	char matricaTagova[100][100]={{' '}}, matricaImenaTagova[100][100]={{' '}};

	while(*string != '\0'){
		if(*string=='<'){
			while(*string != ' ' && *string != '>'){
				matricaTagova[i][j]=*string;
				string++;
				j++;
			}
			matricaTagova[i][j]='>';
			matricaTagova[i][j+1]='\0';
			j=0;
			i++;
		}
		string++;
	}
	i=0;
	j=0;
	
	while(*pok != '\0'){
		if(*pok == '<'){
			pok++;
			if(*pok == '/') pok++;
			while(*pok != ' ' && *pok != '>'){
				matricaImenaTagova[i][j]=*pok;
				pok++;
				j++;
			}
			matricaImenaTagova[i][j]='\0';
			j=0;
			i++;
		}
		pok++;
	}
	
	velicina=i;
	for(i=0; i<velicina; i++){
		for(j=i+1; j<velicina; j++){
			if(UporediStringove(matricaImenaTagova[i], matricaImenaTagova[j]) && provjereni[i]==0 && provjereni[j]==0){
				if(UporediTagove(matricaTagova[i], matricaTagova[j], matricaImenaTagova[i], matricaImenaTagova[j], j-i) ==0) return 0;
				provjereni[i]=1;
				provjereni[j]=1;
			}
		}
	}
	for(i=0; i<velicina; i++)
		if(provjereni[i] != 1) return 0;
		
	return 1;
}

int main(){
	char tekst1[100];
	printf("%d", provjeri(tekst1));
	return 0;
}
#include <stdio.h>

int duzina_stringa(char *p){
	int duzina=0;
	while(*p!='\0'){
		duzina++;
		p++;
	}
	return duzina;
}

void int_u_string(char *p, int broj){
	char *sb=p;
	int tmp=broj;
	
	if(broj<0){
		broj=-broj;
		*sb='-';
		sb++;
	}
	
	do{
		sb++;
		tmp/=10;
	}while(tmp!=0);
	
	*sb='\0';
	sb--;
	
	do{
		*sb--=broj%10+'0';
		broj/=10;
	}while(broj!=0);
}

char* ubaci_broj (char* tekst, int broj){
	int prva=0;
	int ubaciti=0;
	int duzina;
	char sbroj[12];
	char *pom=tekst;
	char *p;
	char *kraj;
	char *kraj1;
	char *br=sbroj;
	char *pom1;
	int_u_string(br,broj);
	pom1=br;
	while(*pom!='\0'){
		br=pom1;
		ubaciti=0;
		
			
				while(*pom==' ' && *pom!='\0') pom++;
			
		
		
		
		if(*pom!=' ') {
			
			while(*pom!=' ' && *pom!='\0') pom++;
		}
		
		if(*pom=='\0') return tekst;
		
		p=pom;
 		while(*p!='\0'){
 			if(*p!=' '){ 
 				ubaciti=1; 
 				break;
 			}
 			p++;
 		}
 		
 		if(ubaciti){
 			
 			kraj=pom;
 			duzina=duzina_stringa(br);
 			
 			while(*kraj!='\0'){
 				kraj++;
 			}
 			
 			kraj1=kraj;
 			
 			while(kraj1!=kraj+duzina+1){
 				*kraj1='a';
 				kraj1++;
 			}
 			
 			*kraj1='\0';
 			kraj--;
 			kraj1--;
 			
 			while(pom!=kraj){
 				*kraj1=*kraj;
 				kraj--;
 				kraj1--;
 			}
 			
 			pom++;
 			while(*br!='\0'){
 				*pom=*br;
 				pom++;
 				br++;
 			}
 			*pom=' ';
 			
 			
 		}
 		
 		
 		
		pom++;
	}
	
	
	return tekst;
}

int main() {


char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
printf("\"%s\"", ubaci_broj(s, 320));

	
	return 0;
}
Ovdje 320 izmedju 320    rijeci 320 
Ovdje 320 izmedju 320 
#include <stdio.h>

int DaLiSlovo(char slovo){ /* Ovo je moja funkcija iz zadatka br. 2 */
	if(slovo<'A' || slovo>'z' || (slovo>'Z' && slovo <'a')) return 1;
	return 0;
}

void najduzi_bp(char *s1, char *s2){
	int max=0, i=0, razmak=1, ne, pomjeri;
	char* kraj;
	char* cuvar;
	
	while(*s1!='\0'){
		ne=DaLiSlovo(*s1);
		if(ne==1) razmak=1;
		else if(razmak==1){
			while(ne!=1 ){
				
				i++;
				s1++;
				ne=DaLiSlovo(*s1);
			}
			
		
			if(max<i){
				max=i;
				kraj=s1;
			}
				
			i=0;
		}
		
		s1++;
	}
	
	pomjeri=max;
	while(pomjeri!=0){
		kraj--;
		pomjeri--;
	}
	
	while(pomjeri!=max){
		*s2=*kraj;
		s2++;
		kraj++;
		pomjeri++;
	}
	
	*s2='\0';
	
}

int main() {
	char tekst[]={"Ja sam neki string"};
	char BigSubString[10];
	
	najduzi_bp(tekst, BigSubString);
	printf("%s", BigSubString);
	return 0;
}
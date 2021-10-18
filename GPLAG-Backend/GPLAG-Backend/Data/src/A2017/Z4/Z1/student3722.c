#include <stdio.h>

int pomocna(int broj){
	int naopak=0;
	while(broj!=0){
		naopak*=10;
		naopak+=broj%10;
		broj/=10;
	}
	return naopak;
}
char* ubaci_broj (char* tekst, int broj){
	int i,naopak;
	i=0;
	
	int j;
	naopak=pomocna(broj);
	while(*(tekst+i)!='\0'){
		
		if(*(tekst+i)==' '){
			i++;
			j=i;
				while(*(tekst+i)!='\0'){
					i++;
					
				}
				*(tekst+i+1)=*(tekst+i);
				
				i--;
				while(i>=j){
					*(tekst+i+1)=*(tekst+i);
					
					i--;
				}
				i++;
			while(naopak!=0){
				j=i;
				while(*(tekst+i)!='\0'){
					i++;
					
				}
				*(tekst+i+1)=*(tekst+i);
				
				i--;
				while(i>=j){
					*(tekst+i+1)=*(tekst+i);
					
					i--;
				}
				i++;
				*(tekst+i)=naopak%10+48;
				naopak/=10;
				i++;
				
			}
		}
		i++;
		
		
	}
	return tekst;
}
int main(){
	char s[40]="Neki tekst";
	printf("%s\n", s);
	ubaci_broj(s,45);
	printf("%s",s);
	return 0;
}
#include <stdio.h>
void izbaci_rijec(char *s, int n){
	int broj_rijeci=1, razmak=0;
	while(*s!='\0'){
		if(*s==' ') razmak=1;
		if(*s!=' '){
			if(razmak == 1){ broj_rijeci++;
			razmak=0;
				
			}
			
		}
		
	
	
	
	s++;
}

}
int main() {
	
	return 0;
}

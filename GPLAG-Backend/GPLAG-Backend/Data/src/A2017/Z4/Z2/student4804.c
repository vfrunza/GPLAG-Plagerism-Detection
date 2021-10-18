#include <stdio.h>

int provjeri_duzine (char* tekst, int* broj,int n1){
	int n=0,counter=0;
	while (*tekst != '\0'){
		if(!(*tekst >='A' && *tekst <= 'Z') &&  !(*tekst >='a' && *tekst <= 'z'))
		{
				if(counter > 0){
					n++;
					if ( counter != *(broj + n - 1) || n > n1){
						return 0;
					}
					counter = 0;
				}
		} else {
			counter++;
			if(*(tekst + 1) == '\0'){
			if(counter > 0){
					n++;
					if (counter != *(broj + n - 1) || n > n1){
						return 0;
					}
					counter = 0;
				}
		}
	}
	tekst++;
	}
	if (n < n1){
		return 0;
	}
return 1;
}


int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}

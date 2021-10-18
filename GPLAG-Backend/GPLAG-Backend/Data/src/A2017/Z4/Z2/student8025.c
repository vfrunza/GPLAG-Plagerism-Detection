#include <stdio.h>


int provjeri_duzine (char *rijeci, int niz[], int vel){
	int brojac=0;
	char* q=rijeci;
	
	while (*q!='\0'){
		q++;
	}
	while (*rijeci!='\0'){
		if (!((*rijeci>='a' && *rijeci<='z') || (*rijeci>='A' && *rijeci<='Z')) && *rijeci!='\0'){
			if (*(rijeci+1)!='\0'){
				rijeci++;
			}
			else {
				break;
			}
			continue;
		}
		if (*rijeci=='\0'){
			break;
		}
		if (brojac>=vel){
			return 0;
		}
		
		char *p;
		
		//while (*rijeci!='\0' && !((*rijeci>='a' && *rijeci<='z') || (*rijeci>='A' && *rijeci<='Z'))){
		//	rijeci++;
		//}
		
		p = rijeci + niz[brojac];
		
		if (p>q){
			return 0;
		}
		brojac++;
		
		if (((*p>='a' && *p<='z') || (*p>='A' && *p<='Z')) && *p!='\0'){
			return 0;
		}
		while (rijeci<p){
			if (!((*rijeci>='a' && *rijeci<='z') || (*rijeci>='A' && *rijeci<='Z'))){
				return 0;
			}
			rijeci++;
		}
		rijeci++;
	}
	if (brojac<vel){
		return 0;
	}

	return 1;
}


int main() {
	
	return 0;
}

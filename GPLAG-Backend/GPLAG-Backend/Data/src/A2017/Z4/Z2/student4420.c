#include <stdio.h>


	int	provjeri_duzine(char niz[],int niz_b[],int broj) {
		char * klizi;
		klizi = niz;
		int brojac=0;
		int brojnik=0;
		while (*klizi != '\0' ){
			while ( *klizi != '\0' && !((*klizi >= 'a' && *klizi <='z') || (*klizi>='A' && *klizi<='Z')) ) {
				klizi++;
			}
			while ( *klizi != '\0' && ((*klizi >= 'a' && *klizi <='z') || (*klizi >= 'A' && *klizi<= 'Z')) ) {
				brojac++;
				klizi++;
			}
			
			if(brojac == *niz_b) {
				brojac=0;
				niz_b++;
				brojnik++;
			}
			else {
				return 0;
			}
			if(*klizi =='\0') break;
			while (*klizi!= '\0' && !((*klizi>='a' && *klizi<='z') || (*klizi>='A' && *klizi<='Z')) ) {
				klizi++;
			}
			
		}
		if (brojnik != broj) return 0;
		
		
		return 1; 
	}
int main() {
	char tekst[] = "Ovo je";
	int niz[] = {3,2};
	int bezveze_niz[]={1,2};
	printf("%d ", provjeri_duzine(tekst,niz,2));
	printf("%d",provjeri_duzine(tekst,bezveze_niz,2));
	return 0;
}

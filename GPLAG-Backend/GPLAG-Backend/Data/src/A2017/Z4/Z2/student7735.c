#include <stdio.h>

int provjeri_duzine(char *string,int *niz,int vel){
	int brojac=0;
	int i=-1;
	while(*string!='\0'){
		while ((*string<'A' || *string>'Z') && (*string<'a' || *string>'z')) {
			if (*string=='\0') break;
			string++;
		}
	while((*string>='A' && *string<='Z') ||(*string>='a' && *string<='z')){
		string++;
		brojac++;
		if ((*string<'A' || *string>'Z') && (*string<'a' || *string>'z')) i++;
		}
		if (vel<=i ) return 0;
		if (niz[i]!=brojac && *string!='\0') return 0;
		else {
			brojac=0;
			if (*string!='\0')
			string++;
		}
	}
	if (vel>i+1) return 0;
	return 1;
}

int main(){
	char tekst[] = "Kakav je ovo test!?!?";
	int niz[] = {5,2,3,4};
	int niz2[] = {5,2,3,8};
	int niz3[] = {5,2,3,4,0};

	printf("%d ", provjeri_duzine(tekst, niz3, 5));
	printf("%d ", provjeri_duzine(tekst, niz2, 4));
	printf("%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}

#include <stdio.h>

int provjeri_duzine (char *s, int niz[], int vel){
	char*p=s;
	int i=0;
	int brojac=0;
	int br_rijeci=0;
	while(*p != '\0'){
		while(*p!='\0' && ((*p<'a' || *p>'z') && (*p<'A' || *p>'Z'))) p++;
		if( (((p==s || *(p-1)==' ') && ((*p>='a' && *p<='z') || (*p>='A' && *p<='Z'))) || (*(p-1)<'A' || (*(p-1) >'Z' && *(p-1)<'a') || *(p-1)>'z')) && *p!='\0'){
			br_rijeci++;
		} 
		if (*p=='\0') p--;
		
		p++;
	}
	if (vel!=br_rijeci) return 0;
	p=s;
	
	while(*p!='\0' && i<vel){
		while((*p<'a' || *p>'z') && (*p<'A' || *p>'Z') && *p!='\0') p++;
		brojac=0;
		while(*p!='\0' && ((*p>='a' && *p<='z') || (*p>='A' && *p<='Z'))){
			brojac++;
			p++;
			if((*p<'a' || *p>'z') && (*p<'A' || *p>'Z') && *p!='\0') break;
		}
		p--;
		if (niz[i++]!=brojac) return 0;
		p++;
	}
	return 1;
}

int main() {
	/* AT6: Ne-slova na kraju stringa */
	char tekst[] = "Kakav je ovo test!?!?";
	int niz[] = {5,2,3,4};
	int niz2[] = {5,2,3,8};
	int niz3[] = {5,2,3,4,0};
	
	printf("%d ", provjeri_duzine(tekst, niz3, 5));
	printf("%d ", provjeri_duzine(tekst, niz2, 4));
	printf("%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}

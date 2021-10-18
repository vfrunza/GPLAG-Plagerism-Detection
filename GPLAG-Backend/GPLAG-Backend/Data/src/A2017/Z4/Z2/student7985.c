#include <stdio.h>

int je_li_slovo(char sl){		
	if(sl>='A' && sl<='Z') return 1;
	else if (sl>='a' && sl<='z') return 2;
	return 0;
}


int provjeri_duzine(char *s, int niz[], int vel){
	int neslovo=1, i=0, br_rijeci=0;
	char *p, *q; /* p početak, q kraj */
	
	while(*s != '\0'){
		if(!je_li_slovo(*s)) neslovo=1;
		else if(neslovo==1){
			 br_rijeci++; 
			p=s;
			while(*s != '\0' && je_li_slovo(*s)) s++;
			q=s;
			if(q-p != niz[i]) return 0; /* q-p je broj slova u riječi*/
			i++;
		}
		if(*s=='\0') break;
		s++;
	}
	
	if(br_rijeci != vel) return 0;
	
	return 1;
}

int main() {
	char string[] = "Ovo je neki primjer teksta";
	int nizzz[] = {3, 2, 4, 7, 6, 4};
	printf("%d", provjeri_duzine(string, nizzz, 6));
	return 0;
}

#include <stdio.h>
/*
int velicina_stringa(char *s)
{
	char *p=s;
	int brojac=0;
	while (*p !='\0') {
		if((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) {
			while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z') || *p!='\0')
				p++;
		}
		p++;
		brojac++;
		
	}
	return brojac;
}
*/
int provjeri_duzine( char * s, int* niz2, int vel2)
{
	char*p=s;
	char *kt;
	char *pt;
	int novi;
	int i=0;
	int brojac=0;
	while (*p != '\0') {
		if((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) {
			pt=p;
			while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))
				p++;
			if(*p==' ' || *p=='\0' || (!(*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))) {
				kt=p;
				novi=kt-pt;
				brojac++;
		if(i == vel2) return 0; 
		printf("dskkds");
				if(niz2[i++] != novi) return 0;
			}
		}
		if(*p == '\0') break; //ako ovo ne uradjimo otici cemo iza kraja
		//javlja memorijske
		p++;
	}
if(brojac != vel2) return 0;
	return 1;

}
int main()
{
	    char c[50] = " ";
	    
    int niz[2]={0};
    int cc;
    cc=provjeri_duzine(c,niz,4);
      printf("%d", provjeri_duzine(c,niz,0));
	return 0;
}

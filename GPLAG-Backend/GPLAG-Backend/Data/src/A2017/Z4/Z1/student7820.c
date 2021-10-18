#include <stdio.h>
#include <math.h>

int slovo(char znak) {
	
	if((znak>='A' && znak<='Z') || (znak>='a' && znak<='z') || znak=='-' || znak=='.' || znak=='?' || znak==',' || znak=='!' || znak==':')
	return 1;
	return 0;
}

	
char *ubaci_broj(char *tekst,int broj) {
	
	char *pok=tekst;
	char *s=tekst,*tmp=tekst,znak;
	int br_cifara,br_cifara2,stepen,i,tmp2,cifra;
	
	
	while(*tekst==' ' ) tekst++;

	while(*tekst!='\0') {
		while(slovo(*tekst)) tekst++;
        
		if(*tekst=='\0') break;
		br_cifara=(int)(log10(fabs(broj)))+1;
		
		if(broj<0) br_cifara++;
		br_cifara++;
		while(*tmp!='\0') tmp++;
		tmp+=br_cifara;
		s=tekst;
		*tmp='\0';
	    tmp--;
		while((tmp-br_cifara)!=s) {
			
				*tmp=*(tmp-br_cifara);
				tmp--;
			}
		br_cifara2=(int)(log10(fabs(broj)));
		s++;
		if(*s=='\0') break;
		if(broj<0) {
			*s='-';
			s++;
		}
		
		stepen=1;
		for(i=0;i<br_cifara2;i++)	stepen*=10;
			tekst=s;
			for(i=0;i<=br_cifara2;i++) {
			tmp2=broj;
			tmp2/=stepen;
			cifra=fabs(tmp2%10);
			znak=cifra+'0';
			*tekst=znak;
			tekst++;
			stepen/=10;
			}
	   *tekst=' ';
		
		while(!(slovo(*tekst)) && *tekst!='\0')  tekst++;
		if(*tekst=='\0') break;
		tekst++;
	}
return pok;
}

int main() {
/*	printf("Zadaća 4, Zadatak 1");*/

char s[]="Ovo      je neki   primjer  teksta.";
ubaci_broj(s,-123);
printf("%s",s);

	return 0;
}

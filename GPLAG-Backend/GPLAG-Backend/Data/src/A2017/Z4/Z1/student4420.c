#include <stdio.h>
#include <stdlib.h>
char* ubaci_broj(char*tekst,int broj) {
	char *s1,*s2,*s3;
	s1=tekst;
	s2=s1;
	s3=s1;
	int broj2=0,brojac2=0;
	broj2=abs(broj);
	int brojac=0;
	while(broj2 != 0) {
		brojac++;
		broj2=broj2/10;
	}
	if(broj < 0) brojac++;
	broj2=abs(broj);
	while( *s1 != '\0' && *(s1+1)!='\0')  {
		if (*s1=='\0') break;
		while(*s1 != '\0' && *s1 ==' ') s1++;
				if ( *s1 == '\0') break;

		while(*s1 != '\0' && *s1!=' ') s1++;
		if ( *s1 == '\0') break;
		s2=s1;
		s3=s2;
		while(*s3 != '\0') s3++;
		while ( s3 != s2 && *s2!='\0') {
			 
			*(s3+brojac+1) = *s3;
			s3--;
		}
		s3=s3+brojac+1;
		*s3=' ';
		s3--;
		brojac2=0;
		while(broj2!=0){
		
			*s3=broj2%10+'0';
			broj2=broj2/10;
			s3--;
			brojac2++;
				if( brojac-brojac2 == 1 && broj < 0){
				*s3='-';
				s3--;
				break;
			}
		}
		broj2=abs(broj);
		if(*s1 =='\0') break;
		if (broj<0) s1=s3+brojac+2;
		else s1=s3+brojac+1;
		s1++;
	}
	s1 = tekst;
	while(*s1 != '\0') s1++;
	s1--;
	if ( *s1 == ' ') {
	*s1='\0';
	s1--,
	*s1='\0';
	s1--;
	while(*s1 == ' ') s1--;
	while(*s1>='1' && *s1<='9') *s1=' ';
}
	s1=tekst;
	while(*s1 !='\0' ) {
		if(s1==tekst){
		while(*s1==' ' && *s1!='\0') s1++;
		}
		if ( *(s1+1) != '\0') {
			s2=s1;
			if ( *s1== ' ' && *(s1+1) == ' ') {
				while(*(s1+1) != '\0') {
					*s1=*(s1+1);
					s1++;
				
					
				}
							*s1=*(s1+1);
					
			}
			
					s1=s2;

		}
		while(*s1==' ' && *s1!='\0') s1++;
		if(*s1=='\0') break;
		s1++;
	}
   
	return tekst;
}


int main() {
/* AT4: Vise razmaka izmedju rijeci */
char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
printf("\"%s\"", ubaci_broj(s, 320));
	return 0;
}

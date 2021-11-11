#include <stdio.h>
char malo_slovo(char slovo){
	if(slovo>='A' && slovo<='Z')
	return slovo+32;
	return slovo;
}
char *izbaci_najcescu(char* s){
	char* povratni=s,*izbaci,*p,*q=s,niz[200];
	int br_ponavljanja,i,max=0,duz=0;
	while(*s!='\0'){
		while(*s!='\0' && !((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
		s++;
		i=0;
		br_ponavljanja=0;
		p=s;
		q=s;
		while(*p!='\0' && ((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')))
		niz[i++]=*p++;
		niz[i]='\0';
		int ima;
		if(i!=0){
			do{
				br_ponavljanja++;
				while((*q>='A' && *q<='Z') || (*q>='a' && *q<='z')) q++;
				int i=0;
				ima=0;
				char *s1=q;
				while(*s1!='\0'){
					i++;
					char* pom1=s1;
					char* pom2=niz;
					while(malo_slovo(*pom1)==malo_slovo(*pom2)){
						pom2++;
						pom1++;
						if(*pom2=='\0' && !(malo_slovo(*pom1)>='a' && malo_slovo(*pom1)<='z'))
						if(i!=0 && !((*(s1-1)>='A' && *(s1-1)<='Z') || (*(s1-1)>='a' && *(s1-1)<='z'))){
							ima=1;
							q=s1;
						}
						if (ima) break;
					}
					if(ima) break;
					s1++;
				}
			}while(*q!='\0' && ima);
			if(br_ponavljanja>max){
				max=br_ponavljanja;
				izbaci=s;
				duz=i;
			}
			s+=p-s;
		}
	}
	if(max!=0){
		i=0;
		p=izbaci;
		s=izbaci+duz;
		while(p!=s)
		niz[i++]=*p++;
		niz[i]='\0';
		p=povratni;
		while(max-->0){
			p=povratni;
			int ima=0,prolaz=0;
			while(*p!='\0'){
				char *pom1=p;
				char *pom2=niz;
				while(malo_slovo(*pom1)==malo_slovo(*pom2)){
					pom2++;
					pom1++;
					if(*pom2=='\0' && !(malo_slovo(*pom1)>='a' && malo_slovo(*pom1)<='z'))
					if(p!=povratni){
						if(!((*(p-1)>='A' && *(p-1)<='Z') || (*(p-1)>='a' && *(p-1)<='z')))
						ima=1;
					}
					else ima=1;
					
					if(ima) break;
				}
				prolaz++;
				if(ima) break;
				p++;
			}
			q=p+i;
			while(*q!='\0'){
				*p++=*q++;
			}
			*p='\0';
		}
	}
	return povratni;
}
int main() {
	char niz[]="Najcescajeizbacena";
	printf("'%s'",izbaci_najcescu(niz));
	return 0;
}
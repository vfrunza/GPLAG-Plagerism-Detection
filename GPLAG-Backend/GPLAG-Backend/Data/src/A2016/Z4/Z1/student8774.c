#include <stdio.h>

int broj_karaktera(char* s){
	char*p=s;
	int n=0;
	while(*p!='\0'){
		p++;
		n++;
	}
	return n;
}

void izbacuje(char* s,char* q){
	int duzina=broj_karaktera(q);
	char* s1=s;
	char* m=s;
	
	while (*s1!='\0'){
		char* q2=q;
		char* p2=s1;
		while(((*p2==*q2) || (*p2==*q2-32) || (*p2==*q2+32)) && *q2!='\0'){
			p2++;
			q2++;
			if(s1==s){
				if(*q2=='\0' && !(*p2>='A' && *p2<='Z') && !(*p2>='a' && *p2<='z'))
				m=s1;
				while(*(m+duzina)!='\0'){
					*m=*(m+duzina);
					m++;
				}
				*m=*(m+duzina);
			}
			else if(*q2=='\0' && (!(*p2>='A' && *p2<='Z') && !(*p2>='a' && *p2<='z')) && !(*(s1-1)>='A' && *(s1-1)<='Z') && !(*(s1-1)>='a' && *(s1-1)<='z')){
				m=s1;
				while(*(m+duzina)!='\0'){
					*m=*(m+duzina);
					m++;
				}
				*m=*(m+duzina);
			}
		}
		s1++;
	}
}

char* izbaci_najcescu(char* s){
	char* p=s;
	char* a=s;
	char* b=s;
	char* c=s;
	char* p1=s;
	int i=0,n=0,duzina=0,maks=0;
	char tekst[100];
	char maksi_rijec[100];
	int broj=broj_karaktera(s);
	if(broj==0){
		return p;
	}
	while(*s!='\0'){
		a=s;
		while(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))){
			if(*s=='\0')
			break;
			s++;
		}
		if(*s=='\0'){
			if(a==p)
			return p;
			break;
		}
		b=s;
		c=s;
		
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
			if(*s=='\0')
			break;
			s++;
		}
		if(c==p && *s=='\0'){
			izbacuje(p,p);
			return p;
		}
		if(*s=='\0')
		break;
		while(i<s-b){
			*(tekst+i)=*c;
			c++;
			duzina++;
			i++;
		}
		tekst[i]='\0';
		p1=p;
		
		while(*p1!='\0'){
			char* p2=p1;
			char* q2=tekst;
			while(((*p2==*q2) || (*p2==*q2-32) || (*p2==*q2+32)) && *q2!='\0'){
				p2++;
				q2++;
				if(p1=p){
					if(*q2=='\0' && !(*p2>='A' && *p2<='Z') && !(*p2>='a' && *p2<='z'))
					n++;
				}
				else if(*q2=='\0' && (!(*p2>='A' && *p2<='Z') && !(*p2>='a' && *p2<='z')) && !(*(p1-1)>='a' && *(p1-1)<='z') && !(*(p1-1)>='A' && *(p1-1)<='Z'))
				n++;
			}
			p1++;
		}
		if (n>maks){
			maks=n;
			for(i=0;i<duzina;i++){
				maksi_rijec[i]=tekst[i];
			}
			maksi_rijec[i]='\0';
		}
		if(*s=='\0')
		break;
		s++;
	}
	izbacuje(p,maksi_rijec);
	return p;
}

int main() {
	char s[10000]={" "};
	printf("Modificiran niz glasi: |%s|",izbaci_najcescu(s));
	return 0;
}

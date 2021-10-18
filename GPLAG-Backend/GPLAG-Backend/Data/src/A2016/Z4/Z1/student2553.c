#include <stdio.h>
int je_li_slovo(char c){
	if((c>=65 && c<=90) ||( c>=97 && c<=122))return 1;
	
	return 0;
}
int je_li_isto(char c1,char c2,int caps){
	int rez=0;
	if(caps==0){
		if(c1>='A' && c1<='Z')c1+='a'-'A';
		if(c2>='A' && c2<='Z')c2+='a'-'A';
		if (c1==c2)rez= 1;
		else rez= 0;
		
	}
	else{
		if (c1==c2)rez=1;
			else rez= 0;
	}
	return rez;
}
int prebroj(char *s,char *s1,int vel){
	char  *q,*temp;
	int i,ponavljanja=0,istarijec=1;
	q=s1;
	temp=s;
	while(*s!='\0'){
		while(je_li_slovo(*s)==0 && *s!='\0')s++;
		istarijec=1;
		if(s==temp){
			for(i=0;i<vel;i++){
				if(je_li_isto(*q,*s,0)==0){ istarijec=0; break;}
				if(*s=='\0') {istarijec=0; break;}
				q++;
				s++;
			}
			if(je_li_slovo(*s)==1)istarijec=0;
		}
		else{
			if(je_li_slovo(*(s-1))==0){
				
				for(i=0;i<vel;i++){
					if(je_li_isto(*q,*s,0)==0){ istarijec=0;break;}
					if(*s=='\0') {istarijec=0; break;}
					q++;
					s++;
				}
				if(je_li_slovo(*s)==1)istarijec=0;
			}else istarijec=0;
		}
		if(istarijec==1){
			ponavljanja++;
		}
		q=s1;
		while(je_li_slovo(*s)==1 && *s!='\0')s++;
		
	}
	q=s1;
	s=temp;
	return ponavljanja;
}
void izbaci(char *s11,char *rijec,int duzina){
	char *p,*a;
	char *sa;
	char *x;
	int i,isto;
	x=s11;

	isto=1;
	p=rijec;
	while(*s11!='\0')s11++;
	if(*s11!='\0')s11--;	
	for(i=0;i<duzina-1;i++){
		rijec++;
	}
	p=rijec;

	while(s11!=x && s11!='\0'){
		
		while(je_li_slovo(*s11)==0 && s11!=x){s11--;}
		isto=1;
		
		sa=s11;
		p=rijec;

		for(i=0;i<duzina;i++){
			if(je_li_isto(*s11,*p,0)==0){
				isto=0;
				break;
				}
				else{
					if(s11!=x){
						if(je_li_slovo(*(s11-1))==1 && i==(duzina-1)){
						isto=0;
						break;}
						}
				}
			if(s11!=x) s11--;
			p--;
		}
		
		s11=sa;
	
		p=rijec;

		if(isto==1){
			for(i=0;i<duzina;i++){
				
				a=s11;
				
				while(*(s11+1)!='\0'){
					*s11=*(s11+1);
					s11++;
				}
				*s11='\0';
				s11=a;
			if(s11!=x)s11--;
			}
		}
		
		p=rijec;
		while(je_li_slovo(*s11)==1 && s11!=x ){s11--;}

		
	}
}

char* izbaci_najcescu(char* s){
	int a,duzina=0,najcescaduzina=0,max=0;
	char *pok=s,*najcescapokazivac=s,*temp=s,*save=s;
	
	max=0;
	while(*s!='\0'){
		while(je_li_slovo(*s)==0 && *s!='\0')s++;
		
		duzina=0;
		temp=s;
		
		while(je_li_slovo(*s)==1 && *s!='\0'){
			duzina++;
			s++;
		}
		s=temp;

		pok=s;
		temp=save;
		a=prebroj(temp,pok,duzina);

		temp=save;
	
		if(a>max){
			max=a;
			najcescaduzina=duzina;
			najcescapokazivac=s;
		}
		
		while(je_li_slovo(*s)==1 && *s!='\0')s++;
	
		
		
	}
	s=save;

	duzina=0;
	temp=najcescapokazivac;
	while(je_li_slovo(*temp)==1 && *temp!='\0'){duzina++; temp++;}
	izbaci(s,najcescapokazivac,najcescaduzina);
	s=save;
	
	return s;
}
int main() {
	char t[]="Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";

	izbaci_najcescu(t);

	printf("\n");

	printf("%s",t);

	return 0;
}

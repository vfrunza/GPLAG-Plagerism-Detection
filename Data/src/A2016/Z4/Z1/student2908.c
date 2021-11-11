#include <stdio.h>

char* izbaci_najcescu (char* s){
	int brojaci[100],i=0,j;
	int razmak=1, broj_rijeci=0,maxi;
	char *pocetak;
	char *p,*x,*r;
	x=s;p=s;r=s;
	while(*p!='\0'){
		while(*r!=' ' && *r!='\n' && *r!= '\0') r++;
			while(*p!=' ' && *p!='\n' && *r!=' ' && *r!='\n'){
				if(*p++==*++r) continue;
				else break;
			}
		if((*p==' ' || *p=='\n'|| *p!='\0' ) && ( *r!=' ' ||  *r!='\n' || *r!='\0')) brojaci[i]++;
		p=x;
		if(r=='\0'){
				while(*p!=' ' && *p!='\n') p++;
				x=++p; i++;
				r=p;
		}
		else
			while(*r++!=' ' && *r!='\n' && *r!='\0');
	}
	x=s;
	maxi=0;
	for(j=0;j<i;j++){
		if(brojaci[i]>brojaci[maxi])
			maxi=i;
	}
	while(*s!='\0'){
		if(*s==' ')
		razmak=1;
		else if(razmak==1){
			razmak=0;
			if(*s==' ')
				razmak=0;
			broj_rijeci++;
			if(broj_rijeci==i) pocetak=s;
			if(broj_rijeci==i+1){
				while(*pocetak++=*s++);
				return x;
			}
		}
		s++;
	}
	if(broj_rijeci==i) *pocetak='\0';
	
	return x;
}
int main(){
 char s[100]="nermana nermana emir nermana emir emir emir";
 printf("%s",izbaci_najcescu(s));
 return 0;
}
	
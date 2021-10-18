#include <stdio.h>

char *ubaci_broj(char *tekst, int broj){
	char cifre[15];
	char *c=cifre,*b=tekst,*p=tekst,*q=tekst,*k=tekst,*y=tekst;
	int vel=0,x=broj,t=0;
	
	*c++=' ';
	vel++;
	if(broj<0){
		vel++;
		broj=-broj;
		*c++='-';
	}
	do{
		vel++;
		x/=10;
		c++;
	}while (x);
	*c--='\0';
	do{
		*c--=broj%10 + '0';
		broj/=10;
	}while(broj);
	
	
	if(*k!='\0'){
	while(*k)k++;
	do{
		k--;
	}while(*k==' ' && k!=p);
	while(p!=k){
		if(*p!=' ')t=1;
		if(*p==' ' && t==1){
			char *r=tekst;
			while(*r)r++;
			while(r>=p){
				*(r+vel)=*r;
				r--;
			}
			t=0;
			y=cifre;
			while(*y){
				*p++=*y++;
				
			}
			if(*p==' ' && *(p+1)==' '){
				b=p;
				b++;
				while(*b){
					*b=*(b+1);
					b++;
			}
			}
			while(*k)k++;
			do{
				k--;
			}while(*k==' ');
			
			p--;
		}
	
		p++;
	}
	}
	
	

return q;	
}



int main() {
	char a[10000]="";
	int b=-123123;
	ubaci_broj(a,b);
	return 0;
}

#include <stdio.h>
int izbroji(int broj){
	int rj=0;
	if(broj<0) broj=broj*(-1);
	while(broj!=0){
		rj++;
		broj=broj/10;
	}
	return rj;
} 
char* ubaci_broj (char* tekst, int broj){
	char *pocetak;
	char *p=tekst;
	int a,neg=0, biloslovo=0;
	int cifre=izbroji(broj);
	cifre++; // zbog razmaka
	int brojic;
    if(broj<0){
    	cifre++;
    	broj=broj*(-1);
    	neg++;
    }
   	char *pomoc;
		char*q;

	while(*p!='\0'){
		brojic=broj;
		

		if((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) biloslovo=1;
		if(*p==' ' && ((*(p+1)>='A' && *(p+1)<='Z') || (*(p+1)>='a' && *(p+1)<='z')) && (*(p-1)!=' ' || biloslovo==1)){
			pomoc=p;
	while(*pomoc!='\0'){
		pomoc++;
	}			
	    q=pomoc+cifre;

		while(pomoc!=p){
		*q=*pomoc;
			q--;
			pomoc--;
		}
		if(*q!='\0') {
			*q=' ';
			q--;
		}
			while(brojic!=0){
				a=brojic%10;
				*q=a+'0';
				brojic=brojic/10;
				q--;
			}
		if(neg) *q='-';
		if(*(p+cifre)!='\0') p=p+cifre;
		
		}
		p++;
		
}
return tekst;
}
int main() {
	char s[12] = "hello.world";
char s2[15] = "hello world";
printf("\"%s\"\n", ubaci_broj(s, 15));
printf("\"%s\"", ubaci_broj(s2, 15));

	return 0;
}


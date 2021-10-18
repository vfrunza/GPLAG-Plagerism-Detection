#include <stdio.h>

char* ubaci_broj (char* tekst, int broj)
{
	char *poc=tekst,*pt,*kt,*kraj,*provkraj;
	
	int predznak=0,i,brbr=0,temp;
	if(broj<0){
		predznak=1;
		broj*=-1;
	}
	temp=broj;
	while(broj!=0){
		broj/=10;
		brbr++;
	}
	if(*tekst==' '){
		while(*tekst==' ')
			tekst++;
	}
	while(*tekst!='\0'){
		while(*tekst!=' ' && *tekst!='\0')
			tekst++;
		pt=tekst;
		//provjera je li zadnja rijec
		provkraj=tekst;
		while(*provkraj!='\0'){
			if(*provkraj!=' ')
				break;
			provkraj++;
		}
		if(*provkraj=='\0')
			return poc;
		kraj=tekst;
		while(*kraj!='\0')
			kraj++;
		broj=temp;
		//kad je minus
		if(predznak==1){
			while(kraj>=tekst){
				*(kraj+brbr+2)=*kraj;
				kraj--;
			}
			pt++;
			*pt='-';
			for(i=brbr;i>0;i--){
				kt=pt+i;
				*kt=(broj%10)+'0';
				broj/=10;
			}
			tekst=tekst+brbr+2;
			
		}
		
		else{
			while(kraj>=tekst){
				*(kraj+brbr+1)=*kraj;
				kraj--;
			}
			for(i=brbr;i>0;i--){
				kt=pt+i;
				*kt=(broj%10)+'0';
				broj/=10;
			}
			tekst=tekst+brbr+1;
		}
		while(*tekst==' ')
			tekst++;
		
	}
	
    
	return poc;

}

int main() {
	

	return 0;
}

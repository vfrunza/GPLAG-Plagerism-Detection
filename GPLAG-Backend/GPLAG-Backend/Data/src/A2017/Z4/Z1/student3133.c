#include <stdio.h>

int izbroji(int br){
	int brojac=0;
	if(br<0)
		br*=-1;
	do{
		brojac++;
		br/=10;
	}while(br!=0);
	return brojac;
}
void ubaci_broj(char *s,int br){
	char *pok=s,*pok1=s,*pok2,*pok3,*pok4,c;
	int brojac=0,flag=0,kop;
	if(br<0){
		br*=-1;
		flag=1;
	}
 while(*pok!='\0'){
 	kop=br;
	 	while(*pok==' '&&*pok!='\0')
	 		pok++;
	 	if((*pok>='a'&&*pok<='z')||(*pok>='A'&&*pok<='Z')){
			pok1=pok;
			while(*pok1!=' ')
				pok1++;
			brojac=izbroji(br);
			pok2=pok1;
	if(flag){
		while(*pok2!='\0')
			pok2++;
		pok3=pok2+brojac+1;
	while(pok2!=pok1+1)
		*pok3--=*pok2--;
	pok4=pok3;
	do{
		*pok4--=kop%10 + "0";
		br/=10;
	}while(kop!=0);
	}
					
	 	}
	 	
 	pok++;
 }

}
int main() {
	char s[100]="hihihi ovo je kul.";
	ubaci_broj(s,-11);
	printf("%s",s);
	return 0;
}

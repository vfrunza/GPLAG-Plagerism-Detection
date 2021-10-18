#include <stdio.h>
void najduzi_bp(char *s1, char *s2){
	int ascii_brojac[127]={0}, brojac=0, velicina=0, pocetak=1, i;
	char *pok_na_najveci=s1;
	char *pok=s1;
	char c;
	
	while(*s1!='\0'){
		if(*s1<'A'||*s1>'Z'&&*s1<'a'||*s1>'z'){
			//slucaj ako imas vise znakva koja nisu slovo ?
			brojac=0;
			for(i=65;i<122;i++)ascii_brojac[i]=0;
			pocetak=1;
			s1++;
			continue;
		}
		
		
		if(*s1>='A'&&(*s1<='Z')){
			c=*s1+'a'-'A';
		} 
		else c=*s1;
		if(ascii_brojac[c]==0){
			ascii_brojac[c]++;
			brojac++;
			if(pocetak){
				pok=s1;				
				pocetak=0;
			}
			if(velicina<brojac){
				velicina=brojac;
				pok_na_najveci=pok;
			}
		}
		
		else{
			s1=s1-(brojac-1);
			brojac=0;
			for(i=65;i<122;i++)ascii_brojac[i]=0;
			pocetak=1;
			
			continue;
		}
		s1++;
	}
	
	for(i=0;i<velicina;i++){
		*(s2+i)=*(pok_na_najveci+i);
	}
	*(s2+i)='\0';
}
int main() {
	char s[10];
	najduzi_bp("Ovo je neki primjer teksta da",s);
	printf("%s",s);
	return 0;
}

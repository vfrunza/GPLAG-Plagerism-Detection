#include <stdio.h>
char*kodiraj(char* s,char* tabela){
	int i,max=0,j;
	int brojac[95]={0};
	char* p;
	char* q;
	char* t;
	p=s;
	q=s;
	t=tabela;
	while(*q!='\0'){
		for(i=0;i<95;i++){
			if(*q==i+32)
			brojac[i]++;
			
		}
		q++;
	}
	for(i=0;i<96;i++){
		for(j=0;j<95;j++){
			if(brojac[j]>brojac[max])
			max=j;
		}
		*tabela++=32+max;
		brojac[max]=-1;
		max=0;
	}
	*tabela='\0';
     tabela=t; 
	while(*p!='\0'){
		while(*p!=*t)
		t++;
		*p=126-(t-tabela);
	t=tabela; 
		p++;
	}
	return s;
}
char* dekodiraj(char* s,char* tabela){
	int j,i;
	char* p=s;
	char* t=tabela;
/*	p=s;
	t=tabela; */
	while(*p!='\0'){
		j=126-*p;
		for(i=0;i<j;i++)
			t++;
			*p=*t;
			t=tabela;
			p++;
}
		return s;
	
}
int main() {
	char s[]="LLMLNLNMONM";
	char koder[200]=" ";
	char dekoder [200]=" ";
	int i;
	kodiraj(s,koder);
	printf("%s \n",s);
	for(i=0;i<10;i++)
	printf("%c",koder[i]);
	printf("\n");
	kodiraj(s,dekoder);
	printf("%s \n",s);
	for(i=0;i<10;i++)
		printf("%c",dekoder[i]);
	printf("\n");
	
	dekodiraj(s,dekoder);
	printf("%s ",s);
	dekodiraj(s,koder);
	printf("%s ",s);
	
	return 0;
}

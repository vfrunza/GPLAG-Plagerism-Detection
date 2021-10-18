#include<stdio.h>
void unesi(char niz[], int velicina){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
	
}
int provjera_duzine(char* s,int*niz, int velicina_niz)
{
	
	
	int i=0, a=0;
	while(*s!='\0'){
		while((*s>='A'&& *s<='Z')||(*s>='a'&& s<='z')){
		a++;
		s++;
	}
	if(niz[i]!=a) return 0;
	else
	{
		s++;
		i++;}
		a=0;
	

		if(*s='\0'&& (i!=velicina_niz )) return 0;
		
	}return 1;
}
int main(){
	
	int niz[100],i=0, velicina_niz;
	char s[100];
	unesi(s,100);
	
	
	printf("%d", provjera_duzine(s,niz,velicina_niz));
	return 0;
}









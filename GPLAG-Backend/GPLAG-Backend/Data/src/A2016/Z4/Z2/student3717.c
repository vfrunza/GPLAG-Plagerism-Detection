#include <stdio.h>

char *copy(char *s, char *a){
	char *poc=s;
	while(*a){
		*s++=*a++;
	}
	*s='\0';
	return poc;
}

int duz(char *s){
	int broj=0;
	while(*s!='\0'){
		broj++;
		s++;
	}
	return broj;
}

int ponavljanje(char *s, char x){
	int broj=0;
	while(*s!='\0'){
		if(*s==x)
		broj++;
		s++;
	}
	return broj;
}

char *kodiraj(char *s, char *tab){
	char *poc=s,*poctab=tab,*k, *pock=k,str[100]="",temp;
	int i,j,n,duzinak,duzinatab,logika;
	poctab=tab;
	k=&str[0];
	if(*tab=='\0'){
		*tab=*s;
		while(*s!='\0'){
			logika=1;
			tab=poctab;
			while(*tab!='\0'){
				if(*tab==*s)
				logika=0;
				tab++;
			}
			if(logika==1)
			*tab=*s;
			s++;
		}
		tab++;
		*tab='\0';
		tab=poctab;
		s=poc;
		n=duz(tab);
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					if(ponavljanje(s,tab[i])>ponavljanje(s,tab[j])){
						temp=tab[i];
						tab[i]=tab[j];
						tab[j]=temp;
					}
				}
			}
	}
	pock=k;
	*k=' ';
	while(*k!='~'){
		k++;
		*k=*(k-1)+1;
	}
	k++;
	*k='\0';
	k=pock;
		for(j=0; j<n; j++){
			while(*k!='\0'){
				if(*k==tab[j])
				copy(k,k+1);
				else k++;
			}
			k=pock;
		}
		duzinak=duz(k);
		copy(tab,k);
		duzinatab=duz(tab);
		while(*s!='\0'){
			for(j=0; j<duzinatab; j++){
				if(*s==tab[j]){
					*s=126-j;
					break;
				}
			}
			s++;
		}
		return poc;
}

char *dekodiraj(char *s, char *tab){
	char *poc=s;
	int j;
	while(*s!='\0'){
		j=126-*s;
		*s=tab[j];
		s++;
	}
	return poc;
}

int main() {
	char sifrarnik[100]="";
	char tekst[]="";
	int j;
	kodiraj(tekst,sifrarnik);
	dekodiraj(tekst,sifrarnik);
	printf("%s\n",tekst);
	for(j=0; j<10; j++){
		printf("%c",sifrarnik[j]);
	}
	return 0;
}

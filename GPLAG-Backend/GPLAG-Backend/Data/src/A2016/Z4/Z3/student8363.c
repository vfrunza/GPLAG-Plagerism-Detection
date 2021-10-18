#include <stdio.h>

int abs (int a){
	if(a>=0)return a;
	return a*=-1;
}
int strcmp( char *s1,  char *s2) {
	char *p=s1,*q=s2;
	while((*p!='\0' && *p!=' ') || *q!='\0') {
		if(*p!=*q)return 1;
		p++;
		q++;
	}
	return 0;
}
int get_len(char *a) {
	int i=0;
	while(*a!=' ' && *a!='\0') {
		a++;
		i++;
	}
	return i;
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char *tmp = tekst, *krajteksta = tekst;
	char *tmp2,*tmp3;
	int i,l1,l2,c,j,duzina_teksta=-1;
	
	while(*krajteksta!='\0')krajteksta++;
	for(i=0; i<broj_rijeci; i++) {
		tmp = tekst;
		while(*tmp) {
			if(strcmp(tmp,*(rijeci+i))==0) {
				l1 = get_len(*(rijeci+i));
				l2 = get_len(*(zamjene+i));
				c =  abs(l2-l1);
				tmp2= tmp;
				duzina_teksta=0;
				while(*tmp2!='\0'){tmp2++;duzina_teksta++;}
				if(l2 > l1)
				while(tmp2 >= tmp) {
					*(tmp2 + c )= *tmp2;
					tmp2--;
				}
				tmp2 =  tmp;
				tmp3 = *(zamjene+i);
				for(j=0; j<l2; j++) {
					*(tmp2 + j) = *(tmp3 + j);
				}
				tmp2=tmp2+j;
				while(*tmp2 != ' ' && *tmp2!='\0'){
					tmp3=tmp2 + 1;
					while(*tmp3!='\0'){
						if(tmp3!=tekst)
						*(tmp3 - 1)=*(tmp3);
						tmp3++;
					}
					if(tmp3!=tekst)*(tmp3-1)='\0';
				}
				
			}
			while(*tmp!=' ' && *tmp!='\0')tmp++;
			while(*tmp==' ' && *tmp!='\0')tmp++;
			
			
		}
	}
	return tekst;
}
int main() {
	return 0;
}

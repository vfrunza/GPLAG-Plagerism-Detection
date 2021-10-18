#include <stdio.h>

int provjeri_duzine(char *recenica,int *broj,int vel){
	char *p=recenica, *q=recenica,*r=recenica;
	int brojac=0,br=0;
	
	while (*r){
		if((*r>=65 && *r<=90) || (*r>=97 && *r <=122)){
			br++;
			while(((*r>=65 && *r<=90) || (*r>=97 && *r<=122)) && *r) r++;
		}
		if(*r=='\0')break;
		r++;
	}

	if(br!=vel) return 0;
	while(*p){
		if((*p>=65 && *p<=90) || (*p>=97 && *p<=122)){
			q=p;
			while((*q>=65 && *q<=90) || (*q>=97 && *q<=122)){
				brojac++;
				q++;
			}
			
			p=q;
			if(brojac!=*broj) return 0;
			broj++;
			brojac=0;
		}
		else p++;
	}
	return 1;
	
}

int main() {
	
	char a[]="jasamarmin";
	int b[]={3,2,4,7,6};
	char *c=a;
	int *n=b;
	int x=provjeri_duzine(c,n,5);
	printf("%d",x);
	return 0;
}

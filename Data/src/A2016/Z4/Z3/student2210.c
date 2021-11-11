#include <stdio.h>
char* zamjena_rijeci(char* tekst,char** rijeci,char** zamjene,int broj_rijeci){
	int a=0,b=0,i,j=0,k;
	char* p=tekst;
	char* q=tekst;
	char* zadnji=p;
	if(*tekst==NULL || broj_rijeci<=0) return q;
	while(*tekst!='\0'){
		for(i=0;i<broj_rijeci;i++){
			while(*tekst!=' ' && *tekst!=',' && rijeci[i][j]!='\0'){
				if(*tekst!=rijeci[i][j])
				break;
				j++;
				tekst++;
			}
			if((*tekst==' ' || *tekst==',' || *tekst=='\0') && rijeci[i][j]=='\0'){
				a=0;
				b=0;
				while(rijeci[i][a]!='\0')
				a++;
				while(zamjene[i][b]!='\0')
				b++;
				while(*zadnji!='\0')
				zadnji++;
				while(zadnji>p){
					*(zadnji-a+b)=*zadnji;
					zadnji--;
				}
				for(k=0;k<b;k++){
					if(*p==' ' && k==0)
					p++;
					*p=zamjene[i][k];
					p++;
					tekst=p;
				}
			}
			else if(j==broj_rijeci-1 || *tekst=='-' || *tekst==','){
				while(*tekst!=' ' && *tekst!='\0')
				tekst++;
			}
			p=tekst;
			j=0;
		}
		tekst++;
	}
	return q;
}
int main() {
	char* rijeci[2] = {"beli","sneg"};
	char* zamjene[2] = {"bijeli","snijeg"};
	char tekst[100] = {"beli sneg je pokrio beli breg"};
	printf("%s", zamjena_rijeci(tekst,rijeci,zamjene,2));
	
	return 0;
}

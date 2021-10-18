#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pomjeri(char *s,int broj)
{
	int i=0;
	for(i=broj; i<strlen(s)-1; i++) {
		s[i]=s[i+1];
	}
	s[strlen(s)-1]='\0';
}
void izbaci_duple(char *niz)
{
	int i=0,j=0;
	for(i=0; i<strlen(niz); i++) {
		for(j=i+1; j<strlen(niz); j++) {
			if((niz[i]==niz[j])||((niz[i]+'a'-'A')==niz[j])) {
				pomjeri(niz,j);
				j--;
			}
		}
	}
}
void najduzi_bp(char *s1,char *s2)
{
	int t1=0,t2=0,i=0,j=0,brznakova=0,b=0,nova_duzina=0,duzina=0,k=0,max=0,p=0,n=0;
	char niz[1000]= {0},novi[1000]= {0},novi_niz[1000]= {0};
	char *pom=s1;
	char* kraj=s1;
	char* pocetak=s1;
	char*tmp=s2;
	while(*pom!='\0') {
		brznakova++;
		pom++;
	}
	while (*s1!='\0')	{
		while(*s1<'A'||(*s1>'Z'&&*s1<'a')||*s1>'z') {
			s1++;
			t1=1;
		}
		if(t1==1) s1--;
		while((*s1>='A'&&*s1<='Z')||(*s1>='a'&& *s1<='z')) {
			niz[i]=*s1;
			i++;
			s1++;
			t2=1;
		}

		if(t2==1) {
			s1--;
			niz[i]='\0';
		}
		if(t2==1) {
			pom=niz;
			izbaci_duple(niz);
			while (*pom!='\0') {
				novi[j]=*pom;
				j++;
				pom++;
				n=1;
			}
			if(n) {
				novi[j]='\0';
				pocetak=novi;
			}
			duzina=j;
			n=0;
			b=0;
			if(duzina>max) {
				max=duzina;
				for(k=0; k<duzina; k++)
					novi_niz[k]=novi[k];
				nova_duzina=duzina;
				novi_niz[k]='\0';
				b=1;
			}
		}
		duzina=0;
		j=0;
		p=0;
		t1=0;
		t2=0;
		s1++;
		i=0;
	}
	tmp=s2;
	for(i=0; i<9; i++) {
		if(i>nova_duzina) {
			*s2=' ';
			s2++;
		} else {
			*s2=novi_niz[i];
			s2++;
		}
	}
	s2='\0';
	s2=tmp;

}
int main()
{
	char niz[]="Ovo je primjer",niz2[10];
	najduzi_bp(niz,niz2);
	printf("%s",niz2);
	return 0;
}

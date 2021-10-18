#include <stdio.h>
int provjeri_duzine(char* recenica,int niz[],int velicina)
{
	int p[50000];
	int i,j,temp;
	i=0;
	while(*recenica!='\0')
	{
		temp=0;
		while((*recenica>=65 && *recenica<=90) || (*recenica>=97 && *recenica<=122))
		{
		   temp++;
		   recenica++;
		}
		if(temp>0) {p[i]=temp; i++;}
		if(*recenica=='\0') break;
		recenica++;
	}
	if(i!=velicina) return 0;
    for(j=0;j<velicina;j++)
    if(p[j]!=niz[j]) return 0;
    return 1;
}
int main() {
	char tekst[50]="   neki   primjer,85848&&/&   neki primjer&TEST";
	int niz[5]={4,7,4,7,4};
	int p=provjeri_duzine(tekst,niz,5);
	if(p==1) printf("DA");
	else if(p==0) printf("NE");
	return 0;
}

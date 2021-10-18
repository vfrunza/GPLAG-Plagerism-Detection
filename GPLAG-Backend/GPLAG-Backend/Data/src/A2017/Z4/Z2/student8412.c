#include <stdio.h>
int provjeri_duzine(char* tekst,int* niz,int vel)
{ int a=0,brojrijeci=0,i=0,brslova=0;
	while(*(tekst+i)!='\0')
{
	if(a==0 && ((*(tekst+i)>='A' && *(tekst+i)<='Z') || (*(tekst+i)>='a' && *(tekst+i)<='z'))) {a=1; brojrijeci++; }
	if(!((*(tekst+i)>='A' && *(tekst+i)<='Z') || (*(tekst+i)>='a' && *(tekst+i)<='z'))) a=0;
	i++;
}
if(brojrijeci!=vel) return 0;
i=0;
a=0;
brojrijeci=0;
while(*(tekst+i)!='\0')
{   //broji rijeci
	if(a==0 && ((*(tekst+i)>='A' && *(tekst+i)<='Z') || (*(tekst+i)>='a' && *(tekst+i)<='z'))) {a=1; brojrijeci++;
	}
	if(!((*(tekst+i)>='A' && *(tekst+i)<='Z') || (*(tekst+i)>='a' && *(tekst+i)<='z'))) a=0;
	//broji slova u rijeci
	if((*(tekst+i)>='A' && *(tekst+i)<='Z') || (*(tekst+i)>='a' && *(tekst+i)<='z')) {brslova++;}
	//ako naidje na drugi znak-zavrsetak rijeci, poredi br. slova u prethodnoj rijeci sa brojem pozicioniranim na mjestu  u nizu
	if(!((*(tekst+i)>='A' && *(tekst+i)<='Z') || (*(tekst+i)>='a' && *(tekst+i)<='z')) && brslova!=0) {
		if(brslova!=*(niz+brojrijeci-1)) return 0;
		brslova=0;
		}
	
	i++;
}
return 1;
}
int main() {
	char tekst[] = " otkad to";
	int niz[2]={5,2};
	printf("broj rijeci je %d",provjeri_duzine(tekst,niz,2));
	return 0;
}

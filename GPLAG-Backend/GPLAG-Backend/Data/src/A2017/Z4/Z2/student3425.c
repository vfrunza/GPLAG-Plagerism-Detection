#include <stdio.h>

int provjeri_duzine(char *p, int niz[], int vel){
	int i=-1;	/*Brojac rijeci*/
	int j=0;	/*Brojac slova u rijeci*/
	
	while(*p!='\0'){
		if((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')){ 
			i++;	/*Nova rijec pa povecavamo brojac*/
			while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')){
				j++;
				p++;
			}
			p--;
			if (i>=vel || niz[i]!=j) return 0;	/*Uslov pomocu kojeg provjeravamo da li se podudara broj slova rijeci sa indeksom broja rijeci (i) */
		}
		j=0;
		p++;
	}
	if((i+1)!=vel) return 0;
	return 1;
}

int main() {
	char recenica[50];
	int niz[10],i;
	printf("Unesite neki tekst: ");
	for(i=0;i<50;i++){
		char x=getchar();	
		if(x=='\n'){
			recenica[i]='\0';
			break;
		}
		recenica[i]=x;
	}
	
	printf("Unesite brojeve (-1 za kraj unosa) : ");
	for(i=0;i<10;i++){
		int x;
		scanf("%d",&x);
		if(x==-1) break;
		niz[i]=x;
	}
	if(provjeri_duzine(recenica,niz,10)) printf("ODGOVARA");
	else printf("NE ODGOVARA");
	return 0;
}

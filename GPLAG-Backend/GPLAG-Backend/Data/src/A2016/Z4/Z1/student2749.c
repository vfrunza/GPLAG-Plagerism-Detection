#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
/*Funkcija za broj rijeci*/
int brojr(char*p){
	int br=0, bioupetlji;
	 while(*p!='\0'){
	 	bioupetlji=0;
	 	while((*p>='a' && *p<='z') || (*p>='A' && *p<='Z')){
	 		p++;
	 		if(*p=='\0'){
	 			break;
	 		}
	 		bioupetlji=1;
	 	}
	 	if(bioupetlji) br++;
	 	if(*p=='\0') break;
	 	p++;
	 }
	 return br;
}

int poredi_rijeci (char *s1,char *s2){
	while (((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')) && ((*s2>='a' && *s2<='z') || (*s2>='A' && *s2<='Z'))){
		if(*s1==*s2 || *s1==*s2+32 || *s1==*s2-32 || *s1+32==*s2 || *s1-32==*s2){
			s1++;
			s2++;
		}
		else return 0;
	}
	
	/*ako je jedan string jos uvijek slovo a drugi nije*/
	if(((*s1>'Z' && *s1<'a') || *s1>'z' || *s1<'A') && ((*s2>='a' && *s2<='z') || (*s2>='A' && *s2<='Z'))) return 0;
	if(((*s2>'Z' && *s2<'a') || *s2>'z' || *s2<'A') && ((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z'))) return 0;
	if((*s1>'Z' && *s1<'a') || *s1>'z' || *s1<'A') s1--;
	if((*s2>'Z' && *s2<'a') || *s2>'z' || *s2<'A') s2--;
	if(*s1==*s2 || *s1==*s2+32 || *s1==*s2-32 || *s1+32==*s2 || *s1-32==*s2) return 1;
}
/*Broj slova*/
int brojsl(char*s1){
	int brsl=0;
	while ((*s1>=65 && *s1<=90) || (*s1>=97 && *s1<=122)){
		brsl++; s1++;
		if(*s1=='\0') break;
	}
	return brsl;
}

char* izbaci_najcescu(char*s){
	char*p=s, *q=s, *t=s, *x; /*sve pokazivaci na prvi karakter stringa*/
	if(*p=='\0'){ return s;}
	char*izbaci;
	char a[100];
	izbaci=a;
	int brojrijeci, max, i, j, redbr, brojslova=0, brpon[100];/*redbr je redni broj rijeci koja se najvise ponavlja*/
	brojrijeci=brojr(p);
	char* rijec[100]; 
	for(i=0;i<brojrijeci;i++){
		while((*p>'Z' && *p<'a') || *p>'z' || *p<'A'){
			p++;
			if(*p=='\0') break;
		}
		if((*p>='a' && *p<='z') || (*p>='A' && *p<='Z')) rijec[i]=p;
		/*dolazi do kraja prve rijeci*/
		while((*p>='a' && *p<='z') || (*p>='A' && *p<='Z')){
			p++;
			if(*p=='\0') break;
		}
		if(*p=='\0') continue;
		/*dolazi do kraja "neslova"*/
		while((*p>'Z' && *p<'a') || *p>'z' || *p<'A'){
			p++;
			if(*p=='\0') break;
		}
	}
	for(i=0;i<brojrijeci;i++){
		brpon[i]=1;
		for(j=i+1;j<brojrijeci;j++){
			if(poredi_rijeci(rijec[i],rijec[j])){
				brpon[i]++;
			}
		}
	}
	
	max=brpon[0]; redbr=0;
	for(i=0;i<brojrijeci;i++){
		if(brpon[i]>max){ 
			max=brpon[i];
			redbr=i;
		}
	}
	if(brojrijeci!=0){
	x=rijec[redbr];
	while((*(rijec[redbr])>='a' && *(rijec[redbr])<='z') || (*(rijec[redbr])>='A' && *(rijec[redbr])<='Z')){
		*izbaci=*rijec[redbr];
		izbaci++; 
		(rijec[redbr])++;
		if(*(rijec[redbr])=='\0') break;
	}
	brojslova=brojsl(x);
	*izbaci='\0';
	izbaci=a;
	rijec[redbr]=x;
	while(*q!='\0'){
		while((*q>'Z' && *q<'a') || *q>'z' || *q<'A'){
			q++;
			if(*q=='\0') break;
		}
		t=q;
		if(poredi_rijeci(t,izbaci)){
			while(*(t+brojslova)!='\0'){
				*t=*(t+brojslova);
				t++;
			}
			*t='\0';
		}
		while((*q>='a' && *q<='z') || (*q>='A' && *q<='Z')){
			q++;
			if(*q=='\0') break;
		}
	}
	}
	return s;
}

int main() {
	char a[500];
	printf("Unesite tekst: ");
	unesi(a, 500);
	printf("'%s'", izbaci_najcescu(a));
	return 0;
}

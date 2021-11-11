#include <stdio.h>
void unesi(char niz[], int velicina) {
	char znak = getchar();
	int i=0;
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

char *velika(char *s){
	char *p;
	p=s;
	while(*s!='\0'){
		if(*s>='a' && *s<='z')
			*s=*s-32;
			s++;
	}
	return p;
}

int poredi_rijeci(char *prva,char *druga){
	int i=0;
	while(prva[i]!='\0' || druga[i]!='\0'){
		if(prva[i]==druga[i])
		i++;
		else
		return 0;
	}
	if(prva[i]==druga[i])
	return 1;
	else
	return 0;
}

int max_rijec(char* a){
	char rijeci[50][100]={""},s[100]="";
	int i=0,k=0,j=0,max=0,niz[50]={0};
	
	while(!((*a>='a' && *a<='z')||(*a>='A' && *a<='Z'))&&(*a=='\0')){
		a++;
	}
//	printf("%s",a);
	while(*a!='\0'){
		s[i]=*a;
		a++;
		i++;
	}
	velika(s);
	for(i=0;s[i]!='\0';i++){
		if(!((s[i]>=65 && s[i]<=90))){
			rijeci[k][i]='\0';
			while(((s[i]>=65 && s[i]<=90)))
			i++;
			k++;
			j=0;
		}
		else{
			rijeci[k][j]=s[i];
			
			j++;
		}
	}
	
	for(i=0;i<k+1;i++){
		for(j=0;j<k+1;j++){
			if(poredi_rijeci(rijeci[i],rijeci[j]))
			niz[i]++;
		}
	}
	max=niz[0];
	for(i=0;i<k+1;i++){
	if(niz[i]>max){
		max=niz[i];
	}
	}
	for(i=0;i<k+1;i++){
		if(niz[i]==max){
			j=i;
			break;
		}
	}
	return j;
}

char veliko_malo(char s){
	if(s>='a' && s<='z')
	s=s-32;
	else
	s=s+32;
	return s;
}

char* izbaci_najcescu(char* s){
	char *a,izbaci[100]="";
	int b=max_rijec(s),i=0,j=-1,k=0,n=0,h=0,m=0;
	a=s;
		for(i=0;s[i]!='\0';i++){
			if((s[i]>=69 && s[i]<=90)||(s[i]>=97 && s[i]<=122)){
				j++;
				if(j==b){
					k=i;
					i=0;
					while((s[k]>=69 && s[k]<=90)||(s[k]>=97 && s[k]<=122)){
					izbaci[i]=s[k];
					k++;i++;
					}
					izbaci[i]='\0';
					break;
				}
				while(((s[i]>=69 && s[i]<=90)||(s[i]>=97 && s[i]<=122)))
				i++;
			}
		}
//		printf("%s",izbaci);
		s=a;
		i=0;b=0;
		while(s[i]!='\0'){
			if(!((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z'))){
			i++;m=i;b=0;j=0;}
			else{
				if((s[i]==izbaci[b] || s[i]==veliko_malo(izbaci[b]) || s[i]==veliko_malo(izbaci[b]))&&(s[i]!='\0')){
				b++;
				j++;
				}
				else{
					for(h=i;((s[h]>='A' && s[h]<='Z')||(s[h]>='a' && s[h]<='z'));h++)
					i++;
					b=0;j=0;i--;
				}
				if(j==k && !((s[i+1]>='A'&&s[i+1]<='Z')||(s[i+1]>='a'&&s[i+1]<='z'))){
					b=0;
					j=0;
					for(h=0;h<k;h++){
					for(n=m;s[n]!='\0';n++){
						s[n]=s[n+1];
					}
					}
				
					i=-1;
				}
				i++;
				
			}
		}
	return a;
}

int main() {
	
	char t[100];
	unesi(t,100);
	izbaci_najcescu(t);
	return 0;
}

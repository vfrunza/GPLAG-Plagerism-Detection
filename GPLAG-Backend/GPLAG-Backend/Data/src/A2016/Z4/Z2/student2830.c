#include <stdio.h>
int izbroji(char s[]){
	int n=0;
	while(*s!='\0'){
		n++;
		s++;
	}
	return n;
}
void izbaci_najcescu(char niz[]){
	int i=0,j,n,z;
char *s;
s=niz;
n=izbroji(niz);
while(*s!='\0'){
	for(j=i+1;j<n;j++){
		if(*s==niz[j]){
			for(z=j;z<n;z++){
				niz[z]=niz[z+1];
			}
			j--;
		}

}
s++;
i++;
}

}

char *kodiraj(char text[], char string[]){
	
	int i=0,j=0,z=0,n,max,b,k=0,c=0,novi;
	int niz[50];
	char *q[50],rez[50],temp='a';
	char *p,*s,*d,*f,*l;
	f=text;
		for(i=0;i<50;i++){
		niz[i]=1;
	}
	i=0;
	while(*f!='\0'){
		rez[i]=*f;
		f++;
		i++;
	}
	rez[i]='\0';
	p=rez;
	s=string;
	d=string;
	i=0;
	while(*p != '\0'){
		q[i]=p;
		i++;
		p++;
	}
	n=i;
	p=rez;
for(i=0; i<n-1; i++){
	for(j=i+1; j<n; j++){
		if(*q[i] == *q[j]) niz[i]++;
	}
}

	for(i=0;i<n;i++){
		max=i;
		for(j=i+1;j<n;j++){
			if(niz[j] > niz[max]){
			max=j;
			} else if(niz[j] == niz[max]){
				if(*q[j] < *q[max]){
					temp=*q[j];
					*q[j]=*q[max];
					*q[max]=temp;
					novi=niz[j];
					niz[j]=niz[max];
					niz[max]=novi;
				}
			}
		}
		temp=*q[i];
		*q[i]=*q[max];
		*q[max]=temp;
	                novi=niz[i];
					niz[i]=niz[max];
					niz[max]=novi;
	}
izbaci_najcescu(rez);
	p=rez;
	i=0;
	b=izbroji(rez);
while(i<b){
	*(s+i)=*(p+i);
	i++;
}
p=rez;
for(j=32; j<127; j++){
		p=rez;
	for(z=0; z<b; z++){
		if(*(p+z)==j){
		k=1;
		break;
		}
	}
	if(k==0){
	*(s+i)=j;
	i++;
	}
	k=0;
}
p=rez;
*(s+i)='\0';
c=izbroji(text);
for(i=0;i<c;i++){
	for(j=0;j<94+b;j++){
		if(text[i]==d[j]){
			text[i]=126-j;
			break;
		}
	}
}
text[i]='\0';
l=text;
return l;
}
char *dekodiraj(char sifra[], char tabela[]){
	int b,i;
	char *p,*q;
	p=sifra;
	q=tabela;
	b=izbroji(tabela);
	while(*p!='\0'){
		for(i=0;i<b;i++){
			if(126-i==*p){
				*p=*(q+i);
				break;
			}
		}
		p++;
	}
return sifra;
}


int main() {
	char text[]="Ovo je neki testni tekst";
	char sifrarnik[100];
	kodiraj(text,sifrarnik);
	return 0;
}

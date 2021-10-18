#include <stdio.h>

void kopiraj (char* prvi, char* drugi) {
	while(*prvi!='\0') {
		*drugi++ = *prvi++;
	}
	*drugi='\0';
}

int nadji(char* string, char a,int vel) {
	int i;
	for(i=0;i<vel;i++) {
		if(a==string[i]) return i;
	}
	return 0;
}

int neki(char znak,char* string, int vel) {
	int i;
	for(i=0;i<vel;i++) {
		if(znak==string[i]) return 1;
	}
	return 0;
}

void sortiraj_po_zadatku (char* s, int* brojaci,int vel) {
	char temp;
	int i,j,temp1;
	for(i=0;i<vel;i++) {
		for(j=i;j<vel;j++) {
			if(i==j) continue;
			else if (brojaci[i]<brojaci[j]) {
				temp=*(s+i);
				*(s+i)=*(s+j);
				*(s+j)=temp;
				temp1=brojaci[i];
				brojaci[i]=brojaci[j];
				brojaci[j]=temp1;
			}
			else if(*(s+i)>*(s+j) && brojaci[i]==brojaci[j]) {
				temp=*(s+i);
				*(s+i)=*(s+j);
				*(s+j)=temp;
				temp1=brojaci[i];
				brojaci[i]=brojaci[j];
				brojaci[j]=temp1;
			}
			else if(brojaci[i]>brojaci[j]) continue;
		}
	}
}

int check1 (char* prvi, char* drugi,int vel,int* brojaci,int br) {
	int j;
	for(j=0;j<vel;j++) {
		if(j==br) continue;
		 else if (prvi[br]==drugi[j] && brojaci[br]==brojaci[j]) return j;
		}
		return 0;
}

int velicina(char* niz) {
	int brojac=0;
	while(*niz!='\0') {
		niz++;
		brojac++;
	}
	return brojac;
}

int check(char* prvi, char*drugi,int i,int vel) {
	int j;
	for(j=0;j<vel;j++) {
		if(prvi[i]==drugi[j] && j!=i) return j;
	}
	return 0;
}

int check2(int* prvi, int* drugi, int i, int vel) {
	int j;
	for(j=0;j<vel;j++) {
		if(prvi[i]==drugi[j] && j!=i) return 1;
	}
	return 0;
}

char* kodiraj (char* string, char* s) {
	int k,i,j,d,l,vel=0;
	int brojaci[5000];
	char isti[5000];
	char* p;
	char* q;
	char znak;
	k=velicina(string);
	kopiraj(string,isti);
	d=k;
	for(i=0;i<k;i++) {
		brojaci[i]=1;
	}
	for(i=0;i<k;i++) {
		for(j=0;j<k;j++) {
			if(i==j) continue;
			else if(*(isti+i)==*(isti+j)) brojaci[i]++;
		}
	}
	for(i=0;i<d;i++){
		l=check1(isti,isti,d,brojaci,i);
		if(l!=0) {
			for(j=l;j<d-1;j++) {
				brojaci[j]=brojaci[j+1];
				*(isti+j)=*(isti+j+1);
			}
			d--;
			i--;
		}
	}
	p=isti+d;
	*p='\0';
	sortiraj_po_zadatku(isti,brojaci,d);
	znak=' ';
	while(2) {
		if(znak=='~') break;
		else if(neki(znak,isti,k)==1) {
			znak++;
			continue;
		}
		*p++=znak++;
		vel++;
	}
	*p='~';
	p++;
	*p='\0';
	vel=vel+k;
	kopiraj(isti,s);
	p=string;
	q=s;
	znak='~';
	while(*p!='\0') {
		*p=znak-nadji(s,*p,vel);
		p++;
		q++;
	}
	return s;
}

char* dekodiraj (char* string, char* s) {
	char isti[5000];
	int brojaci[5000];
	int i,j,k,l;
	char* p;
	char* q;
	int a;
	k=velicina(string);
	kopiraj(string,isti);
	for(i=0;i<k;i++) {
		brojaci[i]=1;
	}
	for(i=0;i<k;i++) {
		for(j=0;j<k;j++) {
			if(i==j) continue;
			else if(*(isti+i)==*(isti+j)) brojaci[i]++;
		}
	}
	for(i=0;i<k;i++) {
		l=check1(isti,isti,k,brojaci,i);
		if (l!=0) {
			for(j=l;j<k-1;j++) {
			brojaci[j]=brojaci[j+1];
			*(isti+j)=*(isti+j+1);
			}
		k--;
		i--;
		}
	}
	p=isti+k;
	*p='\0';
	q=string;
	while(*q!='\0') {
		a=nadji(isti,*q,k);
		*q=s[a];
		q++;
	}
	return string;
}

int main() {
	char prvi[5000]="t~|n|x~{}w{ons}x|~{}w{yuz{y~wzx|~v}q|vyuzpr}";
	char drugi[5000]=" eotaimsdrUcjknuv!";
	printf("\n%s", dekodiraj(prvi,drugi));
	return 0;
}

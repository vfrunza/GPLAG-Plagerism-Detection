#include <stdio.h>

int main() {
/*	char niz[10];
	int i=0;
	char znak='A';
	niz[i]=znak;
	
	printf("%c",niz[0]);
	i++;
	znak='B';
	niz[i]=znak;
	printf("%c",niz[1]); */
	
	char n[10]={"amare"};
	int i;
	for(i=0;i<4;i++){
		printf("%c ",n[i]);
	}
/*	char *pok=n;
	char s;
	
	s=*pok;
	
	printf("%c",s);
	
	int nesto[10]={2,3,4,5};
	i=0;
	int broj=nesto[++i];
	
	printf("%d",broj);
	
	*/
	
	
	return 0;
}


#include <stdio.h>

int f1(char *x){
	char *q=x+1;
	while(*q>*(q-1) && *q!='\0')
	q++;
	return q-x;
}

int *f2(int *p,char *q){
	int i;
	p=p+4;
	for(i=0;i<4;i++){
	*(--p)=(*q)++;
	printf("amar- %d",*p);
	}
	printf("zzzz %d",*p);
	return p++;
}

void f3(char *x){
	char *s=x+2;
	*(s++)=*x++;
	*s++=(*x)--;
	s--;
	
}


int main() {
	int Q[5]={13,14,15,36};
	char P[8]={'M','N','O','P','Q','\0'};
	int q=2;
	printf("%d\n",*(q+P));
	char s[18]="Humamu2";
	int p=4;
	q=*(Q+p-q)+ *(q+P);
	printf("%d\n",q);
   
   	q=f1(s);
	printf("%d\n",q);
	int *pf2=f2(Q,P);
	printf("%d\n",*pf2);
	printf("%d\n",*(pf2+1));
	printf("%c %d %s\n",*s+4,*(s+4),s+4);
	f3(s);
	printf("%s\n",s);
	
	
	return 0;
}




// ISPITNI ISPIS

#include <stdio.h>


int *f1(int *p,int *q){
	int i;
	for(i=0;i<4;i++){
	*p++ +=*q++;
	}
	return p-4;
}

int f2(int *x,int p){
	int *s=x;
	while(*s++<p);
	return s-x;
}

void f3(char *x){
	char *s=x+3;
	*(s++)=*x++;
	s++;
}


int main() {
	int P[5]={4,5,6,7};
	int Q[13]={5,6,7,8};
	char s[9]="Rumunija";
	int q=3,p=6;
	q=*(Q+p-q)+*(q+P);
	int t;
	printf("%d\n",q);
	q=f2(P,6);
	printf("%d\n",q);
	int *pf1=f1(P,Q);
	printf("%d\n",*(pf1+3));
	printf("%c %d %s\n",*s+3,*(s+3),s+3);
	f3(s);
	printf("%s\n",s);
	return 0;
}


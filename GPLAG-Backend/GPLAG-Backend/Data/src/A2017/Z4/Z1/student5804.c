#include<stdio.h>
#include<stdlib.h>
void f1(int a, int *b){a++; *b=a;a--;}
void f2(int *p1, int *p2){while(p1>p2){ printf("(%d,%d)", *p1, *p2);p1--;p2++;}
printf("\n");}
int f3(int k, int*p){int s=0; while(*(p)++<k){ s+=*p;printf("s je %d p je %d\n", s, *p);}printf("s je %d p je %d i k %d\n", s, *p, k); return s;}
void f4(int *p1, int *p2){int lj=0; while(p1<p2){*p1++=*(p2+lj);lj++;}}
int main(){
	int a=1, x=1;
	int niz[10]={3,1,8,6,5,4,7,9,0,8};
	int  b=3;
//	f1(b,&a); printf("%d %d\n", a, b);
//	f2(&niz[9], niz+2);
//	b=f3(a, niz); printf("%d %d\n",a, b);
//	f4(niz, niz+4);
//	for(i=0; i<10;i++) printf("%d ", niz[i]);
int *pok1=niz;
int *pok2=niz+4;
while(*pok1++<*pok2++){ a++; printf("a %d\n", a);}
while(pok1++<pok2++) {a++; printf("x %d", x); }

	return 0;
}
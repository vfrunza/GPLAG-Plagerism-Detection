#include <stdio.h>


void fx(char *s) { 
	*s++='A';
	*(s+2)='A'; 
	s+=4; 
	*s='A';
	 }


int main() {
	char recenica[]={"Travnik"};
	fx(recenica);
	printf("%s",recenica);
	
	return 0;
}


#include <stdio.h>

/*
int a(int *x,int *y){
	*y=*x / *y;
	return *y;
}

int b(int *p, int x){
	int *z=p;
	while(*z++<x);
	return z-p;
}

void c(char *p){
	*(p+1)='-';
	*p++='-';
	p+=1;
	*p--='-';
}





int main() {
int X[4]={19, 29, 39, 49};
int Y[2][2]={5,6,7,8};
char z[10]="Bijeljina";
int y=1,x=1;
y=Y[0][0]+*(X+3);
printf("%d\n",y);
y=b(X,40);
printf("%d\n",y);
b(Y,39);
printf("%d\n",y);
a(&x,&y);
printf("%d\n",x);
c(z);
printf("%s\n",z);
return 0;
}

*/

#include <stdio.h>

int main() {
int niz[7] = {6,3,-7,-8,5,-9,
2};
int i, j, tmp;
for (i=0; i<6; i++)
	for (j=i+1; j<7; j++)
		if (niz[i]>niz[j]) {
			tmp=niz[i];
			niz[i]=niz[j];
			niz[j]=tmp;
		}
printf("%d", niz[4]);
return 0;
}



#include <stdio.h>

int f1(int a,int *b){
	a+=*b++;
	return a;
	
}

int fk(int *a,int b){
	*a= *a/b;
	printf("%d",*a++);
	return *a++;
}

void fz(char *p){
	*p++='A';
	*(p+2)='A';
	p+=4;
	*p='A';
}

int fy(int *p){
	int x;
	x=*p++;
	x;
	x+=*p++;
	return x;
}


int fx(int a,int *b){
	a+=*b++;
	return a;
}
int main() {
int X[4][4]={1,2,3,4};
int y[4]={50,60,70,80};
char g[]="Travnik";
int e=0,f=0;
f=73;
f=f1(f+1,X+1);
printf("%d\n",f);
f=fx(f+1,X[0]+1);
printf("%d\n",f);

int c;
fz(g);
printf("%s\n",g);
f=fy(X);
printf("%d\n",f);
c=fx(e,&e);
printf("%d %d\n",e,c);

return 0;
}

/*
int B[3][3]={1,2,3,4};
int b=1,a=1;
b=105;
b=fk(B+1,b+1);
printf("%d\n",b);
	return 0;
}

*/